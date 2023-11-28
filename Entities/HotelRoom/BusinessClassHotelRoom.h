#pragma once
#ifndef HOTEL_BUSINESSCLASSHOTELROOM_H
#define HOTEL_BUSINESSCLASSHOTELROOM_H

#include "HotelRoomInterface.h"
#include "QVector"

class BusinessClassHotelRoom : public HotelRoomInterface {
    QVector<Equipment*> equipments;
public:
    BusinessClassHotelRoom(const QString &number, int seats, bool available, const QVector<Equipment*> &equipments)
            : HotelRoomInterface(number, seats, available), equipments(equipments) {}
    int getCost() override {
        return 0;
    }

    QVector<Equipment*> getEquipments() override {
        return QVector<Equipment*>();
    }
};
#endif //HOTEL_BUSINESSCLASSHOTELROOM_H
