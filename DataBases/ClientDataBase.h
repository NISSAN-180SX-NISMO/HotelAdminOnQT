#pragma once
#ifndef HOTEL_CLIENTDATABASE_H
#define HOTEL_CLIENTDATABASE_H

#include "../Entities/Booking.h"
#include "QVector"
#include "DataBaseAdapter.h"

class ClientDataBase : public DataBaseAdapter<Booking> {
private:
    QVector<Booking> bookings;
public:
    void push(Booking booking) override {

    }

    void remove(int ID) override {

    }

    void saveToJSON() override {

    }

    void loadFromJSON() override {

    }
};
#endif //HOTEL_CLIENTDATABASE_H
