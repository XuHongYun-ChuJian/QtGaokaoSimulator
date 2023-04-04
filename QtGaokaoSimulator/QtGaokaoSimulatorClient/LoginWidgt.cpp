#include "LoginWidgt.h"
#include "ui_loginwidgt.h"

LoginWidgt::LoginWidgt(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginWidgt)
{
    ui->setupUi(this);
}

LoginWidgt::~LoginWidgt()
{
    delete ui;
}
