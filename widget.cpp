#include "widget.h"
#include "ui_widget.h"
#include "mydata.h"
#include "mydatatablemodel.h"
#include "comboboxitemdelegate.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    model = new MyDataTableModel(this);
    ui->tableView->setModel(model);

    QComboBoxItemDelegate *d = new QComboBoxItemDelegate(this);
    d->add("未着手");
    d->add("進行中");
    d->add("完了");
    ui->tableView->setItemDelegateForColumn(2,d);

    setLayout(ui->verticalLayout);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    // ダミーデータの追加
    MyData *data = new MyData();
    data->setText(QString("Hello"));
    data->setCheck(false);
    data->setSatus(MyData::Status::InProgras);
    model->add(data);
}
