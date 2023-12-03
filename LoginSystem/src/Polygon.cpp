#include "Polygon.h"

void Polygon::set_point(const QPoint& point){
    points.push_back(point);
}

void Polygon::draw(const int translate_x, const int translate_y){
    QPainter& painter = get_qpainter();

    painter.setPen(get_pen());
    painter.setBrush(get_brush());

    painter.translate(translate_x, translate_y);

    painter.drawPolygon(points.begin(), points.size());
}
