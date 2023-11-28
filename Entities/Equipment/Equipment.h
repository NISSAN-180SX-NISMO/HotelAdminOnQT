#pragma once
#ifndef HOTEL_EQUIPMENT_H
#define HOTEL_EQUIPMENT_H


#include <QString>

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
public:
    Equipment() {  ++ID; }
    virtual int getCost() = 0;
    virtual QString getInfo() = 0;

};

namespace Equipments {
    class TV : public Equipment {
    public:
        int getCost() override {  return TV_COST; }
        QString getInfo() override {
            return "Телевизор";
        }
    };

    class Table : public Equipment {
    public:
        int getCost() override {  return TABLE_COST; }
        QString getInfo() override {
            return "Стол рабочий";
        }
    };

    class Bed : public Equipment {
    public:
        int getCost() override {  return BED_COST; }
        QString getInfo() override {
            return "Кровать";
        }
    };

    class Bathroom : public Equipment {
    public:
        int getCost() override {  return BATHROOM_COST; }
        QString getInfo() override {
            return "Душевая комната";
        }
    };

    class WIFI : public Equipment {
    public:
        int getCost() override {  return WIFI_COST; }
        QString getInfo() override {
            return "WIFI";
        }
    };

    class Armchair : public Equipment {
    public:
        int getCost() override {  return ARMCHAIR_COST; }
        QString getInfo() override {
            return "Кресло";
        }
    };

    class DressingRoom : public Equipment {
    public:
        int getCost() override {  return DRESSING_ROOM_COST; }
        QString getInfo() override {
            return "Гардеробная комната";
        }
    };


}


#endif //HOTEL_EQUIPMENT_H
