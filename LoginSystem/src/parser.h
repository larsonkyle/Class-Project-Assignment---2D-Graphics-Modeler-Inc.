#include <iostream>
#include <fstream>
#include <QMetaEnum>

#include "Shape.h"
#include "Line.h"
#include "Polyline.h"
#include "Polygon.h"
#include "Rectangle.h"
#include "Ellipse.h"
#include "Text.h"
#include "vector_doubles.h"
// Look over Basic Drawing Example project on QT

const int FILE_OPEN_ERROR = 0;

Shape::ShapeType shapeStrToInt(const std::string s);
void inputLine(std::ifstream& fin, const std::string shapeID, vector<Shape*> shapeVector);
void inputPolyline(std::ifstream& fin, const std::string shapeID, vector<Shape*> shapeVector);
void inputPolygon(std::ifstream& fin, const std::string shapeID, vector<Shape*> shapeVector);
void inputRectangle(std::ifstream& fin, const std::string shapeID, vector<Shape*> shapeVector);
void inputSquare(std::ifstream& fin, const std::string shapeID, vector<Shape*> shapeVector);
void inputEllipse(std::ifstream& fin, const std::string shapeID, vector<Shape*> shapeVector);
void inputCircle(std::ifstream& fin, const std::string shapeID, vector<Shape*> shapeVector);
void inputText(std::ifstream& fin, const std::string shapeID, vector<Shape*> shapeVector);

void getShapes(vector<Shape*> shapeVector) {
    std::string dummy;
    std::string shapeID;
    std::string shapeType;
    int shapeCounter = 0;

    std::ifstream fin;

    try {
        fin.open("shapes.txt");

        if (!fin) {
            throw (FILE_OPEN_ERROR);
        }
    }

    catch(int) {
        std::cout << "Error - find could not be opened";
    }

    fin >> dummy;
    fin >> shapeID;

    fin >> dummy;
    fin >> shapeType;

    while (!fin.eof()) {
        if (fin) {
            switch(shapeStrToInt(shapeType)) {
                case Shape::ShapeType::Line:
                    inputLine(fin, shapeID, shapeVector);
                    break;
                case Shape::ShapeType::Polyline:
                    inputPolyline(fin, shapeID, shapeVector);
                    break;
                case Shape::ShapeType::Polygon:
                    inputPolygon(fin, shapeID, shapeVector);
                    break;
                case Shape::ShapeType::Rectangle:
                    inputRectangle(fin, shapeID, shapeVector);
                    break;
                case Shape::ShapeType::Square:
                    inputSquare(fin, shapeID, shapeVector);
                    break;
                case Shape::ShapeType::Ellipse:
                    inputEllipse(fin, shapeID, shapeVector);
                    break;
                case Shape::ShapeType::Circle:
                    inputCircle(fin, shapeID, shapeVector);
                    break;
                case Shape::ShapeType::Text:
                    inputText(fin, shapeID, shapeVector);
                    break;
                case Shape::ShapeType::NoShape:
                    break;
            }
        }

        shapeCounter++;

        fin >> dummy;
        fin >> shapeID;

        fin >> dummy;
        fin >> shapeType;
    }

    std::cout << std::endl;
    fin.close();
}

Line::ShapeType shapeStrToInt(const std::string s) {
    if (s == "Line")
        return Shape::ShapeType::Line;
    if (s == "Polyline")
        return Shape::ShapeType::Polyline;
    if (s == "Polygon")
        return Shape::ShapeType::Polygon;
    if (s == "Rectangle")
        return Shape::ShapeType::Rectangle;
    if (s == "Square")
        return Shape::ShapeType::Square;
    if (s == "Ellipse")
        return Shape::ShapeType::Ellipse;
    if (s == "Circle")
        return Shape::ShapeType::Circle;
    if (s == "Text")
        return Shape::ShapeType::Text;
    return Shape::ShapeType::NoShape;
}

