#pragma once
#ifndef HOTEL_HOTELROOMBUILDER_H
#define HOTEL_HOTELROOMBUILDER_H

#include "Models/HotelRoomInterface.h"
#include "Models/RegularHotelRoom.h"
#include "Models/BusinessClassHotelRoom.h"
#include "Models/LuxuryHotelRoom.h"

class HotelRoomBuilder {
private:
    QString number;
    int seats = 0;
    bool available = true;
    QVector<Equipment*> equipments;
public:
    HotelRoomBuilder* setNumber(QString number){
        this->number = number;
        return this;
    }

    HotelRoomBuilder* setSeats(int seats){
        this->seats = seats;
        return this;
    }

    HotelRoomBuilder* setAvailable(bool available){
        this->available = available;
        return this;
    }

    HotelRoomBuilder* appendEquipment(Equipment* equipment){
        this->equipments.push_back(equipment);
        return this;
    }

    HotelRoomInterface* getHotelRoom(){
        int equipmentsCost = [](QVector<Equipment*> equipments){
            int sum = 0;
            for (auto equipment : equipments)
                sum += equipment->getCost();
            return sum;
        }(this->equipments);
        if (equipmentsCost <= 5000)
            return new RegularHotelRoom((number[0] != 'R' ? "RG" : "") + number, seats, available, equipments);
        else if (equipmentsCost <= 9000)
            return new BusinessClassHotelRoom((number[0] != 'B' ? "BC" : "") + number, seats, available, equipments);
        else {
            return new LuxuryHotelRoom((number[0] != 'L' ? "LX" : "") + number, seats, available, equipments);
        }
    }

};
#endif //HOTEL_HOTELROOMBUILDER_H
