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

void ProjectQt::on_pushButtonAccess_clicked()
{

}

void ProjectQt::on_pushButtonSubmit_clicked()
{
//    bool b = parserData(QString("21/03/2019"));
//    std::cout << b << std::endl;
    this->write();
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
        const QString mess = field + " non valido.\nInserire una email o numero di telefono (10 cifre) validi!";
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
    //CAPISCI COME GESTIRE I RADIO BUTTON (fare l'evento clicked?) !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1
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
            return;
        }
        line = in.readLine();
    }
    //std::cout << "ok" << std::endl;
    file.close();
    // VERIFICARE CHE I DATI IN INPUT SIANO COERENTI, IN PARTICOLARE EMAIL/NUMERO E DATA (cambiare widget?)
    //std::cout << "ok2" << std::endl;
    QFile fileOut("users.csv");
    if (!fileOut.open(QIODevice::Append | QFile::Text)) {
        QMessageBox::critical(this, tr("Unable to open file"),
                              file.errorString());
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

void ProjectQt::read()
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
        //std::cout << line.toUtf8().constData() << std::endl;
        //devo suddividere la stringa in base al campo

        QStringList list = line.split(',');
        //Qua posso fare i controlli per ogni pezzo della stringa
        //0.email/Phone, 1.password, 2.nome, 3.cognome, 4.data, 5.genere
        assert(list.size() == 6);
        bool b = parserPhone(list[0]);
        std::cout << b << std::endl;
        line = in.readLine();
    }
    file.close();
}

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
    while(field.at(i) != '.')
    {
        i++;
        if (i >= field.size())
            return false;
    }
    i++; //salto il punto
    if (field.size() > i+1)
        return true;
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

void ProjectQt::on_radioButtonMan_clicked()
{

}
