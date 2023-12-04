//
// Created by user on 04.12.2023.
//

#ifndef HOTEL_BUSINESSCLASSHOTELROOMBUILDER_H
#define HOTEL_BUSINESSCLASSHOTELROOMBUILDER_H

#include "HotelRoomBuilder.h"

class BusinessClassHotelRoomBuilder : public HotelRoomBuilder {
public:
    BusinessClassHotelRoomBuilder(QString number) : HotelRoomBuilder(number) {}

    HotelRoom *getHotelRoom() override {
        return new BusinessClassHotelRoom(number, seats, available, equipments);
    }
};

#endif //HOTEL_BUSINESSCLASSHOTELROOMBUILDER_H
