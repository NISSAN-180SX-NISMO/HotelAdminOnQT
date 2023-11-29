#pragma once
#ifndef HOTEL_BOOKINGBUILDER_H
#define HOTEL_BOOKINGBUILDER_H

#include "Models/Client.h"
#include "../HotelRoom/Models/HotelRoomInterface.h"
#include "QVector"
#include "QDateTime"
#include "Models/Booking.h"


class BookingBuilder {
private:
    QVector<Client*> clients;
    HotelRoomInterface* room;
    QDateTime bookingDate;
    QDateTime endBookingDate;
public:
    BookingBuilder* setRoom(HotelRoomInterface* room){
        this->room = room;
        return this;
    }
    BookingBuilder* setBookingDate(QDateTime bookingDate){
        this->bookingDate = bookingDate;
        return this;
    }
    BookingBuilder* setEndBookingDate(QDateTime endBookingDate){
        this->endBookingDate = endBookingDate;
        return this;
    }

    BookingBuilder* appendClient(Client* client){
        if (!room) return this;
        if(clients.size() == room->getSeats()) return this;
        clients.push_back(client);
        return this;
    }

    Booking* getBooking(){
        return new Booking(clients, room, bookingDate, endBookingDate);
    }
};
#endif //HOTEL_BOOKINGBUILDER_H
