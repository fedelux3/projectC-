#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCharts>
#include <iostream>

using namespace QtCharts;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    for (int i = 0; i < 5; ++i) {
        series[i] = createChart(filesName[i]);

        if (series[i] == 0){
            QMessageBox::warning(this, "Error create chart", "chart non creato");
            return;
        }
    }

    chart->setTitle("Index stock exchange");
    axis_x->setMin(QDateTime(*startDate));
    axis_x->setMax(QDateTime(*lastDate));
    axis_x->setTickCount(10);
    axis_x->setFormat("dd MM yyyy");
    axis_x->setTitleText("Data");
    axis_y->setRange(0, 9300);
    axis_y->setTickCount(10);

    chart->addAxis(axis_x, Qt::AlignBottom);
    chart->addAxis(axis_y, Qt::AlignLeft);
    chart->legend()->show();

    for (int i = 0; i < 5; ++i) {
        chart->addSeries(series[i]);
        series[i]->attachAxis(axis_x);
        series[i]->attachAxis(axis_y);
        connect(series[i], &QLineSeries::clicked, this, &MainWindow::seriesClicked);
    }

    const auto markers = chart->legend()->markers();
    for (QLegendMarker *marker : markers) {
      // Disconnect possible existing connection to avoid multiple connections
      QObject::disconnect(marker, &QLegendMarker::clicked, this,
                          &MainWindow::handleMarkerClicked);
      QObject::connect(marker, &QLegendMarker::clicked, this,
                       &MainWindow::handleMarkerClicked);
    }

    chartView->setRenderHint(QPainter::Antialiasing);

    ui->verticalLayout->addWidget(chartView);
}

/*
 * Distruttore
 */
MainWindow::~MainWindow()
{
    delete ui;
    for(int i = 0; i < 5; ++i)
        delete series[i];
    delete[] series;
    delete[] filesName;
    delete startDate;
    delete lastDate;
    delete selectedDate;
    delete chart;
    delete chartView;
    delete axis_x;
    delete axis_y;
}

/*
 * Setta il chart con tutte le series che poi viene stampato nella window.
 */
QLineSeries* MainWindow::createChart(QString indice)
{
    QLineSeries *actualSeries = new QLineSeries;
    QFile data(indice);
    if (!data.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "Creazione Chart fallita", "impossibile aprire il file");
        return 0;
    }

    QStringList listRecords;
    QStringList date;
    QDateTime x;
    double y;
    QTextStream in(&data);
    in.readLine(); //salto la prima riga
    QString record = in.readLine();
    //devo trovare il minimo in modo da capire da dove parte il grafico
    setMinimChart(record);
    while(!in.atEnd())
    {
        listRecords = record.split(",");
        QString newX = listRecords.at(0);
        QString newY = listRecords.at(1);

        if (newY != ".") //caso di dato non presente
        {
            date = newX.split("-");
            int newYear = date.at(0).toInt();
            int newMonth = date.at(1).toInt();
            int newDay = date.at(2).toInt();
            x.setDate(QDate(newYear, newMonth, newDay));
            y = newY.toDouble();

            actualSeries->append(x.toMSecsSinceEpoch(), y);
        }
        record = in.readLine();
    }
    setMaxChart(record);

    delete selectedDate;
    selectedDate = new QDate(lastDate->year(), lastDate->month(), lastDate->day());
    data.close();
    //aggiungo nome a legenda
    QString name = indice.split(".").at(0);
    actualSeries->setName(name);
    //aggiungo valore nella labelBox
    QString dt = (*selectedDate).toString("dd-MM-yyyy");
    QStringList sl = dt.split("-");

    ui->lblCoord->setText(
      QString("X: %1 \nY: ---")
          .arg(dt));

    return actualSeries;
}

/*
 * Setta il valore minimo delle x presente nel chart
 */
void MainWindow::setMinimChart(QString newMin)
{
    QStringList date = newMin.split(",").at(0).split("-");

    int minYear = date.at(0).toInt();
    int minMonth = date.at(1).toInt();
    int minDay = date.at(2).toInt();

    QDate *newMinDate = new QDate(minYear, minMonth, minDay);

    if (startDate == 0 || newMinDate < startDate){
        delete startDate;
        startDate = newMinDate;
    } else {
        delete newMinDate;
        newMinDate = 0;
    }
}

/*
 * Setta il valore massimo delle x presente nel chart
 */
void MainWindow::setMaxChart(QString newMax)
{
    QStringList date = newMax.split(",").at(0).split("-");

    int maxYear = date.at(0).toInt();
    int maxMonth = date.at(1).toInt();
    int maxDay = date.at(2).toInt();

    QDate *newMaxDate = new QDate(maxYear, maxMonth, maxDay);

    if (lastDate == 0 || newMaxDate > lastDate) {
        delete lastDate;
        lastDate = newMaxDate;
    } else {
        delete newMaxDate;
        newMaxDate = 0;
    }
}

/*
 * Rende invisibile/visibile le series leagate a un determinato indice.
 * Viene gestito tramite la legenda
 */
void MainWindow::handleMarkerClicked() {
  QLegendMarker *marker = qobject_cast<QLegendMarker *>(sender());
  Q_ASSERT(marker);

  switch (marker->type()) {
  case QLegendMarker::LegendMarkerTypeXY: {

    marker->series()->setVisible(!marker->series()->isVisible());


    marker->setVisible(true);

    qreal alpha = 1.0;

    if (!marker->series()->isVisible())
      alpha = 0.3;

    QColor color;
    QBrush brush = marker->labelBrush();
    color = brush.color();
    color.setAlphaF(alpha);
    brush.setColor(color);
    marker->setLabelBrush(brush);

    break;
  }
  default: {
    qDebug() << "Unknown marker type";
    break;
  }
  }
}

