#pragma once
#ifndef HOTEL_BUSINESSCLASSHOTELROOM_H
#define HOTEL_BUSINESSCLASSHOTELROOM_H

#include "HotelRoom.h"
#include "QVector"

class BusinessClassHotelRoom : public HotelRoom {
public:
    BusinessClassHotelRoom(const QString &number, int seats, bool available, const QVector<Equipment*> &equipments)
            : HotelRoom(number, seats, available, equipments) {}

    HotelRoom *copy() override {
        return new BusinessClassHotelRoom(this->getNumber(), this->getSeats(), this->isAvailable(), this->equipments);
    }

    float getCost() override {
        float cost = BUSINESS_COST;
        for (auto eq: equipments)
            cost += BUSINESS_COEF * eq->getCost();
        return cost;
    }

    QString getEquipments() override {
        QString info;
        for (auto eq : equipments)
            info += eq->getInfo() + "\n";
        return info.remove(info.size() - 1, info.size());
    }
};
#endif //HOTEL_BUSINESSCLASSHOTELROOM_H
