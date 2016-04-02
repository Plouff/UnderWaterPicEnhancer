#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "histogramcalculator.h"
#include "splitterdecoration.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    histCalc(&currentPicMat)
{
    ui->setupUi(this);

    picPathStr = "D:/temp/P1070216.JPG";
    currentPicMat = cv::imread(picPathStr.toStdString());
    histCalc.configure();
    histCalc.computeHist();
    ui->glView->setPixmapWithPath(picPathStr);
    ui->hists->setHist(&histCalc);

    helper::decorateSplitter(ui->splitter, 1);
}

MainWindow::~MainWindow()
{
    delete ui;
}
