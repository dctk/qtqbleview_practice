#include "mydata.h"

MyData::MyData(QObject *parent)
    : QObject{parent}
{

}

bool MyData::check() const
{
    return m_check;
}

void MyData::setCheck(bool newCheck)
{
    if (m_check == newCheck)
        return;
    m_check = newCheck;
    emit checkChanged();
}

const QString &MyData::text() const
{
    return m_text;
}

void MyData::setText(const QString &newText)
{
    if (m_text == newText)
        return;
    m_text = newText;
    emit textChanged();
}

MyData::Status MyData::status() const
{
    return m_status;
}

void MyData::setSatus(Status newStatus)
{
    if (m_status == newStatus)
        return;
    m_status = newStatus;
    emit statusChanged();
}


