TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    tictactoe.cpp \
    game.cpp

HEADERS += \
    tictactoe.h \
    game.h

unix|win32: LIBS += -lWinMM

