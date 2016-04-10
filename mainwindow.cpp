#include <memory>

#include "opencv2/opencv.hpp"

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "histogramcalculator.h"
#include "splitterdecoration.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Init menus and actions
    createActions();
    createMenus();

    // Init histograms
    //picPathStr = "D:/temp/P1070216.JPG";
    pic = new PictureData(this, tr("D:/temp/P1070216.JPG"));
    updatePicInUse();

    // Decorate Splitter
    helper::decorateSplitter(ui->splitter, 1);
}

MainWindow::~MainWindow()
{
    delete ui;
    if (pic)
    {
        delete pic;
    }
}

void MainWindow::open()
{
    // Get path to picture
    QString picPathStr;
    PictureData * oldPic = pic;

    picPathStr = QFileDialog::getOpenFileName(this,
        tr("Open Image"), "D:/temp/",
        tr("Image Files (*.jpg *.jpeg *.tiff *.bmp);;All files (*.*)"));

    pic = new PictureData(this, picPathStr);
    if (oldPic)
    {
        delete oldPic;
    }

    updatePicInUse();
}

void MainWindow::save()
{

}

void MainWindow::exit()
{
    QWidget::close();
}

void MainWindow::updatePicInUse()
{
    // Init histograms
    ui->histsViewer->setHist(&pic->histGraphs);

    // Init OpenGL view
    ui->glViewer->setPixmap(&pic->pixmapInitial);
}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(openAct);
    fileMenu->addAction(saveAct);
    fileMenu->addAction(exitAct);
}

void MainWindow::createActions()
{
    openAct = new QAction(tr("&Open..."), this);
    openAct->setShortcuts(QKeySequence::Open);
    openAct->setStatusTip(tr("Open a picture"));
    connect(openAct, &QAction::triggered, this, &MainWindow::open);

    saveAct = new QAction(tr("&Save"), this);
    saveAct->setShortcuts(QKeySequence::Save);
    saveAct->setStatusTip(tr("Save the document to disk"));
    connect(saveAct, &QAction::triggered, this, &MainWindow::save);

    exitAct = new QAction(tr("E&xit"), this);
    exitAct->setShortcuts(QKeySequence::Quit);
    exitAct->setStatusTip(tr("Exit the application"));
    connect(exitAct, &QAction::triggered, this, &MainWindow::exit);
}
