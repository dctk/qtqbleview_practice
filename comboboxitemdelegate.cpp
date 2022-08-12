#include "comboboxitemdelegate.h"
#include <QComboBox>

QComboBoxItemDelegate::QComboBoxItemDelegate(QObject *parent)
    : QItemDelegate{parent}
{
}

QWidget *QComboBoxItemDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QComboBox *combobox = new QComboBox(parent);
    combobox->addItems(items);
    if (items.length() > 0){
        combobox->setCurrentIndex(0);
    }
    return combobox;
}

void QComboBoxItemDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QComboBox *combobox = static_cast<QComboBox*>(editor);
    int value = index.model()->data(index,Qt::EditRole).toUInt();
    return combobox->setCurrentIndex(value);
}

void QComboBoxItemDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QComboBox *combobox = static_cast<QComboBox*>(editor);
    model->setData(index,combobox->currentIndex(),Qt::EditRole);
}

void QComboBoxItemDelegate::add(QString data)
{
    items.append(data);
}
