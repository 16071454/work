#include "picviewdialog.h"
#include "ui_picviewdialog.h"
#include "QPushButton"
#include <QIcon>
#include <QDesktopWidget>

PicViewDialog::PicViewDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PicViewDialog)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setFixedSize(QApplication::desktop()->size());
    QPushButton *label = new QPushButton(this);
    label->setFixedSize(110,48);
    label->setStyleSheet("QPushButton{background-image: url(:/imag/closeclicked .png);background-repeat: no-repeat;background-position:left;border:none;}"
                                    "QPushButton:hover{background-image: url(:/imag/closehover.png);background-repeat: no-repeat;background-position:left;border:none;}"
                                    "QPushButton:pressed{background-image: url(:/imag/closeclicked .png);background-repeat: no-repeat;background-position:left;border:none;}");

   // QIcon pixmap(":/imag/u241.png");
  //  label->setIconSize(QSize(40,40));
   // label->setIcon(pixmap);
    label->move(this->width()-10-label->width(),10);
    connect(label,&QPushButton::clicked,this,[=](){this->close();});
    label->setFlat(true);
    label->setFocusPolicy(Qt::NoFocus);
    this->setWindowOpacity(0.95);


}

PicViewDialog::~PicViewDialog()
{
    delete ui;
}

void PicViewDialog::setpicPath(QString picpath,int roation)
{
    ui->label->setFixedSize(800,600);
    QPixmap pixmaplogo (picpath);
    QMatrix matrix;
    matrix.rotate(0-roation);

    pixmaplogo = pixmaplogo.scaled(ui->label->size(), Qt::KeepAspectRatio);
    ui->label->setPixmap(pixmaplogo.transformed(matrix, Qt::SmoothTransformation));


    // QLabel *Label= new QLabel();
    // Label->setFixedSize(400,800);
    //  Label->setScaledContents(true);
    //     QPixmap pixmap3("E:/newjob/pixmap1.jpg");
    //     pixmap3.transformed(matrix, Qt::SmoothTransformation);
    //     pixmap3.save("E:/newjob/pixmap2.jpg");
    //   pixmap3.scaled(Label->size(), Qt::KeepAspectRatio);
    //Label->setPixmap(pixmap3.transformed(matrix, Qt::SmoothTransformation));
    // Label->show();

    //    ui->label->setFixedSize(500,400);
    //    QImage ShowLoadImage(picpath);
    //    //ui->label->setScaledContents(true);

    //    ui->label->setPixmap(QPixmap::fromImage(ShowLoadImage).scaled(ui->label->width(),
    //                                                                            ui->label->height(),
    //                                                                            Qt::KeepAspectRatio,
    //                                                                            Qt::SmoothTransformation));
}
