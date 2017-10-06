#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    length(8),
    posicoes(),
    solucao(1)
{
    ui->setupUi(this);
    int distribuicao[8];
    oito_rainhas(&distribuicao[0],0);
    std::string padrao = posicoes.front();

    exibir(padrao);

}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::eValido(int *array,int linha ,int coluna)
{
    for(int i = linha - 1 ; i >= 0 ; i--)
    {
        if(
                array[i] == coluna ||
                array[i] == coluna - (linha - i) ||
                array[i] == coluna + (linha - i)
                )
            return false;
    }
    return true;
}

void MainWindow::oito_rainhas(int *array, int linha){

    if(linha < length)
    {
        for(int coluna = 0 ; coluna < length ; coluna++)
        {
            if(eValido(array,linha,coluna))
            {
                array[linha] = coluna;
                oito_rainhas(array , linha + 1);
            }
        }
    }
    else
    {
        std::string valor = "" ;
        for(int i = 0 ; i < length  ; i++)
            valor += (char)(array[i] + 48);
        posicoes.push_back(valor);
    }
}

void MainWindow::limpar(){
    for(int linha = 0 ; linha < ui->tableWidget_Tabuleiro->rowCount() ; linha++)
        for(int coluna = 0 ; coluna < ui->tableWidget_Tabuleiro->columnCount() ; coluna++)
            if(ui->tableWidget_Tabuleiro->item(linha,coluna)) delete ui->tableWidget_Tabuleiro->item(linha,coluna);
}

void MainWindow::exibir(std::string str)
{
    limpar();
    ui->label->setText(QString::number(solucao));
    QPixmap rainha(":/rainha.png");
    rainha.scaled(QSize(48,48));

    for(int i = 0 ; str[i] ; i++)
        ui->tableWidget_Tabuleiro->setItem(i,(int)(str[i]-48),new QTableWidgetItem(QIcon(rainha),""));
}

void MainWindow::on_pushButton_Next_clicked()
{
    solucao++;
    if(solucao>92) solucao = 1;
    posicoes.push_back(posicoes.front());
    posicoes.pop_front();
    exibir(posicoes.front());
}

void MainWindow::on_pushButton_Back_clicked()
{
    solucao--;
    if(solucao<1) solucao = 92;
    posicoes.push_front(posicoes.back());
    posicoes.pop_back();
    exibir(posicoes.front());
}
