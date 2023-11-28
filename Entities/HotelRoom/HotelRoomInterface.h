#pragma once
#ifndef HOTEL_HOTELROOMINTERFACE_H
#define HOTEL_HOTELROOMINTERFACE_H


#include <QString>
#include "../Equipment/Equipment.h"

class HotelRoomInterface {
private:
    static int ID;
    QString number;
    int seats;
    bool available;
public:
    HotelRoomInterface(const QString &number, int seats, bool available) : number(number), seats(seats), available(available) { ++ID; }
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

    virtual int getCost() = 0;
    virtual QVector<Equipment *> getEquipments() = 0;
};



#endif //HOTEL_HOTELROOMINTERFACE_H
