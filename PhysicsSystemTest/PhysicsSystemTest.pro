QT += core
QT -= gui

TARGET = PhysicsSystemTest
TEMPLATE = app
CONFIG   += console c++11
CONFIG   -= app_bundle


SOURCES += main.cpp

# PhysicsSystem
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../PhysicsSystem/release/ -lPhysicsSystem
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../PhysicsSystem/debug/ -lPhysicsSystem
else:unix: LIBS += -L$$OUT_PWD/../PhysicsSystem/ -lPhysicsSystem

INCLUDEPATH += $$PWD/../PhysicsSystem
DEPENDPATH += $$PWD/../PhysicsSystem

win32:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../PhysicsSystem/release/libPhysicsSystem.a
else:win32:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../PhysicsSystem/debug/libPhysicsSystem.a
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../PhysicsSystem/libPhysicsSystem.a

# Box2D
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../Box2D_project/Box2D_install/ -L$$PWD/../../../Box2D_project/Box2D_install/ -lBox2D
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../Box2D_project/Box2D_install/ -L$$PWD/../../../Box2D_project/Box2D_install/ -lBox2D-d
else:unix: LIBS += -L$$PWD/../../../../Box2D_project/Box2D_install/ -L$$PWD/../../../Box2D_project/Box2D_install/ -lBox2D

INCLUDEPATH += $$PWD/../../../../Box2D_project/Box2D_install/include $$PWD/../../../Box2D_project/Box2D_install/include
DEPENDPATH += $$PWD/../../../../Box2D_project/Box2D_install/include $$PWD/../../../Box2D_project/Box2D_install/include
