//
// Created by Luca Schidu on 4/18/2016.
//

#include "Car.h"

void Car::drawCar(HDC hdcMem) {
    SelectObject(hdcMem, brush);

    if(direction == 2 || direction == 4) {
        Rectangle(hdcMem, x, y, x + height, y + width);
    }else{
        Rectangle(hdcMem, x, y, x + width, y + height);
    }
}


void Car::setY(int y) {
    this->y = y;
}

void Car::setX(int x) {
    this->x = x;
}

int Car::getX() {
    return this->x;
}

int Car::getY(){
    return this->y;
}

int Car::getDirection() {
    return this->direction;
}



Car::Car(int x, int y, int width, int height, int direction) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->direction = direction;
    brush = CreateSolidBrush(RGB(0, 0, 0));
}

int Car::getWidth() {
    return this->width;
}


int Car::getHeight() {
    return this->height;
}

void Car::deleteBrush() {
    DeleteObject(brush);
}