#include "Rectangle.h"
// Rectangle.cpp

bool Rectangle::isSquare() const
{
    return (rect.width() == rect.height());
}

void Rectangle::draw(QPaintDevice* device)
{
    QPainter& painter = get_qpainter();
    painter.begin(device);

    // Set pen and brush styles for the rectangle
    painter.setPen(get_pen());
    painter.setBrush(get_brush());

    // Draw the rectangle using the points
    painter.drawRect(rect);

    painter.end();
}

void Rectangle::move(int t_x, int t_y) {
    QPoint new_point = QPoint(t_x, t_y);
    rect.moveTopLeft(new_point);
}