void inputLine(std::ifstream& fin, const std::string shapeID, vector<Shape*> shapeVector) {
    std::string dim1;
    std::string dim2;
    std::string dim3;
    std::string dim4;
    std::string penColor;
    std::string penWidth;
    std::string penStyle;
    std::string penCapStyle;
    std::string penJoinStyle;
    std::string dummy;

    QPoint p1, p2;

    fin >> dummy;
    fin >> dim1;
    dim1.erase(dim1.size() - 1);

    fin >> dim2;
    dim2.erase(dim2.size() - 1);

    fin >> dim3;
    dim3.erase(dim3.size() - 1);

    fin >> dim4;

    fin >> dummy;
    fin >> penColor;

    fin >> dummy;
    fin >> penWidth;

    fin >> dummy;
    fin >> penStyle;

    fin >> dummy;
    fin >> penCapStyle;

    fin >> dummy;
    fin >> penJoinStyle;

    p1.setX(stoi(dim1));
    p1.setY(stoi(dim2));
    p2.setX(stoi(dim3));
    p2.setY(stoi(dim4));

    Qt::GlobalColor qtPenColor = static_cast<Qt::GlobalColor>((QMetaEnum::fromType<Qt::GlobalColor>()).keyToValue(penColor.c_str()));
    Qt::PenStyle qtPenStyle = static_cast<Qt::PenStyle>((QMetaEnum::fromType<Qt::PenStyle>()).keyToValue(penStyle.c_str()));
    Qt::PenCapStyle qtPenCapStyle = static_cast<Qt::PenCapStyle>((QMetaEnum::fromType<Qt::PenCapStyle>()).keyToValue(penCapStyle.c_str()));
    Qt::PenJoinStyle qtPenJoinStyle = static_cast<Qt::PenJoinStyle>((QMetaEnum::fromType<Qt::PenJoinStyle>()).keyToValue(penJoinStyle.c_str()));

    Line* linePtr = new Line;

    linePtr->set_point(p1, p2);
    linePtr->set_shape(Shape::ShapeType::Line);
    linePtr->set_id(stoi(shapeID));
    linePtr->set_pen(qtPenColor, stoi(penWidth), qtPenStyle, qtPenCapStyle, qtPenJoinStyle);

    shapeVector.push_back(linePtr);
}

void inputPolyline(std::ifstream& fin, const std::string shapeID, vector<Shape*> shapeVector) {
    std::string dim1;
    std::string dim2;
    std::string dim3;
    std::string dim4;
    std::string dim5;
    std::string dim6;
    std::string dim7;
    std::string dim8;
    std::string penColor;
    std::string penWidth;
    std::string penStyle;
    std::string penCapStyle;
    std::string penJoinStyle;
    std::string dummy;

    QPoint p1, p2, p3, p4;

    fin >> dummy;
    fin >> dim1;
    dim1.erase(dim1.size() - 1);

    fin >> dim2;
    dim2.erase(dim2.size() - 1);

    fin >> dim3;
    dim3.erase(dim3.size() - 1);

    fin >> dim4;
    dim4.erase(dim4.size() - 1);

    fin >> dim5;
    dim5.erase(dim5.size() - 1);

    fin >> dim6;
    dim6.erase(dim6.size() - 1);

    fin >> dim7;
    dim7.erase(dim7.size() - 1);

    fin >> dim8;

    fin >> dummy;
    fin >> penColor;

    fin >> dummy;
    fin >> penWidth;

    fin >> dummy;
    fin >> penStyle;

    fin >> dummy;
    fin >> penCapStyle;

    fin >> dummy;
    fin >> penJoinStyle;

    p1.setX(stoi(dim1));
    p1.setY(stoi(dim2));
    p2.setX(stoi(dim3));
    p2.setY(stoi(dim4));
    p3.setX(stoi(dim5));
    p3.setY(stoi(dim6));
    p4.setX(stoi(dim7));
    p4.setY(stoi(dim8));

    Qt::GlobalColor qtPenColor = static_cast<Qt::GlobalColor>((QMetaEnum::fromType<Qt::GlobalColor>()).keyToValue(penColor.c_str()));
    Qt::PenStyle qtPenStyle = static_cast<Qt::PenStyle>((QMetaEnum::fromType<Qt::PenStyle>()).keyToValue(penStyle.c_str()));
    Qt::PenCapStyle qtPenCapStyle = static_cast<Qt::PenCapStyle>((QMetaEnum::fromType<Qt::PenCapStyle>()).keyToValue(penCapStyle.c_str()));
    Qt::PenJoinStyle qtPenJoinStyle = static_cast<Qt::PenJoinStyle>((QMetaEnum::fromType<Qt::PenJoinStyle>()).keyToValue(penJoinStyle.c_str()));

    Polyline* polylinePtr = new Polyline;

    polylinePtr->set_point(p1);
    polylinePtr->set_point(p2);
    polylinePtr->set_point(p3);
    polylinePtr->set_point(p4);
    polylinePtr->set_shape(Shape::ShapeType::Polyline);
    polylinePtr->set_id(stoi(shapeID));
    polylinePtr->set_pen(qtPenColor, stoi(penWidth), qtPenStyle, qtPenCapStyle, qtPenJoinStyle);

    shapeVector.push_back(polylinePtr);
}

