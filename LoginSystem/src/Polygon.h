#ifndef POLYGON_H_
#define POLYGON_H_

#include "Shape.h"

class Polygon : public Shape{
	public:
		Polygon(QPaintDevice* device = nullptr, int id = -1) : Shape{device, id, ShapeType::Polygon} {}
        //~Polygon() { }

		void set_point(const QPoint& point);
        vector<QPoint> getPoints() override {return points;}

		void draw(const int translate_x = 0, const int translate_y = 0) override;

	private:
		vector<QPoint> points;

};

#endif
