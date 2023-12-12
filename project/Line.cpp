#include "Line.h"
// Line.cpp
void Line::set_point(const QPoint& new_point_begin, const QPoint& new_point_end)
{
    // Set the points for the line
    point_begin = new_point_begin;
    point_end = new_point_end;
}

void Line::draw(QPaintDevice* device)
{
    QPainter& painter = get_qpainter();
    painter.begin(device);

    painter.setPen(get_pen());
    painter.setBrush(get_brush());

    painter.drawLine(point_begin, point_end);

    painter.end();
}

void Line::move(int t_x, int t_y) {
    // first point = new point and all other points or adjusted accoridngly to keep the shape structure the same
    QPoint new_point = QPoint(t_x, t_y);
    point_end += new_point - point_begin;
    point_begin = new_point;
}
