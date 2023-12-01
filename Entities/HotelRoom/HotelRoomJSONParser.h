#pragma once
#ifndef HOTEL_HOTELROOMJSONPARSER_H
#define HOTEL_HOTELROOMJSONPARSER_H

#include <QVector>
#include "Models/HotelRoom.h"
#include "HotelRoomBuilder.h"
#include "json.hpp"
#include "fstream"

class HotelRoomJSONParser {
private:
    QVector<HotelRoom*> rooms;

public:
    HotelRoomJSONParser(QVector<HotelRoom*> rooms) {
        this->rooms = rooms;
    }
    void saveToJSON(QString filename){
        nlohmann::json json_data;
        for (const auto& room : rooms) {
            json_data.push_back(room->toJSON());
        }

        std::ofstream file(filename.toStdString());
        file << json_data.dump(2);
        file.close();
    }
    static QVector<HotelRoom*> loadFromJSON(QString filename);
};



#endif //HOTEL_HOTELROOMJSONPARSER_H
