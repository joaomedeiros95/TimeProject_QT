#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_pushButton_clicked();
    void calculardia(int dia, int mes, int ano);

    void on_actionAno_Bissexto_triggered();

    void on_actionSobre_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
