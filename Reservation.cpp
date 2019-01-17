//
//  Reservation.cpp
//  P1CarRental
//
//  Created by Brendon Malouf on 2/17/18.
//  Copyright © 2018 Brendon Malouf. All rights reserved.
//

#include "Reservation.hpp"

Reservation::
Reservation(string name, string cRented): name{name}, carRented{cRented}{}

ostream& operator<<(ostream& out, Reservation r){
    out << r.getName() << " rented ["
    << r.getRentedCar() << "]" << endl;
    return out;
}
