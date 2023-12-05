#include "Text.h"

void Text::set_text(const QRect& tO, const QString t, const QColor c, const Qt::AlignmentFlag a,
                    const int pS, const QString f, const QFont::Style s, const QFont::Weight w)
{
    // Set the textBoxangle for the text
    textBox = tO;
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
    
    painter.drawText(textBox, align, text);

    painter.end();
}

void Text::move(int t_x, int t_y) {
    QPoint new_point = QPoint(t_x, t_y);
    textBox.moveTopLeft(new_point);
}

