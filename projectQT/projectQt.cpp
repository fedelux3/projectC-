#include "projectQt.h"
#include "ui_projectQt.h"

ProjectQt::ProjectQt(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ProjectQt)
{
    ui->setupUi(this);
}

ProjectQt::~ProjectQt()
{
    delete ui;
}
//CAPIRE COME AGGANCIARE LA SIZE DELLA FINESTRA!!!!!!!!!!!!!!!!!!
//INSERIRE L'UTENTE ADMIN E PERMETTERGLI DI VEDERE TUTTI GLI UTENTI REGISTRATI!!!!!!!!!!!
void ProjectQt::on_pushButtonAccess_clicked()
{
    QString user = ui->lineEditEmail->text();
    QString password = ui->lineEditPassword->text();
    this->validUser(user, password);
}

void ProjectQt::on_pushButtonSubmit_clicked()
{
    bool b = ui->lineEditNewEmail->isModified()
            && ui->lineEditNewName->isModified()
            && ui->lineEditNewSurname->isModified()
            && ui->lineEditNewPassword->isModified();
    if (b)
        this->write();
    else {
        const QString mess = "inserisci tutti i dati";
        QMessageBox::critical(this, tr("Data missing"), mess);
    }
}

void ProjectQt::write()
{
    QString name = ui->lineEditNewName->text();
    QString surname = ui->lineEditNewSurname->text();
    QString field = ui->lineEditNewEmail->text();
    QString password = ui->lineEditNewPassword->text();
    QString gender("");
    QString day = ui->spinBoxDay->text();
    QString month = ui->spinBoxMonth->text();
    QString year = ui->spinBoxYear->text();

    QDate date(year.toInt(), month.toInt(), day.toInt());

    //controllo la validita' dei dati inseriti
    if (!(parserEmail(field) || parserPhone(field)))
    {
        const QString mess = field + " non valido.\nInserire una email(<nome>@<dominio>.it) o numero di telefono (10 cifre) validi!";
        QMessageBox::critical(this, tr("Sintax error"), mess);
        return;
    }
    //verifico validita' data
    if (!date.isValid())
    {
        const QString mess = "Inserire una data valida!";
        QMessageBox::critical(this, tr("Sintax error"), mess);
        return;
    }

    QRadioButton *man = ui->radioButtonMan;
    QRadioButton *woman = ui->radioButtonWoman;
    if (!man->isChecked() && !woman->isChecked()) {
        const QString mess = "Seleziona il sesso";
        QMessageBox::critical(this, tr("Missing Field"), mess);
        return;
    }
    if (man->isChecked())
        gender = "M";
    else {
        gender = "F";
    }
    //verifico che non vi sia gia' il nuovo utente
    QFile file("users.csv");
    if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
        QMessageBox::critical(this, tr("Unable to open file"),
                              file.errorString());
        return;
    }
    QTextStream in(&file);
    QString line = in.readLine();

    while(!line.isNull())
    {
        QStringList row = line.split(',');
        if (row[0] == field)
        {
            const QString mess = "Utente " + field + " e' gia' registrato!";
            QMessageBox::critical(this,tr("Unable to insert user"), mess);
            file.close();
            return;
        }
        line = in.readLine();
    }
    //std::cout << "ok" << std::endl;
    file.close();

    //std::cout << "ok2" << std::endl;
    QFile fileOut("users.csv");
    if (!fileOut.open(QIODevice::Append | QFile::Text)) {
        QMessageBox::critical(this, tr("Unable to open file"),
                              file.errorString());
        file.close();
        return;
    }//std::cout << "ok3" << std::endl;
    QTextStream out(&fileOut);
    QString newRow(field + "," +
                   password + "," +
                   name + "," +
                   surname + "," +
                   date.toString("dd/MM/yyyy") + "," +
                   gender + "\n");

    out << newRow;
    //std::cout << "inserito!" << std::endl;
    const QString mess = "Ciao, " + name + " " + surname + "\nBenvenuto nel nostro sistema!";
    QMessageBox::about(this, tr("Inserimento riuscito"), mess);
    fileOut.close();
}

//DA ELIMINARE
void ProjectQt::read()
{
    QFile file("users.csv");
    if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
        QMessageBox::critical(this, tr("Unable to open file"),
                                  file.errorString());
        return;
    }
    //questa parte mi permette di leggere riga per riga nel file
    QTextStream in(&file);
    QString line = in.readLine();
    while (!line.isNull()) {
        //std::cout << line.toUtf8().constData() << std::endl;
        //devo suddividere la stringa in base al campo

        QStringList list = line.split(',');
        //Qua posso fare i controlli per ogni pezzo della stringa
        //0.email/Phone, 1.password, 2.nome, 3.cognome, 4.data, 5.genere
        assert(list.size() == 6);
        //bool b = parserPhone(list[0]);
        //std::cout << b << std::endl;
        line = in.readLine();
    }
    file.close();
}

