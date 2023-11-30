//
// Created by user on 30.11.2023.
//

#ifndef HOTEL_APPENDCLIENTDIALOG_H
#define HOTEL_APPENDCLIENTDIALOG_H

#include <QDialog>
#include "../../DataBases/HotelRoomDataBase.h"
#include "../../DataBases/DataBase.h"


QT_BEGIN_NAMESPACE
namespace Ui { class AppendClientDialog; }
QT_END_NAMESPACE

class AppendClientDialog : public QDialog {
Q_OBJECT

public:
    explicit AppendClientDialog(QWidget *parent = nullptr);
    ~AppendClientDialog() override;
    void initShow();
signals:
    void dialogChanged();
    void clientCreated();
public slots:
    void updateForm();
private slots:
    void on_appendClient_pushButton_clicked();
    void on_save_pushButton_clicked();
private:
    Ui::AppendClientDialog *ui;
    HotelRoomDataBase* rooms = DataBase::getRooms();
    ClientDataBase* clients = DataBase::getClients();
    QVector<Client*> currentClients;
    bool formIsValid();
    void loadRooms();
};


#endif //HOTEL_APPENDCLIENTDIALOG_H
