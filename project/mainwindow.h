#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "renderArea.h"
#include <QVBoxLayout>
#include "Shape.h"
#include "Line.h"
#include "Ellipse.h"
#include "Polygon.h"
#include "Polyline.h"
#include "Rectangle.h"
#include "loginwindow.h"
#include "text.h"
#include "contactus.h"
#include "testimonials.h"
#include <QMenuBar>
#include <QMenu>

class LoginWindow;
class ContactUs;
class Testimonials;

namespace Ui { class MainWindow; }

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
    Ui::MainWindow *ui;
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
