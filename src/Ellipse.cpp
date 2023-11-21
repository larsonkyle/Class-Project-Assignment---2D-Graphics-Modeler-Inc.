#include "Ellipse.h"
// Ellipse.cpp

#include "Ellipse.h"

bool Ellipse::isCircle() const
{
    // Check if the ellipse is a circle by comparing its width and height
    return rect.width() == rect.height();
}

void Ellipse::set_rect(const QRect& new_rect)
{
    // Set the rectangle for the ellipse
    rect = new_rect;
}

void Ellipse::draw(const int translate_x, const int translate_y)
{
    QPainter& painter = get_qpainter();
    
    // Set pen and brush styles for the ellipse
    painter.setPen(get_pen());
    painter.setBrush(get_brush());
    
    // Draw the ellipse using the rectangle
    QRect translatedRect = rect.translated(translate_x, translate_y);
    painter.drawEllipse(translatedRect);
}
