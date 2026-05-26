#ifndef _USR_H_
#define _USR_H_

class Rectangle {
private:
    int height;
    int width;
public:
    void Set(int h, int w) {
        height = h;
        width = w;
    }

    int GetArea() {
        return height * width;
    }
};

Rectangle GetRect(int h, int w) {
    Rectangle r;
    r.Set(h, w);
    return r;
}

int GetRectArea(Rectangle rect) {
    return rect.GetArea();
}

#endif
