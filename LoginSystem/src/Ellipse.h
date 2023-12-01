#ifndef ELLIPSE_H_
#define ELLIPSE_H_

#include "Shape.h"

class Ellipse : public Shape{
    public:
        Ellipse(QPaintDevice* device = nullptr, int id = -1) : Shape{device, id, ShapeType::Ellipse} { }
        //~Ellipse() override { }

        bool isCircle() const;
        void set_ellipse(const QRect& new_ellipse) {ellipse = new_ellipse;}
        QRect getRect() override {return ellipse;}

		void draw(const int translate_x = 0, const int translate_y = 0) override;

    private:
        QRect ellipse;
};

#endif
