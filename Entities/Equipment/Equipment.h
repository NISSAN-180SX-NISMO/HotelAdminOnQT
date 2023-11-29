#pragma once
#ifndef HOTEL_EQUIPMENT_H
#define HOTEL_EQUIPMENT_H


#include <QString>
#include "json.hpp"

#define TV_COST 1500;
#define TABLE_COST 1000;
#define BED_COST 1000;
#define BATHROOM_COST 3000;
#define WIFI_COST 2000;
#define ARMCHAIR_COST 2000;
#define DRESSING_ROOM_COST 5000;


class Equipment {
private:
    static int ID;
    virtual QString getType() const = 0;
public:
    Equipment() {  ++ID; }
    virtual int getCost() = 0;
    virtual QString getInfo() = 0;
    nlohmann::json toJSON() const {
        nlohmann::json data;
        // Добавьте соответствующие поля в JSON
        data["type"] = getType().toStdString();
        return data;
    }
    static Equipment* fromJSON(const nlohmann::json& data);
};

namespace Equipments {
    class TV : public Equipment {
    private:
        QString getType() const override { return "TV"; }
    public:
        int getCost() override {  return TV_COST; }
        QString getInfo() override {
            return "Телевизор";
        }
    };

    class Table : public Equipment {
    private:
        QString getType() const override { return "Table"; }
    public:
        int getCost() override {  return TABLE_COST; }
        QString getInfo() override {
            return "Стол письменный";
        }
    };

    class Bed : public Equipment {
    private:
        QString getType() const override { return "Bed"; }
    public:
        int getCost() override {  return BED_COST; }
        QString getInfo() override {
            return "Кровать";
        }
    };

    class Bathroom : public Equipment {
    private:
        QString getType() const override { return "Bathroom"; }
    public:
        int getCost() override {  return BATHROOM_COST; }
        QString getInfo() override {
            return "Ванная комната";
        }
    };

    class WIFI : public Equipment {
    private:
        QString getType() const override { return "WIFI"; }
    public:
        int getCost() override {  return WIFI_COST; }
        QString getInfo() override {
            return "WIFI";
        }
    };

    class Armchair : public Equipment {
    private:
        QString getType() const override { return "Armchair"; }
    public:
        int getCost() override {  return ARMCHAIR_COST; }
        QString getInfo() override {
            return "Кресло";
        }
    };

    class DressingRoom : public Equipment {
    private:
        QString getType() const override { return "DressingRoom"; }
    public:
        int getCost() override {  return DRESSING_ROOM_COST; }
        QString getInfo() override {
            return "Гардеробная комната";
        }
    };


}



#endif //HOTEL_EQUIPMENT_H
