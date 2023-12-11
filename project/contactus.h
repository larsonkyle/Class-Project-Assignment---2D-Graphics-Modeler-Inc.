#ifndef CONTACTUS_H
#define CONTACTUS_H
#include <QMessageBox>
#include <QMainWindow>

namespace Ui { class ContactUs; }

class ContactUs : public QMainWindow {
    Q_OBJECT

public:
    explicit ContactUs(QWidget *parent = nullptr);
    ~ContactUs();

private slots:
    void on_submit_clicked();

private:
    Ui::ContactUs *ui;
};

#endif // CONTACTUS_H
