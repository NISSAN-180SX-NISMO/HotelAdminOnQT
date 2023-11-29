//
// Created by user on 29.11.2023.
//

#ifndef HOTEL_BOOKINGJSONPARSER_H
#define HOTEL_BOOKINGJSONPARSER_H


#include <fstream>
#include "Models/Booking.h"


class BookingJSONParser {
private:
    QVector<Booking*> bookings;
public:
    BookingJSONParser(QVector<Booking*> bookings) {
        this->bookings = bookings;
    }
    void saveToJSON(QString filename){
        nlohmann::json json_data;
        for (const auto& booking : bookings) {
            json_data.push_back(booking->toJSON());
        }

        std::ofstream file(filename.toStdString());
        file << json_data.dump(2);
        file.close();
    }
    static QVector<Booking*> loadFromJSON(QString filename);
};


#endif //HOTEL_BOOKINGJSONPARSER_H
