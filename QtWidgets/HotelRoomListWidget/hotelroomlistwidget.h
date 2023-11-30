//
// Created by user on 28.11.2023.
//

#ifndef HOTEL_HOTELROOMLISTWIDGET_H
#define HOTEL_HOTELROOMLISTWIDGET_H

#include <QWidget>
#include "../../DataBases/HotelRoomDataBase.h"
#include "../../DataBases/DataBase.h"
#include "../AppendHotelRoomDialog/appendhotelroomdialog.h"


QT_BEGIN_NAMESPACE
namespace Ui { class HotelRoomListWidget; }
QT_END_NAMESPACE

class HotelRoomListWidget : public QWidget {
Q_OBJECT

public:
    explicit HotelRoomListWidget(QWidget *parent = nullptr);

    ~HotelRoomListWidget() override;
private slots:
    void on_appendRoom_pushButton_clicked();
public slots:
    void updateRooms();
    void on_lineEdit_textChanged(const QString &arg1);
private:
    AppendHotelRoomDialog* appendRoomForm = nullptr;
    HotelRoomDataBase* rooms = nullptr;
    Ui::HotelRoomListWidget *ui;
};


#endif //HOTEL_HOTELROOMLISTWIDGET_H
