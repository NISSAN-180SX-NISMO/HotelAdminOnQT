#pragma once
#ifndef HOTEL_APPENDHOTELROOMDIALOG_H
#define HOTEL_APPENDHOTELROOMDIALOG_H

#include <QDialog>
#include "QVector"
#include "../../Entities/Equipment/Equipment.h"
#include "../../DataBases/HotelRoomDataBase.h"


QT_BEGIN_NAMESPACE
namespace Ui { class AppendHotelRoomDialog; }
QT_END_NAMESPACE

class AppendHotelRoomDialog : public QDialog {
Q_OBJECT

public:
    explicit AppendHotelRoomDialog(QWidget *parent = nullptr);

    ~AppendHotelRoomDialog() override;
signals:
    void dialogChanged();
    void roomCreated();
public slots:
    void updateForm();
private slots:
    void on_appendEquipment_pushButton_clicked();
    void on_createRoom_pushButton_clicked();
private:
    Ui::AppendHotelRoomDialog *ui;
    QVector<Equipment*> currentEquipments;
    HotelRoomDataBase* rooms = nullptr;
    void addEquipmentToCurrentList(const QString &equipment);
    void updateQuipmentsListView();
    bool formIsValid();
};


#endif //HOTEL_APPENDHOTELROOMDIALOG_H
