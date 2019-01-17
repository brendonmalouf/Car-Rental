//
//  ReservationArrayList.cpp
//  P1CarRental
//
//  Created by Brendon Malouf on 2/26/18.
//  Copyright © 2018 Brendon Malouf. All rights reserved.
//

#include "ReservationArrayList.hpp"

//----------------------------------------------------------------------------
ostream& operator<<(ostream& out, ArrayList& a){
    a.rResetList();
    out << "Reservation List: \n";
    for(int i = 0; i < a.rGetLength(); ++i){
        int index = i;
        out << index + 1 << ". " << a.rGetNextItem();
    }
    out << endl;
    return out;
}

//----------------------------------------------------------------------------
void ArrayList::rMakeEmpty(){
    length = 0;
}

//----------------------------------------------------------------------------
void ArrayList::rPutItem(Reservation res){
    data[length++] = res;
}

//----------------------------------------------------------------------------
Reservation ArrayList::rGetItem(Reservation res, bool& found){
    found = false;
    for(int i = 0; i < length; ++i){
        if (data[i].CompareTo(res) == Relation::EQ) {
            res = data[i];
            found = true;
            break;
        }
    }
    return res;
}

//----------------------------------------------------------------------------
void ArrayList::rDeleteItem(Reservation res){
    for(int i = 0; i < length; ++i){
        if (data[i].CompareTo(res) == Relation::EQ)
            data[i] = data[--length];
    }
}

//----------------------------------------------------------------------------
void ArrayList::rResetList(){
    currentPos = 0;
}

//----------------------------------------------------------------------------
Reservation ArrayList::rGetNextItem(){
    if(currentPos < length)
        return data[currentPos++];
    
    throw "Out of Range";
}

//----------------------------------------------------------------------------
int ArrayList::rGetLength(){
    return length;
}
