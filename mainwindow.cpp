#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <time.h>
#include "bissexto.h"
#include "sobre.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label_4->setText("");
    ui->lineEdit->setPlaceholderText("Ano:");
    ui->lineEdit_2->setPlaceholderText("Dia:");
    ui->lineEdit_3->setPlaceholderText("Mês:");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    int ano = ui->lineEdit->text().toInt();
    int dia = ui->lineEdit_2->text().toInt();
    int mes = ui->lineEdit_3->text().toInt();

    calculardia(dia, mes, ano);
}

void MainWindow::calculardia (int dia, int mes, int ano) {
    time_t tempocorrido;
    struct tm * infotempo;
    const char * diadasemana[] = { "Domingo", "Segunda",
                                "Terça", "Quarta",
                                "Quinta", "Sexta", "Sábado"};

    time ( &tempocorrido );
    infotempo = localtime ( &tempocorrido );
    infotempo->tm_year = ano - 1900;
    infotempo->tm_mon = mes - 1;
    infotempo->tm_mday = dia;

    mktime ( infotempo );

    ui->label_4->setText(diadasemana[infotempo->tm_wday]);

}

void MainWindow::on_actionAno_Bissexto_triggered()
{
    Bissexto bissexto;
    bissexto.setModal(true);
    bissexto.exec();
}

void MainWindow::on_actionSobre_triggered()
{
    Sobre sobre;
    sobre.setModal(true);
    sobre.exec();
}
