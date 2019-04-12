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
