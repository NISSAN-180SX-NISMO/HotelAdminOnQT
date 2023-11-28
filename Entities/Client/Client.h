#pragma once
#ifndef HOTEL_CLIENT_H
#define HOTEL_CLIENT_H


#include <QString>

class Client {
private:
    static int ID;
    QString name;
public:
    explicit Client(const QString &name) : name(name) { ++ID; }
    static int getId() {
        return ID;
    }
    const QString &getName() const {
        return name;
    }
};


#endif //HOTEL_CLIENT_H
