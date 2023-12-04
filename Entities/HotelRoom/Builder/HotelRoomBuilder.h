#pragma once
#ifndef HOTEL_HOTELROOMBUILDER_H
#define HOTEL_HOTELROOMBUILDER_H

#include "../Models/HotelRoom.h"
#include "../Models/RegularHotelRoom.h"
#include "../Models/BusinessClassHotelRoom.h"
#include "../Models/LuxuryHotelRoom.h"

class HotelRoomBuilder {
protected:
    QString number;
    int seats = 0;
    bool available = true;
    QVector<Equipment*> equipments;
public:
    HotelRoomBuilder(QString number){
        this->number = number;
    }
    HotelRoomBuilder* setSeats(int seats){
        this->seats = seats;
        return this;
    }

    HotelRoomBuilder* setAvailable(bool available){
        this->available = available;
        return this;
    }

    HotelRoomBuilder* appendEquipment(Equipment* equipment){
        this->equipments.push_back(equipment);
        return this;
    }

    virtual HotelRoom* getHotelRoom() = 0;

};
#endif //HOTEL_HOTELROOMBUILDER_H
