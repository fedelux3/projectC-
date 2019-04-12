#ifndef PROJECTQT_H
#define PROJECTQT_H

#include <QMainWindow>
#include <iostream>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>

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


private:
    Ui::ProjectQt *ui;

    //legge il csv
    void read();
    //inserisce nel csv
    void insert();
    //parser per la data
    bool parserData(QString field);
    //parser per email
    bool parserEmail(QString field);
    //parser per num telefono
    bool parserPhone(QString field);
    //stabilisce se e' una email o un numero di telefono
    QString emailORphone(QString field);
};

#endif // MAINWINDOW_H
