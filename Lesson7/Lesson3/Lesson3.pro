QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

TRANSLATIONS += QtLanguage_ru.ts QtLanguage_eng.ts
CODECFORSRC = UTF-8

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dialog.cpp \
    main.cpp \
    mainwindow.cpp \
    pathwidget.cpp \
    search_thread.cpp \
    settings.cpp

HEADERS += \
    dialog.h \
    hotkeys.h \
    mainwindow.h \
    pathwidget.h \
    search_thread.h \
    settings.h

FORMS += \
    dialog.ui \
    mainwindow.ui \
    settings.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    help.qrc
