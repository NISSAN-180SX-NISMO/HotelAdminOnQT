//
// Created by user on 28.11.2023.
//

#ifndef HOTEL_CLIENTSLISTWIDGET_H
#define HOTEL_CLIENTSLISTWIDGET_H

#include <QWidget>
#include "../../DataBases/DataBase.h"


QT_BEGIN_NAMESPACE
namespace Ui { class ClientsListWidget; }
QT_END_NAMESPACE

class ClientsListWidget : public QWidget {
Q_OBJECT

public:
    explicit ClientsListWidget(QWidget *parent = nullptr);

    ~ClientsListWidget() override;

private:
    Ui::ClientsListWidget *ui;
    ClientDataBase* clients = DataBase::getClients();
};


#endif //HOTEL_CLIENTSLISTWIDGET_H
