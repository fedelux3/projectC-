#ifndef PROJECTQT_H
#define PROJECTQT_H

#include <QMainWindow>
#include <iostream>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QDate>

namespace Ui {
class ProjectQt;
}

class ProjectQt : public QMainWindow
{
    Q_OBJECT

public:
    explicit ProjectQt(QWidget *parent = nullptr);
    ~ProjectQt();

private slots:
    void on_pushButtonAccess_clicked();

    void on_pushButtonSubmit_clicked();
    void on_pushButtonRecovery_clicked();

private:
    Ui::ProjectQt *ui;

    //legge il csv
    void read();
    //inserisce nel csv
    void write();
    //controlla se la mail/telefono di field esiste e controlla la password
    void validUser(QString field, QString password);
    //restituisce password corretta
    void passwordRecovery(QString user);
    //parser per la data
    bool parserData(QString field);
    //parser per email
    bool parserEmail(QString field);
    //parser per num telefono
    bool parserPhone(QString field);

};

#endif // PROJECTQT_H
