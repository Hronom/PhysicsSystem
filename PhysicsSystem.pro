TEMPLATE = subdirs

SUBDIRS += \
    PhysicsSystem \
    PhysicsSystemTest

PhysicsSystemTest.depends = PhysicsSystem
