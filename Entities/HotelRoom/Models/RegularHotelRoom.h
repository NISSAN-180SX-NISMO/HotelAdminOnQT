#pragma once
#ifndef HOTEL_REGULARHOTELROOM_H
#define HOTEL_REGULARHOTELROOM_H

#include <QVector>
#include "HotelRoom.h"

class RegularHotelRoom : public HotelRoom {
public:
    RegularHotelRoom(const QString &number, int seats, bool available, const QVector<Equipment*> &equipments)
            : HotelRoom(number, seats, available, equipments) {}

    HotelRoom *copy() override {
        return new RegularHotelRoom(this->getNumber(), this->getSeats(), this->isAvailable(), this->equipments);
    }

    float getCost() override {
        float cost = REGULAR_COST;
        for (auto eq: equipments)
            cost += REGULAR_COEF * eq->getCost();
        return cost;
    }

    QString getEquipments() override {
        QString info;
        for (auto eq : equipments)
            info += eq->getInfo() + "\n";
        return info.remove(info.size() - 1, info.size());
    }
};
#endif //HOTEL_REGULARHOTELROOM_H
