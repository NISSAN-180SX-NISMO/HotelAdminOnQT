#pragma once
#ifndef HOTEL_BOOKING_H
#define HOTEL_BOOKING_H


#include <QDateTime>
#include "Client/Client.h"
#include "HotelRoom/HotelRoomInterface.h"
#include "QVector"

class Booking {
private:
    friend class BookingBuilder;
    Booking(const QVector<Client *> &clients, HotelRoomInterface *room, QDateTime bookingDate, QDateTime endBookingDate) :
    clients(clients), room(room), bookingDate(bookingDate), endBookingDate(endBookingDate) {}
    QVector<Client*> clients;
    HotelRoomInterface* room;
    QDateTime bookingDate;
    QDateTime endBookingDate;
};
#endif //HOTEL_BOOKING_H
