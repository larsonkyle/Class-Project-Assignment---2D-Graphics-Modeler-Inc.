#include "Line.h"
// Line.cpp
void Line::set_point(const QPoint& new_point_begin, const QPoint& new_point_end)
{
    // Set the points for the line
    point_begin = new_point_begin;
    point_end = new_point_end;
}

void Line::draw(const int translate_x, const int translate_y)
{
      QPainter& painter = get_qpainter();

      painter.setPen(get_pen());
      painter.setBrush(get_brush());

      painter.translate(translate_x, translate_y);

      painter.drawLine(point_begin, point_end);
}

