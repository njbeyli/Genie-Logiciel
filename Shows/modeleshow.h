#ifndef MODELESHOW_H
#define MODELESHOW_H

#include <QWidget>
#include "show.h"

namespace Ui {
class ModeleShow;
}

class ModeleShow : public Show
{
    Q_OBJECT

public:
    explicit ModeleShow(QString s, bool type, QWidget *parent = 0);
    ~ModeleShow();
    void setg(Gerance *g);
protected:
    void setReadOnly(bool t);

protected slots:
    void addModele();
    void leffha();

private:
    Ui::ModeleShow *ui;
};

#endif // MODELESHOW_H
