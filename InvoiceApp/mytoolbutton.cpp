#include "mytoolbutton.h"

MyToolButton::MyToolButton(QObject *parent)
{

}

void MyToolButton::setType(INVOICETYPE type)
{
    _type =type;
    switch (_type) {
    case RECIPTION:
    {
        QPixmap pmap(":/imag/saomiaoreciptionnormal.png");
        this->setIcon(pmap);
        this->setIconSize(pmap.size());
        break;
    }

    case ADDWORK:
    {
        QPixmap pmap(":/imag/saomiaoaddworknormal.png");
        this->setIcon(pmap);
        this->setIconSize(pmap.size());
        break;
    }
    case TEAMWORK:
    {
        QPixmap pmap(":/imag/saomiaoteamworknormal.png");
        this->setIcon(pmap);
        this->setIconSize(pmap.size());
        break;
    }
    case TRAVEL:
    {
        QPixmap pmap(":/imag/saomiaotravelnormal.png");
        this->setIcon(pmap);
        this->setIconSize(pmap.size());
        break;
    }
    case OTHERS:
    {
        QPixmap pmap(":/imag/saomiaoothernormal.png");
        this->setIcon(pmap);
        this->setIconSize(pmap.size());
        break;
    }
    default:
        break;
    }
}

void MyToolButton::enterEvent(QEvent *e)
{
    switch (_type) {
    case RECIPTION:
    {
        QPixmap pmap(":/imag/saomiaoreciptionhover.png");
        this->setIcon(pmap);
        this->setIconSize(pmap.size());
        break;
    }

    case ADDWORK:
    {
        QPixmap pmap(":/imag/saomiaoaddworkhover.png");
        this->setIcon(pmap);
        this->setIconSize(pmap.size());
        break;
    }
    case TEAMWORK:
    {
        QPixmap pmap(":/imag/saomiaoteamworkhover.png");
        this->setIcon(pmap);
        this->setIconSize(pmap.size());
        break;
    }
    case TRAVEL:
    {
        QPixmap pmap(":/imag/saomiaotravelhover.png");
        this->setIcon(pmap);
        this->setIconSize(pmap.size());
        break;
    }
    case OTHERS:
    {
        QPixmap pmap(":/imag/saomiaootherhover.png");
        this->setIcon(pmap);
        this->setIconSize(pmap.size());
        break;
    }
    default:
        break;
    }
}

void MyToolButton::leaveEvent(QEvent *e)
{
    switch (_type) {
    case RECIPTION:
    {
        QPixmap pmap(":/imag/saomiaoreciptionnormal.png");
        this->setIcon(pmap);
        this->setIconSize(pmap.size());
        break;
    }

    case ADDWORK:
    {
        QPixmap pmap(":/imag/saomiaoaddworknormal.png");
        this->setIcon(pmap);
        this->setIconSize(pmap.size());
        break;
    }
    case TEAMWORK:
    {
        QPixmap pmap(":/imag/saomiaoteamworknormal.png");
        this->setIcon(pmap);
        this->setIconSize(pmap.size());
        break;
    }
    case TRAVEL:
    {
        QPixmap pmap(":/imag/saomiaotravelnormal.png");
        this->setIcon(pmap);
        this->setIconSize(pmap.size());
        break;
    }
    case OTHERS:
    {
        QPixmap pmap(":/imag/saomiaoothernormal.png");
        this->setIcon(pmap);
        this->setIconSize(pmap.size());
        break;
    }
    default:
        break;
    }
}

