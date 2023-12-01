#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->NameInput->setPlaceholderText("Enter Your Full Name: ");
    ui->EmailInput->setPlaceholderText("Enter Your Email Address: ");
    ui->MessageInput->setPlaceholderText("Enter Message:");

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_submit_clicked()
{
    // QString emailInput = ui->EmailInput->text();
    //QString nameInput = ui->NameInput->text();
    // QString message = ui->MessageInput->text();
    QMessageBox::information(this, "Contact", "Submitted successfully!\n");
}
