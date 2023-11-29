#pragma once
#ifndef HOTEL_HOTELROOMDATABASE_H
#define HOTEL_HOTELROOMDATABASE_H

#include <fstream>
#include <iostream>
#include "../Entities/HotelRoom/Models/HotelRoomInterface.h"
#include "../Entities/HotelRoom/HotelRoomBuilder.h"
#include "DataBaseAdapter.h"
#include "QVector"
#include "../Entities/HotelRoom/HotelRoomJSONParser.h"

class HotelRoomDataBase : public DataBaseAdapter<HotelRoomInterface*>{
protected:
    QVector<HotelRoomInterface*> rooms;
    friend class DataBase;
    HotelRoomDataBase():DataBaseAdapter<HotelRoomInterface *>(){
        this->push(HotelRoomBuilder().
                setNumber("111")->
                setSeats(2)->
                appendEquipment(new Equipments::TV)->
                appendEquipment(new Equipments::Bed)->
                getHotelRoom());

        this->push(HotelRoomBuilder().
                setNumber("222")->
                setSeats(2)->
                appendEquipment(new Equipments::TV)->
                appendEquipment(new Equipments::Bed)->
                appendEquipment(new Equipments::WIFI)->
                appendEquipment(new Equipments::Table)->
                getHotelRoom());

        this->push(HotelRoomBuilder().
                setNumber("333")->
                setSeats(2)->
                appendEquipment(new Equipments::TV)->
                appendEquipment(new Equipments::Bed)->
                appendEquipment(new Equipments::WIFI)->
                appendEquipment(new Equipments::Table)->
                appendEquipment(new Equipments::DressingRoom)->
                getHotelRoom());

        HotelRoomJSONParser parser(this->rooms);
        parser.saveToJSON("rooms.json");
        //this->rooms = HotelRoomJSONParser::loadFromJSON("rooms.json");
    };
public:
    void push(HotelRoomInterface *room) override {
        rooms.push_back(room);
    }

    void remove(int ID) override {
        for (int i = 0; i < rooms.size(); ++i)
            if (rooms[i]->getID() == ID)
                rooms.erase(rooms.begin() + i);
    }

    void saveToJSON() override {
        // TODO
    }

    void loadFromJSON() override {
        // TODO
    }

    QVector<HotelRoomInterface *> getAll() override {
        return rooms;
    }
};
#endif //HOTEL_HOTELROOMDATABASE_H
