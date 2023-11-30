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
//        this->push(HotelRoomBuilder().
//                setNumber("111")->
//                setSeats(2)->
//                appendEquipment(new Equipments::TV)->
//                appendEquipment(new Equipments::Bed)->
//                getHotelRoom());
//
//        this->push(HotelRoomBuilder().
//                setNumber("222")->
//                setSeats(2)->
//                appendEquipment(new Equipments::TV)->
//                appendEquipment(new Equipments::Bed)->
//                appendEquipment(new Equipments::WIFI)->
//                appendEquipment(new Equipments::Table)->
//                getHotelRoom());
//
//        this->push(HotelRoomBuilder().
//                setNumber("333")->
//                setSeats(2)->
//                appendEquipment(new Equipments::TV)->
//                appendEquipment(new Equipments::Bed)->
//                appendEquipment(new Equipments::WIFI)->
//                appendEquipment(new Equipments::Table)->
//                appendEquipment(new Equipments::DressingRoom)->
//                getHotelRoom());
//        HotelRoomJSONParser parser(this->rooms);
//        parser.saveToJSON("rooms.json");
        std::cout << "HotelRoomDataBase start\n";
        this->rooms = HotelRoomJSONParser::loadFromJSON("rooms.json");
        std::cout << "HotelRoomDataBase end\n";
    };
public:
    void push(HotelRoomInterface *room) override {
        rooms.push_back(room);
        HotelRoomJSONParser parser(this->rooms);
        parser.saveToJSON("rooms.json");
    }

    void remove(QString number) override {
        for (int i = 0; i < rooms.size(); ++i)
            if (rooms[i]->getNumber() == number)
                rooms.erase(rooms.begin() + i);
        HotelRoomJSONParser parser(this->rooms);
        parser.saveToJSON("rooms.json");
    }


    QVector<HotelRoomInterface *> getAll() override {
        return rooms;
    }

    bool contains(const QString &number) override {
        for(auto room : rooms)
            if (room->getNumber() == number)
                return true;
        return false;
    }

    HotelRoomInterface* get(const QString &number) override {
        std::string short_number = number.toStdString();
        std::regex regex_pattern("\\d{3}");
        std::sregex_iterator iter(short_number.begin(), short_number.end(), regex_pattern);
        std::smatch match = *iter;
        for(auto room : rooms) {
            std::sregex_iterator iter2(room->getNumber().toStdString().begin(), room->getNumber().toStdString().end(), regex_pattern);
            std::smatch match2 = *iter2;
            if (room->getNumber() == number || match2.str() == match.str())
                return room;
        }
        return nullptr;
    }
};
#endif //HOTEL_HOTELROOMDATABASE_H
