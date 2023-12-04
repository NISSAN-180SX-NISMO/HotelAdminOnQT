#pragma once
#ifndef HOTEL_HOTELROOMDATABASE_H
#define HOTEL_HOTELROOMDATABASE_H

#include <fstream>
#include <iostream>
#include "../Entities/HotelRoom/Models/HotelRoom.h"
#include "../Entities/HotelRoom/Builder/HotelRoomBuilder.h"
#include "DataBaseRepository.h"
#include "QVector"
#include "../Entities/HotelRoom/HotelRoomJSONParser.h"

class HotelRoomDataBase : public DataBaseRepository<HotelRoom*>{
protected:
    QVector<HotelRoom*> rooms;
    friend class DataBase;
    HotelRoomDataBase(): DataBaseRepository<HotelRoom *>(){
        this->rooms = HotelRoomJSONParser::loadFromJSON("rooms.json");
    };
public:
    void push(HotelRoom *room) override {
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


    QVector<HotelRoom *> getAll() override {
        return rooms;
    }

    bool contains(const QString &number) override {
        for(auto room : rooms)
            if (room->getNumber() == number)
                return true;
        return false;
    }

    HotelRoom* get(const QString &number) override {
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
