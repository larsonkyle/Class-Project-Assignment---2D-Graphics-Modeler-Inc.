#include "Ellipse.h"
// Ellipse.cpp

bool Ellipse::isCircle() const
{
    // Check if the ellipse is a circle by comparing its width and height
    return (ellipse.width() == ellipse.height());
}

void Ellipse::move(int x, int y, int vertex)
{
    QPoint temp(x,y);
    location = temp;
}

void Ellipse::draw(QPainter *painter)
{
    // Set pen and brush styles for the ellipse
    painter->setPen(get_pen());
    painter->setBrush(get_brush());

    painter->drawEllipse(ellipse);
}
