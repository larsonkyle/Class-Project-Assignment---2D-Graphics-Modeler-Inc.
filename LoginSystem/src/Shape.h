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

        Shape(int id = -1, ShapeType shape = ShapeType::NoShape);
        virtual ~Shape() {}

		//Deliverable: Must suppress copy operations
        Shape(const Shape&)            = delete;//copy constructor
        Shape& operator=(const Shape&) = delete;//copy assignment

        int get_id() const;
		ShapeType get_shape() const;
		const QPen& get_pen() const;
		const QBrush& get_brush() const;

        void set_id(const int setId);
        void set_shape(const ShapeType sh);
        void set_pen(const GlobalColor pc, const int width, const PenStyle ps, const PenCapStyle pcs, const PenJoinStyle pjs);
        void set_pen(const GlobalColor pc);
        void set_brush(const GlobalColor bc, const BrushStyle bs);

		void default_style();

        virtual void draw(QPaintDevice* device) = 0;
        virtual void move(int translate_x, int translate_y) = 0;
        virtual double getPerimeter() = 0;
        virtual double getArea() = 0;

        virtual QPoint getPointBegin() {return QPoint(0,0);}
        virtual QPoint getPointEnd() {return QPoint(0,0);}
        virtual vector<QPoint> getPoints() {return tempForVirtualFunc;}
        virtual QRect getRect() {return QRect();}

        virtual QFont get_font() {return QFont();}
        virtual QString getTextString() {return QString();}
        virtual QColor getTextColor() {return QColor();}
        virtual AlignmentFlag getAlign() {return AlignCenter;}

        //Used to Sort IDs of shapes
        bool operator==(const Shape& right);
        //Preconditions: a Shape type with a valid ID
        //Postconditions: will return true/false of whether the IDs are equal
        bool operator<(const Shape& right);
        //Preconditions: a Shape type with a valid ID
        //Postconditions: will return true/false of whether left Shape's ID is less than right Shape's ID


	protected:
		QPainter& get_qpainter();

	private:
        QPainter qpainter;

		int id;
		ShapeType shape;
		QPen pen;
		QBrush brush;

        vector<QPoint> tempForVirtualFunc;
};

#endif
