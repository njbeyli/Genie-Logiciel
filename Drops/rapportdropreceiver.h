#ifndef RAPPORTDROPRECEIVER_H
#define RAPPORTDROPRECEIVER_H

#include <QLabel>

class RapportDropReceiver : public QLabel
{
    Q_OBJECT
public:
    explicit RapportDropReceiver(QWidget *parent = 0);

protected:
    void dragEnterEvent(QDragEnterEvent *);
    void dragLeaveEvent(QDragLeaveEvent *);
    void dragMoveEvent(QDragMoveEvent *);
    void dropEvent(QDropEvent *);

public:


signals:
    void alMawloud(QString s);
public slots:

};

#endif // RAPPORTDROPRECEIVER_H
