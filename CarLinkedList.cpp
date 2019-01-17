//
//  CarLinkedList.cpp
//  P1CarRental
//
//  Created by Brendon Malouf on 2/16/18.
//  Copyright © 2018 Brendon Malouf. All rights reserved.
//

#include "CarLinkedList.hpp"

//----------------------------------------------------------------------------
ostream& operator<<(ostream& out, LinkedList& l){
    l.resetList();
    out << "All cars: \n";
    for(int i = 0; i < l.getLength(); ++i){
        int index = i;
        out << index + 1 << ". " << l.getNextCar();
    }
    out << endl;
    return out;
}

//----------------------------------------------------------------------------
void LinkedList::makeEmpty(){
    Node* temp;
    while(head != nullptr){
        temp = head;
        head = head->next;
        delete temp;
    }
    length = 0;
}

//----------------------------------------------------------------------------
void LinkedList::putCar(Car car){
    Node* temp = new Node;
    temp->data = car;
    temp->next = head;
    head = temp;
    length++;
}

//----------------------------------------------------------------------------
Car& LinkedList::getCar(Car car, bool &found){
    found = false;
    Node* temp = head;
    while(temp != nullptr){
        if(temp->data.CompareTo(car) == Relation::EQ){
            found = true;
            car = temp->data;
            break;
        }
        temp = temp->next;
    }
    return car;
}

//----------------------------------------------------------------------------
void LinkedList::deleteCar(Car car){
    if( car.getAvailable() == false ){
        cout << "A user has rented it." << endl;
        return;
    }
    if(head == nullptr){
        cout << "A user has rented it." << endl;
        return;
    }
    
    Node* temp;
    if(head->data.CompareTo(car) == Relation::EQ){
        temp = head->next;
        delete head;
        head = temp;
        length--;
    }else{
        temp = head;
        while(temp->next != nullptr){
            if(temp->next->data.CompareTo(car) == Relation::EQ){
                Node* temp2 = temp->next;
                temp->next = temp->next->next;
                delete temp2;
                length--;
                return;
            }
            temp = temp->next;
        }
    }
}

//----------------------------------------------------------------------------
void LinkedList::resetList(){
    currentPos = NULL;
}

//----------------------------------------------------------------------------
Car LinkedList::getNextCar(){
    if(currentPos == NULL)
        currentPos = head;
    else
        currentPos = currentPos->next;
    
    return currentPos->data;
}

//----------------------------------------------------------------------------
Car& LinkedList::
getCarAtIndex(int index){
    currentPos = head;
    for(int i = 0; i < index; i++){
        currentPos = head->next;
    }
    return currentPos->data;
}

//----------------------------------------------------------------------------
int LinkedList::getLength(){
    return length;
}

//----------------------------------------------------------------------------
void LinkedList::
printAvailCar( ostream& out ){
    resetList();
    out << "Available cars: \n";
    for(int i = 0; i < getLength(); ++i){
        int index = i;
        out << index + 1 << ". ";
        Car temp = getCarAtIndex(index);
        if(temp.getAvailable() == true)
            temp.PrintAvailable( out );
    }
    out << endl;
}

//----------------------------------------------------------------------------
LinkedList::~LinkedList(){
    makeEmpty();
}
