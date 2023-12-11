#ifndef POLYGON_H_
#define POLYGON_H_

#include "Shape.h"
#include <QObject>
#include <QPaintDevice>
#include <QPainter>

class Polygon : public Shape{
public:
    Polygon(QPaintDevice * device, int id = -1) : Shape{device, id, ShapeType::Polygon} {}
    Polygon() : Shape{nullptr, -1, ShapeType::Polygon} {}

    ~Polygon() override {}

    void set_point(QPoint& point);
    const vector<QPoint>& getPoints() const;

    void move(int x, int y, int vertex) override;
    void draw(QPainter *painter) override;
    void setNumVertices(int numVertices);
    int getNumVertices() const;

private:
    vector<QPoint> points;
    int numVertices;
};

#endif

