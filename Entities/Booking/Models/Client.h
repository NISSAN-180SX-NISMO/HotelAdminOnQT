#pragma once
#ifndef HOTEL_CLIENT_H
#define HOTEL_CLIENT_H


#include <QString>
#include "../../../json.hpp"

class Client {
private:
    static int ID;
    QString name;
public:
    Client(QString name) : name(name) { ++ID; }
    static int getId() {
        return ID;
    }
    const QString &getName() const {
        return name;
    }
    nlohmann::json toJSON() const {
        nlohmann::json data;
        data["name"] = getName().toStdString();
        return data;
    }
    static Client* clientFromJSON(nlohmann::json client_data);
};


#endif //HOTEL_CLIENT_H
