//
//  Reservation.hpp
//  P1CarRental
//
//  Created by Brendon Malouf on 2/17/18.
//  Copyright © 2018 Brendon Malouf. All rights reserved.
//

#ifndef Reservation_hpp
#define Reservation_hpp

#include <iostream>
#include <string>
#include "enums.hpp"

using namespace std;

class Reservation{
private:
    string name;
    string carRented; //license plate number (key)
public:
    Reservation(): name{""}, carRented{""}{};
    Reservation(string name, string cRented);
    string getName(){ return name;} //gets name reservations under
    string getRentedCar(){ return carRented;} //gets license plate number 
    Relation CompareTo(Reservation other){
        if(carRented < other.getRentedCar())
            return Relation::LT;
        else if (carRented == other.getRentedCar())
            return Relation::EQ;
        return Relation::GT;
    }
};

ostream& operator<<(ostream& out, Reservation r);

#endif /* Reservation_hpp */
