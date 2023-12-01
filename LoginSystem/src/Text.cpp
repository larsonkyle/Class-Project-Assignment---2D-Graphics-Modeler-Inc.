#include "Text.h"

void Text::set_text(const QRect& tO, const QString t, const QColor c, const Qt::AlignmentFlag a,
                    const int pS, const QString f, const QFont::Style s, const QFont::Weight w)
{
    // Set the rectangle for the text
    rect = tO;
    text = t;
    color  = c;
    align = a;
    pointSize = pS;
    family = f;
    style = s;
    weight = w;

    font.setFamily(family);
    font.setStyle(style);
    font.setPointSize(pointSize);
    font.setWeight(weight);
}

void Text::draw(const int translate_x, const int translate_y)
{
    QPainter& painter = get_qpainter();
    
    painter.setFont(font);
    painter.setPen(color);
    
    painter.translate(translate_x, translate_y);
    painter.drawText(rect, align, text);
}

