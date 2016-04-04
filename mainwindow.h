#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QAction>
#include <QFileDialog>
#include <QMenu>

#include "picturedata.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void open();
    void save();
    void exit();

private:
    void updatePicInUse();
    void createActions();
    void createMenus();

    Ui::MainWindow *ui;
    QMenu *fileMenu;
    //QMenu *editMenu;

    QAction *openAct;
    QAction *saveAct;
    QAction *exitAct;

protected:
    PictureData * pic;
};

#endif // MAINWINDOW_H
