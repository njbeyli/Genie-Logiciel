#ifndef TEXTFILTER_H
#define TEXTFILTER_H
#include "abstractfilter.h"
#include <QLineEdit>

class TextFilter : public AbstractFilter
{
    Q_OBJECT
    QLineEdit *_le;
public:
    explicit TextFilter(QWidget *parent = 0);
private slots:
    void iShouldSend();
signals:

public slots:

};

#endif // TEXTFILTER_H
