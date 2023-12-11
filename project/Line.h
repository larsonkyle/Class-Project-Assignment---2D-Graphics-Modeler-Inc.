#ifndef LINE_H_
#define LINE_H_

#include "Shape.h"

class Line : public Shape {
public:
    Line(QPaintDevice * device, int id = -1) : Shape{device, id, ShapeType::Line} {}

    // New default constructor
    Line() : Shape{nullptr, -1, ShapeType::Line} {}

    ~Line() override {}
    static double distanceFromLineToPoint(const QPoint &a, const QPoint &b, const QPoint &p);
    void set_point(const QPoint& point_begin, const QPoint& point_end);

    void move(int x, int y, int vertex) override;
    void draw(QPainter *painter) override;
private:
    QPoint point_begin;
    QPoint point_end;
};

#endif // LINE_H_
