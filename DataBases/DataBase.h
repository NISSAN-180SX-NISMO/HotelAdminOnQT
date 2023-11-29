#pragma once
#ifndef HOTEL_DATABASE_H
#define HOTEL_DATABASE_H

#include "ClientDataBase.h"
#include "HotelRoomDataBase.h"

class DataBase {
private:
    ClientDataBase *clients = nullptr;
    HotelRoomDataBase *rooms = nullptr;
public:
    ClientDataBase* getClients(){
        if (!clients) clients = new ClientDataBase();
        return clients;
    }
    HotelRoomDataBase* getRooms(){
        if (!rooms) rooms = new HotelRoomDataBase();
        return rooms;
    }
};
#endif //HOTEL_DATABASE_H
