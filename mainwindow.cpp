#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cstdlib>
#include <ctime> // why i have used this is cause i want rand() function which will genrate randome numbers and time () to seed randomness.
#include <QTime>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>  // for file dialogs this allows Qt to open a native OS Save As dialog.


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    // The Following space is just for giving style to the tables and buttons.


    // --- Buttons Styling ---
    ui->myButton->setStyleSheet(
        "QPushButton { "
        "background-color: #1976D2;"   // deep blue (Start/Stop)
        "color: white; "
        "font-weight: bold; "
        "border-radius: 4px; "
        "padding: 6px 18px; "
        "} "
        "QPushButton:pressed { background-color: #1565C0; }" // slightly darker blue
    );

    ui->pauseButton->setStyleSheet(
        "QPushButton { "
        "background-color: #607D8B;"   // Cool gray / blue-gray (Pause/Resume)
        "color: white; "
        "font-weight: bold; "
        "border-radius: 4px; "
        "padding: 6px 18px; "
        "} "
        "QPushButton:pressed { background-color: #455A64; }"  // darker gray on press
    );

    // --- Status Label Styling ---
    ui->statusLabel->setStyleSheet(
        "color: #D32F2F; "        // strong but not harsh red
        "font-weight: bold; "
        "font-size: 14px;"
    );










    ui->statusLabel->setStyleSheet("color: red; font-weight: bold;");


    isOn = false;

    isPaused = false;  // initially not paused


    timer = new QTimer(this); // here (this) is main window and Qt auto-detects child objects and prevents memory leaks.
    counter =0;

    srand(time(0));


    connect(timer, SIGNAL(timeout()),
            this, SLOT(onTimerTimeout()));

    ui->myButton->setText("Start");
    ui->statusLabel->setText("Status: STOPPED");


    connect(ui->myButton, SIGNAL(clicked()),
            this, SLOT(onButtonClicked()));

    connect(ui->pauseButton, &QPushButton::clicked, this, [=]() {
        isPaused = !isPaused;  // toggle pause
        if (isPaused)
            ui->pauseButton->setText("Resume");
        else
            ui->pauseButton->setText("Pause");
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::onButtonClicked()
{
    if (!isOn)
        {
            timer->start(1000);   // 1 second
            isOn = true;

            ui->myButton->setText("Stop");
            ui->statusLabel->setText("RUNNING");
            ui->statusLabel->setStyleSheet("color: green; font-weight: bold;");
            // ---- OPEN CSV FILE ----
            logFile.setFileName("can_log.csv"); //here set file creates file name
                if (logFile.open(QIODevice::WriteOnly | QIODevice::Text)) // writeOnly means Overwrite old File
                    {
                        QTextStream out(&logFile);
                        out << "CAN ID,Data,Time\n"; // CSV header
             }

        }
        else
        {
            timer->stop();
            isOn = false;

            ui->myButton->setText("Start");
            ui->statusLabel->setText("STOPPED");
            ui->statusLabel->setStyleSheet("color: red; font-weight: bold;");

            ui->canTable->setRowCount(0); // clear table

       }
}

void MainWindow::onTimerTimeout()
{
    if (isPaused)
        return; // skip generating new CAN frames while paused

    //This will generate CAN like data just for example
    int canId = rand() % 2048;   // 11-bit CAN ID
        int data  = rand() % 256;    // 1 byte data
        QString time = QTime::currentTime().toString("hh:mm:ss");

        int row = ui->canTable->rowCount();
        ui->canTable->insertRow(row);

        ui->canTable->setItem(row, 0,
            new QTableWidgetItem(QString::number(canId)));

        ui->canTable->setItem(row, 1,
            new QTableWidgetItem(QString::number(data)));

        ui->canTable->setItem(row, 2,
            new QTableWidgetItem(time));

        /* Highlight errors
         *  Red = critical error,
         *  Orange = warning
         *

*/

        if (canId >= 1500) // Critical error
        {
            for (int col = 0; col < 3; col++)
                ui->canTable->item(row, col)->setBackground(Qt::red);
        }
        else if (canId >= 1000) // Warning
        {
            for (int col = 0; col < 3; col++)
                ui->canTable->item(row, col)->setBackground(QColor(255, 165, 0)); // Orange
        }
        else // Normal
        {
            for (int col = 0; col < 3; col++)
                ui->canTable->item(row, col)->setBackground(QColor(200, 255, 200)); // Light green
        }


        if (ui->canTable->rowCount() > MAX_ROWS) //limits the table size
           {
               ui->canTable->removeRow(0); // remove oldest CAN Frame and keeps newest data visible like a exact CAN tool
           }

        if (logFile.isOpen())
        {
            QTextStream out(&logFile);
            out << canId << ","
                << data << ","
                << time << "\n";
        }
        else
        {
            timer->stop();
            isOn = false;

            ui->myButton->setText("Start");
            ui->statusLabel->setText("STOPPED");
            ui->statusLabel->setStyleSheet("color: red; font-weight: bold;");

            ui->canTable->setRowCount(0);

            // ---- CLOSE CSV FILE ----
            if (logFile.isOpen())
                logFile.close();
        }


        ui->canTable->scrollToBottom();
}

