#pragma once
#ifndef HOTEL_LUXURYHOTELROOM_H
#define HOTEL_LUXURYHOTELROOM_H

#include <QVector>
#include "HotelRoomInterface.h"

class LuxuryHotelRoom : public HotelRoomInterface {
public:
    LuxuryHotelRoom(const QString &number, int seats, bool available, const QVector<Equipment*> &equipments)
            : HotelRoomInterface(number, seats, available, equipments) {}

    HotelRoomInterface *copy() override {
        return new LuxuryHotelRoom(this->getNumber(), this->getSeats(), this->isAvailable(), this->equipments);
    }

    float getCost() override {
        float cost = LUXURY_COST;
        for (auto eq: equipments)
            cost += LUXURY_COEF * eq->getCost();
        return cost;
    }

    QString getEquipments() override {
        QString info;
        for (auto eq : equipments)
            info += eq->getInfo() + "\n";
        return info.remove(info.size() - 1, info.size());
    }
};
#endif //HOTEL_LUXURYHOTELROOM_H
