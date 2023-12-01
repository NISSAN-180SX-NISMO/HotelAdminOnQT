#pragma once
#ifndef HOTEL_BOOKING_H
#define HOTEL_BOOKING_H


#include <QDateTime>
#include "Client.h"
#include "json.hpp"
#include "../../HotelRoom/Models/HotelRoom.h"
#include "QVector"

class Booking {
private:
    friend class BookingBuilder;
    Booking(const QVector<Client *> &clients, HotelRoom *room, QDateTime bookingDate, QDateTime endBookingDate) :
    clients(clients), room(room), bookingDate(bookingDate), endBookingDate(endBookingDate) {}
    QVector<Client*> clients;
    HotelRoom* room;
    QDateTime bookingDate;
    QDateTime endBookingDate;
public:
    const QVector<Client *> &getClients() const {
        return clients;
    }

    HotelRoom *getRoom() const {
        return room;
    }

    const QDateTime &getBookingDate() const {
        return bookingDate;
    }

    const QDateTime &getEndBookingDate() const {
        return endBookingDate;
    }

    nlohmann::json toJSON() const {
        nlohmann::json data;
        data["room"] = getRoom()->toJSON();
        data["bookingDate"] = getBookingDate().toString("dd/MM/yyyy hh:mm").toStdString();
        data["endBookingDate"] = getEndBookingDate().toString("dd/MM/yyyy hh:mm").toStdString();
        nlohmann::json clients_json;
        for (const auto& client : clients)
            clients_json.push_back(client->toJSON());
        data["clients"] = clients_json;
        return data;
    }
    static Booking* bookingFromJSON(nlohmann::json booking_data);
};
#endif //HOTEL_BOOKING_H