/*
 * Questo metodo stampa nella label del box in basso il valore cliccato nella series
 */
void MainWindow::seriesClicked(QPointF point) {
    //seleziono la data in modo da poterla riprendere quando clicco sui tempi
    QString dt = QDateTime::fromMSecsSinceEpoch(point.x()).toString("dd-MM-yyyy");
    QStringList sl = dt.split("-");
    int newDay = sl.at(0).toInt();
    int newMonth = sl.at(1).toInt();
    int newYear = sl.at(2).toInt();

    delete selectedDate;
    selectedDate = new QDate(newYear,newMonth,newDay);
    newPoint = point.y();

    ui->lblCoord->setText(
      QString("X: %1 \nY: %2 ")
          .arg(dt)
          .arg(point.y()));

}

void MainWindow::on_lbl5g_linkActivated(const QString &link)
{
    axis_x->setRange(QDateTime(selectedDate->addDays(-5)),
            QDateTime(*selectedDate));
    step = 5;
}

void MainWindow::on_lbl1m_linkActivated(const QString &link)
{
    axis_x->setRange(QDateTime(selectedDate->addMonths(-1)),
            QDateTime(*selectedDate));
    step = 10;
}

void MainWindow::on_lbl6m_linkActivated(const QString &link)
{
    axis_x->setRange(QDateTime(selectedDate->addMonths(-6)),
            QDateTime(*selectedDate));
    step = 60;
}

void MainWindow::on_lbl1a_linkActivated(const QString &link)
{
    axis_x->setRange(QDateTime(selectedDate->addYears(-1)),
            QDateTime(*selectedDate));
    step = 100;
}

void MainWindow::on_lbl5a_linkActivated(const QString &link)
{
    axis_x->setRange(QDateTime(selectedDate->addYears(-5)),
            QDateTime(*selectedDate));
    step = 500;
}

void MainWindow::on_lblMax_linkActivated(const QString &link)
{
    axis_x->setRange(QDateTime(*startDate),
            QDateTime(*lastDate));

    selectedDate->setDate(lastDate->year(), lastDate->month(), lastDate->day());
    QString dt = (*selectedDate).toString("dd-MM-yyyy");
    QStringList sl = dt.split("-");

    ui->lblCoord->setText(
      QString("X: %1 \nY: ---")
          .arg(dt));
    step = 0;
}

/*
 * Setta il range del chart indietro in base allo step che sto effettuando
 */
void MainWindow::on_btnBack_clicked()
{
    switch(step) {
    case 5: //5 giorni
        *selectedDate = selectedDate->addDays(-5);
        axis_x->setRange(QDateTime(selectedDate->addDays(-5)),
                QDateTime(*selectedDate));
        break;
    case 10: //1 mese
        *selectedDate = selectedDate->addMonths(-1);
        axis_x->setRange(QDateTime(selectedDate->addMonths(-1)),
                QDateTime(*selectedDate));
        break;
    case 60:
        *selectedDate = selectedDate->addMonths(-6);
        axis_x->setRange(QDateTime(selectedDate->addMonths(-6)),
                QDateTime(*selectedDate));
        break;
    case 100:
        *selectedDate = selectedDate->addYears(-1);
        axis_x->setRange(QDateTime(selectedDate->addYears(-1)),
                QDateTime(*selectedDate));
        break;
    case 500:
        *selectedDate = selectedDate->addYears(-5);
        axis_x->setRange(QDateTime(selectedDate->addYears(-5)),
                QDateTime(*selectedDate));
        break;
    default:
        QMessageBox::about(this, "btnBack Error", "non consentito back");
    }

    QString dt = (*selectedDate).toString("dd-MM-yyyy");
    QStringList sl = dt.split("-");

    ui->lblCoord->setText(
      QString("X: %1 \nY: ---")
          .arg(dt));
}

/*
 * Setta il range del chart in avanti in base allo step che sto effettuando
 */
void MainWindow::on_btnForward_clicked()
{
    switch(step) {
    case 5: //5 giorni
        axis_x->setRange(QDateTime(*selectedDate),
                QDateTime(selectedDate->addDays(5)));
        *selectedDate = selectedDate->addDays(5);
        break;
    case 10: //1 mese
        axis_x->setRange(QDateTime(*selectedDate),
                QDateTime(selectedDate->addMonths(1)));
        *selectedDate = selectedDate->addMonths(1);
        break;
    case 60:
        axis_x->setRange(QDateTime(*selectedDate),
                QDateTime(selectedDate->addMonths(6)));
        *selectedDate = selectedDate->addMonths(6);
        break;
    case 100:
        axis_x->setRange(QDateTime(*selectedDate),
                QDateTime(selectedDate->addYears(1)));
        *selectedDate = selectedDate->addYears(1);
        break;
    case 500:
        axis_x->setRange(QDateTime(*selectedDate),
                QDateTime(selectedDate->addYears(5)));
        *selectedDate = selectedDate->addYears(5);
        break;
    default:
        QMessageBox::about(this, "forwardBtn Error", "non consentito avanzare");
    }

    QString dt = (*selectedDate).toString("dd-MM-yyyy");
    QStringList sl = dt.split("-");

    ui->lblCoord->setText(
      QString("X: %1 \nY: ---")
          .arg(dt));
}
