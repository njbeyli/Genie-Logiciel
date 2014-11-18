#ifndef MYBOTTOMDOCK_H
#define MYBOTTOMDOCK_H

#include <QWidget>
#include <QPushButton>

class MyBotDock : public QWidget
{
    Q_OBJECT

    QList<QPushButton *> _l;
    int _selectedPos;
public:
    explicit MyBotDock(QList<QWidget *> l, QWidget *parent = 0);

protected:

    void leaveEvent(QEvent *);

signals:

    void inElementClicked(int);
public slots:
    void sizingEvent();
    void sendCheckedPos(int);
};

#endif // MYBOTTOMDOCK_H
