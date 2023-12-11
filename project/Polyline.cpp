#include "Polyline.h"

//Polyline::Polyline(QPaintDevice* device = nullptr, int id = -1) : Shape{device, id, ShapeType::Polyline} {}

void Polyline::set_point(const QPoint& point){
    points.push_back(point);
}

const vector<QPoint>& Polyline::getPoints() const{
    return points;
}
void Polyline::draw(QPainter* painter) {
    if (!painter) return;

    painter->setPen(get_pen());
    painter->setBrush(get_brush());

    painter->drawPolyline(points.begin(), points.size());
}


void Polyline::move(int x, int y, int vertex)
{
    QPoint temp(x , y);
    points[vertex - 1] = temp;
}

void Polyline::setNumberPoints(int numberPoints)
{
    numberPoints = numberPoints;
}
int Polyline::getNumberPoints() const
{
    return numberPoints;
}

double Polyline::distanceFromLineToPoint(const QPoint &a, const QPoint &b, const QPoint &p) const {
    // Calculate the distance of point p from line segment (a, b)
    double norm = std::hypot(b.x() - a.x(), b.y() - a.y());
    return std::abs((p.y() - a.y()) * (b.x() - a.x()) - (p.x() - a.x()) * (b.y() - a.y())) / norm;
}
