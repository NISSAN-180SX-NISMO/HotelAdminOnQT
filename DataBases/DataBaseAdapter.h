#pragma once
#ifndef HOTEL_DATABASEADAPTER_H
#define HOTEL_DATABASEADAPTER_H

template<class value>
class DataBaseAdapter {
public:
    DataBaseAdapter() {
        loadFromJSON();
    }
    virtual void push(value) = 0;
    virtual void remove(int ID) = 0;
    virtual void saveToJSON() = 0;
    virtual void loadFromJSON() = 0;
};
#endif //HOTEL_DATABASEADAPTER_H
