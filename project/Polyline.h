#ifndef POLYLINE_H_
#define POLYLINE_H_
#include "Shape.h"

class Polyline : public Shape{
public:
    Polyline(QPaintDevice * device, int id = -1) : Shape{device, id, ShapeType::Polyline} {}
    Polyline() : Shape{nullptr, -1, ShapeType::Polyline} {}

    ~Polyline() override {}

    void set_point(const QPoint& point);
    const vector<QPoint>& getPoints() const; //to read current points
    double distanceFromLineToPoint(const QPoint &a, const QPoint &b, const QPoint &p) const;
    void move(int x, int y, int vertex) override;
    void draw(QPainter *painter) override;
    void setNumberPoints(int numberPoints);
    int getNumberPoints() const;
private:
    vector<QPoint> points;
    int numberPoints;
};

#endif
