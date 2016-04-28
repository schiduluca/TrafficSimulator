//
// Created by Luca Schidu on 4/26/2016.
//

#include "Pedestrian.h"

//
// Created by Luca Schidu on 4/18/2016.
//

#include "Car.h"

void Pedestrian::drawPedestrian(HDC hdcMem) {
    SelectObject(hdcMem, brush);

    if(direction == 2 || direction == 4) {
        Rectangle(hdcMem, x, y, x + height, y + width);
    }else{
        Rectangle(hdcMem, x, y, x + width, y + height);
    }
}


void Pedestrian::setY(int y) {
    this->y = y;
}

void Pedestrian::setX(int x) {
    this->x = x;
}


void Pedestrian::drawPedestrian(HDC hdcMem) {
    SelectObject(hdcMem, brush);

    if(direction == 2 || direction == 4) {
        Rectangle(hdcMem, x, y, x + height, y + width);
    }else{
        Rectangle(hdcMem, x, y, x + width, y + height);
    }
}

int Pedestrian::getX() {
    return this->x;
}

int Pedestrian::getY(){
    return this->y;
}

int Pedestrian::getDirection() {
    return this->direction;
}





int Pedestrian::getWidth() {
    return this->width;
}


Pedestrian::Pedestrian(int x, int y, int width, int height, int direction) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->direction = direction;
    brush = CreateSolidBrush(RGB(45, 12, 100));
}


void Pedestrian::deleteBrush() {
    DeleteObject(brush);
}


int Pedestrian::getHeight() {
    return this->height;
}
