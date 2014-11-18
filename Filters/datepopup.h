#ifndef DATEPOPUP_H
#define DATEPOPUP_H

#include <QDateEdit>

class DatePopup : public QDateEdit
{
    Q_OBJECT
public:
    explicit DatePopup(QWidget *parent = 0);


protected:
    //void mouseDoubleClickEvent(QMouseEvent *e);

signals:

public slots:

};

#endif // DATEPOPUP_H
