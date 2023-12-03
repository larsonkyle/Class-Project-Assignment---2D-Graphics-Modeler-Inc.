#include "Ellipse.h"
// Ellipse.cpp

bool Ellipse::isCircle() const
{
    // Check if the ellipse is a circle by comparing its width and height
    return (ellipse.width() == ellipse.height());
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
