//
// Created by Luca Schidu on 4/18/2016.
//

#include <time.h>
#include "Controller.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

Controller::Controller() {
    initTrafficLights();
    srand(time(NULL));
    trafficLight = 1;
}

void Controller::initTrafficLights() {

    trOne = new TrafficLight(280, 150, 40, false);
    trTwo = new TrafficLight(480, 150, 40, true);
    trThree = new TrafficLight(280, 400, 40, true);
    trFour = new TrafficLight(480, 400, 40, false);
}

void Controller::generateCar() {

    int vector = rand() % 4;
    bool canGenerate;

    switch (vector){
        case 0:
            vector = rand() % 100;
            if(vector == 0){
                canGenerate = true;
                for(int i = 0; i < vecOne.size(); i++){
                    if(vecOne[i].getX() < 0 )
                        canGenerate = false;
                }

                if(canGenerate){
                    car = new Car(-100, 330, 80, 40, 1);
                    vecOne.push_back(*car);

                }
            }

            break;
        case 1:
            vector = rand() % 100;
            if(vector == 0){
                canGenerate = true;
                for(int i = 0; i < vecTwo.size(); i++){
                    if(vecTwo[i].getY() < 0 )
                        canGenerate = false;
                }

                if(canGenerate){
                    car = new Car(330, -100, 80, 40, 2);
                    vecTwo.push_back(*car);
                }
                cout << vecTwo.size() << " " ;
            }

            break;
        case 2:
            vector = rand() % 100;
            if(vector == 0){
                canGenerate = true;
                for(int i = 0; i < vecThree.size(); i++){
                    if(vecThree[i].getX() + vecThree[i].getHeight() > 800 )
                        canGenerate = false;
                }

                if(canGenerate){
                    car = new Car(820, 230, 80, 40, 3);
                    vecThree.push_back(*car);
                }
            }

            break;
        case 3:
            vector = rand() % 100;
            if(vector == 0){
                canGenerate = true;

                for(int i = 0; i < vecFour.size(); i++){
                    if(vecFour[i].getY() + vecFour[i].getHeight() > 600 )
                        canGenerate = false;
                }
                if(canGenerate){
                    car = new Car(430, 600, 80, 40, 4);
                    vecFour.push_back(*car);
                }
            }

            break;
    }
}

void Controller::drawCars(HDC hdcMem) {

    for(int i = 0; i < vecOne.size(); i++) {
        vecOne[i].drawCar(hdcMem);
    }

    for(int i = 0; i < vecTwo.size(); i++) {
        vecTwo[i].drawCar(hdcMem);
    }

    for(int i = 0; i < vecThree.size(); i++) {
        vecThree[i].drawCar(hdcMem);
    }

    for(int i = 0; i < vecFour.size(); i++) {
        vecFour[i].drawCar(hdcMem);
    }
}


void Controller::drawTrafficLights(HDC hdcMem) {
    trOne->draw(hdcMem);
    trTwo->draw(hdcMem);
    trThree->draw(hdcMem);
    trFour->draw(hdcMem);
}

void Controller::moveCars() {

        for(int i = 0; i < vecOne.size(); i++) {
            if(trafficLight == 1) {
                if(vecOne[i].getX() <= 300 - 100 || vecOne[i].getX() > 320 ) {
                    if(canCarMove(i, vecOne, 1))
                        vecOne[i].setX(vecOne[i].getX() + 1);
                }
            }else{
                vecOne[i].setX(vecOne[i].getX() + 1);
            }
        }

        for(int i = 0; i < vecTwo.size(); i++) {
            if(trafficLight == 0) {
                if(vecTwo[i].getY() <= 150 - 50 || vecTwo[i].getY() > 170) {
                    if(canCarMove(i, vecTwo, 2))
                        vecTwo[i].setY(vecTwo[i].getY() + 1);
                }
            }else{
                vecTwo[i].setY(vecTwo[i].getY() + 1);
            }
        }

        for(int i = 0; i < vecThree.size(); i++) {
            if(trafficLight == 1) {
                if(vecThree[i].getX() >= 500 + 10 || vecThree[i].getX() < 490) {
                    if(canCarMove(i, vecThree, 3))
                        vecThree[i].setX(vecThree[i].getX() - 1);
                }
            }else{
                vecThree[i].setX(vecThree[i].getX() - 1);
            }
        }

        for(int i = 0; i < vecFour.size(); i++) {
            if(trafficLight == 0) {
                if(vecFour[i].getY() >= 400 + 10 || vecFour[i].getY() < 380) {
                    if(canCarMove(i, vecFour, 4))
                        vecFour[i].setY(vecFour[i].getY() - 1);
                }
            }else{
                vecFour[i].setY(vecFour[i].getY() - 1);
            }
        }
 }


void Controller::changeTraficLight() {

    trOne->changeColor();
    trTwo->changeColor();
    trThree->changeColor();
    trFour->changeColor();

    if(trafficLight == 0) {
        trafficLight = 1;
    }else{
        trafficLight = 0;
    }
}


bool Controller::canCarMove(int index, vector<Car> cars, int direction) {
    bool canMove = true;

    for(int i = 0; i < index; i++) {

        if(index != i) {
            switch(direction) {
                case 1:
                    if(cars[index].getX() + cars[index].getWidth() + 10 >= cars[i].getX()) {
                        canMove = false;
                    }
                    break;
                case 2:
                    if(cars[index].getY() + cars[index].getWidth() + 10 >= cars[i].getY()) {
                        canMove = false;
                    }
                    break;
                case 3:
                    if(cars[index].getX() - 10 <= cars[i].getX() + cars[i].getWidth()) {
                        canMove = false;
                    }
                    break;
                case 4:
                    if(cars[index].getY() - 10 <= cars[i].getY() + cars[i].getWidth()) {
                        canMove = false;
                    }
                    break;
            }
        }
    }

    return canMove;
}

