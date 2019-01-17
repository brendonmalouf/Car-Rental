//
//  ReservationArrayList.hpp
//  P1CarRental
//
//  Created by Brendon Malouf on 2/26/18.
//  Copyright © 2018 Brendon Malouf. All rights reserved.
//

#ifndef ReservationArrayList_hpp
#define ReservationArrayList_hpp

#define MAX_ELEMS 100

#include "Reservation.hpp"
#include "Car.hpp"

class ArrayList{
private:
    int currentPos;
    int length;
    Reservation data[MAX_ELEMS];
    
public:
    ArrayList(): currentPos{0}, length{0}{}
    void rMakeEmpty();
    void rPutItem(Reservation res);
    Reservation rGetItem(Reservation res, bool& found); 
    void rDeleteItem(Reservation res);
    void rResetList();
    Reservation rGetNextItem();
    int rGetLength();
};

ostream& operator<<(ostream& out, ArrayList& a);

#endif /* ReservationArrayList_hpp */
