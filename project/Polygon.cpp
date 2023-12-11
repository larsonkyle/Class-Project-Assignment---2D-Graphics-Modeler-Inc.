#include "Polygon.h"

void Polygon::set_point(QPoint &point){
    points.push_back(point);
}

const vector<QPoint>& Polygon::getPoints() const{
    return points;
}

void Polygon::draw(QPainter* painter) {
    if (!painter) return;

    painter->setPen(get_pen());
    painter->setBrush(get_brush());

    painter->drawPolygon(points.begin(), points.size());
}

void Polygon::move(int x, int y, int vertex)
{
    if (vertex > 0 && vertex <= points.size()) {
        points[vertex - 1] = QPoint(x, y);
    }
}

void Polygon::setNumVertices(int numVertices)
{
    this->numVertices = numVertices;
}

int Polygon::getNumVertices() const
{
    return numVertices;
}

