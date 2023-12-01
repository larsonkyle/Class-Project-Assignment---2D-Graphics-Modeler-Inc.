#include "Rectangle.h"
// Rectangle.cpp

bool Rectangle::isSquare() const
{
    return (rect.width() == rect.height());
}

void Rectangle::draw(const int translate_x, const int translate_y)
{
    QPainter& painter = get_qpainter();
    
    // Set pen and brush styles for the rectangle
    painter.setPen(get_pen());
    painter.setBrush(get_brush());
    
    // Draw the rectangle using the points
    rect.translate(translate_x, translate_y); 
    painter.drawRect(rect);
}
