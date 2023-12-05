#include "Polyline.h"

void Polyline::set_point(const QPoint& point){
    points.push_back(point);
}

void Polyline::draw(QPaintDevice* device){
    QPainter& painter = get_qpainter();
    painter.begin(device);

    painter.setPen(get_pen());
    painter.setBrush(get_brush());

    painter.drawPolyline(points.begin(), points.size());
}

void Polyline::move(int t_x, int t_y) {
    QPoint new_point = QPoint(t_x, t_y);

    for (int i = 1; i < points.size(); i++) {
        points[i] += new_point - points[0];
    }

    points[0] = new_point;
}
