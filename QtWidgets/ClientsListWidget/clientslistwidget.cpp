//
// Created by user on 28.11.2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_ClientsListWidget.h" resolved

#include "clientslistwidget.h"
#include "ui_ClientsListWidget.h"
#include "../HotelRoomListWidget/hotelroomlistwidget.h"


ClientsListWidget::ClientsListWidget(QWidget *parent) :
        QWidget(parent), ui(new Ui::ClientsListWidget) {
    ui->setupUi(this);
    ui->lineEdit->setPlaceholderText("Введите номер комнаты");
    updateClients();
    ui->removeBooking_pushButton->setEnabled(false);
    connect(ui->lineEdit, &QLineEdit::textChanged, this, &ClientsListWidget::on_lineEdit_textChanged);
}

ClientsListWidget::~ClientsListWidget() {
    delete ui;
}

void ClientsListWidget::on_createBooking_pushButton_clicked() {
    connect(appendClientDialog, &AppendClientDialog::clientCreated, this, &ClientsListWidget::updateClients);
    appendClientDialog->initShow();
}

void ClientsListWidget::updateClients() {
    this->clients = DataBase::getClients();

    ui->tableWidget->setRowCount(0);
    ui->tableWidget->clear();

    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Клиент" << "Номер" << "Дата заселения" <<  "Дата выселения");
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView(Qt::Orientation()).Stretch);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView(Qt::Orientation()).ResizeToContents);
    int eps = 0;
    for (int j = 0; j < clients->getAll().size(); ++j) {

        for (int i = 0; i < clients->getAll()[j]->getClients().size(); ++i, ++eps) {
            ui->tableWidget->insertRow(eps);
            QTableWidgetItem * name = new QTableWidgetItem(clients->getAll()[j]->getClients()[i]->getName());
            QTableWidgetItem * number = new QTableWidgetItem(clients->getAll()[j]->getRoom()->getNumber());
            QTableWidgetItem * bookingDate = new QTableWidgetItem(
                    clients->getAll()[j]->getBookingDate().toString("dd/MM/yyyy hh:mm"));
            QTableWidgetItem * endBookingDate = new QTableWidgetItem(
                    clients->getAll()[j]->getEndBookingDate().toString("dd/MM/yyyy hh:mm"));

            ui->tableWidget->setItem(eps, 0, name);
            ui->tableWidget->setItem(eps, 1, number);
            ui->tableWidget->setItem(eps, 2, bookingDate);
            ui->tableWidget->setItem(eps, 3, endBookingDate);
        }
    }
}

void ClientsListWidget::on_lineEdit_textChanged(const QString &arg1) {
    ui->removeBooking_pushButton->setEnabled(clients->contains(arg1));
}

void ClientsListWidget::on_removeBooking_pushButton_clicked() {
    QString number = ui->lineEdit->text();
    DataBase::getRooms()->get(number)->setAvailable(true);
    clients->remove(number);
    updateClients();
    emit on_lineEdit_textChanged(ui->lineEdit->text());
    emit clientRemoved();
}

