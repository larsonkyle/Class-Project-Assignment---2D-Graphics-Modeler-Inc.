#include "contactus.h"
#include "ui_contactus.h"

ContactUs::ContactUs(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::ContactUs) {
    ui->setupUi(this);
    ui->NameInput->setPlaceholderText("Enter Your Full Name: ");
    ui->EmailInput->setPlaceholderText("Enter Your Email Address: ");
    ui->MessageInput->setPlaceholderText("Enter Message:");
}

ContactUs::~ContactUs() {
    delete ui;
}

void ContactUs::on_submit_clicked() {
    QMessageBox::information(this, "Contact", "Submitted successfully!");
}
