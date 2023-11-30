//
// Created by user on 28.11.2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainTabWindow.h" resolved

#include <QVBoxLayout>
#include "maintabwindow.h"
#include "ui_MainTabWindow.h"
#include "../HotelRoomListWidget/hotelroomlistwidget.h"
#include "../ClientsListWidget/clientslistwidget.h"



MainTabWindow::MainTabWindow(QWidget *parent)
        : QDialog(parent)
{
    tabWidget = new QTabWidget;
    HotelRoomListWidget* hotelRoomListWidget = new HotelRoomListWidget();
    ClientsListWidget* clientsListWidget = new ClientsListWidget();
    AppendClientDialog* appendClientDialog = clientsListWidget->getAppendClientDialog();
    connect(appendClientDialog, &AppendClientDialog::clientCreated, hotelRoomListWidget, &HotelRoomListWidget::updateRooms);

    tabWidget->addTab(hotelRoomListWidget,tr("Список комнат"));
    tabWidget->addTab(clientsListWidget,"Список гостей");

    auto *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(tabWidget);
    this->resize(1920, 1080);
    setLayout(mainLayout);
    setWindowTitle(tr("Tab Dialog"));

    DataBase::getRooms();
    DataBase::getClients();
}

MainTabWindow::~MainTabWindow() {
    delete ui;
}
