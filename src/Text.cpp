#include "Text.h"

void Text::set_rect(const QRect& new_rect)
{
    // Set the rectangle for the text
    rect = new_rect;
}

void Text::draw(const int translate_x, const int translate_y)
{
    QPainter& painter = get_qpainter();
    
    // Set font and text color for the text
    QFont font(family, pointSize, style, weight);
    font.setPointSize(pointSize);
    font.setStyle(style);
    font.setWeight(weight);
    
    painter.setFont(font);
    painter.setPen(color);
    

    QRect translatedRect = rect.translated(translate_x, translate_y);
    painter.drawText(translatedRect, align, text);
}

