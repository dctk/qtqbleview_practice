#include "mydatatablemodel.h"
#include "mydata.h"


//https://doc.qt.io/qt-5/modelview.html
MyDataTableModel::MyDataTableModel(QObject *parent)
    : QAbstractTableModel{parent}
{
}

MyDataTableModel::~MyDataTableModel()
{

}

int MyDataTableModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return items.count();
}

int MyDataTableModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return 3;
}

QVariant MyDataTableModel::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    int column = index.column();

    if (!index.isValid()){
        return QVariant();
    }

    if (role == Qt::CheckStateRole && column == 0){
        if(items[row]->check()){
            return Qt::Checked;
        }
        else{
            return Qt::Unchecked;
        }
    }
    else if (role == Qt::EditRole){
        if (column == 1){
            QVariant value = items[row]->text();
            return value;
        }
        else if (column == 2){
            QVariant value = items[row]->status();
            return value;
        }
    }
    else if (role == Qt::DisplayRole){
        switch(column){
        case 0:
            if (items[row]->check()){
                return "選択中";
            }
            else{
                return QVariant();
            }
        case 1:
            return items[row]->text();
        case 2:
            switch(items[row]->status()){
            case MyData::Status::NotStarted:
                return "未着手";
                break;
            case MyData::Status::InProgras:
                return "進行中";
                break;
            case MyData::Status::Finish:
                return "完了";
                break;
            }

            return items[row]->status();
        default:
            Q_UNREACHABLE();
            break;
        }
    }
    return QVariant();
}

QVariant MyDataTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole){
        return QVariant();
    }

    if (orientation == Qt::Horizontal){
        switch(section){
        case 0:
            return "選択";
        case 1:
            return "テキスト";
        case 2:
            return "状態";
        default:
            Q_UNREACHABLE();
            break;
        }
    }

    return QVariant();
}

void MyDataTableModel::add(MyData *data)
{
    beginInsertRows(QModelIndex(),items.count(),items.count());
    items.push_back(data);
    endInsertRows();
}

bool MyDataTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!index.isValid()){
        return false;
    }

    int column = index.column();
    int row = index.row();
    if (role == Qt::CheckStateRole){
        if (column == 0){
            if (value == Qt::Checked){
                items[row]->setCheck(true);
                emit dataChanged(index,index);
            }
            else if (value == Qt::Unchecked){
                items[row]->setCheck(false);
                emit dataChanged(index,index);
            }
        }
    }
    else if (role == Qt::EditRole){
        if (column == 1){
            items[row]->setText(value.toString());
            emit dataChanged(index,index);
        }
        else if (column == 2){
            switch(value.toUInt()){
            case 0:
                items[row]->setSatus(MyData::Status::NotStarted);
                break;
            case 1:
                items[row]->setSatus(MyData::Status::InProgras);
                break;
            case 2:
                items[row]->setSatus(MyData::Status::Finish);
                break;
            }
        }
    }

    return QAbstractItemModel::setData(index, value, role);
}

Qt::ItemFlags MyDataTableModel::flags(const QModelIndex &index) const
{
    Qt::ItemFlags flag = QAbstractItemModel::flags(index);


    int column = index.column();
    if (column == 0){
        flag |= Qt::ItemIsEnabled | Qt::ItemIsUserCheckable;
    }
    else if (column == 1){
        flag |= Qt::ItemIsEnabled | Qt::ItemIsEditable;
    }
    else if (column == 2){
        flag |= Qt::ItemIsEnabled | Qt::ItemIsEditable;
    }
    return flag;
}
