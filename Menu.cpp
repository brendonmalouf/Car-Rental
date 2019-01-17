//
//  Menu.cpp
//  P1CarRental
//
//  Created by Brendon Malouf on 2/22/18.
//  Copyright © 2018 Brendon Malouf. All rights reserved.
//

#include "Menu.hpp"

LinkedList carList = LinkedList();
ArrayList resList = ArrayList();

//----------------------------------------------------------------------------
//puts printMenu in infinite for loop
void Menu::
runMenu(){
    for(;;){
        printMenu();
    }
}

//----------------------------------------------------------------------------
//Prints menu
void Menu::
printMenu(){
    int menuChoice;
    string junk;
    Menu menu;
    
    cout << "-------------------------------------------" << endl;
    cout << "XYZ Car Rental" << endl;
    cout << "-------------------------------------------" << endl;
    cout << "1. List all cars" << endl;
    cout << "2. Add car to inventory" << endl;
    cout << "3. Remove car from inventory" << endl;
    cout << "4. List all reservations" << endl;
    cout << "5. Add a reservation" << endl;
    cout << "6. Cancel reservation" << endl;
    cout << "7. Exit" << endl;
    cout << "\nPlease enter your selection: ";
    cin >> menuChoice;
    switch (menuChoice) {
        case 1:
            menu.listCars();
            break;
        case 2:
            menu.addCar();
            break;
        case 3:
            menu.removeCar();
            break;
        case 4:
            menu.listRes();
            break;
        case 5:
            menu.addRes();
            break;
        case 6:
            menu.cancelRes();
            break;
        case 7:
            cout << "Thank you for visiting XYZ Car Rental!\n";
            exit(0);
            break;
        default:
            break;
    }
}

//----------------------------------------------------------------------------
void Menu::
listCars(){
    cout << carList << endl;
}

//----------------------------------------------------------------------------
void Menu::
addCar(){
    Car c;
    string inPNum;
    string inMake;
    string inModel;
    vehicleType inType;
    double inPPD;
    bool availability = true;
    
    cout << "Please enter the following information for the car you wish to "
    << "add:" << endl;
    
    cout << "Plate number: ";
    cin >> inPNum;
    c.getPlateNumber() = inPNum;
    
    cout << "Make: ";
    cin >> inMake;
    
    cout << "Model: ";
    cin >> inModel;
    
    cout << "Type (0 = sedan, 1 = suv, 2 = exotic): ";
    cin >> inType;
    while ( inType < vehicleType::sedan || inType > vehicleType::exotic) {
        cout << "invalid input..." << endl;
        cout << "prompt again" << endl;
        cin >> inType;
    }
    
    cout << "Price per day to rent: $ ";
    cin >> inPPD;
    
    c = Car(inPNum, inMake, inModel, inType, inPPD, availability);
    carList.putCar(c);
}

//----------------------------------------------------------------------------
void Menu::
removeCar(){
    Car c;
    string inPNum;
    cout << "Please input the license plate number of the car you would like"
    << " to remove: ";
    cin >> inPNum;
    carList.deleteCar(Car(inPNum,"","",sedan,0,true));
}

//----------------------------------------------------------------------------
void Menu::
listRes(){
    cout << resList << endl;
}

//----------------------------------------------------------------------------
void Menu::
addRes(){
    string name;
    int choice;
    int cancel;
    string plateNumber;
    Car c;
    
    cout << "Please enter your name: ";
    cin >> name;
    carList.printAvailCar(cout);
    cancel = carList.getLength() + 1;
    cout << cancel << ". Cancel" << endl;
    cout << "\nPlease enter the number of the car you wish to reserve: ";
    cin >> choice;
    if (choice == cancel) return;
    else{
        c = carList.getCarAtIndex(choice);
        //c.setAvailable(false);
        carList.deleteCar(Car(c.getPlateNumber(),"","",sedan,0,true));
        carList.putCar( Car( c.getPlateNumber(),c.getMake(), c.getModel(),
                            c.getType(),c.getPPD(), false ) );
        //cout << "To test setter function: " << c.getAvailable() << endl;
        plateNumber = c.getPlateNumber();
        Reservation r(name, plateNumber);
        resList.rPutItem(r);
    }
}

//----------------------------------------------------------------------------
void Menu::
cancelRes(){
    string name;
    Reservation r;
    Car c;
    bool temp = false;
    
    cout << "Please enter the exact name of your reservation: ";
    cin >> name;
    r = Reservation(name, "");
    resList.rDeleteItem( resList.rGetItem(r, temp) );
    c.setAvailable( true );
}
