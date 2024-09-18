#include "chartwindow.h"
#include <QVBoxLayout>
#include <QtCharts/QChartView>

ChartWindow::ChartWindow(QWidget *parent) : QWidget(parent) {
    layout = new QVBoxLayout(this);  //Inicializamos el layout
    setLayout(layout);
}

void ChartWindow::addChart(QChart *chart) {
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    layout->addWidget(chartView);  //Añadimos el gráfico al layout
}
