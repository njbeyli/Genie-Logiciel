#ifndef OPERATIONSHOW_H
#define OPERATIONSHOW_H

#include <QWidget>
#include <QLabel>
#include <QTextEdit>
#include <QSpinBox>


class OperationShow : public QWidget
{
    Q_OBJECT
    QLabel *_code,*_desc;
    QSpinBox *_grav;
    QTextEdit *_rem;
public:
    explicit OperationShow(QWidget *parent = 0);
    void setReadOnly(bool t);
    void setDateh(QString c,QString d,int g,QString r);
    QString getid()const;
    QString getrem()const;
    QString getgrav()const;
signals:

public slots:

};

#endif // OPERATIONSHOW_H
