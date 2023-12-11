#include "Rectangle.h"
// Rectangle.cpp

bool Rectangle::isSquare() const
{
    return (rect.width() == rect.height());
}

const vector<QPoint>& Rectangle::getPoints() const{
    return points;
}

void Rectangle::set_rect(const QRect& rect)
{
    // Set the rectangle's position and size
    points.resize(2);
    points[0] = rect.topLeft();
    points[1] = rect.bottomRight();
}

void Rectangle::draw(QPainter* painter) {
    if (!painter) return;

    // Set pen and brush styles for the rectangle
    painter->setPen(get_pen());
    painter->setBrush(get_brush());

    // Draw the rectangle using the points
    painter->drawRect(rect);
}

void Rectangle::move(int x, int y, int vertex)
{

    QPoint temp(x , y);
    location = temp;

}
void Rectangle::setLocation(int x, int y)
{
    QPoint temp(x , y);
    location = temp;
}

void Rectangle::setDimensions(double w, double h)
{
    width = w;
    height = h;
}

double Rectangle::getWidth()
{
    return width;
}

double Rectangle::getHeight()
{
    return height;
}

QPoint& Rectangle::getLocation()
{
    return location;
}
