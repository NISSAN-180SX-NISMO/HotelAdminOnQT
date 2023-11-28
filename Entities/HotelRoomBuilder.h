#pragma once
#ifndef HOTEL_HOTELROOMBUILDER_H
#define HOTEL_HOTELROOMBUILDER_H

#include "HotelRoom/HotelRoomInterface.h"
#include "HotelRoom/RegularHotelRoom.h"
#include "HotelRoom/BusinessClassHotelRoom.h"
#include "HotelRoom/LuxuryHotelRoom.h"

class HotelRoomBuilder {
private:
    QString number;
    int seats = 0;
    bool available = false;
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
            return new RegularHotelRoom("RG" + number, seats, true, equipments);
        else if (equipmentsCost <= 9000)
            return new BusinessClassHotelRoom("BC" + number, seats, true, equipments);
        else {
            return new LuxuryHotelRoom("LX" + number, seats, true, equipments);
        }
    }

};
#endif //HOTEL_HOTELROOMBUILDER_H
