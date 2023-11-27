#include "Polyline.h"

//Polyline::Polyline(QPaintDevice* device = nullptr, int id = -1) : Shape{device, id, ShapeType::Polyline} {}

void Polyline::set_point(const QPoint& point){
    points.push_back(point);
}

const vector<QPoint>& Polyline::getPoints() const{
    return points;
}

void Polyline::draw(const int translate_x, const int translate_y){
    QPainter& painter = get_qpainter();

    painter.setPen(get_pen());
    painter.setBrush(get_brush());

    painter.translate(translate_x, translate_y);

    painter.drawPolyline(points.begin(), points.size());
}
