#ifndef LISTEFILTRE_H
#define LISTEFILTRE_H

#include <QWidget>
#include <QPushButton>
#include <QCheckBox>
#include <QListView>
#include <QAbstractListModel>
#include <QVBoxLayout>
#include "abstractfilter.h"

class ListeFiltre : public AbstractFilter
{
    Q_OBJECT

    QPushButton *_head;
    QCheckBox *_checkTous;

protected:

    QListView * _lv;
    QAbstractListModel *_lm;
    QVBoxLayout *_qvb;

public:
    explicit ListeFiltre(QString s,QWidget *parent = 0);
    virtual void remplirMod()=0;

    QListView * lv()const;
signals:

private slots:
    void iShouldSend();

public slots:
    void hide_lv();
    void check(bool t);
    void sCheck();
};

#endif // LISTEFILTRE_H
