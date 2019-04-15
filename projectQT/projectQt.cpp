#include "projectQt.h"
#include "ui_projectQt.h"

ProjectQt::ProjectQt(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ProjectQt)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->gridLayoutWidget_2);
}

ProjectQt::~ProjectQt()
{
    delete ui;
}

/**
 * Procedura che gestisce l'accesso al sistema, attivata dal pulsante 'Access'. Se la mail inserita
 * e' quella dell'admin e la password e' corretta, stampa l'elenco di utenti in una QDialog. Altrimenti
 * fa partire la procedura di userValid() per verificare che l'utente e password inseriti siano quelli
 * di un utente nel file.
 * @brief ProjectQt::on_pushButtonAccess_clicked
 */
void ProjectQt::on_pushButtonAccess_clicked()
{
    QString user = ui->lineEditEmail->text();
    QString password = ui->lineEditPassword->text();
    if (user == "admin@pas.com")
    {
        if (password == "admin")
        {
            QString stamp;
            //stampo tutti gli utenti
            QFile file("users.csv");
            if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
                QMessageBox::critical(this, tr("Unable to open file"),
                                          file.errorString());
                return;
            }

            QTextStream in(&file);
            QString line = in.readLine();
            while (!line.isNull()) {

                //devo suddividere la stringa in base al campo

                QStringList list = line.split(',');
                //Qua posso fare i controlli per ogni pezzo della stringa
                //0.email/Phone, 1.password, 2.nome, 3.cognome, 4.data, 5.genere
                int i = 0;
                for (; i < 5; ++i)
                {
                    stamp += list[i] + " - ";
                }
                stamp += list[i] + "\n\n";
                line = in.readLine();
            }
            file.close();
            QMessageBox::about(this, tr("Users"), stamp);
            return;
        } else {
            const QString mess = "Password admin errata";
            QMessageBox::critical(this, tr("Password error"), mess);
            return;
        }
    } //end if admin
    this->validUser(user, password);
}

/**
 * Verifica che siano stati inseriti tutti i dati obbligatori per l'iscrizione di un
 * nuovo utente e nel caso fa partire la procedura di write(). Viene attivato alla
 * pressione del button 'Submit'.
 * @brief ProjectQt::on_pushButtonSubmit_clicked
 */
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

/**
 * Per recuperare la password dimenticata si clicca sull'apposito button che verifica se
 * viene inserita una email/telefono nell'apposito campo e nel caso avvia la procedura
 * di recupero password.
 * @brief ProjectQt::on_pushButtonRecovery_clicked
 */
void ProjectQt::on_pushButtonRecovery_clicked()
{
    if (ui->lineEditEmail->isModified()){
        QString user = ui->lineEditEmail->text();
        this->passwordRecovery(user);
    }
}

/**
 * Si occupa dell'inserimento di un nuovo utente. Verifica che siano stati inseriti i dati
 * in tutti i campi. Verifica la validita' dell'email o telefono e della data. Salva nel file
 * 'users.csv' il nuovo utente appendendo il record in fondo al file.
 * @brief ProjectQt::write nuovo utente
 */
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

    file.close();
    QFile fileOut("users.csv");
    if (!fileOut.open(QIODevice::Append | QFile::Text)) {
        QMessageBox::critical(this, tr("Unable to open file"),
                              file.errorString());
        file.close();
        return;
    }
    QTextStream out(&fileOut);
    QString newRow(field + "," +
                   password + "," +
                   name + "," +
                   surname + "," +
                   date.toString("dd/MM/yyyy") + "," +
                   gender + "\n");

    out << newRow;

    const QString mess = "Ciao, " + name + " " + surname + "\nBenvenuto nel nostro sistema!";
    QMessageBox::about(this, tr("Inserimento riuscito"), mess);
    fileOut.close();
}

/**
 * Verifica che field sia un indirizzo mail corretto. Ovvero deve seguire la seguente sintassi
 * <testo>@<dominio>.it
 * @brief ProjectQt::parserEmail
 * @param field
 * @return true se field e' un indirizzo valido
 * @return false altrimenti
 */
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

/**
 * Verifica che field sia un numero di telefono valido, quindi con 10 cifre
 * @brief ProjectQt::parserPhone
 * @param field
 * @return true se field e' numero di telefono correto
 * @return false altrimenti
 */
bool ProjectQt::parserPhone(QString field)
{
    if (field.size() != 10)//numero di 10 cifre
    {
        return false;
    }
    for (int i = 0; i < field.size(); ++i)
    {
        if (field.at(i) < '0' || field.at(i) > '9'){
            return false;
        }
    }
    return true;
}

/**
 * Verifica se la coppia di campi field (email/telefono) e password inseriti sono associati a un utente.
 * In quel caso viene mostrata una dialog di bentornato. Se la password viene sbagliata o viene inserito
 * un field scorretto viene segnalato
 * @brief ProjectQt::validUser
 * @param field: email/telefono
 * @param password
 */
void ProjectQt::validUser(QString field, QString password)
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
        QStringList list = line.split(',');
        //0.email/Phone, 1.password, 2.nome, 3.cognome, 4.data, 5.genere
        assert(list.size() == 6);
        if (list[0] == field) {
            if (list[1] == password) {
                const QString mess = "Bentornato nel nostro sistema " + list[2] + " " + list[3] + "!";
                QMessageBox::about(this, tr("Logged in"), mess);
                file.close();
                return;
            } else {
                const QString mess = "Hai dimenticato la password? Clicca nella bottone \"recupero password\"";
                QMessageBox::critical(this, tr("Password not correct"), mess);
                file.close();
                return;
            }
        }
        line = in.readLine();
    }
    const QString mess = "Effettua la registazione";
    QMessageBox::about(this, tr("User not found"), mess);
    file.close();
}

/**
 * Permette di avviare la procedura di ripristino password se si e' dimenticata.
 * In output si apre una dialog sia in caso di esito positivo, sia in caso di esito negativo.
 * @brief ProjectQt::passwordRecovery
 * @param user : email/telefono dell'utente
 */
void ProjectQt::passwordRecovery(QString user)
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
        QStringList list = line.split(',');
        //0.email/Phone, 1.password, 2.nome, 3.cognome, 4.data, 5.genere
        if (list[0] == user) {
            const QString mess = "e-mail con procedura di ripristino inviata";
            QMessageBox::about(this, tr("Recovery Password"), mess);
            file.close();
            return;
        }
        line = in.readLine();
    }
    const QString mess = "controlla se email/telefono corretto";
    QMessageBox::critical(this, tr("Username error"), mess);
    file.close();
    return;
}
