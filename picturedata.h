#ifndef PICTUREDATA_H
#define PICTUREDATA_H

#include <QObject>
#include <QString>

#include "opencv2/opencv.hpp"

#include "histogramcalculator.h"
#include "histogramtypes.h"

class PictureData : public QObject
{
    Q_OBJECT
public:
    explicit PictureData(
            QObject *parent = 0, QString p_picPathStr = "");
    QString getPicPathStr() const;

    /// The X Y coords histograms for the display
    helper::histGraphs_s<double> histGraphs;

signals:

public slots:

private:
    /// The path to the picture
    QString picPathStr;
    /// The @c cv::Mat of the initial picture (ie. without modifications)
    cv::Mat matInitial;
    /// The @c cv::Mat for the display of ongoing modifications
    cv::Mat * matWorking;
    /// The histograms as Mat of the initial picture
    helper::histMats_s histMatsRaw;
    /// The normalized histograms as Mat of the initial picture
    helper::histMats_s histMatsNormalized;

    /// The histogram calculator object
    HistogramCalculator histCalc;
};

#endif // PICTUREDATA_H
