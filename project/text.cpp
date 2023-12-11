#include "text.h"

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

const QFont& Text::get_font() const{
    return font;
}

void Text::draw(QPainter* painter) {
    if (!painter) return;

    painter->setFont(font);
    painter->setPen(color);

    painter->drawText(rect, align, text);
}

void Text::move(const int x, const int y, int junk)
{
    QPoint temp(x, y);
    location = temp;
}
void Text::setLocation(int x, int y)
{
    location.setX(x);
    location.setY(y);
}
