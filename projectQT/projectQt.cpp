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
    read();
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

//            for (int i = 0; i < list.size(); ++i){
//                std::cout << list[i].toUtf8().constData() << std::endl;
//            }
            //Qua posso fare i controlli per ogni pezzo della stringa
            //0.email/Phone, 1.password, 2.nome, 3.cognome, 4.data, 5.genere
            assert(list.size() == 6);
            bool b = parserPhone(list[0]);
            std::cout << b << std::endl;
            line = in.readLine();
        }
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


