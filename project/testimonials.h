#ifndef TESTIMONIALS_H
#define TESTIMONIALS_H

#include <QMainWindow>

namespace Ui { class Testimonials; }

class Testimonials : public QMainWindow {
    Q_OBJECT

public:
    explicit Testimonials(QWidget *parent = nullptr);
    ~Testimonials();

private slots:
    void on_submit_clicked();

private:
    Ui::Testimonials *ui;
};

#endif // TESTIMONIALS_H
