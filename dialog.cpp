#include "dialog.h"
#include "ui_dialog.h"
#include <QTextBrowser>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(ui->modalButton, &QPushButton::clicked, this, &Dialog::Modal);
    connect(ui->nonModalButton, &QPushButton::clicked, this, &Dialog::NonModal);
    connect(ui->customButton, &QPushButton::clicked, this, &Dialog::Custom);
    connect(ui->closeButton, &QPushButton::clicked, this, &Dialog::accept);

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::Modal() {
    dptr = new QDialog(this);
    dptr->setModal(true);
    QVBoxLayout* mainLayout = new QVBoxLayout(dptr);
    mainLayout->addWidget(new QLabel("Hello"));
    mainLayout->addStretch();
    mainLayout->addWidget(new QLabel("World"));
    mainLayout->addStretch();
    mainLayout->addWidget(new QLabel("Modal"));
    dptr->show();
    // dptr->exec(); also sets the Modal to true automatically
}

void Dialog::NonModal() {
    dptr = new QDialog(this);
    dptr->setModal(false);
    QVBoxLayout* mainLayout = new QVBoxLayout(dptr);
    mainLayout->addWidget(new QLabel("Hello"));
    mainLayout->addStretch();
    mainLayout->addWidget(new QLabel("World"));
    mainLayout->addStretch();
    mainLayout->addWidget(new QLabel("Non-Modal"));
    dptr->show();
}

void Dialog::Custom() {
    dptr = new QDialog(this);
    dptr->setModal(true);
    QVBoxLayout* mainLayout = new QVBoxLayout(dptr);
    QTextBrowser* tb = new QTextBrowser();
    tb->setHtml("Text displayed within a <b>QTextBrowser</b> widget.");
    QPushButton* clos = new QPushButton("Close");
    mainLayout->addWidget(tb);
    mainLayout->addWidget(clos);
    dptr->connect(clos, &QPushButton::clicked, dptr, &QDialog::accept);
    dptr->show();
}
