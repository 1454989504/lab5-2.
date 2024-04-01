#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "dwgobject.h"


enum DrawType
{
    DNone,
    DLine,
    DCircle,
    DRectangle,
    DPoint
};
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    DrawType curDrawType =DNone;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // 手动添加下面的槽函数
    void pointTB_clicked ();

    void lineTB_clicked();
    void circleTB_clicked();

    void on_actionSave_triggered();

    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionExit_triggered();

    void on_actionSaveAs_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
