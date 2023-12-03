#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->userTest->setPlaceholderText("Enter review here: ");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_submit_clicked()
{
    QString userReview = ui->userTest->toPlainText();

    // Optionally, update the QLabel with the user's review
    ui->userTest_Display->setText(userReview + " -You " );

    // Clear the userTest text edit after submission
    ui->userTest->clear();
}

void MainWindow::updateReview()
{
    // Get the text from the QTextEdit and update the QLabel
    ui->userTest_Display->setText(ui->userTest->toPlainText()+" -You " );
}
