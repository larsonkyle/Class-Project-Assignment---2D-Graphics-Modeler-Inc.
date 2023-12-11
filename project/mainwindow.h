#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "renderArea.h"

class LoginWindow;
class ContactUs;
class Testimonials;

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_lineButton_clicked();
    void on_ellipseButton_clicked();
    void on_polygonButton_clicked();
    void on_polylineButton_clicked();
    void on_rectangleButton_clicked();
    void on_textButton_clicked();
    void showLoginWindow();
    void showContactUs();
    void showTestimonials();
    //void showDrawingArea();

private:
    RenderArea *renderArea;
    QPushButton *lineButton;
    QPushButton *ellipseButton;
    QPushButton *polygonButton;
    QPushButton *polylineButton;
    QPushButton *rectangleButton;
    QPushButton *textButton;
    ContactUs *contactUsForm;
    Testimonials *testimonialsWindow;
};

#endif // MAINWINDOW_H
