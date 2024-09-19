#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "chartwindow.h"
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QChart>
#include <QtCharts/QValueAxis>
#include <QHBoxLayout>
#include "test.cpp"

using namespace std;
using namespace std::chrono;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //ui->setupUi(this);

    // Establecer el título de la ventana
    //setWindowTitle("Algoritmos de Ordenamiento y Estructuras de Datos");

    //Tamaños de prueba
    vector<int> sizes = {100, 500, 1000, 5000, 10000};

    //Crear gráficos y configurar ejes
    auto createChart = [](QLineSeries* series, QLineSeries* theoreticalSeries, const QString& title, const QString& caseType) {
        QChart *chart = new QChart();
        chart->legend()->show();
        chart->addSeries(series);
        chart->addSeries(theoreticalSeries);

        series->setName(caseType);
        theoreticalSeries->setName("Caso Teórico");
        chart->setTitle(title);

        QValueAxis *axisX = new QValueAxis();
        axisX->setTitleText("Tamaño del Conjunto de Datos");
        axisX->setLabelFormat("%d");
        axisX->setTickCount(6);
        chart->addAxis(axisX, Qt::AlignBottom);
        series->attachAxis(axisX);
        theoreticalSeries->attachAxis(axisX);

        QValueAxis *axisY = new QValueAxis();
        axisY->setTitleText("Tiempo (µs)");
        axisY->setLabelFormat("%d");
        axisY->setTickCount(6);
        chart->addAxis(axisY, Qt::AlignLeft);
        series->attachAxis(axisY);
        theoreticalSeries->attachAxis(axisY);

        return chart;
    };

    //Bubble Sort
    QLineSeries *bubbleBest = new QLineSeries();
    QLineSeries *bubbleWorst = new QLineSeries();
    QLineSeries *bubbleAverage = new QLineSeries();
    QLineSeries *bubbleBestTheoretical = new QLineSeries();
    QLineSeries *bubbleWorstTheoretical = new QLineSeries();
    QLineSeries *bubbleAverageTheoretical = new QLineSeries();

    bubbleBest->setColor(Qt::green);
    bubbleWorst->setColor(Qt::red);
    bubbleAverage->setColor(Qt::blue);
    bubbleBestTheoretical->setColor(QColorConstants::Svg::orange);
    bubbleWorstTheoretical->setColor(QColorConstants::Svg::orange);
    bubbleAverageTheoretical->setColor(QColorConstants::Svg::orange);

    for (int size : sizes) {
        bubbleBest->append(size, testBubbleSort(size));
        bubbleWorst->append(size, testBubbleSortWorst(size));
        bubbleAverage->append(size, testBubbleSortAverage(size));

        bubbleBestTheoretical->append(size, getBubbleSortTheoretical(size, "Mejor Caso"));
        bubbleWorstTheoretical->append(size, getBubbleSortTheoretical(size, "Peor Caso"));
        bubbleAverageTheoretical->append(size, getBubbleSortTheoretical(size, "Caso Promedio"));
    }

    ChartWindow *bubbleSortWindow = new ChartWindow();
    bubbleSortWindow->setWindowTitle("Bubble Sort");
    bubbleSortWindow->resize(1300, 800);

    bubbleSortWindow->addChart(createChart(bubbleBest, bubbleBestTheoretical, "Bubble Sort", "Mejor Caso"));
    bubbleSortWindow->addChart(createChart(bubbleWorst, bubbleWorstTheoretical, "Bubble Sort", "Peor Caso"));
    bubbleSortWindow->addChart(createChart(bubbleAverage, bubbleAverageTheoretical, "Bubble Sort", "Caso Promedio"));

    bubbleSortWindow->show();

    //Selection Sort
    QLineSeries *selectionBest = new QLineSeries();
    QLineSeries *selectionWorst = new QLineSeries();
    QLineSeries *selectionAverage = new QLineSeries();
    QLineSeries *selectionBestTheoretical = new QLineSeries();
    QLineSeries *selectionWorstTheoretical = new QLineSeries();
    QLineSeries *selectionAverageTheoretical = new QLineSeries();

    selectionBest->setColor(Qt::green);
    selectionWorst->setColor(Qt::red);
    selectionAverage->setColor(Qt::blue);
    selectionBestTheoretical->setColor(QColorConstants::Svg::orange);
    selectionWorstTheoretical->setColor(QColorConstants::Svg::orange);
    selectionAverageTheoretical->setColor(QColorConstants::Svg::orange);

    for (int size : sizes) {
        selectionBest->append(size, testSelectionSort(size));
        selectionWorst->append(size, testSelectionSortWorst(size));
        selectionAverage->append(size, testSelectionSortAverage(size));

        selectionBestTheoretical->append(size, getSelectionSortTheoretical(size, "Mejor Caso"));
        selectionWorstTheoretical->append(size, getSelectionSortTheoretical(size, "Peor Caso"));
        selectionAverageTheoretical->append(size, getSelectionSortTheoretical(size, "Caso Promedio"));
    }

    ChartWindow *selectionSortWindow = new ChartWindow();
    selectionSortWindow->setWindowTitle("Selection Sort");
    selectionSortWindow->resize(1300, 800);

    selectionSortWindow->addChart(createChart(selectionBest, selectionBestTheoretical, "Selection Sort", "Mejor Caso"));
    selectionSortWindow->addChart(createChart(selectionWorst, selectionWorstTheoretical, "Selection Sort", "Peor Caso"));
    selectionSortWindow->addChart(createChart(selectionAverage, selectionAverageTheoretical, "Selection Sort", "Caso Promedio"));

    selectionSortWindow->show();

    //Merge Sort
    QLineSeries *mergeBest = new QLineSeries();
    QLineSeries *mergeWorst = new QLineSeries();
    QLineSeries *mergeAverage = new QLineSeries();
    QLineSeries *mergeBestTheoretical = new QLineSeries();
    QLineSeries *mergeWorstTheoretical = new QLineSeries();
    QLineSeries *mergeAverageTheoretical = new QLineSeries();

    mergeBest->setColor(Qt::green);
    mergeWorst->setColor(Qt::red);
    mergeAverage->setColor(Qt::blue);
    mergeBestTheoretical->setColor(QColorConstants::Svg::orange);
    mergeWorstTheoretical->setColor(QColorConstants::Svg::orange);
    mergeAverageTheoretical->setColor(QColorConstants::Svg::orange);

    for (int size : sizes) {
        mergeBest->append(size, testMergeSort(size));
        mergeWorst->append(size, testMergeSortWorst(size));
        mergeAverage->append(size, testMergeSortAverage(size));

        mergeBestTheoretical->append(size, getMergeSortTheoretical(size, "Mejor Caso"));
        mergeWorstTheoretical->append(size, getMergeSortTheoretical(size, "Peor Caso"));
        mergeAverageTheoretical->append(size, getMergeSortTheoretical(size, "Caso Promedio"));
    }

    ChartWindow *mergeSortWindow = new ChartWindow();
    mergeSortWindow->setWindowTitle("Merge Sort");
    mergeSortWindow->resize(1300, 800);

    mergeSortWindow->addChart(createChart(mergeBest, mergeBestTheoretical, "Merge Sort", "Mejor Caso"));
    mergeSortWindow->addChart(createChart(mergeWorst, mergeWorstTheoretical, "Merge Sort", "Peor Caso"));
    mergeSortWindow->addChart(createChart(mergeAverage, mergeAverageTheoretical, "Merge Sort", "Caso Promedio"));

    mergeSortWindow->show();

    //Linked List
    QLineSeries *linkedListBest = new QLineSeries();
    QLineSeries *linkedListWorst = new QLineSeries();
    QLineSeries *linkedListAverage = new QLineSeries();
    QLineSeries *linkedListBestTheoretical = new QLineSeries();
    QLineSeries *linkedListWorstTheoretical = new QLineSeries();
    QLineSeries *linkedListAverageTheoretical = new QLineSeries();

    linkedListBest->setColor(Qt::green);
    linkedListWorst->setColor(Qt::red);
    linkedListAverage->setColor(Qt::blue);
    linkedListBestTheoretical->setColor(QColorConstants::Svg::orange);
    linkedListWorstTheoretical->setColor(QColorConstants::Svg::orange);
    linkedListAverageTheoretical->setColor(QColorConstants::Svg::orange);

    for (int size : sizes) {
        linkedListBest->append(size, testLinkedListBest(size));
        linkedListWorst->append(size, testLinkedListWorst(size));
        linkedListAverage->append(size, testLinkedListAverage(size));

        linkedListBestTheoretical->append(size, getLinkedListTheoretical(size, "Mejor Caso"));
        linkedListWorstTheoretical->append(size, getLinkedListTheoretical(size, "Peor Caso"));
        linkedListAverageTheoretical->append(size, getLinkedListTheoretical(size, "Caso Promedio"));
    }

    ChartWindow *linkedListWindow = new ChartWindow();
    linkedListWindow->setWindowTitle("Linked List");
    linkedListWindow->resize(1300, 800);

    linkedListWindow->addChart(createChart(linkedListBest, linkedListBestTheoretical, "Linked List", "Mejor Caso"));
    linkedListWindow->addChart(createChart(linkedListWorst, linkedListWorstTheoretical, "Linked List", "Peor Caso"));
    linkedListWindow->addChart(createChart(linkedListAverage, linkedListAverageTheoretical, "Linked List", "Caso Promedio"));

    linkedListWindow->show();

    //Binary Tree
    QLineSeries *binaryTreeBest = new QLineSeries();
    QLineSeries *binaryTreeWorst = new QLineSeries();
    QLineSeries *binaryTreeAverage = new QLineSeries();
    QLineSeries *binaryTreeBestTheoretical = new QLineSeries();
    QLineSeries *binaryTreeWorstTheoretical = new QLineSeries();
    QLineSeries *binaryTreeAverageTheoretical = new QLineSeries();

    binaryTreeBest->setColor(Qt::green);
    binaryTreeWorst->setColor(Qt::red);
    binaryTreeAverage->setColor(Qt::blue);
    binaryTreeBestTheoretical->setColor(QColorConstants::Svg::orange);
    binaryTreeWorstTheoretical->setColor(QColorConstants::Svg::orange);
    binaryTreeAverageTheoretical->setColor(QColorConstants::Svg::orange);

    for (int size : sizes) {
        binaryTreeBest->append(size, testBinaryTreeBest(size));
        binaryTreeWorst->append(size, testBinaryTreeWorst(size));
        binaryTreeAverage->append(size, testBinaryTreeAverage(size));

        binaryTreeBestTheoretical->append(size, getBinaryTreeTheoretical(size, "Mejor Caso"));
        binaryTreeWorstTheoretical->append(size, getBinaryTreeTheoretical(size, "Peor Caso"));
        binaryTreeAverageTheoretical->append(size, getBinaryTreeTheoretical(size, "Caso Promedio"));
    }

    ChartWindow *binaryTreeWindow = new ChartWindow();
    binaryTreeWindow->setWindowTitle("Binary Tree");
    binaryTreeWindow->resize(1300, 800);

    binaryTreeWindow->addChart(createChart(binaryTreeBest, binaryTreeBestTheoretical, "Binary Tree", "Mejor Caso"));
    binaryTreeWindow->addChart(createChart(binaryTreeWorst, binaryTreeWorstTheoretical, "Binary Tree", "Peor Caso"));
    binaryTreeWindow->addChart(createChart(binaryTreeAverage, binaryTreeAverageTheoretical, "Binary Tree", "Caso Promedio"));

    binaryTreeWindow->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
