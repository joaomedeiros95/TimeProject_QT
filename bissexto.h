#ifndef BISSEXTO_H
#define BISSEXTO_H

#include <QDialog>

namespace Ui {
class Bissexto;
}

class Bissexto : public QDialog
{
    Q_OBJECT

public:
    explicit Bissexto(QWidget *parent = 0);
    ~Bissexto();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Bissexto *ui;
};

#endif // BISSEXTO_H
