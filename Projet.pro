#-------------------------------------------------
#
# Project created by QtCreator 2014-04-29T00:34:09
#
#-------------------------------------------------

QT       += core gui
QT       += network
QT       += sql
QT       += core
QTPLUGIN += qsqlmysql
CONFIG += console

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Projet
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mythread.cpp \
    item.cpp \
    vol.cpp \
    passager.cpp \
    checkin.cpp \
    programme.cpp \
    pdm.cpp \
    counter.cpp \
    obcounter.cpp \
    rapports.cpp \
    edm.cpp \
    aeroport.cpp \
    avion.cpp \
    compagnie.cpp \
    modele.cpp \
    chi.cpp \
    operations.cpp \
    direction.cpp \
    gerance.cpp \
    semaine.cpp \
    commonparser.cpp \
    equipa.cpp \
    edl.cpp \
    maintenance.cpp \
    update.cpp \
    fly.cpp \
    CentralWidgets/abstractcentwid.cpp \
    CentralWidgets/guichet.cpp \
    CentralWidgets/guichetcheckin.cpp \
    CentralWidgets/tourdecontrole.cpp \
    Drops/dropreceiver.cpp \
    Drops/mystringmodel.cpp \
    Drops/programecreator.cpp \
    Drops/showcreators.cpp \
    Drops/volcreator.cpp \
    Drops/volpassagercreator.cpp \
    Filters/abstractfilter.cpp \
    Filters/aerofiltre.cpp \
    Filters/compfiltre.cpp \
    Filters/datepopup.cpp \
    Filters/listefiltre.cpp \
    Filters/textfilter.cpp \
    Lists/abstractlist.cpp \
    Lists/commonlist.cpp \
    Lists/flight.cpp \
    Lists/listcollection.cpp \
    Lists/mylistwidget.cpp \
    Lists/mytablewidget.cpp \
    Lists/tousvol.cpp \
    Lists/voldaujourd.cpp \
    MyDock/dockbutton.cpp \
    MyDock/mybotdock.cpp \
    Shows/dummyshow.cpp \
    Shows/empdemaintshow.cpp \
    Shows/eqdmshow.cpp \
    Shows/flexibleshowcollection.cpp \
    Shows/guichetshow.cpp \
    Shows/horizontalshowcollection.cpp \
    Shows/oneatimeshowcollection.cpp \
    Shows/programeshow.cpp \
    Shows/show.cpp \
    Shows/showcollection.cpp \
    Shows/volshow.cpp \
    CentralWidgets/guichetonboard.cpp \
    Drops/eqmcreator.cpp \
    Shows/rapportshow.cpp \
    Shows/operationshow.cpp \
    Drops/rapportcreator.cpp \
    CentralWidgets/takeof.cpp \
    Special/withtimebutton.cpp \
    Lists/programelist.cpp \
    Drops/dropreceivedir.cpp \
    Drops/multicreator.cpp \
    CentralWidgets/directionwidget.cpp \
    Lists/generiquelist.cpp \
    Drops/myteststringmodel.cpp \
    Shows/modeleshow.cpp \
    Drops/modelcreator.cpp \
    Shows/employeshow.cpp \
    Drops/avioncreator.cpp \
    treatthread.cpp \
    Drops/emplcreator.cpp \
    CentralWidgets/changementwid.cpp \
    Drops/aerocreator.cpp \
    Shows/compagnieshow.cpp \
    Drops/compagniecreator.cpp \
    Shows/avionshow.cpp \
    CentralWidgets/maintenancewid.cpp \
    Lists/tousvolrapport.cpp \
    Drops/rapportdropreceiver.cpp

HEADERS  += mainwindow.h \
    mythread.h \
    item.h \
    vol.h \
    passager.h \
    checkin.h \
    programme.h \
    pdm.h \
    counter.h \
    obcounter.h \
    rapports.h \
    edm.h \
    aeroport.h \
    avion.h \
    compagnie.h \
    modele.h \
    chi.h \
    operations.h \
    direction.h \
    gerance.h \
    semaine.h \
    commonparser.h \
    equipa.h \
    edl.h \
    maintenance.h \
    update.h \
    fly.h \
    CentralWidgets/abstractcentwid.h \
    CentralWidgets/guichet.h \
    CentralWidgets/guichetcheckin.h \
    CentralWidgets/tourdecontrole.h \
    Drops/dropreceiver.h \
    Drops/mystringmodel.h \
    Drops/programecreator.h \
    Drops/showcreators.h \
    Drops/volcreator.h \
    Drops/volpassagercreator.h \
    Filters/abstractfilter.h \
    Filters/aerofiltre.h \
    Filters/compfiltre.h \
    Filters/datepopup.h \
    Filters/listefiltre.h \
    Filters/textfilter.h \
    Lists/abstractlist.h \
    Lists/commonlist.h \
    Lists/flight.h \
    Lists/listcollection.h \
    Lists/mylistwidget.h \
    Lists/mytablewidget.h \
    Lists/tousvol.h \
    Lists/voldaujourd.h \
    MyDock/dockbutton.h \
    MyDock/mybotdock.h \
    Shows/dummyshow.h \
    Shows/empdemaintshow.h \
    Shows/eqdmshow.h \
    Shows/flexibleshowcollection.h \
    Shows/guichetshow.cpp.autosave \
    Shows/guichetshow.h \
    Shows/horizontalshowcollection.h \
    Shows/oneatimeshowcollection.h \
    Shows/programeshow.h \
    Shows/show.h \
    Shows/showcollection.h \
    Shows/volshow.h \
    CentralWidgets/guichetonboard.h \
    Drops/eqmcreator.h \
    Shows/rapportshow.h \
    Shows/operationshow.h \
    Drops/rapportcreator.h \
    CentralWidgets/takeof.h \
    Special/withtimebutton.h \
    Lists/programelist.h \
    Drops/dropreceivedir.h \
    Drops/multicreator.h \
    CentralWidgets/directionwidget.h \
    Lists/generiquelist.h \
    Drops/myteststringmodel.h \
    Shows/modeleshow.h \
    Drops/modelcreator.h \
    Shows/employeshow.h \
    Drops/avioncreator.h \
    treatthread.h \
    Drops/emplcreator.h \
    CentralWidgets/changementwid.h \
    Drops/aerocreator.h \
    Shows/compagnieshow.h \
    Drops/compagniecreator.h \
    Shows/avionshow.h \
    CentralWidgets/maintenancewid.h \
    Lists/tousvolrapport.h \
    Drops/rapportdropreceiver.h

FORMS    += \
    checkin.ui \
    CentralWidgets/abstractcentwid.ui \
    CentralWidgets/guichet.ui \
    Lists/flight.ui \
    Lists/voldaujourd.ui \
    Shows/empdemaintshow.ui \
    Shows/eqdmshow.ui \
    Shows/guichetshow.ui \
    Shows/programeshow.ui \
    Shows/volshow.ui \
    mainwindow.ui \
    Shows/rapportshow.ui \
    Shows/modeleshow.ui \
    Shows/employeshow.ui \
    Shows/compagnieshow.ui \
    Shows/avionshow.ui

OTHER_FILES += \
    ../build-Projet-Desktop_Qt_5_2_1_MinGW_32bit-Debug/MyStyle.qss
