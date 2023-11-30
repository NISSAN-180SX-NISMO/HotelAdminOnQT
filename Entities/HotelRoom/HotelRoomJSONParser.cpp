
#include <iostream>
#include "HotelRoomJSONParser.h"

QVector<HotelRoomInterface *> HotelRoomJSONParser::loadFromJSON(QString filename) {
    std::ifstream input_file(filename.toStdString());
    nlohmann::json loaded_data;
    input_file >> loaded_data;
    input_file.close();
    QVector<HotelRoomInterface *> rooms;
    for (const auto& room_data : loaded_data) {
        HotelRoomInterface* room = HotelRoomInterface::roomFromJSON(room_data);
        if (room) {
            rooms.push_back(room);
        } else {
            // Обработка ошибок, если тип не распознан
        }
    }
    return rooms;
}


