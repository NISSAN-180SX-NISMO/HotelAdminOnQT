//
// Created by user on 04.12.2023.
//

#ifndef HOTEL_HOTELROOMDIRECTOR_H
#define HOTEL_HOTELROOMDIRECTOR_H

#include <QString>
#include "HotelRoomBuilder.h"
#include "RegularHotelRoomBuilder.h"
#include "BusinessClassHotelRoomBuilder.h"
#include "LuxuryHotelRoomBuilder.h"

class HotelRoomDirector {
private:
    QString number;
public:
    HotelRoomDirector(QString number) : number(number) {}
    HotelRoomBuilder* getBuilder() {
        if (number[0] == 'R') {
            return new RegularHotelRoomBuilder(number);
        } else if (number[0] == 'B') {
            return new BusinessClassHotelRoomBuilder(number);
        } else if (number[0] == 'L') {
            return new LuxuryHotelRoomBuilder(number);
        }
        return nullptr;
    }
};

#endif //HOTEL_HOTELROOMDIRECTOR_H
