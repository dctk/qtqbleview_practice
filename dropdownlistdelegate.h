#ifndef DROPDOWNLISTDELEGATE_H
#define DROPDOWNLISTDELEGATE_H

#include <QObject>
#include <QItemDelegate>
#include <QComboBox>

class DropDownListDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    explicit DropDownListDelegate(QItemDelegate *parent = nullptr);

    // QAbstractItemDelegate interface
public:
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void setEditorData(QWidget *editor, const QModelIndex &index) const;

private:
    QComboBox *combobox;

};


#endif // DROPDOWNLISTDELEGATE_H
