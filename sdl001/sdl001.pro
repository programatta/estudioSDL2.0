TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -L/usr/lib -lSDL2

INCLUDES += /usr/local/include

SOURCES += \
        main.cpp \
    game.cpp

HEADERS += \
    game.h

DISTFILES += \
    README.md
