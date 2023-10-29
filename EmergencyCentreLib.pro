QT -= gui

TEMPLATE = lib
DEFINES += EMERGENCYCENTRELIB_LIBRARY

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    concreteservice.cpp \
    emergencycentrelib.cpp \
    librarytest.cpp \
    motionsensor.cpp \
    sensor.cpp \
    smokesensor.cpp

HEADERS += \
    EmergencyCentreLib_global.h \
    concreteservice.h \
    emergencycentrelib.h \
    librarytest.h \
    motionsensor.h \
    sensor.h \
    service.h \
    smokesensor.h \
    space.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
