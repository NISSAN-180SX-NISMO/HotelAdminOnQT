//
// Created by user on 28.11.2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_ClientsListWidget.h" resolved

#include "clientslistwidget.h"
#include "ui_ClientsListWidget.h"


ClientsListWidget::ClientsListWidget(QWidget *parent) :
        QWidget(parent), ui(new Ui::ClientsListWidget) {
    ui->setupUi(this);


    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Клиент" << "Номер" << "Дата заселения" <<  "Дата выселения");
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView(Qt::Orientation()).Stretch);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView(Qt::Orientation()).ResizeToContents);
    int eps = 0;
    std::cout  << clients->getAll().size();
    for (int j = 0; j < clients->getAll().size(); ++j)
        for (int i = 0; i < clients->getAll()[j]->getClients().size(); ++i, ++eps) {
            ui->tableWidget->insertRow(j + eps);
            QTableWidgetItem *name = new QTableWidgetItem(clients->getAll()[j]->getClients()[i]->getName());
            QTableWidgetItem *number = new QTableWidgetItem(clients->getAll()[j]->getRoom()->getNumber());
            QTableWidgetItem *bookingDate = new QTableWidgetItem(clients->getAll()[j]->getBookingDate().toString());
            QTableWidgetItem *endBookingDate = new QTableWidgetItem(clients->getAll()[j]->getEndBookingDate().toString());

            ui->tableWidget->setItem(j + eps, 0, name);
            ui->tableWidget->setItem(j + eps, 1, number);
            ui->tableWidget->setItem(j + eps, 2, bookingDate);
            ui->tableWidget->setItem(j + eps, 3, endBookingDate);
        }

}

ClientsListWidget::~ClientsListWidget() {
    delete ui;
}
