#ifndef SHOW_H
#define SHOW_H

#include <QFrame>
#include <QPushButton>
#include "gerance.h"

class Show : public QFrame
{

    Q_OBJECT

    QPushButton * _exit;

    Gerance *_g;
public:
    explicit Show(QWidget *parent = 0);
    QPushButton * exit();
    QPushButton * submit();
    Gerance *g()const;
    virtual void setg(Gerance *g);

protected:
    QPushButton * _submit;
    void setExitPos();
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
    virtual void setReadOnly(bool t)=0;

signals:

public slots:
    void mySubmitDestroyed();

};

#endif // SHOW_H
