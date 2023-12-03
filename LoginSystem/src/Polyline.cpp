#include "Polyline.h"

void Polyline::set_point(const QPoint& point){
    points.push_back(point);
}

void Polyline::draw(const int translate_x, const int translate_y){
    QPainter& painter = get_qpainter();

    painter.setPen(get_pen());
    painter.setBrush(get_brush());

    painter.translate(translate_x, translate_y);

    painter.drawPolyline(points.begin(), points.size());
}