void inputPolygon(std::ifstream& fin, const std::string shapeID, vector<Shape*> shapeVector) {
    std::string dim1;
    std::string dim2;
    std::string dim3;
    std::string dim4;
    std::string dim5;
    std::string dim6;
    std::string dim7;
    std::string dim8;
    std::string penColor;
    std::string penWidth;
    std::string penStyle;
    std::string penCapStyle;
    std::string penJoinStyle;
    std::string brushColor;
    std::string brushStyle;
    std::string dummy;

    QPoint p1, p2, p3, p4;

    fin >> dummy;
    fin >> dim1;
    dim1.erase(dim1.size() - 1);

    fin >> dim2;
    dim2.erase(dim2.size() - 1);

    fin >> dim3;
    dim3.erase(dim3.size() - 1);

    fin >> dim4;
    dim4.erase(dim4.size() - 1);

    fin >> dim5;
    dim5.erase(dim5.size() - 1);

    fin >> dim6;
    dim6.erase(dim6.size() - 1);

    fin >> dim7;
    dim7.erase(dim7.size() - 1);

    fin >> dim8;

    fin >> dummy;
    fin >> penColor;

    fin >> dummy;
    fin >> penWidth;

    fin >> dummy;
    fin >> penStyle;

    fin >> dummy;
    fin >> penCapStyle;

    fin >> dummy;
    fin >> penJoinStyle;

    fin >> dummy;
    fin >> brushColor;

    fin >> dummy;
    fin >> brushStyle;

    p1.setX(stoi(dim1));
    p1.setY(stoi(dim2));
    p2.setX(stoi(dim3));
    p2.setY(stoi(dim4));
    p3.setX(stoi(dim5));
    p3.setY(stoi(dim6));
    p4.setX(stoi(dim7));
    p4.setY(stoi(dim8));

    Qt::GlobalColor qtPenColor = static_cast<Qt::GlobalColor>((QMetaEnum::fromType<Qt::GlobalColor>()).keyToValue(penColor.c_str()));
    Qt::PenStyle qtPenStyle = static_cast<Qt::PenStyle>((QMetaEnum::fromType<Qt::PenStyle>()).keyToValue(penStyle.c_str()));
    Qt::PenCapStyle qtPenCapStyle = static_cast<Qt::PenCapStyle>((QMetaEnum::fromType<Qt::PenCapStyle>()).keyToValue(penCapStyle.c_str()));
    Qt::PenJoinStyle qtPenJoinStyle = static_cast<Qt::PenJoinStyle>((QMetaEnum::fromType<Qt::PenJoinStyle>()).keyToValue(penJoinStyle.c_str()));
    Qt::GlobalColor qtBrushColor = static_cast<Qt::GlobalColor>((QMetaEnum::fromType<Qt::GlobalColor>()).keyToValue(brushColor.c_str()));
    Qt::BrushStyle qtBrushStyle = static_cast<Qt::BrushStyle>((QMetaEnum::fromType<Qt::BrushStyle>()).keyToValue(brushStyle.c_str()));

    Polygon* polygonPtr = new Polygon;

    polygonPtr->set_point(p1);
    polygonPtr->set_point(p2);
    polygonPtr->set_point(p3);
    polygonPtr->set_point(p4);
    polygonPtr->set_shape(Shape::ShapeType::Polygon);
    polygonPtr->set_id(stoi(shapeID));
    polygonPtr->set_pen(qtPenColor, stoi(penWidth), qtPenStyle, qtPenCapStyle, qtPenJoinStyle);
    polygonPtr->set_brush(qtBrushColor, qtBrushStyle);

    shapeVector.push_back(polygonPtr);
}

