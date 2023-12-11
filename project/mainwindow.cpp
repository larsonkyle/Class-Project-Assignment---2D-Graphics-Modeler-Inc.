#include "mainwindow.h"
#include <QVBoxLayout>
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

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), renderArea(new RenderArea(this)),
    contactUsForm(new ContactUs(this)), testimonialsWindow(new Testimonials(this)) {

    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    // Initialize buttons for menu-like options
   // QPushButton *drawShapesButton = new QPushButton(tr("Draw Shapes"), this);
    QPushButton *loginButton = new QPushButton(tr("Login"), this);
    QPushButton *contactUsButton = new QPushButton(tr("Contact Us"), this);
    QPushButton *testimonialsButton = new QPushButton(tr("Testimonials"), this);

    //layout->addWidget(drawShapesButton);
    layout->addWidget(loginButton);
    layout->addWidget(contactUsButton);
    layout->addWidget(testimonialsButton);

    // Connect button signals to slots
   // connect(drawShapesButton, &QPushButton::clicked, this, &MainWindow::showDrawingArea);
    connect(loginButton, &QPushButton::clicked, this, &MainWindow::showLoginWindow);
    connect(contactUsButton, &QPushButton::clicked, this, &MainWindow::showContactUs);
    connect(testimonialsButton, &QPushButton::clicked, this, &MainWindow::showTestimonials);
    // Initialize and add shape buttons
    lineButton = new QPushButton("Line", this);
    ellipseButton = new QPushButton("Ellipse", this);
    polygonButton = new QPushButton("Polygon", this);
    polylineButton = new QPushButton("Polyline", this);
    rectangleButton = new QPushButton("Rectangle", this);
    textButton = new QPushButton("Text", this);

    layout->addWidget(renderArea);
    layout->addWidget(lineButton);
    layout->addWidget(ellipseButton);
    layout->addWidget(polygonButton);
    layout->addWidget(polylineButton);
    layout->addWidget(rectangleButton);
    layout->addWidget(textButton);

    // Connect shape buttons
    connect(lineButton, &QPushButton::clicked, this, &MainWindow::on_lineButton_clicked);
    connect(ellipseButton, &QPushButton::clicked, this, &MainWindow::on_ellipseButton_clicked);
    connect(polygonButton, &QPushButton::clicked, this, &MainWindow::on_polygonButton_clicked);
    connect(polylineButton, &QPushButton::clicked, this, &MainWindow::on_polylineButton_clicked);
    connect(rectangleButton, &QPushButton::clicked, this, &MainWindow::on_rectangleButton_clicked);
    connect(textButton, &QPushButton::clicked, this, &MainWindow::on_textButton_clicked);
}

MainWindow::~MainWindow() {
    delete contactUsForm;
    delete testimonialsWindow;
}

void MainWindow::on_lineButton_clicked() {
    auto line = std::make_unique<Line>();
    line->set_point(QPoint(20, 20), QPoint(200, 200));
    renderArea->addShape(std::move(line));
    renderArea->update();
}

void MainWindow::on_ellipseButton_clicked() {
    auto ellipse = std::make_unique<Ellipse>();
    ellipse->set_ellipse(QRect(100, 100, 200, 100));
    renderArea->addShape(std::move(ellipse));
    renderArea->update();
}

void MainWindow::on_polygonButton_clicked() {
    auto polygon = std::make_unique<Polygon>();
    QVector<QPoint> points = { QPoint(20, 20), QPoint(200, 20), QPoint(200, 200), QPoint(20, 200) };
    for (auto &point : points) {
        polygon->set_point(point);
    }
    polygon->setNumVertices(points.size());
    renderArea->addShape(std::move(polygon));
    renderArea->update();
}

void MainWindow::on_polylineButton_clicked() {
    auto polyline = std::make_unique<Polyline>();
    QVector<QPoint> points = { QPoint(20, 20), QPoint(200, 20), QPoint(200, 200) };
    for (auto &point : points) {
        polyline->set_point(point);
    }
    polyline->setNumberPoints(points.size());
    renderArea->addShape(std::move(polyline));
    renderArea->update();
}

void MainWindow::on_rectangleButton_clicked() {
    auto rectangle = std::make_unique<Rectangle>();
    rectangle->set_rect(QRect(150, 150, 300, 300));
    renderArea->addShape(std::move(rectangle));
    renderArea->update();
}

void MainWindow::on_textButton_clicked() {
    auto text = std::make_unique<Text>();
    text->set_text(QRect(30, 30, 600, 150), "Example Text", QColor(Qt::black), Qt::AlignCenter, 12, "Arial", QFont::StyleNormal, QFont::Normal);
    renderArea->addShape(std::move(text));
    renderArea->update();
}

void MainWindow::showLoginWindow() {
    LoginWindow loginWin;
    loginWin.show();
}

void MainWindow::showContactUs() {
    contactUsForm->show();
}

void MainWindow::showTestimonials() {
    testimonialsWindow->show();
}

/*void MainWindow::showDrawingArea() {
    // Ensure that the drawing area and shape buttons are visible
    renderArea->setVisible(true);
    lineButton->setVisible(true);
    ellipseButton->setVisible(true);
    polygonButton->setVisible(true);
    polylineButton->setVisible(true);
    rectangleButton->setVisible(true);
    textButton->setVisible(true);

    centralWidget()->layout()->update();
}
*/


