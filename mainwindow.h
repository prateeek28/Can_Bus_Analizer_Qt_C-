#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QTimer>
#include <QMainWindow>
#include <QFile>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    bool isOn;  // isOn remembers the current state.
    QTimer *timer;
    int counter;
    const int MAX_ROWS = 50;
    QFile logFile;

    bool isPaused;  // true = paused, false = running

/*
QFile logFile Why here?
->We need the file accessible from multiple functions &
Local variables won’t work for this.
*/

private slots:
    void onButtonClicked();
    void onTimerTimeout();
};
#endif // MAINWINDOW_H
