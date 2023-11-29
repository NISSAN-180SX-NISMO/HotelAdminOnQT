
#include <iostream>
#include "HotelRoomJSONParser.h"

QVector<HotelRoomInterface *> HotelRoomJSONParser::loadFromJSON(QString filename) {
    // Загрузка из файла
    std::ifstream input_file(filename.toStdString());
    nlohmann::json loaded_data;
    input_file >> loaded_data;
    input_file.close();

    QVector<HotelRoomInterface *> rooms;
    std::cout << "1\n";
    for (const auto& room_data : loaded_data) {
        HotelRoomInterface* room = HotelRoomJSONParser::roomFromJSON(room_data);
        if (room) {
            rooms.push_back(room);
        } else {
            // Обработка ошибок, если тип не распознан
        }
    }
    return rooms;
}

HotelRoomInterface *HotelRoomJSONParser::roomFromJSON(nlohmann::json room_data) {

    HotelRoomBuilder* builder =
            (new HotelRoomBuilder())->
                    setNumber(QString::fromStdString(room_data["number"]))->
                    setSeats(room_data["seats"])->
                    setAvailable(room_data["available"]);
    for (const auto& equipment_data : room_data["equipments"]) {
        Equipment* equipment = Equipment::fromJSON(equipment_data);
        if (equipment) {
            builder->appendEquipment(equipment);
        } else {
            // Обработка ошибок, если тип не распознан
        }
    }
    return builder->getHotelRoom();
}
