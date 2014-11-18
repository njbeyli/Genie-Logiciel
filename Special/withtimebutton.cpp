#include "withtimebutton.h"
#include <QDebug>
#include <QTimeEdit>
#include <QVBoxLayout>

WithTimeButton::WithTimeButton(QWidget *parent) :
    QPushButton(parent)
{
}

void WithTimeButton::mouseDoubleClickEvent(QMouseEvent *)
{
    QTimeEdit *te=new QTimeEdit(this);
    QVBoxLayout *l=new QVBoxLayout;

    l->addWidget(te);
    setLayout(l);
}
