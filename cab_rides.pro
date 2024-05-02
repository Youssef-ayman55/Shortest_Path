QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    add_city.cpp \
    delete_city.cpp \
    display_graph.cpp \
    find_path.cpp \
    graph.cpp \
    main.cpp \
    mainwindow.cpp \
    node_display.cpp

HEADERS += \
    add_city.h \
    delete_city.h \
    display_graph.h \
    find_path.h \
    graph.h \
    mainwindow.h \
    node_display.h

FORMS += \
    add_city.ui \
    delete_city.ui \
    display_graph.ui \
    find_path.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
