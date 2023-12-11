#include "loginwindow.h"
#include "ui_loginwindow.h"
#include <QMessageBox>

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::LoginWindow) {
    ui->setupUi(this);
}

LoginWindow::~LoginWindow() {
    delete ui;
}

void LoginWindow::on_LoginButton_clicked() {
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    if (username == "admin" && password == "pass") {
        QMessageBox::information(this, "Login", "Login Successful! Signed in as Admin.");
    } else {
        QMessageBox::warning(this, "Login", "Invalid credentials. Please try again.");
    }
}

void LoginWindow::on_pushButton_Guest_Sign_in_clicked() {
    QMessageBox::information(this, "Login", "Signed in as Guest.");
    // Implement guest sign-in logic here if needed
}
