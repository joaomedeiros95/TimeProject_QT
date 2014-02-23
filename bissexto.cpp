#include "bissexto.h"
#include "ui_bissexto.h"
#include <time.h>

Bissexto::Bissexto(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Bissexto)
{
    ui->setupUi(this);
    ui->label_2->setText("");
    ui->lineEdit->setPlaceholderText("Digite o Ano...");
}

Bissexto::~Bissexto()
{
    delete ui;
}

void Bissexto::on_pushButton_clicked()
{
    int ano = ui->lineEdit->text().toInt();

    time_t rawtime;
    struct tm * timeinfo;

    time ( &rawtime );                      //Testa para encontrar o dia do ano se o mês fosse de 29 dias;
    timeinfo = localtime ( &rawtime );
    timeinfo->tm_year = ano - 1900;
    timeinfo->tm_mon = 2 - 1;
    timeinfo->tm_mday = 29;

    mktime ( timeinfo );

    int primeiro = timeinfo->tm_wday;

    time ( &rawtime );                      //Testa para encontrar o primeiro dia do mês de março do ano dado;
    timeinfo = localtime ( &rawtime );
    timeinfo->tm_year = ano - 1900;
    timeinfo->tm_mon = 3 - 1;
    timeinfo->tm_mday = 1;

    mktime (timeinfo);

    int segundo = timeinfo->tm_wday;

    if (primeiro == segundo) {              //Se o primeiro dia de março for igual ao dia 29 de fevereiro, então o ano não é bissexto!
        ui->label_2->setText("Ano não é bissexto!");
    }
    else {                                  //Se os dias forem diferentes é porque o ano é bissexto!
        ui->label_2->setText("Ano é bissexto!");
    }
}
