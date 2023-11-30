#include "Booking.h"
#include "../BookingBuilder.h"
#include "../DataBases/DataBase.h"
#include "iostream"


Booking *Booking::bookingFromJSON(nlohmann::json booking_data) {
    HotelRoomInterface* room = DataBase::getRooms()->get(QString::fromStdString(booking_data["room"]["number"]));
    std::cout << "im here\n";
    std::cout << room->getNumber().toStdString() << "\n";
    BookingBuilder * builder = (new BookingBuilder)->
            setBookingDate(QDateTime().fromString(QString::fromStdString(booking_data["bookingDate"]), QString("dd/MM/yyyy hh:mm")))->
            setEndBookingDate(QDateTime().fromString(QString::fromStdString(booking_data["endBookingDate"]), QString("dd/MM/yyyy hh:mm")))->
            setRoom(room);
    for (const auto& client : booking_data["clients"])
        builder->appendClient(Client::clientFromJSON(client));
    return builder->getBooking();
}