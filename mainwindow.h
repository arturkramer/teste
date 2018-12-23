#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QVector>
#include <QFileDialog>
#include <QMessageBox>
#include <QInputDialog>
#include <QString>
#include "manipulaarquivo.h"
#include "jogador.h"
#include "elenco.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    elenco time;
    elenco time2;
    jogador atleta;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void atualizarEstatisticas();

private slots:

    void on_btn_inserir_clicked();

    void on_btn_ordenar_nome_clicked();

    void on_btn_ordenar_ass_clicked();

    void on_btn_ordenar_prio_clicked();

    void on_actionSalvar_triggered();

    void on_actionCarregar_triggered();

    void on_tbl_dados_cellDoubleClicked(int row, int column);

private:
    Ui::MainWindow *ui;
    void inserirJogadorNaTabela(jogador atleta, int row);

    void Salvar();
    void Carregar();
};

#endif // MAINWINDOW_H

