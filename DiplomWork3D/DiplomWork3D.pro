#-------------------------------------------------
#
# Project created by QtCreator 2015-04-02T19:50:45
#
#-------------------------------------------------

QT       += core gui
QT       += opengl
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DiplomWork3D
TEMPLATE = app

LIBS += -lopengl32 -lglu32 -lglut
SOURCES += main.cpp\
        diplomwork.cpp \
    scene3d.cpp \
#    c:\Users\Vladymyrlem\Documents\GitHub\DiplomWork3D_corr\build-DiplomWork3D-Desktop_Qt_5_4_1_MinGW_32bit-Release/release/moc_diplomwork.cpp \
#    E:/Univer/ЗИЕИТ/Дипломная робота/Раздел 1/build-DiplomWork3D-Desktop_Qt_5_4_1_MinGW_32bit-Debug/debug/moc_diplomwork.cpp \
#    E:/Univer/ЗИЕИТ/Дипломная робота/Раздел 1/build-DiplomWork3D-Desktop_Qt_5_4_1_MinGW_32bit-Debug/debug/moc_diplomwork.cpp

HEADERS  += diplomwork.h \
    scene3d.h

FORMS    += \
    diplomwork.ui

DISTFILES += \
#    c:\Users\Vladymyrlem\Documents\GitHub\DiplomWork3D_corr\build-DiplomWork3D-Desktop_Qt_5_4_1_MinGW_32bit-Debug/debug/icudt53.dll \
#    c:\Users\Vladymyrlem\Documents\GitHub\DiplomWork3D_corr\build-DiplomWork3D-Desktop_Qt_5_4_1_MinGW_32bit-Debug/debug/icuin53.dll \
#    E:/Univer/ЗИЕИТ/Дипломная робота/Раздел 1/build-DiplomWork3D-Desktop_Qt_5_4_1_MinGW_32bit-Debug/debug/icuuc53.dll \
#    E:/Univer/ЗИЕИТ/Дипломная робота/Раздел 1/build-DiplomWork3D-Desktop_Qt_5_4_1_MinGW_32bit-Debug/debug/libgcc_s_dw2-1.dll \
#    E:/Univer/ЗИЕИТ/Дипломная робота/Раздел 1/build-DiplomWork3D-Desktop_Qt_5_4_1_MinGW_32bit-Debug/debug/libstdc++-6.dll \
#    E:/Univer/ЗИЕИТ/Дипломная робота/Раздел 1/build-DiplomWork3D-Desktop_Qt_5_4_1_MinGW_32bit-Debug/debug/libwinpthread-1.dll \
#    E:/Univer/ЗИЕИТ/Дипломная робота/Раздел 1/build-DiplomWork3D-Desktop_Qt_5_4_1_MinGW_32bit-Debug/debug/Qt5Cored.dll \
#    E:/Univer/ЗИЕИТ/Дипломная робота/Раздел 1/build-DiplomWork3D-Desktop_Qt_5_4_1_MinGW_32bit-Debug/debug/Qt5Guid.dll \
#    E:/Univer/ЗИЕИТ/Дипломная робота/Раздел 1/build-DiplomWork3D-Desktop_Qt_5_4_1_MinGW_32bit-Debug/debug/Qt5Widgetsd.dll \
    icuin53.dll \
    icuuc53.dll \
    libgcc_s_dw2-1.dll \
    libstdc++-6.dll \
    libwinpthread-1.dll \
    Qt5Cored.dll \
    Qt5Guid.dll \
    Qt5Widgetsd.dll

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/e:\Programs for windows 10\Qt\5.6\mingw49_32\lib\-lglut32

INCLUDEPATH += $$PWD/e:\Programs for windows 10\Qt\5.6\mingw49_32\include\
DEPENDPATH += $$PWD/e:\Programs for windows 10\Qt\5.6\mingw49_32\include\
