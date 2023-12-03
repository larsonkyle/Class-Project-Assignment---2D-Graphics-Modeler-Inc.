#include "Polyline.h"

void Polyline::set_point(const QPoint& point){
    points.push_back(point);
}

void Polyline::draw(QPaintDevice* device){
    QPainter& painter = get_qpainter();
    painter.begin(device);

    painter.setPen(get_pen());
    painter.setBrush(get_brush());

    painter.drawPolyline(points.data(), points.size());
    painter.end();
}