void inputRectangle(std::ifstream& fin, const std::string shapeID, vector<Shape*> shapeVector) {
    std::string dim1;
    std::string dim2;
    std::string dim3;
    std::string dim4;
    std::string penColor;
    std::string penWidth;
    std::string penStyle;
    std::string penCapStyle;
    std::string penJoinStyle;
    std::string brushColor;
    std::string brushStyle;
    std::string dummy;

    QPoint p1;

    fin >> dummy;
    fin >> dim1;
    dim1.erase(dim1.size() - 1);

    fin >> dim2;
    dim2.erase(dim2.size() - 1);

    fin >> dim3;
    dim3.erase(dim3.size() - 1);

    fin >> dim4;

    fin >> dummy;
    fin >> penColor;

    fin >> dummy;
    fin >> penWidth;

    fin >> dummy;
    fin >> penStyle;

    fin >> dummy;
    fin >> penCapStyle;

    fin >> dummy;
    fin >> penJoinStyle;

    fin >> dummy;
    fin >> brushColor;

    fin >> dummy;
    fin >> brushStyle;

    p1.setX(stoi(dim1));
    p1.setY(stoi(dim2));

    Qt::GlobalColor qtPenColor = static_cast<Qt::GlobalColor>((QMetaEnum::fromType<Qt::GlobalColor>()).keyToValue(penColor.c_str()));
    Qt::PenStyle qtPenStyle = static_cast<Qt::PenStyle>((QMetaEnum::fromType<Qt::PenStyle>()).keyToValue(penStyle.c_str()));
    Qt::PenCapStyle qtPenCapStyle = static_cast<Qt::PenCapStyle>((QMetaEnum::fromType<Qt::PenCapStyle>()).keyToValue(penCapStyle.c_str()));
    Qt::PenJoinStyle qtPenJoinStyle = static_cast<Qt::PenJoinStyle>((QMetaEnum::fromType<Qt::PenJoinStyle>()).keyToValue(penJoinStyle.c_str()));
    Qt::GlobalColor qtBrushColor = static_cast<Qt::GlobalColor>((QMetaEnum::fromType<Qt::GlobalColor>()).keyToValue(brushColor.c_str()));
    Qt::BrushStyle qtBrushStyle = static_cast<Qt::BrushStyle>((QMetaEnum::fromType<Qt::BrushStyle>()).keyToValue(brushStyle.c_str()));

    Rectangle* rectanglePtr = new Rectangle;
    QRect r;
    r.setTopLeft(p1);
    r.setHeight(stoi(dim3));
    r.setWidth(stoi(dim4));

    rectanglePtr->set_rect(r);
    rectanglePtr->set_shape(Shape::ShapeType::Rectangle);
    rectanglePtr->set_id(stoi(shapeID));
    rectanglePtr->set_pen(qtPenColor, stoi(penWidth), qtPenStyle, qtPenCapStyle, qtPenJoinStyle);
    rectanglePtr->set_brush(qtBrushColor, qtBrushStyle);

    shapeVector.push_back(rectanglePtr);
}

