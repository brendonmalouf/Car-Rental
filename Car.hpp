//
//  Car.hpp
//  P1CarRental
//
//  Created by Brendon Malouf on 2/16/18.
//  Copyright © 2018 Brendon Malouf. All rights reserved.
//

#ifndef Car_hpp
#define Car_hpp

#include "enums.hpp"
#include <iostream>
#include <string>
using namespace std;

extern const char* typeNames[5];

//Car class: contains attributes related to the car
class Car{
protected:
    string plateNumber;
    string make;
    string model;
    vehicleType vType;
    double pricePerDay;
    bool isAvailable = false;

public:
    Car(): plateNumber{""}, make{""}, model{""}, vType(), pricePerDay{0},
    isAvailable{true}{} //Default construtor
    Car(string pNum, string make, string model, vehicleType vType, double ppd,
        bool isAvail); //Constructor
    ostream& print( ostream& out );
    string getPlateNumber(){ return plateNumber; } //gets plateNumber
    string getMake(){ return make; } //gets make
    string getModel(){ return model; } //gets model
    vehicleType getType(){ return vType; } //gets vType
    double getPPD(){ return pricePerDay; } //gets pricePerDay
    void setAvailable( bool available ){ isAvailable = available; }
    bool getAvailable(){ return isAvailable; } //gets boolean for isAvailable
    ostream& PrintAvailable( ostream& out );
    Relation CompareTo(Car other){
        if(plateNumber < other.getPlateNumber())
            return Relation::LT;
        else if (plateNumber == other.getPlateNumber())
            return Relation::EQ;
        return Relation::GT;
    }
};

ostream& operator<<(ostream& out, Car c);


#endif /* Car_hpp */
