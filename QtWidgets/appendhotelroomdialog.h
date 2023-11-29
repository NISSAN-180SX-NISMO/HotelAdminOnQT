//
// Created by user on 29.11.2023.
//

#ifndef HOTEL_APPENDHOTELROOMDIALOG_H
#define HOTEL_APPENDHOTELROOMDIALOG_H

#include <QDialog>


QT_BEGIN_NAMESPACE
namespace Ui { class AppendHotelRoomDialog; }
QT_END_NAMESPACE

class AppendHotelRoomDialog : public QDialog {
Q_OBJECT

public:
    explicit AppendHotelRoomDialog(QWidget *parent = nullptr);

    ~AppendHotelRoomDialog() override;

private:
    Ui::AppendHotelRoomDialog *ui;
};


#endif //HOTEL_APPENDHOTELROOMDIALOG_H
