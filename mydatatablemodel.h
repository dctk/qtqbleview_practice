#ifndef MYDATATABLEMODEL_H
#define MYDATATABLEMODEL_H

#include <QAbstractTableModel>

class MyData;

class MyDataTableModel : public QAbstractTableModel
{
public:
    explicit MyDataTableModel(QObject *parent = nullptr);
    ~MyDataTableModel();

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

public:
    void add(MyData *data);

private:
    QVector<MyData*> items;


    // QAbstractItemModel interface
public:
    bool setData(const QModelIndex &index, const QVariant &value, int role);

    // QAbstractItemModel interface
public:
    Qt::ItemFlags flags(const QModelIndex &index) const;
};




#endif // MYDATATABLEMODEL_H
