#ifndef WITHTIMEBUTTON_H
#define WITHTIMEBUTTON_H

#include <QPushButton>
#include <QMouseEvent>

class WithTimeButton : public QPushButton
{
    Q_OBJECT
public:
    explicit WithTimeButton(QWidget *parent = 0);

signals:

protected:
    void mouseDoubleClickEvent(QMouseEvent *);

public slots:

};

#endif // WITHTIMEBUTTON_H
