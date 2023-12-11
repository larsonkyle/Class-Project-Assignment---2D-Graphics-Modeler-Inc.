#ifndef SERIALIZER_H
#define SERIALIZER_H

#include <iostream>
#include <fstream>
#include <QMetaEnum>

#include "Shape.h"
#include "vector_doubles.h"

using std::endl;

void outputLine(std::ofstream& fout, vector<Shape*>::iterator it);
void outputPolyline(std::ofstream& fout, vector<Shape*>::iterator it);
void outputPolygon(std::ofstream& fout, vector<Shape*>::iterator it);
void outputRectangle(std::ofstream& fout, vector<Shape*>::iterator it);
void outputSquare(std::ofstream& fout, vector<Shape*>::iterator it);
void outputEllipse(std::ofstream& fout, vector<Shape*>::iterator it);
void outputCircle(std::ofstream& fout, vector<Shape*>::iterator it);
void outputText(std::ofstream& fout, vector<Shape*>::iterator it);

void writeShapes(vector<Shape*> shapeVector) {
    std::ofstream fout;
    vector<Shape*>::iterator it;
    fout.open("shapes.txt", std::ofstream::out | std::ofstream::trunc);

    for (it = shapeVector.begin(); it < shapeVector.end(); it++) {
        switch((*it)->get_shape()) {
        case Shape::ShapeType::Line:
            outputLine(fout, it);
            break;
        case Shape::ShapeType::Polyline:
            outputPolyline(fout, it);
            break;
        case Shape::ShapeType::Polygon:
            outputPolygon(fout, it);
            break;
        case Shape::ShapeType::Rectangle:
            outputRectangle(fout, it);
            break;
        case Shape::ShapeType::Square:
            outputSquare(fout, it);
            break;
        case Shape::ShapeType::Ellipse:
            outputEllipse(fout, it);
            break;
        case Shape::ShapeType::Circle:
            outputCircle(fout, it);
            break;
        case Shape::ShapeType::Text:
            outputText(fout, it);
            break;
        case Shape::ShapeType::NoShape:
            break;
        }
    }

    fout.close();
}

void outputLine(std::ofstream& fout, vector<Shape*>::iterator it) {
    QPen pen = (*it)->get_pen();

    std::string penColor = pen.color().name().toStdString();
    std::string penWidth = std::to_string(pen.width());
    std::string penStyle = QMetaEnum::fromType<PenStyle>().valueToKey(static_cast<int>(pen.style()));
    std::string penCapStyle = QMetaEnum::fromType<PenCapStyle>().valueToKey(static_cast<int>(pen.capStyle()));
    std::string penJoinStyle = QMetaEnum::fromType<PenJoinStyle>().valueToKey(static_cast<int>(pen.joinStyle()));

    fout << "ShapeId: " << (*it)->get_id() << endl;
    fout << "ShapeType: Line" << endl;
    fout << "ShapeDimensions: "
         << (*it)->getPointBegin().x() << ", "
         << (*it)->getPointBegin().y() << ", "
         << (*it)->getPointEnd().x() << ", "
         << (*it)->getPointEnd().y() << endl;
    fout << "PenColor: " << penColor << endl;
    fout << "PenWidth: " << penWidth << endl;
    fout << "PenStyle: " << penStyle << endl;
    fout << "PenCapStyle: " << penCapStyle << endl;
    fout << "PenJoinStyle: " << penJoinStyle << endl << endl;
}

void outputPolyline(std::ofstream& fout, vector<Shape*>::iterator it) {
    QPen pen = (*it)->get_pen();

    std::string penColor = pen.color().name().toStdString();
    std::string penWidth = std::to_string(pen.width());
    std::string penStyle = QMetaEnum::fromType<PenStyle>().valueToKey(static_cast<int>(pen.style()));
    std::string penCapStyle = QMetaEnum::fromType<PenCapStyle>().valueToKey(static_cast<int>(pen.capStyle()));
    std::string penJoinStyle = QMetaEnum::fromType<PenJoinStyle>().valueToKey(static_cast<int>(pen.joinStyle()));

    fout << "ShapeId: " << (*it)->get_id() << endl;
    fout << "ShapeType: Polyline" << endl;
    fout << "ShapeDimensions: "
         << (*it)->getPoints()[0].x() << ", "
         << (*it)->getPoints()[0].y() << ", "
         << (*it)->getPoints()[1].x() << ", "
         << (*it)->getPoints()[1].y() << ", "
         << (*it)->getPoints()[2].x() << ", "
         << (*it)->getPoints()[2].y() << ", "
         << (*it)->getPoints()[3].x() << ", "
         << (*it)->getPoints()[3].y() << endl;
    fout << "PenColor: " << penColor << endl;
    fout << "PenWidth: " << penWidth << endl;
    fout << "PenStyle: " << penStyle << endl;
    fout << "PenCapStyle: " << penCapStyle << endl;
    fout << "PenJoinStyle: " << penJoinStyle << endl << endl;
}

