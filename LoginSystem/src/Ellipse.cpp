#include "Ellipse.h"
// Ellipse.cpp

bool Ellipse::isCircle() const
{
    // Check if the ellipse is a circle by comparing its width and height
    return ellipse.width() == ellipse.height();
}

void Ellipse::draw(QPaintDevice* device)
{
    QPainter& painter = get_qpainter();
    painter.begin(device);
    
    // Set pen and brush styles for the ellipse
    painter.setPen(get_pen());
    painter.setBrush(get_brush());
    
    painter.drawEllipse(ellipse);

    painter.end();
}

void Ellipse::move(int t_x, int t_y) {
    QPoint new_point = QPoint(t_x, t_y);
    ellipse.moveTopLeft(new_point);
}

double Ellipse::getPerimeter() {
    if (isCircle()) {
        return 2 * M_PI * (ellipse.width() / 2.0);
    }

    // very accurate approximation (exact answer would require calculus)
    int a = ellipse.width() / 2;
    int b = ellipse.height() / 2;

    double h = ((a - b) * (a - b)) / ((a + b) * (a + b));
    return M_PI * (a + b) * (1 + ((3 * h) / (10 + std::sqrt(4 - (3 * h)))));
}

double Ellipse::getArea() {
    return ellipse.width() * ellipse.height() * M_PI;
}


