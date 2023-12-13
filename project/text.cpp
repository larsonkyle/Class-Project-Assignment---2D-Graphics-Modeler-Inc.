#include "Text.h"

void Text::set_text(const std::string t, const Qt::AlignmentFlag a)
{
    text = QString(t.c_str());
    align = a;
}

void Text::draw(QPaintDevice* device)
{
    QPainter& painter = get_qpainter();
    painter.begin(device);

    painter.setFont(font);

    painter.setPen(get_pen());

    painter.drawText(textBox, align, text);

    painter.end();
}

void Text::move(int t_x, int t_y) {
    QPoint new_point = QPoint(t_x, t_y);
    textBox.moveTopLeft(new_point);
}