void outputPolygon(std::ofstream& fout, vector<Shape*>::iterator it) {
    QPen pen = (*it)->get_pen();
    QBrush brush = (*it)->get_brush();

    std::string penColor = pen.color().name().toStdString();
    std::string penWidth = std::to_string(pen.width());
    std::string penStyle = QMetaEnum::fromType<PenStyle>().valueToKey(static_cast<int>(pen.style()));
    std::string penCapStyle = QMetaEnum::fromType<PenCapStyle>().valueToKey(static_cast<int>(pen.capStyle()));
    std::string penJoinStyle = QMetaEnum::fromType<PenJoinStyle>().valueToKey(static_cast<int>(pen.joinStyle()));
    std::string brushColor = brush.color().name().toStdString();
    std::string brushStyle = QMetaEnum::fromType<BrushStyle>().valueToKey(static_cast<int>(brush.style()));

    fout << "ShapeId: " << (*it)->get_id() << endl;
    fout << "ShapeType: Polygon" << endl;
    fout << "ShapeDimensions: "
         << (*it)->getPoints()[0].x() << ", "
         << (*it)->getPoints()[0].y() << ", "
         << (*it)->getPoints()[1].x() << ", "
         << (*it)->getPoints()[1].y() << ", "
         << (*it)->getPoints()[2].x() << ", "
         << (*it)->getPoints()[2].y() << ", "
         << (*it)->getPoints()[3].x() << ", "
         << (*it)->getPoints()[3].y() << endl;
    fout << "PenColor: " << penColor << endl;
    fout << "PenWidth: " << penWidth << endl;
    fout << "PenStyle: " << penStyle << endl;
    fout << "PenCapStyle: " << penCapStyle << endl;
    fout << "PenJoinStyle: " << penJoinStyle << endl;
    fout << "BrushColor: " << brushColor << endl;
    fout << "BrushStyle: " << brushStyle << endl << endl;
}

void outputRectangle(std::ofstream& fout, vector<Shape*>::iterator it) {
    QPen pen = (*it)->get_pen();
    QBrush brush = (*it)->get_brush();

    std::string penColor = pen.color().name().toStdString();
    std::string penWidth = std::to_string(pen.width());
    std::string penStyle = QMetaEnum::fromType<PenStyle>().valueToKey(static_cast<int>(pen.style()));
    std::string penCapStyle = QMetaEnum::fromType<PenCapStyle>().valueToKey(static_cast<int>(pen.capStyle()));
    std::string penJoinStyle = QMetaEnum::fromType<PenJoinStyle>().valueToKey(static_cast<int>(pen.joinStyle()));
    std::string brushColor = brush.color().name().toStdString();
    std::string brushStyle = QMetaEnum::fromType<BrushStyle>().valueToKey(static_cast<int>(brush.style()));

    fout << "ShapeId: " << (*it)->get_id() << endl;
    fout << "ShapeType: Rectangle" << endl;
    fout << "ShapeDimensions: "
         << (*it)->getRect().topLeft().x() << ", "
         << (*it)->getRect().topLeft().y() << ", "
         << (*it)->getRect().width() << ", "
         << (*it)->getRect().height() << endl;
    fout << "PenColor: " << penColor << endl;
    fout << "PenWidth: " << penWidth << endl;
    fout << "PenStyle: " << penStyle << endl;
    fout << "PenCapStyle: " << penCapStyle << endl;
    fout << "PenJoinStyle: " << penJoinStyle << endl;
    fout << "BrushColor: " << brushColor << endl;
    fout << "BrushStyle: " << brushStyle << endl << endl;
}

void outputSquare(std::ofstream& fout, vector<Shape*>::iterator it) {
    QPen pen = (*it)->get_pen();
    QBrush brush = (*it)->get_brush();

    std::string penColor = pen.color().name().toStdString();
    std::string penWidth = std::to_string(pen.width());
    std::string penStyle = QMetaEnum::fromType<PenStyle>().valueToKey(static_cast<int>(pen.style()));
    std::string penCapStyle = QMetaEnum::fromType<PenCapStyle>().valueToKey(static_cast<int>(pen.capStyle()));
    std::string penJoinStyle = QMetaEnum::fromType<PenJoinStyle>().valueToKey(static_cast<int>(pen.joinStyle()));
    std::string brushColor = brush.color().name().toStdString();
    std::string brushStyle = QMetaEnum::fromType<BrushStyle>().valueToKey(static_cast<int>(brush.style()));

    fout << "ShapeId: " << (*it)->get_id() << endl;
    fout << "ShapeType: Square" << endl;
    fout << "ShapeDimensions: "
         << (*it)->getRect().topLeft().x() << ", "
         << (*it)->getRect().topLeft().y() << ", "
         << (*it)->getRect().width() << endl;
    fout << "PenColor: " << penColor << endl;
    fout << "PenWidth: " << penWidth << endl;
    fout << "PenStyle: " << penStyle << endl;
    fout << "PenCapStyle: " << penCapStyle << endl;
    fout << "PenJoinStyle: " << penJoinStyle << endl;
    fout << "BrushColor: " << brushColor << endl;
    fout << "BrushStyle: " << brushStyle << endl << endl;
}

