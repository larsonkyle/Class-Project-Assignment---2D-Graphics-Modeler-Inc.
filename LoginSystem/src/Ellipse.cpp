#include "Ellipse.h"
// Ellipse.cpp

bool Ellipse::isCircle() const
{
    // Check if the ellipse is a circle by comparing its width and height
    return (ellipse.width() == ellipse.height());
}

void Ellipse::draw(const int translate_x, const int translate_y)
{
    QPainter& painter = get_qpainter();
    
    // Set pen and brush styles for the ellipse
    painter.setPen(get_pen());
    painter.setBrush(get_brush());
    
    painter.translate(translate_x, translate_y);
    painter.drawEllipse(ellipse);
}
