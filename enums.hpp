//
//  enums.hpp
//  P1CarRental
//
//  Created by Brendon Malouf on 2/17/18.
//  Copyright © 2018 Brendon Malouf. All rights reserved.
//

#ifndef enums_hpp
#define enums_hpp

#include <iostream>
#include <string>
using namespace std;

//----------------------------------------------------------------------------
//enumeration for relations
enum class Relation{
    LT,
    EQ,
    GT,
};

//----------------------------------------------------------------------------
// enum for vehicleTypes
enum vehicleType{
    sedan,
    suv,
    exotic
};

//----------------------------------------------------------------------------
inline istream& operator>> ( istream& in, vehicleType& t )
{
    int val;
    if ( in >> val ) {
        t = static_cast<vehicleType>(val);
    }
    return in;
}


#endif /* enums_hpp */
