#include "mainwindow.h"
#include <QApplication>


//--------------------------------------
// TEMP
#include "debugmacros.h"
#include "glpicviewerwithcommands.h"
#include "histowitheditboxes.h"
#include "histogramcalculator.h"
#include "pichistogrammanager.h"
#include "Shared/openglpicviewer.h"
#include "singlehistogram.h"

#include <QtWidgets>
#include <opencv2/opencv.hpp>

// TEMP
//--------------------------------------

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow w;

    HistogramCalculator * histCalc;
    cv::Mat * mat;
    PicHistogramManager histmgr;

    // Histogram computing
    mat = new cv::Mat();
    *mat = cv::imread("D:/temp/P1070216.JPG");
    histCalc = new HistogramCalculator(mat);
    histCalc->configure();
    histCalc->computeHist();

    // Histogram manager only
    histmgr.setHist(histCalc);
    histmgr.show();


    w.show();

    return app.exec();
}
