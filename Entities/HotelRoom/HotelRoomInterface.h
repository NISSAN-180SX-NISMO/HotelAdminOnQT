#pragma once
#ifndef HOTEL_HOTELROOMINTERFACE_H
#define HOTEL_HOTELROOMINTERFACE_H


#include <QString>
#include "../Equipment/Equipment.h"

#define REGULAR_COEF 1.2
#define REGULAR_COST 9000
#define BUSINESS_COEF 1.7
#define BUSINESS_COST 14000
#define LUXURY_COEF 2.5
#define LUXURY_COST 20000

class HotelRoomInterface {
private:
    static int ID;
    QString number;
    int seats;
    bool available;
public:
    HotelRoomInterface(const QString &number, int seats, bool available) : number(number + QString::number(ID)), seats(seats), available(available) { ++ID; }
    const QString &getNumber() const {
        return number;
    }
    void setNumber(const QString &number) {
        HotelRoomInterface::number = number;
    }
    int getSeats() const {
        return seats;
    }
    void setSeats(int seats) {
        HotelRoomInterface::seats = seats;
    }
    bool isAvailable() const {
        return available;
    }
    void setAvailable(bool available) {
        HotelRoomInterface::available = available;
    }
    int getID(){
        return this->ID;
    }

    virtual float getCost() = 0;
    virtual QString getEquipments() = 0;
};



#endif //HOTEL_HOTELROOMINTERFACE_H
