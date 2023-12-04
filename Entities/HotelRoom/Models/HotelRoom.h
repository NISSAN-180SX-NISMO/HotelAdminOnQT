#pragma once
#ifndef HOTEL_HOTELROOM_H
#define HOTEL_HOTELROOM_H


#include <QString>
#include <QList>
#include "../../Equipment/Equipment.h"
#include "json.hpp"
#include <regex>

#define REGULAR_COEF 1.2
#define REGULAR_COST 9000
#define BUSINESS_COEF 1.7
#define BUSINESS_COST 14000
#define LUXURY_COEF 2.5
#define LUXURY_COST 20000

class HotelRoom {
private:
    static int ID;
    QString number;
    int seats;
    bool available;
protected:
    QVector<Equipment*> equipments;
public:
    HotelRoom(const QString &number, int seats, bool available, QVector<Equipment*> equipments)
    :
    number(number + "-" + QString::number(ID)),
    seats(seats), available(available),
    equipments(equipments)
    { ++ID; }

    const QString &getNumber() const {
        return number;
    }
    void setNumber(const QString &number) {
        HotelRoom::number = number;
    }
    int getSeats() const {
        return seats;
    }
    void setSeats(int seats) {
        HotelRoom::seats = seats;
    }
    bool isAvailable() const {
        return available;
    }
    void setAvailable(bool available) {
        HotelRoom::available = available;
    }
    int getID(){
        return this->ID;
    }

    nlohmann::json toJSON() const {
        nlohmann::json data;
        std::string number = getNumber().toStdString();
        std::regex regex_pattern("[RBL]\\d{3}");
        std::sregex_iterator iter(number.begin(), number.end(), regex_pattern);
        std::smatch match = *iter;

        data["number"] = match.str();
        data["seats"] = getSeats();
        data["available"] = isAvailable();
        nlohmann::json eq_json;
        for (const auto& equipment : equipments) {
            eq_json.push_back(equipment->toJSON());
        }
        data["equipments"] = eq_json;
        return data;
    }
    static HotelRoom* roomFromJSON(nlohmann::json room_data);

    virtual HotelRoom* copy() = 0;
    virtual float getCost() = 0;
    virtual QString getEquipments() = 0;
};



#endif //HOTEL_HOTELROOM_H
