#include "picturedata.h"

PictureData::PictureData(
        QObject *parent, QString p_picPathStr)
    : QObject(parent), picPathStr(p_picPathStr),
      histCalc(&matInitial, &histMatsRaw, &histMatsNormalized,
               &histGraphs, this)
{
    matInitial = cv::imread(picPathStr.toStdString());

    // Configure histogram calculator
    histCalc.configure();
    histCalc.computeHist();
}

/**
 * @brief Getter for #picPathStr
 * @return The path to the picture on disk
 */
QString PictureData::getPicPathStr() const
{
    return picPathStr;
}
