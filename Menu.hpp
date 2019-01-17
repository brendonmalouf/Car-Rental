//
//  Menu.hpp
//  P1CarRental
//
//  Created by Brendon Malouf on 2/22/18.
//  Copyright © 2018 Brendon Malouf. All rights reserved.
//

#ifndef Menu_hpp
#define Menu_hpp

#include "Car.hpp"
#include "CarLinkedList.hpp"
#include "Reservation.hpp"
#include "ReservationArrayList.hpp"

class Menu{
public:
    void runMenu();
    void printMenu();
    void listCars();
    void addCar();
    void removeCar();
    void listRes();
    void addRes();
    void cancelRes();
};

#endif /* Menu_hpp */
