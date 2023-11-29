#include "Booking.h"
#include "../BookingBuilder.h"

Booking *Booking::bookingFromJSON(nlohmann::json booking_data) {
   BookingBuilder * builder = (new BookingBuilder)->
           setBookingDate(QDateTime().fromString(QString::fromStdString(booking_data["bookingDate"])))->
           setEndBookingDate(QDateTime().fromString(QString::fromStdString(booking_data["endBookingDate"])))->
           setRoom(HotelRoomInterface::roomFromJSON(booking_data["room"]));
   for (const auto& client : booking_data["clients"])
       builder->appendClient(Client::clientFromJSON(client));
   return builder->getBooking();
}