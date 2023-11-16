#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->lineEdit_username->setPlaceholderText("Enter Username");
    ui->lineEdit_password->setPlaceholderText("Enter Password");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Loginbutton_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    if(username == "admin" && password == "pass")
    {
        QMessageBox::information(this, "Login", "Login Successful!");
    }
    else
    {
        QMessageBox::warning(this, "Login", "Username or password is incorrect.\nPlease try again.");
    }
}

