#include "Polygon.h"

void Polygon::set_point(const QPoint& point){
    points.push_back(point);
}

void Polygon::draw(QPaintDevice* device){
    QPainter& painter = get_qpainter();
    painter.begin(device);

    painter.setPen(get_pen());
    painter.setBrush(get_brush());

    painter.drawPolygon(points.begin(), points.size());

    painter.end();
}

void Polygon::move(int t_x, int t_y) {
    QPoint new_point = QPoint(t_x, t_y);

    for (int i = 1; i < points.size(); i++) {
        points[i] += new_point - points[0];
    }

    points[0] = new_point;
}

double Polygon::getPerimeter() {
    double perimeter = 0.0;

    for (size_t i = 0; i < points.size() - 1; ++i) {
        int x = points[i + 1].x() - points[i].x();
        int y = points[i + 1].y() - points[i].y();
        perimeter += std::sqrt(x * x + y * y);
    }

    // closing the loop - subtract first point by last point
    int x = points[0].x() - points[points.size() - 1].x();
    int y = points[0].y() - points[points.size() - 1].y();
    perimeter += std::sqrt(x * x + y * y);

    return perimeter;
}

double Polygon::getArea() {     // shoelace theorem
    double area = 0.0;

    for (size_t i = 0; i < points.size() - 1; ++i) {
        area += (points[i].x() * points[i + 1].y() - points[i + 1].x() * points[i].y());
    }

    // closing the loop - instance between first and last point
    area += ((points[points.size() - 1].x() * points[0]).y()) - (points[points.size() - 1].x() * points[0].y());

    return std::abs(area) / 2.0;
}
