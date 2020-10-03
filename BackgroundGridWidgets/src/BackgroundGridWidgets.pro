QT += gui widgets

CONFIG += c++11

HEADERS += \
    MainWindow.h \
    PixmapBuilder.h

SOURCES += \
    main.cpp \
    MainWindow.cpp \
    PixmapBuilder.cpp \

RESOURCES += \
    resources.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
