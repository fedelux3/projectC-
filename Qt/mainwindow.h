#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCharts>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_lbl5g_linkActivated(const QString &link);

    void on_lbl1m_linkActivated(const QString &link);

    void on_lbl6m_linkActivated(const QString &link);

    void on_lbl1a_linkActivated(const QString &link);

    void on_lbl5a_linkActivated(const QString &link);

    void on_lblMax_linkActivated(const QString &link);

    void on_btnBack_clicked();

    void on_btnForward_clicked();

private:
    Ui::MainWindow *ui;

    QDate *startDate = 0;
    QDate *lastDate = 0;
    QDate *selectedDate = 0;

    int step = 0;
    double newPoint = 0;

    QLineSeries **series = new QLineSeries*[5];
    QChart *chart = new QChart();
    QDateTimeAxis *axis_x = new QDateTimeAxis;
    QValueAxis *axis_y = new QValueAxis;
    QChartView *chartView = new QChartView(chart);
    QString *filesName = new QString[5]{"DJCA.csv", "NASDAQ100.csv", "RU3000TR.csv", "SP500.csv",
                         "WILL5000IND.csv"};

    QLineSeries* createChart(QString indice);
    void setMinimChart(QString newMin);
    void setMaxChart(QString newMax);
    void handleMarkerClicked();
    void seriesClicked(QPointF);
    void updateBox();
};

#endif // MAINWINDOW_H
