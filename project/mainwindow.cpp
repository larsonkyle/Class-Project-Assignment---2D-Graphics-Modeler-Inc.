#include "mainwindow.h"
#include "parser.h"
//#include "serializer.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), renderArea(new RenderArea(this)),
    contactUsForm(new ContactUs(this)), testimonialsWindow(new Testimonials(this)),
    loginwindow(new LoginWindow(this)) {

    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    // Initialize buttons for menu-like options
   // QPushButton *drawShapesButton = new QPushButton(tr("Draw Shapes"), this);
    QPushButton *Loginbutton = new QPushButton(tr("Login"), this);
    QPushButton *contactUsButton = new QPushButton(tr("Contact Us"), this);
    QPushButton *testimonialsButton = new QPushButton(tr("Testimonials"), this);

    //layout->addWidget(drawShapesButton);
    layout->addWidget(Loginbutton);
    layout->addWidget(contactUsButton);
    layout->addWidget(testimonialsButton);

    // Connect button signals to slots
   // connect(drawShapesButton, &QPushButton::clicked, this, &MainWindow::showDrawingArea);
    connect(Loginbutton, &QPushButton::clicked, this, &MainWindow::showLoginWindow);
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

    getShapes(*renderArea);
    //writeShapes(renderArea->getVector());
}

MainWindow::~MainWindow() {
    delete contactUsForm;
    delete testimonialsWindow;
    delete loginwindow;
}

void MainWindow::on_lineButton_clicked() {
    auto line = new Line;
    line->set_point(QPoint(20, 20), QPoint(200, 200));
    renderArea->addShape(std::move(line));
    renderArea->update();
}

void MainWindow::on_ellipseButton_clicked() {
    auto ellipse = new Ellipse;
    ellipse->set_ellipse(QRect(100, 100, 200, 100));
    renderArea->addShape(std::move(ellipse));
    renderArea->update();
}

void MainWindow::on_polygonButton_clicked() {
    auto polygon = new Polygon;
    QVector<QPoint> points = { QPoint(20, 20), QPoint(200, 20), QPoint(200, 200), QPoint(20, 200) };
    for (auto &point : points) {
        polygon->set_point(point);
    }
    //polygon->setNumVertices(points.size());
    renderArea->addShape(std::move(polygon));
    renderArea->update();
}

void MainWindow::on_polylineButton_clicked() {
    auto polyline = new Polyline;
    QVector<QPoint> points = { QPoint(30, 30), QPoint(150, 30), QPoint(300, 150), QPoint(300, 300) };
    for (auto &point : points) {
        polyline->set_point(point);
    }
    //polyline->setNumberPoints(points.size());
    renderArea->addShape(std::move(polyline));
    renderArea->update();
}

void MainWindow::on_rectangleButton_clicked() {
    auto rectangle = new Rectangle;
    rectangle->set_rect(QRect(150, 150, 300, 300));
    renderArea->addShape(std::move(rectangle));
    renderArea->update();
}

void MainWindow::on_textButton_clicked() {
    auto text = new Text;
    text->set_textBox(QRect(30, 30, 600, 150));
    text->set_pen(Qt::blue);
    text->set_font(12, "Arial", QFont::StyleNormal, QFont::Normal);
    text->set_text("Example Text", Qt::AlignCenter);
    renderArea->addShape(std::move(text));
    renderArea->update();
}

void MainWindow::showLoginWindow() {
    loginwindow->show();
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


