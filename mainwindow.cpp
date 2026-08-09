#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Eval.h"
#include <QButtonGroup>
#include <QLineEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    numberGroup= new QButtonGroup(this);

    numberGroup->addButton(ui->btn0);
    numberGroup->addButton(ui->btn1);
    numberGroup->addButton(ui->btn2);
    numberGroup->addButton(ui->btn3);
    numberGroup->addButton(ui->btn4);
    numberGroup->addButton(ui->btn5);
    numberGroup->addButton(ui->btn6);
    numberGroup->addButton(ui->btn7);
    numberGroup->addButton(ui->btn8);
    numberGroup->addButton(ui->btn9);
    numberGroup->addButton(ui->btnPoint);
    numberGroup->addButton(ui->btnPlus);
    numberGroup->addButton(ui->btnOpen);
    numberGroup->addButton(ui->btnClose);
    numberGroup->addButton(ui->btnMul);
    numberGroup->addButton(ui->btnMinus);
    numberGroup->addButton(ui->btnDiv);

    connect(numberGroup,
            QOverload<QAbstractButton*>::of(&QButtonGroup::buttonClicked),
            this,
            &MainWindow::on_numberButton_clicked);



}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_btnEqual_clicked()
{
    Eval eval;
    double res=eval.Evaluate(expr.toStdString());
    QString qstr = QString("%1").arg(res);
    ui->lblResult->setText(qstr);

}

void MainWindow::on_numberButton_clicked(QAbstractButton *button)
{
   expr.append(button->text());
   ui->lblResult->setText(expr);
}

void MainWindow::on_btnBackspace_clicked()
{
    expr.remove(expr.length()-1,1);
    ui->lblResult->setText(expr);
}


void MainWindow::on_btnCancel_clicked()
{

    ui->lblResult->clear();
}