//DA ELIMINARE
//true se e' una data valida, false altrimenti format dd/mm/yyyy
bool ProjectQt::parserData(QString field)
{
    bool correct = true;
    if (field.size() != 10)
    {
        std::cout << "error parserData" << std::endl;
        return false;
    }
    for (int i = 0; i < field.size(); ++i){
        //std::cout << field.toUtf8()[i] << std::endl;
        switch(i){
        case 2:
                if (field.at(i) != '/')
                    correct = false;
            break;
        case 5:
                if (field.at(i) != '/')
                    correct = false;
            break;
        default:
            if (field.at(i) < '0' || field.at(i) > '9'){
                //std::cout << "NUMERO" << std::endl;
                correct = false;
            }
        }
    }
    return correct;
}

bool ProjectQt::parserEmail(QString field)
{
    int i = 0;
    while(field.at(i) != '@')
    {
        i++;
        if (i >= field.size())
            return false; //sono arrivato alla fine della stringa
    }
    //i++; //salto la @
    for (; i < field.size(); ++i)
    {
        if (field.at(i) == '.' && i+2 == field.size()-1 )
            if (field.at(i+1) == 'i' && field.at(i+2) == 't')
                return true;
    }
    return false;
}

bool ProjectQt::parserPhone(QString field)
{
    if (field.size() != 10)//numero di 10 cifre
    {
        //std::cout<< field.size() << std::endl;
        return false;
    }
    for (int i = 0; i < field.size(); ++i)
    {
        if (field.at(i) < '0' || field.at(i) > '9'){
            //std::cout << "NUMERO" << std::endl;
            return false;
        }
    }
    return true;
}

//verifica se l'utente inserito puo' accedere
void ProjectQt::validUser(QString field, QString password)
{
    //QString filename = QFileDialog::getOpenFileName(this, tr("Open"));
    QFile file("users.csv");
    if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
        QMessageBox::critical(this, tr("Unable to open file"),
                                  file.errorString());
        return;
    }
    //questa parte mi permette di leggere riga per riga nel file
    QTextStream in(&file);
    QString line = in.readLine();
    while (!line.isNull()) {
        QStringList list = line.split(',');
        //Qua posso fare i controlli per ogni pezzo della stringa
        //0.email/Phone, 1.password, 2.nome, 3.cognome, 4.data, 5.genere
        assert(list.size() == 6);
        if (list[0] == field) {
            if (list[1] == password) {
                const QString mess = "Bentornato nel nostro sistema " + list[2] + " " + list[3] + "!";
                QMessageBox::about(this, tr("Logged in"), mess);
                return;
            } else {
                const QString mess = "Hai dimenticato la password? Clicca nella label della domanda.";
                QMessageBox::critical(this, tr("Password not correct"), mess);
                return;
            }
        }
        line = in.readLine();
    }
    const QString mess = "Effettua la registazione";
    QMessageBox::about(this, tr("User not found"), mess);

    file.close();
}

void ProjectQt::passwordRecovery(QString user)
{
    //QString filename = QFileDialog::getOpenFileName(this, tr("Open"));
    QFile file("users.csv");
    if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
        QMessageBox::critical(this, tr("Unable to open file"),
                                  file.errorString());
        return;
    }
    //questa parte mi permette di leggere riga per riga nel file
    QTextStream in(&file);
    QString line = in.readLine();
    while (!line.isNull()) {
        QStringList list = line.split(',');
        //Qua posso fare i controlli per ogni pezzo della stringa
        //0.email/Phone, 1.password, 2.nome, 3.cognome, 4.data, 5.genere
        assert(list.size() == 6);
        if (list[0] == user) {
            const QString mess = "user: " + user + " password: " + list[1];
            QMessageBox::about(this, tr("Password found"), mess);
            return;
        }
        line = in.readLine();
    }
    const QString mess = "controlla se email/telefono corretto";
    QMessageBox::critical(this, tr("Username error"), mess);
    return;
}

void ProjectQt::on_pushButtonRecovery_clicked()
{
    if (ui->lineEditEmail->isModified()){
        QString user = ui->lineEditEmail->text();
        this->passwordRecovery(user);
    }
}
