#ifndef PROJECTQT_H
#define PROJECTQT_H

#include <QMainWindow>

namespace Ui {
class ProjectQt;
}

class ProjectQt : public QMainWindow
{
    Q_OBJECT

public:
    explicit ProjectQt(QWidget *parent = nullptr);
    ~ProjectQt();

private:
    Ui::ProjectQt *ui;
};

#endif // MAINWINDOW_H
