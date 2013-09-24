QT += core
QT -= gui

TARGET = PhysicsSystem
TEMPLATE = lib
CONFIG += staticlib c++11

HEADERS += \
    PhysicsSystem.h

SOURCES += \
    PhysicsSystem.cpp

# Box2D
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../Box2D_project/Box2D_install/ -L$$PWD/../../../Box2D_project/Box2D_install/ -lBox2D
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../Box2D_project/Box2D_install/ -L$$PWD/../../../Box2D_project/Box2D_install/ -lBox2D-d
else:unix: LIBS += -L$$PWD/../../../../Box2D_project/Box2D_install/ -L$$PWD/../../../Box2D_project/Box2D_install/ -lBox2D

INCLUDEPATH += $$PWD/../../../../Box2D_project/Box2D_install/include $$PWD/../../../Box2D_project/Box2D_install/include
DEPENDPATH += $$PWD/../../../../Box2D_project/Box2D_install/include $$PWD/../../../Box2D_project/Box2D_install/include

