#pragma once
#ifndef HOTEL_DATABASEREPOSITORY_H
#define HOTEL_DATABASEREPOSITORY_H

#include <QVector>


template<class value>
class DataBaseRepository {
protected:
    DataBaseRepository() {}
public:
    virtual void push(value) = 0;
    virtual void remove(QString) = 0;
    virtual QVector<value> getAll() = 0;
    virtual bool contains(const QString& number) = 0;
    virtual value get(const QString& number) = 0;
};
#endif //HOTEL_DATABASEREPOSITORY_H
