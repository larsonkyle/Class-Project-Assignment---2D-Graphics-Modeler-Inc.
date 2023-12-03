#include "Shape.h"

Shape::Shape(int setId, ShapeType sh){

    id = setId;
    shape = sh;
    this->default_style();
}

/*****GETTERS*****/
int Shape::get_id() const{
   return id;
}

Shape::ShapeType Shape::get_shape() const{
    return shape;
}

const QPen& Shape::get_pen() const{
    return pen;
}

const QBrush& Shape::get_brush() const{
    return brush;
}

//protected:
QPainter& Shape::get_qpainter(){
    return qpainter;
}

/*****SETTERS*******/
void Shape::set_shape(const ShapeType sh){
    shape = sh;
}

void Shape::set_pen(const GlobalColor pc, const int width, const PenStyle ps, const PenCapStyle pcs, const PenJoinStyle pjs){
    pen.setColor(QColor(pc));
    pen.setWidth(width);
    pen.setStyle(ps);
    pen.setCapStyle(pcs);
    pen.setJoinStyle(pjs);
}

void Shape::set_pen(const GlobalColor pc){
    pen.setColor(QColor(pc));
}

void Shape::set_brush(const GlobalColor bc, const BrushStyle bs){
    brush.setColor(bc);
    brush.setStyle(bs);
}

void Shape::set_id(const int setId){
    id = setId;
}
/******set default style*****/
void Shape::default_style(){
    pen = SolidLine;
    brush = NoBrush;
}

bool Shape::operator==(const Shape& right){
    return this->id == right.id;
}

bool Shape::operator<(const Shape& right){
    return this->id < right.id;
}
