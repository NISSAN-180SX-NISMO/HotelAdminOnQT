//
// Created by user on 04.12.2023.
//

#ifndef HOTEL_REGULARHOTELROOMBUILDER_H
#define HOTEL_REGULARHOTELROOMBUILDER_H

#include <QString>
#include "HotelRoomBuilder.h"

class RegularHotelRoomBuilder : public HotelRoomBuilder {
public:
    RegularHotelRoomBuilder(QString number) : HotelRoomBuilder(number) {}

    HotelRoom *getHotelRoom() override {
        return new RegularHotelRoom(number, seats, available, equipments);
    }
};

#endif //HOTEL_REGULARHOTELROOMBUILDER_H
