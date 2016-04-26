//
// Created by Luca Schidu on 4/18/2016.
//

#ifndef WINAPI_CAR_H
#define WINAPI_CAR_H


#include <windef.h>
#include <winuser.h>
#include <wingdi.h>

class Car {
private:
    int width;
    int height;
    int x;
    int y;
    int direction;
    HBRUSH brush;
public:
    Car(int x, int y, int width, int height, int direction);
    int getWidth();
    int getHeight();
    int getX();
    int getY();
    void setX(int x);
    void setY(int y);
    int getDirection();
    void drawCar(HDC hdcMem);
    void deleteBrush();

};


#endif //WINAPI_CAR_H
