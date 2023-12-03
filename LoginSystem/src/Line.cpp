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

