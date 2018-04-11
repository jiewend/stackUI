#include "faceform.h"
#include "ui_faceform.h"

faceForm::faceForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::faceForm)
{
    setWindowFlags(Qt::FramelessWindowHint);
    ui->setupUi(this);
    connect(ui->pushButton_3,SIGNAL(clicked(bool)),this,SLOT(on_pushButton_3_clicked()));
    connect(ui->pushButton_4,SIGNAL(clicked(bool)),this,SLOT(on_pushButton_4_clicked()));
    connect(ui->pushButton_5,SIGNAL(clicked(bool)),this,SLOT(on_pushButton_5_clicked()));
    connect(ui->pushButton_6,SIGNAL(clicked(bool)),this,SLOT(on_pushButton_6_clicked()));
    connect(ui->pushButton_7,SIGNAL(clicked(bool)),this,SLOT(on_pushButton_7_clicked()));
    connect(ui->pushButton_8,SIGNAL(clicked(bool)),this,SLOT(on_pushButton_8_clicked()));
    connect(ui->pushButton_9,SIGNAL(clicked(bool)),this,SLOT(on_pushButton_9_clicked()));
    connect(ui->pushButton_10,SIGNAL(clicked(bool)),this,SLOT(on_pushButton_10_clicked()));
    connect(ui->pushButton_11,SIGNAL(clicked(bool)),this,SLOT(on_pushButton_11_clicked()));
    connect(ui->pushButton_12,SIGNAL(clicked(bool)),this,SLOT(on_pushButton_12_clicked()));
    connect(ui->pushButton_13,SIGNAL(clicked(bool)),this,SLOT(on_pushButton_13_clicked()));
    connect(ui->pushButton_14,SIGNAL(clicked(bool)),this,SLOT(on_pushButton_14_clicked()));
    connect(ui->pushButton_15,SIGNAL(clicked(bool)),this,SLOT(on_pushButton_15_clicked()));
    connect(ui->pushButton_16,SIGNAL(clicked(bool)),this,SLOT(on_pushButton_16_clicked()));
    connect(ui->pushButton_17,SIGNAL(clicked(bool)),this,SLOT(on_pushButton_17_clicked()));
    connect(ui->pushButton_18,SIGNAL(clicked(bool)),this,SLOT(on_pushButton_18_clicked()));
    connect(ui->pushButton_19,SIGNAL(clicked(bool)),this,SLOT(on_pushButton_19_clicked()));
    connect(ui->pushButton_20,SIGNAL(clicked(bool)),this,SLOT(on_pushButton_20_clicked()));
    connect(ui->pushButton_21,SIGNAL(clicked(bool)),this,SLOT(on_pushButton_21_clicked()));
    connect(ui->pushButton_22,SIGNAL(clicked(bool)),this,SLOT(on_pushButton_22_clicked()));
    connect(ui->pushButton_23,SIGNAL(clicked(bool)),this,SLOT(on_pushButton_23_clicked()));
    connect(ui->pushButton_24,SIGNAL(clicked(bool)),this,SLOT(on_pushButton_24_clicked()));
    connect(ui->pushButton_25,SIGNAL(clicked(bool)),this,SLOT(on_pushButton_25_clicked()));
    connect(ui->pushButton_26,SIGNAL(clicked(bool)),this,SLOT(on_pushButton_26_clicked()));
    connect(ui->pushButton_27,SIGNAL(clicked(bool)),this,SLOT(on_pushButton_27_clicked()));
    connect(ui->pushButton_28,SIGNAL(clicked(bool)),this,SLOT(on_pushButton_28_clicked()));
    connect(ui->pushButton_29,SIGNAL(clicked(bool)),this,SLOT(on_pushButton_29_clicked()));
    connect(ui->pushButton_30,SIGNAL(clicked(bool)),this,SLOT(on_pushButton_30_clicked()));

}

