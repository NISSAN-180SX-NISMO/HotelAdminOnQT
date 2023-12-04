//
// Created by user on 04.12.2023.
//

#ifndef HOTEL_LUXURYHOTELROOMBUILDER_H
#define HOTEL_LUXURYHOTELROOMBUILDER_H

#include "HotelRoomBuilder.h"

class LuxuryHotelRoomBuilder : public HotelRoomBuilder {
public:
    LuxuryHotelRoomBuilder(QString number) : HotelRoomBuilder(number) {}

    HotelRoom *getHotelRoom() override {
        return new LuxuryHotelRoom(number, seats, available, equipments);
    }
};

#endif //HOTEL_LUXURYHOTELROOMBUILDER_H
