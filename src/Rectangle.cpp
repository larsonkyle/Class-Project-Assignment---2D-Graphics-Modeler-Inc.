#include "Rectangle.h"
// Rectangle.cpp

bool Rectangle::isSquare() const
{
    // Check if the rectangle is a square
    QRect rect(points[0], points[1]);
    int width = rect.width();
    int height = rect.height();
    
    return width == height;
}

void Rectangle::set_rect(const QRect& rect)
{
    // Set the rectangle's position and size
    points.resize(2);
    points[0] = rect.topLeft();
    points[1] = rect.bottomRight();
}

void Rectangle::draw(const int translate_x, const int translate_y)
{
    QPainter& painter = get_qpainter();
    
    // Set pen and brush styles for the rectangle
    painter.setPen(get_pen());
    painter.setBrush(get_brush());
    
    // Draw the rectangle using the points
    QRect rect(points[0], points[1]);
    rect.translate(translate_x, translate_y); 
    painter.drawRect(rect);
}
