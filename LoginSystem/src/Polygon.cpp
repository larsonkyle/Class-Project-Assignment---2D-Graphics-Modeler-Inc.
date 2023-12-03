#include "Polygon.h"

void Polygon::set_point(const QPoint& point){
    points.push_back(point);
}

void Polygon::draw(QPaintDevice* device){
    QPainter& painter = get_qpainter();
    painter.begin(device);

    painter.setPen(get_pen());
    painter.setBrush(get_brush());

    painter.translate(translate_x, translate_y);

    painter.drawPolygon(points.begin(), points.size());
}
