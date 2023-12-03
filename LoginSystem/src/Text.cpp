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

void Text::draw(QPaintDevice* device)
{
    QPainter& painter = get_qpainter();
    painter.begin(device);
    
    painter.setFont(font);
    painter.setPen(color);
    
    painter.drawText(rect, align, text);

    painter.end();
}

