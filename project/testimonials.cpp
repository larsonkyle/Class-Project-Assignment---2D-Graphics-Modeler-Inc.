#include "testimonials.h"
#include "ui_testimonials.h"

Testimonials::Testimonials(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::Testimonials) {
    ui->setupUi(this);
    ui->userTest->setPlaceholderText("Enter review here:");
}

Testimonials::~Testimonials() {
    delete ui;
}

void Testimonials::on_submit_clicked() {
    QString userReview = ui->userTest->toPlainText();
    ui->userTest_Display->setText(userReview + " - You");
    ui->userTest->clear();
}
