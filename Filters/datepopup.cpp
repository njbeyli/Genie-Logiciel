#include "datepopup.h"
#include <QCalendarWidget>
#include <QMouseEvent>
#include <QDebug>


DatePopup::DatePopup(QWidget *parent) :
    QDateEdit(parent)
{
    setFixedHeight(20);
    setCalendarPopup(true);
    setDate(QDate().currentDate());
//    setStyleSheet("QMenu { font-size:16px; width: 150px; left: 20px;"
//                  "background-color:qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 #cccccc, stop: 1 #333333);}"
//                  "QToolButton {icon-size: 48px, 48px;background-color: qlineargradient(x1:0, y1:0, x2:0,"
//                  "y2:1, stop: 0 #cccccc, stop: 1 #333333);"
//                  "height: 100px; width: 200px;}"
//                  "QAbstractItemView {selection-background-color: rgb(255, 174, 0);}"
//                  "QToolButton::menu-arrow {}"
//                  "QToolButton::menu-button {}"
//                  "QToolButton::menu-indicator{width: 50px;}"
//                  "QToolButton::menu-indicator:pressed,"
//                  "QToolButton::menu-indicator:open{top:10px; left: 10px;}"
//                  "QListView {background-color:white;}"
//                  "QSpinBox::up-button { subcontrol-origin: border;"
//                  "subcontrol-position: top right; width:50px; border-image: url(icons:arrow_up_n.png);}"
//                  "QSpinBox::down-button {subcontrol-origin: border; subcontrol-position: bottom right;"
//                  "border-width: 1px; width:50px;}"
//                  "QSpinBox::down-arrow { width:26px; height:17px;"
//                  "image: url(icons:arrow_down_n.png); } ");
}
