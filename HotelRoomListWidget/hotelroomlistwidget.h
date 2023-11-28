//
// Created by user on 28.11.2023.
//

#ifndef HOTEL_HOTELROOMLISTWIDGET_H
#define HOTEL_HOTELROOMLISTWIDGET_H

#include <QWidget>
#include "../DataBases/HotelRoomDataBase.h"
#include "../DataBases/DataBase.h"


QT_BEGIN_NAMESPACE
namespace Ui { class HotelRoomListWidget; }
QT_END_NAMESPACE

class HotelRoomListWidget : public QWidget {
Q_OBJECT

public:
    explicit HotelRoomListWidget(QWidget *parent = nullptr);

    ~HotelRoomListWidget() override;

private:
    Ui::HotelRoomListWidget *ui;
    HotelRoomDataBase* rooms = DataBase().getRooms();
};


#endif //HOTEL_HOTELROOMLISTWIDGET_H
