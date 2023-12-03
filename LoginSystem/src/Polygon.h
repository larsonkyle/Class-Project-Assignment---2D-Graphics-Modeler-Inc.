#ifndef POLYGON_H_
#define POLYGON_H_

#include "Shape.h"

class Polygon : public Shape{
	public:
        Polygon(int id = -1) : Shape{id, ShapeType::Polygon} {}
        //~Polygon() { }

		void set_point(const QPoint& point);
        vector<QPoint> getPoints() override {return points;}

        void draw(QPaintDevice* device) override;

	private:
		vector<QPoint> points;

};

#endif
