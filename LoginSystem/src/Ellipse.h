#ifndef ELLIPSE_H_
#define ELLIPSE_H_

#include "Shape.h"

class Ellipse : public Shape{
    public:
        Ellipse(int id = -1) : Shape{id, ShapeType::Ellipse} { }
        //~Ellipse() override { }

        bool isCircle() const;
        void set_ellipse(const QRect& new_ellipse) {ellipse = new_ellipse;}
        QRect getRect() override {return ellipse;}

        void draw(QPaintDevice* device) override;

    private:
        QRect ellipse;
};

#endif
