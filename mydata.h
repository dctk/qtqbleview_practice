#ifndef MYDATA_H
#define MYDATA_H

#include <QObject>

/*!
 * \brief The MyData class
 *
 * ListView用のデータ
 */
class MyData : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool check READ check WRITE setCheck NOTIFY checkChanged)
    Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChanged)
    Q_PROPERTY(Status status READ status WRITE setSatus NOTIFY statusChanged)

public:
    explicit MyData(QObject *parent = nullptr);

    typedef enum {
        NotStarted, // タスク未着手
        InProgras,  // タスク進行中
        Finish      // タスク完了
    } Status;

    // データのチェック状態(Viewのチェック状態)-不要なら削除
    bool check() const;
    void setCheck(bool newCheck);

    // テキスト
    const QString &text() const;
    void setText(const QString &newText);

    // タスクの状態
    Status status() const;
    void setSatus(Status newStatus);

    // Status<->文字列変換
    QString statusToString(Status status);
    Status stringToStatus(QString& string,Status defaultStatus=Status::NotStarted);

signals:
    void checkChanged();
    void textChanged();
    void statusChanged();

private:
    bool m_check;
    QString m_text;
    Status m_status;
};

#endif // MYDATA_H
