QT       += core gui
QT += charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    BinaryTree.cpp \
    BubbleSort.cpp \
    LinkedList.cpp \
    MergeSort.cpp \
    SelectionSort.cpp \
    chartwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    test.cpp

HEADERS += \
    ../BubbleSort.h \
    ../MergeSort.h \
    ../SelectionSort.h \
    BinaryTree.h \
    BubbleSort.h \
    LinkedList.h \
    MergeSort.h \
    SelectionSort.h \
    Utils.h \
    chartwindow.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    Tarea2_es_GT.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
