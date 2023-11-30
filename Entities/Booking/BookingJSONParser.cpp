#include <iostream>
#include "BookingJSONParser.h"

QVector<Booking *> BookingJSONParser::loadFromJSON(QString filename) {
    std::ifstream input_file(filename.toStdString());

    nlohmann::json loaded_data;
    input_file >> loaded_data;
    input_file.close();

    QVector<Booking*> bookings;
    for (const auto& booking_data : loaded_data) {
        Booking* booking = Booking::bookingFromJSON(booking_data);
        if (booking) {
            bookings.push_back(booking);
        } else {
            // Обработка ошибок, если тип не распознан
        }
    }
    return bookings;
}
