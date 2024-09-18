#ifndef CHARTWINDOW_H
#define CHARTWINDOW_H

#include <QVBoxLayout>
#include <QWidget>
#include <QtCharts/QChart>

class ChartWindow : public QWidget
{
    Q_OBJECT
public:
    explicit ChartWindow(QWidget *parent = nullptr);

    //Declaración del método addChart
    void addChart(QChart *chart);

private:
    QVBoxLayout *layout; //Variable miembro para el layout
};

#endif //CHARTWINDOW_H
