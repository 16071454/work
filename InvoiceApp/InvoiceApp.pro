#-------------------------------------------------
#
# Project created by QtCreator 2019-11-25T11:29:38
#
#-------------------------------------------------

QT       += core gui webkitwidgets printsupport winextras

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets network

TARGET = InvoiceApp
TEMPLATE = app

CONFIG += c++11

INCLUDEPATH += ./Include/opencv300/opencv/build/include/
                ./Include/opencv300/opencv/build/include/opencv/
                ./Include/opencv300/opencv/build/include/opencv2/



SOURCES += main.cpp\
        LoginDlg.cpp \
    cleaninitfile.cpp \
    verificationcodelabel.cpp \
    mybutton.cpp \
    headdialog.cpp \
    indexdialog.cpp \
    uploadinginfoform.cpp \
    extengroupform.cpp \
    invoiceable.cpp \
    picform.cpp \
    xuanfuoptionform.cpp \
    picviewdialog.cpp \
    scandlg.cpp \
    webdialog.cpp \
    scanoptionform.cpp \
    scanverticalform.cpp \
    scanthread.cpp \
    dib.cpp \
    qtwain.cpp \
    qtwaininterface.cpp \
    dibfile.c \
    dibutil.c \
    twaincpp.cpp \
    scanlogodialog.cpp \
    moveinvoicedialog.cpp \
    selectemployerdialog.cpp \
    processbardialog.cpp \
    mygetemployerthread.cpp \
    uploadinvoicethread.cpp \
    mytoolbutton.cpp \
    opencvobject.cpp

HEADERS  += LoginDlg.h \
    cleaninitfile.h \
    verificationcodelabel.h \
    mybutton.h \
    headdialog.h \
    indexdialog.h \
    uploadinginfoform.h \
    extengroupform.h \
    invoiceable.h \
    picform.h \
    xuanfuoptionform.h \
    picviewdialog.h \
    scandlg.h \
    webdialog.h \
    scanoptionform.h \
    scanverticalform.h \
    scanthread.h \
    dib.h \
    dibapi.h \
    dibutil.h \
    qtwain.h \
    qtwaininterface.h \
    stdafx.h \
    twain.h \
    twaincpp.h \
    scanlogodialog.h \
    moveinvoicedialog.h \
    selectemployerdialog.h \
    processbardialog.h \
    mygetemployerthread.h \
    uploadinvoicethread.h \
    mytoolbutton.h \
    opencvobject.h

FORMS    += LoginDlg.ui \
    headdialog.ui \
    indexdialog.ui \
    uploadinginfoform.ui \
    extengroupform.ui \
    invoiceable.ui \
    picform.ui \
    xuanfuoptionform.ui \
    picviewdialog.ui \
    scandlg.ui \
    webdialog.ui \
    scanoptionform.ui \
    scanverticalform.ui \
    scanlogodialog.ui \
    moveinvoicedialog.ui \
    selectemployerdialog.ui \
    processbardialog.ui

RESOURCES += \
    res.qrc

DISTFILES +=

#INCLUDEPATH +=E:/opencv/build/include

LIBS += -LE:/newjob/InvoiceApp/Include/opencv300/opencv/build/x64/vc12/lib/ -lopencv_world300d\
         -lgdi32
#        -LE:/newjob/InvoiceApp/Include/opencv/build/x64/vc12/lib/ -lopencv_imgproc2410d\
#        -LE:/newjob/InvoiceApp/Include/opencv/build/x64/vc12/lib/ -lopencv_photo2410d\
#        -LE:/newjob/InvoiceApp/Include/opencv/build/x64/vc12/lib/ -lopencv_core2410d\
#        -LE:/newjob/InvoiceApp/Include/opencv/build/x64/vc12/lib/ -lopencv_calib3d2410d\


#CONFIG(debug, debug|release): {
#LIBS += -LE:\opencv\build\x64\vc14\lib\
#-lopencv_world330
#-lopencv_world330d
#}
#else:CONFIG(release, debug|release): {
#LIBS += -LE:\opencv\build\x64\vc14\lib\
#-lopencv_world330
#-lopencv_world330d
#}






