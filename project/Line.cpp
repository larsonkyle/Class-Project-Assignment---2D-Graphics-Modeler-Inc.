#include "Line.h"
// Line.cpp
void Line::set_point(const QPoint& new_point_begin, const QPoint& new_point_end)
{
    // Set the points for the line
    point_begin = new_point_begin;
    point_end = new_point_end;
}

void Line::move(int x, int y, int vertex) {
    point_begin += QPoint(x, y);
    point_end += QPoint(x, y);
}

void Line::draw(QPainter *painter) {
    if (!painter) return; // Safety check

    painter->setPen(get_pen());
    painter->drawLine(point_begin, point_end);
}

double Line::distanceFromLineToPoint(const QPoint &a, const QPoint &b, const QPoint &p) {
    // Calculate the perpendicular distance from point p to the line segment defined by points a and b
    double lineLength = std::hypot(b.x() - a.x(), b.y() - a.y());
    if (lineLength == 0.0) return (p - a).manhattanLength(); // Line is a point

    // Consider the line extending the segment, parameterized as a + t (b - a).
    // We find projection of point p onto the line.
    // It falls where t = [(p-a) . (b-a)] / |b-a|^2
    double t = QPointF(p - a).dotProduct(p - a, b - a) / (lineLength * lineLength);
    if (t < 0.0) return (p - a).manhattanLength();       // Beyond the 'a' end of the segment
    else if (t > 1.0) return (p - b).manhattanLength();  // Beyond the 'b' end of the segment

    QPointF projection = a + t * (b - a);  // Projection falls on the segment
    return (p - projection).manhattanLength();
}
