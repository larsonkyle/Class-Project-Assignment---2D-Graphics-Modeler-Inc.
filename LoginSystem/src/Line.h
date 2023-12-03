#ifndef LINE_H_
#define LINE_H_

#include "Shape.h"

class Line : public Shape{
	public:
        Line(int id = -1) : Shape{id, ShapeType::Line} {}
        //~Line() { }

		void set_point(const QPoint& point_begin, const QPoint& point_end);

        QPoint getPointBegin() override {return point_begin;}
        QPoint getPointEnd() override {return point_end;}

        void draw(QPaintDevice* device) override;

	private:
		QPoint point_begin;
		QPoint point_end;
};


#endif
