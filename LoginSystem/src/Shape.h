#ifndef SHAPE_H_
#define SHAPE_H_

#include <QPaintDevice>
#include <QPainter>
#include <QObject>
#include <QPen>
#include <QBrush>
#include <QRect>
#include "vector_doubles.h"

using namespace Qt;

using myStd::vector;

class Shape{
	public:
        enum ShapeType {NoShape, Line, Polyline, Polygon, Rectangle, Square, Ellipse, Circle, Text};

        Shape(QPaintDevice* device = nullptr, int setId = -1, ShapeType sh = ShapeType::NoShape); // :;
		//virtual ~Shape() {  }

        //Deliverable: Must suppress copy operations
        Shape(const Shape&)            = delete;//copy constructor
        Shape& operator=(const Shape&) = delete;//copy assignment

        int getId() const;
		ShapeType get_shape() const;
		const QPen& get_pen() const;
		const QBrush& get_brush() const;

        void set_shape(const ShapeType sh);
        void set_pen(const GlobalColor pc, const int width, const PenStyle ps, const PenCapStyle pcs, const PenJoinStyle pjs);
        void set_pen(const GlobalColor pc);
        void set_brush(const GlobalColor bc, const BrushStyle bs);
        void set_id(const int setId);

		void default_style();

        //Used to Sort IDs of shapes
        bool operator==(const Shape& right);
        //Preconditions: a Shape type with a valid ID
        //Postconditions: will return true/false of whether the IDs are equal
        bool operator<(const Shape& right);
        //Preconditions: a Shape type with a valid ID
        //Postconditions: will return true/false of whether left Shape's ID is less than right Shape's ID


		virtual void draw(const int translate_x, const int translate_y) = 0;

	protected:
		QPainter& get_qpainter();

	private:
		QPainter qpainter; //Maybe use Unique Pointer???

		int id;
		ShapeType shape;
		QPen pen;
		QBrush brush;
};

#endif
