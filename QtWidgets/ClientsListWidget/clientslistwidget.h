//
// Created by user on 28.11.2023.
//

#ifndef HOTEL_CLIENTSLISTWIDGET_H
#define HOTEL_CLIENTSLISTWIDGET_H

#include <QWidget>
#include "../../DataBases/DataBase.h"
#include "../AppendClientDialog/appendclientdialog.h"


QT_BEGIN_NAMESPACE
namespace Ui { class ClientsListWidget; }
QT_END_NAMESPACE

class ClientsListWidget : public QWidget {
Q_OBJECT

public:
    explicit ClientsListWidget(QWidget *parent = nullptr);

    ~ClientsListWidget() override;
    AppendClientDialog* getAppendClientDialog() const {
        return appendClientDialog;
    }


public slots:
    void updateClients();
    void on_lineEdit_textChanged(const QString &arg1);
    void on_removeBooking_pushButton_clicked();
    void on_createBooking_pushButton_clicked();
private:
    Ui::ClientsListWidget *ui;
    AppendClientDialog* appendClientDialog = new AppendClientDialog(this);
    ClientDataBase* clients = DataBase::getClients();
};


#endif //HOTEL_CLIENTSLISTWIDGET_H
