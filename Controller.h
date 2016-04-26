//
// Created by Luca Schidu on 4/18/2016.
//

#ifndef WINAPI_CONTROLLER_H
#define WINAPI_CONTROLLER_H


#include "Car.h"
#include "TrafficLight.h"
#include <vector>
using namespace std;

class Controller {
    int trafficLight = 0;
    int vectorSize = 10;
    int random;
    vector<Car> vecOne;
    vector<Car> vecTwo;
    vector<Car> vecThree;
    vector<Car> vecFour;
    Car *car;
    TrafficLight *trOne;
    TrafficLight *trTwo;
    TrafficLight *trThree;
    TrafficLight *trFour;

public:
    void initCars();
    void initTrafficLights();
    Controller();
    void changeTraficLight();
    void generateCar();
    void drawCars(HDC hdcMem);
    void moveCars();
    void drawTrafficLights(HDC hdcMem);
    bool canCarMove(int index, vector<Car> cars, int direction );
};


#endif //WINAPI_CONTROLLER_H
