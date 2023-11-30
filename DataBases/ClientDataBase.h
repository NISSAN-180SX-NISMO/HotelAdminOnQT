#pragma once
#ifndef HOTEL_CLIENTDATABASE_H
#define HOTEL_CLIENTDATABASE_H

#include "../Entities/Booking/Models/Booking.h"
#include "QVector"
#include "DataBaseAdapter.h"
#include "../Entities/Booking/BookingBuilder.h"


#include "../Entities/HotelRoom/HotelRoomBuilder.h"
#include "../Entities/Booking/BookingJSONParser.h"

class ClientDataBase : public DataBaseAdapter<Booking*> {
protected:
    QVector<Booking*> bookings;
    friend class DataBase;
    ClientDataBase():DataBaseAdapter<Booking*>(){

//        this->push((new BookingBuilder())->
//                setRoom(HotelRoomBuilder().
//                        setNumber("111")->
//                        setSeats(2)->
//                        appendEquipment(new Equipments::TV)->
//                        appendEquipment(new Equipments::Bed)->
//                        getHotelRoom())->
//                appendClient(new Client("Семен"))->
//                appendClient(new Client("Антон"))->
//                setBookingDate(QDateTime(QDate(2021, 1, 12), QTime(14, 30)))->
//                setEndBookingDate(QDateTime(QDate(2021, 3, 12), QTime(14, 30)))
//        ->getBooking());

//        BookingJSONParser parser(bookings);
//        parser.saveToJSON("bookings.json");

this->bookings = BookingJSONParser::loadFromJSON("bookings.json");
    }

public:
    void push(Booking* booking) override {
        this->bookings.push_back(booking);
    }

    void remove(QString name) override {

    }

    QVector<Booking*> getAll() override {
        return this->bookings;
    }

    bool contains(const QString &name) override {
        for(auto booking : bookings)
            for (auto client : booking->getClients())
                if (client->getName() == name)
                    return true;
        return false;
    }
};


#endif //HOTEL_CLIENTDATABASE_H
