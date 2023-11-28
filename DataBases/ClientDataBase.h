#pragma once
#ifndef HOTEL_CLIENTDATABASE_H
#define HOTEL_CLIENTDATABASE_H

#include "../Entities/Booking.h"
#include "QVector"
#include "DataBaseAdapter.h"

class ClientDataBase : public DataBaseAdapter<Booking> {
protected:
    QVector<Booking> bookings;;
    friend class DataBase;
    ClientDataBase():DataBaseAdapter<Booking>(){
        loadFromJSON();
    }

public:
    void push(Booking booking) override {

    }

    void remove(int ID) override {

    }

    void saveToJSON() override {

    }

    void loadFromJSON() override {

    }

    QVector<Booking> getAll() override {
        return QVector<Booking>();
    }
};


#endif //HOTEL_CLIENTDATABASE_H
