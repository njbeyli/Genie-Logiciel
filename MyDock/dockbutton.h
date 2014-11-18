#ifndef DOCKBUTTON_H
#define DOCKBUTTON_H

#include <QPushButton>

class DockButton : public QPushButton
{
    Q_OBJECT
    int _i;
    QSize _b,_s;
public:
    explicit DockButton(int i, QSize b, QSize s, QString , QWidget *parent = 0);

protected:
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);

signals:
    void pos(int);

public slots:
    void clickedInDock();

};

#endif // DOCKBUTTON_H
