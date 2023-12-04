#pragma once
#ifndef HOTEL_CLIENTDATABASE_H
#define HOTEL_CLIENTDATABASE_H

#include "../Entities/Booking/Models/Booking.h"
#include "QVector"
#include "DataBaseRepository.h"
#include "../Entities/Booking/BookingBuilder.h"


#include "../Entities/HotelRoom/Builder/HotelRoomBuilder.h"
#include "../Entities/Booking/BookingJSONParser.h"
#include "iostream"

class ClientDataBase : public DataBaseRepository<Booking*> {
protected:
    QVector<Booking*> bookings;
    friend class DataBase;
    ClientDataBase(): DataBaseRepository<Booking*>(){
        this->bookings = BookingJSONParser::loadFromJSON("bookings.json");
    }

public:
    void push(Booking* booking) override {
        this->bookings.push_back(booking);
        BookingJSONParser parser(bookings);
        parser.saveToJSON("bookings.json");
    }

    void remove(QString number) override {
        for (int i = 0; i < bookings.size(); ++i)
            if (bookings[i]->getRoom()->getNumber() == number)
                bookings.remove(i);
        BookingJSONParser parser(bookings);
        parser.saveToJSON("bookings.json");
    }

    QVector<Booking*> getAll() override {
        return this->bookings;
    }

    bool contains(const QString &number) override {
        for(auto booking : bookings)
            if (booking->getRoom()->getNumber() == number) {
                return true;
            }
        return false;
    }

    Booking *get(const QString &number) override {
        for(auto booking : bookings)
            if (booking->getRoom()->getNumber() == number)
                return booking;
        return nullptr;
    }
};


#endif //HOTEL_CLIENTDATABASE_H
