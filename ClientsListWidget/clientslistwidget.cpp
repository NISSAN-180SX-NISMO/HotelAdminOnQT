//
// Created by user on 28.11.2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_ClientsListWidget.h" resolved

#include "clientslistwidget.h"
#include "ui_ClientsListWidget.h"


ClientsListWidget::ClientsListWidget(QWidget *parent) :
        QWidget(parent), ui(new Ui::ClientsListWidget) {
    ui->setupUi(this);
}

ClientsListWidget::~ClientsListWidget() {
    delete ui;
}
