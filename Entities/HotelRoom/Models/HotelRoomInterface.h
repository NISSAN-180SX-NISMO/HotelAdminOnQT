#pragma once
#ifndef HOTEL_HOTELROOMINTERFACE_H
#define HOTEL_HOTELROOMINTERFACE_H


#include <QString>
#include <QList>
#include "../../Equipment/Equipment.h"
#include "../../../json.hpp"

#define REGULAR_COEF 1.2
#define REGULAR_COST 9000
#define BUSINESS_COEF 1.7
#define BUSINESS_COST 14000
#define LUXURY_COEF 2.5
#define LUXURY_COST 20000

class HotelRoomInterface {
private:
    static int ID;
    QString number;
    int seats;
    bool available;
protected:
    QVector<Equipment*> equipments;
public:
    HotelRoomInterface(const QString &number, int seats, bool available, QVector<Equipment*> equipments)
    :
    number(number + "-" + QString::number(ID)),
    seats(seats), available(available),
    equipments(equipments)
    { ++ID; }

    const QString &getNumber() const {
        return number;
    }
    void setNumber(const QString &number) {
        HotelRoomInterface::number = number;
    }
    int getSeats() const {
        return seats;
    }
    void setSeats(int seats) {
        HotelRoomInterface::seats = seats;
    }
    bool isAvailable() const {
        return available;
    }
    void setAvailable(bool available) {
        HotelRoomInterface::available = available;
    }
    int getID(){
        return this->ID;
    }

    virtual float getCost() = 0;
    virtual QString getEquipments() = 0;
    nlohmann::json toJSON() const {
        nlohmann::json data;
        data["number"] = getNumber().toStdString();
        data["seats"] = getSeats();
        data["available"] = isAvailable();
        nlohmann::json eq_json;
        for (const auto& equipment : equipments) {
            eq_json.push_back(equipment->toJSON());
        }
        data["equipments"] = eq_json;
        return data;
    }
};



#endif //HOTEL_HOTELROOMINTERFACE_H
