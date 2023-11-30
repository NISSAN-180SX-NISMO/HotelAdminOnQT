//
// Created by user on 28.11.2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_HotelRoomListWidget.h" resolved

#include "hotelroomlistwidget.h"
#include "ui_HotelRoomListWidget.h"



HotelRoomListWidget::HotelRoomListWidget(QWidget *parent) :
        QWidget(parent), ui(new Ui::HotelRoomListWidget) {
    ui->setupUi(this);

    updateRooms();
    ui->lineEdit->setPlaceholderText("Введите номер");
    ui->removeRoom_pushButton->setEnabled(false);
}

HotelRoomListWidget::~HotelRoomListWidget() {
    delete ui;
}

void HotelRoomListWidget::on_appendRoom_pushButton_clicked() {
    appendRoomForm = new AppendHotelRoomDialog();
    connect(appendRoomForm, &AppendHotelRoomDialog::roomCreated, this, &HotelRoomListWidget::updateRooms);
    appendRoomForm->show();
}

void HotelRoomListWidget::updateRooms() {
    this->rooms = DataBase::getRooms();
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->clear();

    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Номер" << "Количество мест" << "Номер свободен" <<  "Стоимость" << " О номере");
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView(Qt::Orientation()).Stretch);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView(Qt::Orientation()).ResizeToContents);
    std::cout << "rooms size = " << rooms->getAll().size() << "\n";
    for (int i = 0; i < rooms->getAll().size(); ++i) {
        ui->tableWidget->insertRow(i);
        QTableWidgetItem *number = new QTableWidgetItem(rooms->getAll()[i]->getNumber());
        QTableWidgetItem *seats = new QTableWidgetItem(QString::number(rooms->getAll()[i]->getSeats()));
        QTableWidgetItem *available = new QTableWidgetItem((rooms->getAll()[i]->isAvailable() ? "Да" : "Нет"));
        QTableWidgetItem *cost = new QTableWidgetItem(QString::number(rooms->getAll()[i]->getCost()));
        QTableWidgetItem *about = new QTableWidgetItem(rooms->getAll()[i]->getEquipments());


        ui->tableWidget->setItem(i, 0, number);
        ui->tableWidget->setItem(i, 1, seats);
        ui->tableWidget->setItem(i, 2, available);
        ui->tableWidget->setItem(i, 3, cost);
        ui->tableWidget->setItem(i, 4, about);

    }
}

void HotelRoomListWidget::on_lineEdit_textChanged(const QString &arg1) {
    std::cout << arg1.toStdString() << "\n";
    bool enb = rooms->contains(arg1);
    std::cout << enb << "\n";
    ui->removeRoom_pushButton->setEnabled(enb);
}
