#pragma once
#ifndef HOTEL_LUXURYHOTELROOM_H
#define HOTEL_LUXURYHOTELROOM_H

#include <QVector>
#include "HotelRoomInterface.h"

class LuxuryHotelRoom : public HotelRoomInterface {
    QVector<Equipment*> equipments;
public:
    LuxuryHotelRoom(const QString &number, int seats, bool available, const QVector<Equipment*> &equipments)
            : HotelRoomInterface(number, seats, available), equipments(equipments) {}
    int getCost() override {
        return 0;
    }

    QVector<Equipment*> getEquipments() override {
        return QVector<Equipment*>();
    }
};
#endif //HOTEL_LUXURYHOTELROOM_H
