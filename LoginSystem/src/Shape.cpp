#include "Shape.h"
Shape::Shape(QPaintDevice* device, int setId, ShapeType sh)
: qpainter(device){

    id = setId;
    shape = sh;
    this->default_style();
}



/*****GETTERS*****/
int Shape::getId() const{
   return  id;
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

void Shape::set_pen(const Qt::GlobalColor pc, const int width, const Qt::PenStyle ps, const Qt::PenCapStyle pcs, const Qt::PenJoinStyle pjs){
    pen.setColor(pc);
    pen.setWidth(width);
    pen.setStyle(ps);
    pen.setCapStyle(pcs);
    pen.setJoinStyle(pjs);
}

void Shape::set_pen(const Qt::GlobalColor pc){
    pen.setColor(pc);
}

void Shape::set_brush(const Qt::GlobalColor bc, const Qt::BrushStyle bs){
    brush.setColor(bc);
    brush.setStyle(bs);
}

void Shape::set_id(const int setId){
    id = setId;
}
/******set default style*****/
void Shape::default_style(){
    pen = Qt::SolidLine;
    brush = Qt::NoBrush;
}

bool Shape::operator==(const Shape& right){
    return this->id == right.id;
}

bool Shape::operator<(const Shape& right){
    return this->id < right.id;
}
