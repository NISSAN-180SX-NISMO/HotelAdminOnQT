//
// Created by user on 28.11.2023.
//

#include "HotelRoom.h"
#include "../Builder/HotelRoomBuilder.h"
#include "../Builder/HotelRoomDirector.h"

int HotelRoom::ID = 0;

HotelRoom *HotelRoom::roomFromJSON(nlohmann::json room_data) {
    HotelRoomDirector director(QString::fromStdString(room_data["number"]));

    HotelRoomBuilder* builder = director.getBuilder()->
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