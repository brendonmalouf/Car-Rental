//
//  Car.cpp
//  P1CarRental
//
//  Created by Brendon Malouf on 2/16/18.
//  Copyright © 2018 Brendon Malouf. All rights reserved.
//

#include "Car.hpp"

//----------------------------------------------------------------------------
Car::Car(string pNum, string make, string model, vehicleType vType, double ppd,
         bool isAvail):
plateNumber(pNum), make{make}, model{model}, vType(vType), pricePerDay(ppd),
isAvailable(isAvail){
}

//----------------------------------------------------------------------------
ostream& operator<<(ostream& out, Car c){
    vehicleType vt = c.getType();
    out << "[" << c.getPlateNumber() << "] " << c.getMake() << " "
    << c.getModel() << " (" << typeNames[vt] << ")" << endl;
    return out;
}

//----------------------------------------------------------------------------
ostream& Car::
PrintAvailable( ostream& out ) {
    vehicleType vt = getType();
    out << "[" << getPlateNumber() << "] " << getMake() << " "
    << getModel() << " (" << typeNames[vt] << ") " << endl;
    
    return out;
}



