//
//  CarLinkedList.hpp
//  P1CarRental
//
//  Created by Brendon Malouf on 2/16/18.
//  Copyright © 2018 Brendon Malouf. All rights reserved.
//

#ifndef CarLinkedList_hpp
#define CarLinkedList_hpp

#include <iostream>
#include <string>
#include "Car.hpp"
using namespace std;

struct Node{
    Car data;
    Node* next;
};

//----------------------------------------------------------------------------
//Contains the attributes for the list of cars
class LinkedList{
private:
    int length;
    Node* currentPos;
    Node* head;
    
public:
    LinkedList(): currentPos{0}, length{0}{}
    ~LinkedList();
    void makeEmpty();
    void putCar(Car car);
    Car& getCar(Car car, bool& found);
    void deleteCar(Car car);
    void resetList();
    Car getNextCar();
    Car& getCarAtIndex(int index);
    int getLength();
    void printAvailCar( ostream& out ); 
    
};

ostream& operator<<(ostream& out, LinkedList& l);

#endif /* CarLinkedList_hpp */
