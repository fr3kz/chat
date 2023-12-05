#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSettings>
#include "apiservice.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QSettings settings;
    apiservice *apiService;
    void login(QString username, QString password);
    void signup(QString username, QString password);


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
