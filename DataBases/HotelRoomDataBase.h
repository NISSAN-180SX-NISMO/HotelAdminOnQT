#pragma once
#ifndef HOTEL_HOTELROOMDATABASE_H
#define HOTEL_HOTELROOMDATABASE_H

#include "../Entities/HotelRoom/HotelRoomInterface.h"
#include "DataBaseAdapter.h"
#include "QVector"

class HotelRoomDataBase : public DataBaseAdapter<HotelRoomInterface*>{
private:
    QVector<HotelRoomInterface*> bookings;
public:
    void push(HotelRoomInterface *room) override {

    }

    void remove(int ID) override {

    }

    void saveToJSON() override {

    }

    void loadFromJSON() override {

    }
};
#endif //HOTEL_HOTELROOMDATABASE_H