void inputSquare(std::ifstream& fin, const std::string shapeID, vector<Shape*> shapeVector) {
    std::string dim1;
    std::string dim2;
    std::string dim3;
    std::string penColor;
    std::string penWidth;
    std::string penStyle;
    std::string penCapStyle;
    std::string penJoinStyle;
    std::string brushColor;
    std::string brushStyle;
    std::string dummy;

    QPoint p1;

    fin >> dummy;
    fin >> dim1;
    dim1.erase(dim1.size() - 1);

    fin >> dim2;
    dim2.erase(dim2.size() - 1);

    fin >> dim3;

    fin >> dummy;
    fin >> penColor;

    fin >> dummy;
    fin >> penWidth;

    fin >> dummy;
    fin >> penStyle;

    fin >> dummy;
    fin >> penCapStyle;

    fin >> dummy;
    fin >> penJoinStyle;

    fin >> dummy;
    fin >> brushColor;

    fin >> dummy;
    fin >> brushStyle;

    p1.setX(stoi(dim1));
    p1.setY(stoi(dim2));

    Qt::GlobalColor qtPenColor = static_cast<Qt::GlobalColor>((QMetaEnum::fromType<Qt::GlobalColor>()).keyToValue(penColor.c_str()));
    Qt::PenStyle qtPenStyle = static_cast<Qt::PenStyle>((QMetaEnum::fromType<Qt::PenStyle>()).keyToValue(penStyle.c_str()));
    Qt::PenCapStyle qtPenCapStyle = static_cast<Qt::PenCapStyle>((QMetaEnum::fromType<Qt::PenCapStyle>()).keyToValue(penCapStyle.c_str()));
    Qt::PenJoinStyle qtPenJoinStyle = static_cast<Qt::PenJoinStyle>((QMetaEnum::fromType<Qt::PenJoinStyle>()).keyToValue(penJoinStyle.c_str()));
    Qt::GlobalColor qtBrushColor = static_cast<Qt::GlobalColor>((QMetaEnum::fromType<Qt::GlobalColor>()).keyToValue(brushColor.c_str()));
    Qt::BrushStyle qtBrushStyle = static_cast<Qt::BrushStyle>((QMetaEnum::fromType<Qt::BrushStyle>()).keyToValue(brushStyle.c_str()));

    Rectangle* squarePtr = new Rectangle;
    QRect s;
    s.setTopLeft(p1);
    s.setHeight(stoi(dim3));
    s.setWidth(stoi(dim3));

    squarePtr->set_rect(s);
    squarePtr->set_shape(Shape::ShapeType::Square);
    squarePtr->set_id(stoi(shapeID));
    squarePtr->set_pen(qtPenColor, stoi(penWidth), qtPenStyle, qtPenCapStyle, qtPenJoinStyle);
    squarePtr->set_brush(qtBrushColor, qtBrushStyle);

    shapeVector.push_back(squarePtr);
}