void outputEllipse(std::ofstream& fout, vector<Shape*>::iterator it) {
    QPen pen = (*it)->get_pen();
    QBrush brush = (*it)->get_brush();

    std::string penColor = pen.color().name().toStdString();
    std::string penWidth = std::to_string(pen.width());
    std::string penStyle = QMetaEnum::fromType<PenStyle>().valueToKey(static_cast<int>(pen.style()));
    std::string penCapStyle = QMetaEnum::fromType<PenCapStyle>().valueToKey(static_cast<int>(pen.capStyle()));
    std::string penJoinStyle = QMetaEnum::fromType<PenJoinStyle>().valueToKey(static_cast<int>(pen.joinStyle()));
    std::string brushColor = brush.color().name().toStdString();
    std::string brushStyle = QMetaEnum::fromType<BrushStyle>().valueToKey(static_cast<int>(brush.style()));

    fout << "ShapeId: " << (*it)->get_id() << endl;
    fout << "ShapeType: Ellipse" << endl;
    fout << "ShapeDimensions: "
         << (*it)->getRect().topLeft().x() << ", "
         << (*it)->getRect().topLeft().y() << ", "
         << (*it)->getRect().width() << ", "
         << (*it)->getRect().height() << endl;
    fout << "PenColor: " << penColor << endl;
    fout << "PenWidth: " << penWidth << endl;
    fout << "PenStyle: " << penStyle << endl;
    fout << "PenCapStyle: " << penCapStyle << endl;
    fout << "PenJoinStyle: " << penJoinStyle << endl;
    fout << "BrushColor: " << brushColor << endl;
    fout << "BrushStyle: " << brushStyle << endl << endl;
}

void outputCircle(std::ofstream& fout, vector<Shape*>::iterator it) {
    QPen pen = (*it)->get_pen();
    QBrush brush = (*it)->get_brush();

    std::string penColor = pen.color().name().toStdString();
    std::string penWidth = std::to_string(pen.width());
    std::string penStyle = QMetaEnum::fromType<PenStyle>().valueToKey(static_cast<int>(pen.style()));
    std::string penCapStyle = QMetaEnum::fromType<PenCapStyle>().valueToKey(static_cast<int>(pen.capStyle()));
    std::string penJoinStyle = QMetaEnum::fromType<PenJoinStyle>().valueToKey(static_cast<int>(pen.joinStyle()));
    std::string brushColor = brush.color().name().toStdString();
    std::string brushStyle = QMetaEnum::fromType<BrushStyle>().valueToKey(static_cast<int>(brush.style()));

    fout << "ShapeId: " << (*it)->get_id() << endl;
    fout << "ShapeType: Circle" << endl;
    fout << "ShapeDimensions: "
         << (*it)->getRect().topLeft().x() << ", "
         << (*it)->getRect().topLeft().y() << ", "
         << (*it)->getRect().width() << endl;
    fout << "PenColor: " << penColor << endl;
    fout << "PenWidth: " << penWidth << endl;
    fout << "PenStyle: " << penStyle << endl;
    fout << "PenCapStyle: " << penCapStyle << endl;
    fout << "PenJoinStyle: " << penJoinStyle << endl;
    fout << "BrushColor: " << brushColor << endl;
    fout << "BrushStyle: " << brushStyle << endl << endl;
}

void outputText(std::ofstream& fout, vector<Shape*>::iterator it) {
    QFont font = (*it)->get_font();

    std::string textString = (*it)->getTextString().toStdString();
    std::string textColor = (*it)->getTextColor().name().toStdString();
    std::string textAlignment = QMetaEnum::fromType<AlignmentFlag>().valueToKey((*it)->getAlign());
    std::string textPointSize = std::to_string(font.pointSize());
    std::string textFontFamily = font.family().toStdString();
    std::string textFontStyle = QMetaEnum::fromType<QFont::Style>().valueToKey(font.style());
    std::string textFontWeight = QMetaEnum::fromType<QFont::Weight>().valueToKey(font.weight());

    fout << "ShapeId: " << (*it)->get_id() << endl;
    fout << "ShapeType: Text" << endl;
    fout << "ShapeDimensions: "
         << (*it)->getRect().topLeft().x() << ", "
         << (*it)->getRect().topLeft().y() << ", "
         << (*it)->getRect().width() << ", "
         << (*it)->getRect().height() << endl;
    fout << "TextString: " << textString << endl;
    fout << "TextColor: " << textColor << endl;
    fout << "TextAlignment: " << textAlignment << endl;
    fout << "TextPointSize: " << textPointSize << endl;
    fout << "TextFontFamily: " << textFontFamily << endl;
    fout << "TextFontStyle: " << textFontStyle << endl;
    fout << "TextFontWeight: " << textFontWeight << endl << endl;
}

#endif // SERIALIZER_H

