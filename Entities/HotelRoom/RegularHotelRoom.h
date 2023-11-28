#pragma once
#ifndef HOTEL_REGULARHOTELROOM_H
#define HOTEL_REGULARHOTELROOM_H

#include <QVector>
#include "HotelRoomInterface.h"

class RegularHotelRoom : public HotelRoomInterface {
private:
    QVector<Equipment*> equipments;
public:
    RegularHotelRoom(const QString &number, int seats, bool available, const QVector<Equipment*> &equipments)
            : HotelRoomInterface(number, seats, available), equipments(equipments) {}

    int getCost() override {
        return 0;
    }

    QVector<Equipment*> getEquipments() override {
        return QVector<Equipment*>();
    }
};
#endif //HOTEL_REGULARHOTELROOM_H
