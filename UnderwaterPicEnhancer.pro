#-------------------------------------------------
#
# Project created by QtCreator 2016-03-20T15:59:58
#
#-------------------------------------------------

#QT       += core gui
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = UnderwaterPicEnhancer
TEMPLATE = app

CONFIG += c++11

# Add sub projects
include(QtCppCustomWidgets/QtCppCustomWidgets.pri)

##################################################
# OPENCV LIB #####################################
##################################################
INCLUDEPATH += "D:/Developpements/Cpp/ExternalCppLibs/opencv-mingw/release/include"

LIBS += -L"D:/Developpements/Cpp/ExternalCppLibs/opencv-mingw/release/x64/mingw/lib"
#LIBS += -lopencv_core300 -lopencv_highgui300 -lopencv_imgproc300

LIBS += -lopencv_core300 \
#        -lopencv_features2d300 \
#        -lopencv_flann300 \
        -lopencv_highgui300 \
        -lopencv_imgcodecs300 \
        -lopencv_imgproc300 \
#        -lopencv_ml300 \
#        -lopencv_objdetect300 \
#        -lopencv_photo300 \
#        -lopencv_shape300 \
#        -lopencv_stitching300\
#        -lopencv_superres300 \
#        -lopencv_ts300 \
#        -lopencv_video300 \
#        -lopencv_videoio300\
#        -lopencv_videostab300


##################################################
# PROJECT SRC ####################################
##################################################

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    picturedata.cpp

HEADERS  += \
    mainwindow.h \
    picturedata.h

FORMS    += mainwindow.ui