faceForm::~faceForm()
{
    delete ui;
}

void faceForm::on_pushButton_clicked()
{
    this->close();
    emit faceClicked("/[/08.gif/]/");
}

void faceForm::on_pushButton_2_clicked()
{
    this->close();
    emit faceClicked("/[/09.gif/]/");
}

void faceForm::on_pushButton_3_clicked()
{
    this->close();
    emit faceClicked("/[/10.gif/]/");
}

void faceForm::on_pushButton_4_clicked()
{
    this->close();
    emit faceClicked("/[/11.gif/]/");
}

void faceForm::on_pushButton_5_clicked()
{
    this->close();
    emit faceClicked("/[/12.gif/]/");
}

void faceForm::on_pushButton_6_clicked()
{
    this->close();
    emit faceClicked("/[/13.gif/]/");
}

void faceForm::on_pushButton_7_clicked()
{
    this->close();
    emit faceClicked("/[/14.gif/]/");
}

void faceForm::on_pushButton_8_clicked()
{
    this->close();
    emit faceClicked("/[/15.gif/]/");
}

void faceForm::on_pushButton_9_clicked()
{
    this->close();
    emit faceClicked("/[/46.gif/]/");
}

void faceForm::on_pushButton_10_clicked()
{
    this->close();
    emit faceClicked("/[/17.gif/]/");
}

void faceForm::on_pushButton_11_clicked()
{
    this->close();
    emit faceClicked("/[/23.gif/]/");
}

void faceForm::on_pushButton_12_clicked()
{
    this->close();
    emit faceClicked("/[/29.gif/]/");
}

void faceForm::on_pushButton_13_clicked()
{
    this->close();
    emit faceClicked("/[/21.gif/]/");
}

void faceForm::on_pushButton_14_clicked()
{
    this->close();
    emit faceClicked("/[/28.gif/]/");
}

void faceForm::on_pushButton_15_clicked()
{
    this->close();
    emit faceClicked("/[/27.gif/]/");
}

void faceForm::on_pushButton_16_clicked()
{
    this->close();
    emit faceClicked("/[/25.gif/]/");
}

void faceForm::on_pushButton_17_clicked()
{
    this->close();
    emit faceClicked("/[/18.gif/]/");
}

void faceForm::on_pushButton_18_clicked()
{
    this->close();
    emit faceClicked("/[/19.gif/]/");
}

void faceForm::on_pushButton_19_clicked()
{
    this->close();
    emit faceClicked("/[/26.gif/]/");
}

void faceForm::on_pushButton_20_clicked()
{
    this->close();
    emit faceClicked("/[/45.gif/]/");
}

void faceForm::on_pushButton_21_clicked()
{
    this->close();
    emit faceClicked("/[/35.gif/]/");
}

void faceForm::on_pushButton_22_clicked()
{
    this->close();
    emit faceClicked("/[/43.gif/]/");
}

void faceForm::on_pushButton_23_clicked()
{
    this->close();
    emit faceClicked("/[/33.gif/]/");
}

void faceForm::on_pushButton_24_clicked()
{
    this->close();
    emit faceClicked("/[/42.gif/]/");
}

void faceForm::on_pushButton_25_clicked()
{
    this->close();
    emit faceClicked("/[/39.gif/]/");
}

void faceForm::on_pushButton_26_clicked()
{
    this->close();
    emit faceClicked("/[/37.gif/]/");
}

void faceForm::on_pushButton_27_clicked()
{
    this->close();
    emit faceClicked("/[/30.gif/]/");
}

void faceForm::on_pushButton_28_clicked()
{
    this->close();
    emit faceClicked("/[/31.gif/]/");
}

void faceForm::on_pushButton_29_clicked()
{
    this->close();
    emit faceClicked("/[/50.gif/]/");
}

void faceForm::on_pushButton_30_clicked()
{
    this->close();
    emit faceClicked("/[/36.gif/]/");
}
