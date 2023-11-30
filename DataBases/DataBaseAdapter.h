#pragma once
#ifndef HOTEL_DATABASEADAPTER_H
#define HOTEL_DATABASEADAPTER_H

#include <QVector>


template<class value>
class DataBaseAdapter {
protected:
    DataBaseAdapter() {}
public:
    virtual void push(value) = 0;
    virtual void remove(QString) = 0;
    virtual QVector<value> getAll() = 0;
    virtual bool contains(const QString& number) = 0;
};
#endif //HOTEL_DATABASEADAPTER_H