void inputEllipse(std::ifstream& fin, const std::string shapeID, vector<Shape*> shapeVector) {
    std::string dim1;
    std::string dim2;
    std::string dim3;
    std::string dim4;
    std::string penColor;
    std::string penWidth;
    std::string penStyle;
    std::string penCapStyle;
    std::string penJoinStyle;
    std::string brushColor;
    std::string brushStyle;
    std::string dummy;

    QPoint p1;

    fin >> dummy;
    fin >> dim1;
    dim1.erase(dim1.size() - 1);

    fin >> dim2;
    dim2.erase(dim2.size() - 1);

    fin >> dim3;
    dim3.erase(dim3.size() - 1);

    fin >> dim4;

    fin >> dummy;
    fin >> penColor;

    fin >> dummy;
    fin >> penWidth;

    fin >> dummy;
    fin >> penStyle;

    fin >> dummy;
    fin >> penCapStyle;

    fin >> dummy;
    fin >> penJoinStyle;

    fin >> dummy;
    fin >> brushColor;

    fin >> dummy;
    fin >> brushStyle;

    p1.setX(stoi(dim1));
    p1.setY(stoi(dim2));

    Qt::GlobalColor qtPenColor = static_cast<Qt::GlobalColor>((QMetaEnum::fromType<Qt::GlobalColor>()).keyToValue(penColor.c_str()));
    Qt::PenStyle qtPenStyle = static_cast<Qt::PenStyle>((QMetaEnum::fromType<Qt::PenStyle>()).keyToValue(penStyle.c_str()));
    Qt::PenCapStyle qtPenCapStyle = static_cast<Qt::PenCapStyle>((QMetaEnum::fromType<Qt::PenCapStyle>()).keyToValue(penCapStyle.c_str()));
    Qt::PenJoinStyle qtPenJoinStyle = static_cast<Qt::PenJoinStyle>((QMetaEnum::fromType<Qt::PenJoinStyle>()).keyToValue(penJoinStyle.c_str()));
    Qt::GlobalColor qtBrushColor = static_cast<Qt::GlobalColor>((QMetaEnum::fromType<Qt::GlobalColor>()).keyToValue(brushColor.c_str()));
    Qt::BrushStyle qtBrushStyle = static_cast<Qt::BrushStyle>((QMetaEnum::fromType<Qt::BrushStyle>()).keyToValue(brushStyle.c_str()));

    Ellipse* ellipsePtr = new Ellipse;
    QRect e;
    e.setTopLeft(p1);
    e.setHeight(stoi(dim3));
    e.setWidth(stoi(dim4));

    ellipsePtr->set_ellipse(e);
    ellipsePtr->set_shape(Shape::ShapeType::Ellipse);
    ellipsePtr->set_id(stoi(shapeID));
    ellipsePtr->set_pen(qtPenColor, stoi(penWidth), qtPenStyle, qtPenCapStyle, qtPenJoinStyle);
    ellipsePtr->set_brush(qtBrushColor, qtBrushStyle);

    shapeVector.push_back(ellipsePtr);
}

void inputCircle(std::ifstream& fin, const std::string shapeID, vector<Shape*> shapeVector) {
    std::string dim1;
    std::string dim2;
    std::string dim3;
    std::string penColor;
    std::string penWidth;
    std::string penStyle;
    std::string penCapStyle;
    std::string penJoinStyle;
    std::string brushColor;
    std::string brushStyle;
    std::string dummy;

    QPoint p1;

    fin >> dummy;
    fin >> dim1;
    dim1.erase(dim1.size() - 1);

    fin >> dim2;
    dim2.erase(dim2.size() - 1);

    fin >> dim3;

    fin >> dummy;
    fin >> penColor;

    fin >> dummy;
    fin >> penWidth;

    fin >> dummy;
    fin >> penStyle;

    fin >> dummy;
    fin >> penCapStyle;

    fin >> dummy;
    fin >> penJoinStyle;

    fin >> dummy;
    fin >> brushColor;

    fin >> dummy;
    fin >> brushStyle;

    p1.setX(stoi(dim1));
    p1.setY(stoi(dim2));

    Qt::GlobalColor qtPenColor = static_cast<Qt::GlobalColor>((QMetaEnum::fromType<Qt::GlobalColor>()).keyToValue(penColor.c_str()));
    Qt::PenStyle qtPenStyle = static_cast<Qt::PenStyle>((QMetaEnum::fromType<Qt::PenStyle>()).keyToValue(penStyle.c_str()));
    Qt::PenCapStyle qtPenCapStyle = static_cast<Qt::PenCapStyle>((QMetaEnum::fromType<Qt::PenCapStyle>()).keyToValue(penCapStyle.c_str()));
    Qt::PenJoinStyle qtPenJoinStyle = static_cast<Qt::PenJoinStyle>((QMetaEnum::fromType<Qt::PenJoinStyle>()).keyToValue(penJoinStyle.c_str()));
    Qt::GlobalColor qtBrushColor = static_cast<Qt::GlobalColor>((QMetaEnum::fromType<Qt::GlobalColor>()).keyToValue(brushColor.c_str()));
    Qt::BrushStyle qtBrushStyle = static_cast<Qt::BrushStyle>((QMetaEnum::fromType<Qt::BrushStyle>()).keyToValue(brushStyle.c_str()));

    Ellipse* circlePtr = new Ellipse;
    QRect c;
    c.setTopLeft(p1);
    c.setHeight(stoi(dim3));
    c.setWidth(stoi(dim3));

    circlePtr->set_ellipse(c);
    circlePtr->set_shape(Shape::ShapeType::Circle);
    circlePtr->set_id(stoi(shapeID));
    circlePtr->set_pen(qtPenColor, stoi(penWidth), qtPenStyle, qtPenCapStyle, qtPenJoinStyle);
    circlePtr->set_brush(qtBrushColor, qtBrushStyle);

    shapeVector.push_back(circlePtr);
}

