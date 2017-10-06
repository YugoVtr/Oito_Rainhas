#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <list>
#include <QTableWidget>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void oito_rainhas(int *array, int linha);
    bool eValido(int *array,int linha ,int coluna);
    void exibir(std::string);
    void limpar();

private slots:
    void on_pushButton_Next_clicked();

    void on_pushButton_Back_clicked();

private:
    Ui::MainWindow *ui;
    int length;
    std::list<std::string> posicoes;
    int solucao;
};

#endif // MAINWINDOW_H
