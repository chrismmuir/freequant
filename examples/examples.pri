TEMPLATE = app
CONFIG -= qt
CONFIG += console

FQ_ROOT = $$PWD/../

win32 {
    BOOST_HOME = $$quote(C:/Program Files (x86)/boost/boost_1_51)
    BOOST_INC = $$BOOST_HOME
    BOOST_LIB = $$BOOST_HOME/lib
    LIBS += -L$$BOOST_LIB
} unix {
    BOOST_INC = /usr/include
    BOOST_LIB = /usr/lib
}

win32 {
    CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../src/release/ -lfreequant
    CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../src/debug/ -lfreequant
} unix {
    LIBS += -L$$OUT_PWD/../../src -lfreequant
}

INCLUDEPATH += $$FQ_ROOT/src $$BOOST_INC
DEPENDPATH  += $$FQ_ROOT/src
DESTDIR      = $$FQ_ROOT/examples/bin