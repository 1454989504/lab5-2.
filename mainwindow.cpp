#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDir>
#include <QFileDialog>
#include <QDebug>
#include <QHBoxLayout>
#include <QToolButton>
#include <QMenu>
#include <QAction>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // Setup File tab layout
    ui->tabWidget->setFixedHeight(80);
    ui->FileHLayout->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    ui->FileHLayout->setContentsMargins(0, 0, 0, 0);
    ui->FileHLayout->setSpacing(0);
    ui->FileTab->setLayout(ui->FileHLayout);

    // Setup Draw tab layout
    QHBoxLayout *drawHL1 = new QHBoxLayout;
    drawHL1->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    drawHL1->setContentsMargins(0, 0, 0, 0);
    drawHL1->setSpacing(0);

    // Create Point tool button
    QToolButton *pointTB = new QToolButton;
    pointTB->setToolButtonStyle(Qt::ToolButtonIconOnly);
    pointTB->setFixedSize(QSize(32, 32));
    pointTB->setText("Point");
    pointTB->setArrowType(Qt::NoArrow);
    const QIcon pointIcon = QIcon::fromTheme("Point", QIcon("://icon/icons/Flower.png"));
    pointTB->setIcon(pointIcon);
    connect(pointTB, &QToolButton::clicked, this, &MainWindow::pointTB_clicked);
    drawHL1->addWidget(pointTB);

    ui->DrawTab->setLayout(drawHL1);

    // Create Line tool button
    QToolButton *lineTB = new QToolButton;
    lineTB->setToolButtonStyle(Qt::ToolButtonIconOnly);
    lineTB->setFixedSize(QSize(32, 32));
    lineTB->setText("Line");
    lineTB->setArrowType(Qt::NoArrow);
    const QIcon lineIcon = QIcon::fromTheme("Line", QIcon("://icon/icons/Line.png"));
    lineTB->setIcon(lineIcon);
    connect(lineTB, &QToolButton::clicked, this, &MainWindow::lineTB_clicked);
    drawHL1->addWidget(lineTB);

    // Create Circle tool button
    QToolButton *circleTB = new QToolButton;
    circleTB->setToolButtonStyle(Qt::ToolButtonIconOnly);
    circleTB->setFixedSize(QSize(32, 32));
    circleTB->setText("Circle");
    circleTB->setArrowType(Qt::NoArrow);
    const QIcon circleIcon = QIcon::fromTheme("Circle", QIcon("://icon/icons/Circle.png"));
    circleTB->setIcon(circleIcon);
    connect(circleTB, &QToolButton::clicked, this, &MainWindow::circleTB_clicked);
    drawHL1->addWidget(circleTB);

    ui->DrawTab->setLayout(drawHL1);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::pointTB_clicked() {
    // Set the current drawing type to Point
    curDrawType = DPoint;
}

void MainWindow::lineTB_clicked() {
    // Set the current drawing type to Line
    curDrawType = DLine;
}

void MainWindow::circleTB_clicked() {
    // Set the current drawing type to Circle
    curDrawType = DCircle;
}

void MainWindow::on_actionNew_triggered() {
    // Prompt user to save before creating a new file
    int ret = QMessageBox::warning(this, "Warning", "Do you want to save your changes?",
                                   QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    if (ret == QMessageBox::Save) {
        // Save the file
        on_actionSave_triggered();
        // Clear the main list if saving is successful
        // m_mainList.clear();
    } else if (ret == QMessageBox::Discard) {
        // Clear the main list without saving
        // m_mainList.clear();
    }
}

void MainWindow::on_actionOpen_triggered() {
    // Open a file
    QString curPath = QDir::currentPath();
    QString aFileName = QFileDialog::getOpenFileName(this, "Choose a file", curPath, "CAD Files (*.*)");
    if (!aFileName.isEmpty()) {
        qDebug() << "Read file contents into m_MainList";
    }
}

void MainWindow::on_actionSave_triggered() {
    // Save the file
    QString curPath = QDir::currentPath();
    QString aFileName = QFileDialog::getSaveFileName(this, "Enter a file name", curPath, "CAD Files (*.*)");
    if (!aFileName.isEmpty()) {
        qDebug() << "Write objects from m_MainList to: " << aFileName;
    }
}

void MainWindow::on_actionSaveAs_triggered() {
    // Save the file with a different name
    QString curPath = QDir::currentPath();
    QString aFileName = QFileDialog::getSaveFileName(this, "Enter a file name", curPath, "CAD Files (*.*)");
    if (!aFileName.isEmpty()) {
        qDebug() << "Write objects from m_MainList to: " << aFileName;
    }
}

void MainWindow::on_actionExit_triggered() {
    // Prompt user to save before exiting
    int ret = QMessageBox::warning(this, "Warning", "Do you want to save your changes?",
                                   QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    if (ret == QMessageBox::Save) {
        // Save the file
        on_actionSave_triggered();
        // Close the application if saving is successful
        close();
    } else if (ret == QMessageBox::Discard) {
        // Close the application without saving
        close();
    }
}
