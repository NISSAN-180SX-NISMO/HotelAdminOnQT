//
// Created by user on 28.11.2023.
//

#include "Equipment.h"
int Equipment::ID = 0;

Equipment* Equipment::fromJSON(const nlohmann::json &data) {
    if (data["type"] == "TV") return new Equipments::TV();
    else if (data["type"] == "Table") return new Equipments::Table();
    else if (data["type"] == "WIFI") return new Equipments::WIFI;
    else if (data["type"] == "Bed") return new Equipments::Bed();
    else if (data["type"] == "DressingRoom") return new Equipments::DressingRoom();
    else if (data["type"] == "Armchair") return new Equipments::Armchair();
    else if (data["type"] == "Bathroom") return new Equipments::Bathroom();
}
