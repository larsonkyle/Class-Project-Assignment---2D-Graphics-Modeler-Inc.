#ifndef TEXT_H_
#define TEXT_H_

#include "Shape.h"

class Text : public Shape{
	public:
        Text(int id = -1) : Shape(id, ShapeType::Text) { }
        //~Text() override { }

        void set_text(const QRect& tO, const QString t, const QColor c, const AlignmentFlag a,
                      const int pS, const QString f, const QFont::Style s, const QFont::Weight w);

        QRect getRect() override {return rect;}
        QFont get_font() override {return font;}

        QString getTextString() override {return text;}
        QColor getTextColor() override {return color;}
        AlignmentFlag getAlign() override {return align;}

        void draw(QPaintDevice* device) override;

	private:
		QRect rect;
		QString text {"Class Project - 2D Graphics Modeler"};
        QColor color {blue};
        AlignmentFlag align {AlignCenter};

		int pointSize {10};
		QString family {"Comic Sans MS"};
		QFont::Style style {QFont::StyleNormal};
        QFont::Weight weight {QFont::Normal};
        QFont font; //in set_text, feed everything from above into here. Then give to qpainter.
};

#endif
