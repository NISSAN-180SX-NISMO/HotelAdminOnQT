//
// Created by user on 29.11.2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_AppendHotelRoomDialog.h" resolved

#include "appendhotelroomdialog.h"
#include "ui_AppendHotelRoomDialog.h"


AppendHotelRoomDialog::AppendHotelRoomDialog(QWidget *parent) :
        QDialog(parent), ui(new Ui::AppendHotelRoomDialog) {
    ui->setupUi(this);
}

AppendHotelRoomDialog::~AppendHotelRoomDialog() {
    delete ui;
}
