#ifndef COMBOBOXITEMDELEGATE_H
#define COMBOBOXITEMDELEGATE_H

#include <QItemDelegate>

class QComboBoxItemDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    explicit QComboBoxItemDelegate(QObject *parent = nullptr);

    // QAbstractItemDelegate interface
public:
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
    void add(QString data);

private:
    QStringList items;
};



#endif // COMBOBOXITEMDELEGATE_H
