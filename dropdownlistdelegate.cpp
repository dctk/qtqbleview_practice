#include "dropdownlistdelegate.h"

DropDownListDelegate::DropDownListDelegate(QItemDelegate *parent)
    : QItemDelegate{parent}
{
}


QWidget *DropDownListDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
}

void DropDownListDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
}