void inputText(std::ifstream& fin, const std::string shapeID, vector<Shape*> shapeVector) {
    std::string dim1;
    std::string dim2;
    std::string dim3;
    std::string dim4;
    std::string textString;
    std::string textColor;
    std::string textAlignment;
    std::string textPointSize;
    std::string textFontFamily;
    std::string textFontStyle;
    std::string textFontWeight;
    std::string dummy;

    QPoint p1;

    fin >> dummy;
    fin >> dim1;
    dim1.erase(dim1.size() - 1);

    fin >> dim2;
    dim2.erase(dim2.size() - 1);

    fin >> dim3;
    dim3.erase(dim3.size() - 1);

    fin >> dim4;

    fin >> dummy;
    fin.ignore();
    getline(fin, textString, '\n');

    fin >> dummy;
    fin >> textColor;

    fin >> dummy;
    fin >> textAlignment;

    fin >> dummy;
    fin >> textPointSize;

    fin >> dummy;
    fin.ignore();
    getline(fin, textFontFamily, '\n');

    fin >> dummy;
    fin >> textFontStyle;

    fin >> dummy;
    fin >> textFontWeight;

    p1.setX(stoi(dim1));
    p1.setY(stoi(dim2));

    Qt::AlignmentFlag qtTextAlignment = static_cast<Qt::AlignmentFlag>((QMetaEnum::fromType<Qt::AlignmentFlag>()).keyToValue(textAlignment.c_str()));
    Qt::GlobalColor qtTextColor = static_cast<Qt::GlobalColor>((QMetaEnum::fromType<Qt::GlobalColor>()).keyToValue(textColor.c_str()));
    QFont::Style qtTextFontStyle = static_cast<QFont::Style>((QMetaEnum::fromType<QFont::Style>()).keyToValue(textFontStyle.c_str()));
    QFont::Weight qtTextFontWeight = static_cast<QFont::Weight>((QMetaEnum::fromType<QFont::Weight>()).keyToValue(textFontWeight.c_str()));

    Text* textPtr = new Text;
    QRect t;
    t.setTopLeft(p1);
    t.setHeight(stoi(dim3));
    t.setWidth(stoi(dim4));

    textPtr->set_text(t, QString(textString.c_str()), QColor(qtTextColor), qtTextAlignment,
                      stoi(textPointSize), QString(textFontFamily.c_str()), qtTextFontStyle, qtTextFontWeight);
    textPtr->set_shape(Shape::ShapeType::Text);
    textPtr->set_id(stoi(shapeID));

    shapeVector.push_back(textPtr);
}
