#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::atualizarEstatisticas()
{
    ui->lbl_mais_ass->setText(time.maiorAssiduidade());
    ui->lbl_menos_ass->setText(time.menorAssiduidade());
    ui->lbl_serv->setText(QString::number(time.porcentagemServ(),'f',2)+"%");
    ui->lbl_dep->setText(QString::number(time.porcentagemDep(),'f',2)+"%");
    ui->lbl_conv->setText(QString::number(time.porcentagemConv(),'f',2)+"%");

    //QString color = engenharia.mediaDaTurma() < 70 ? "red" : "black";
    //ui->lbl_avg->setStyleSheet("color: "+color);

}

void MainWindow::inserirJogadorNaTabela(jogador atleta, int row)
{
    ui->tbl_dados->setItem(row,0,new QTableWidgetItem(atleta.getNome()));
    ui->tbl_dados->setItem(row,1,new QTableWidgetItem(atleta.getMatricula()));
    ui->tbl_dados->setItem(row,2,new QTableWidgetItem(QString::number(atleta.getNumero())));
    ui->tbl_dados->setItem(row,3,new QTableWidgetItem(atleta.getCargo()));
}

void MainWindow::on_btn_inserir_clicked()
{
    if(ui->le_nome->text().size() != 0 && ui->le_mat->text().size() != 0 && ui->le_numero->text().size() != 0){
        if((ui->le_mat->text().size() == 11) || (ui->le_mat->text().size() == 7) || (ui->le_mat->text() == "0")){
            QString nome = (ui->le_nome->text()).toLower();

            atleta.setNome(nome);
            atleta.setMatricula(ui->le_mat->text());
            atleta.setNumero(ui->le_numero->text().toInt());

            int qnt_row = ui->tbl_dados->rowCount();

            ui->tbl_dados->insertRow(qnt_row);
            inserirJogadorNaTabela(atleta, qnt_row);

            ui->le_nome->clear();
            ui->le_mat->clear();
            ui->le_numero->clear();

            time.inserirjogador(atleta);
            atualizarEstatisticas();
        }
        else{
            QMessageBox::information(this,"Inserir jogador","Matrícula inválida, tente novamente!");
            ui->le_mat->clear();
        }
    }
}


void MainWindow::on_btn_ordenar_nome_clicked()
{
    ui->tbl_dados->clearContents();

    time.ordenarPorNome();
    for(int i = 0; i<time.size(); i++){
        inserirJogadorNaTabela(time[i], i);
    }
}


void MainWindow::on_btn_ordenar_ass_clicked()
{
    ui->tbl_dados->clearContents();

    time.ordenarPorAssiduidade();
    for(int i = 0; i<time.size(); i++){
        inserirJogadorNaTabela(time[i], i);
    }
}

void MainWindow::on_btn_ordenar_prio_clicked()
{
    ui->tbl_dados->clearContents();

    time.ordenarPorPrioridade();
    for(int i = 0; i<time.size(); i++){
        inserirJogadorNaTabela(time[i], i);
    }
}

void MainWindow::Salvar()
{
    QString nomeArquivo = QFileDialog::getSaveFileName(this,"Lista de Peladeiros","","(*.txt);;(*.csv)");
    if( manipulaarquivo::salvarElenco(nomeArquivo,time) ){
        QMessageBox::information(this, "Salvar pelada","Dados Salvos com Sucesso");
    }else{
        QMessageBox::information(this, "Salvar pelada","Não foi possível salvar os dados");
    }

}

void MainWindow::Carregar()
{
    QString nomeArquivo = QFileDialog::getOpenFileName(this,"Lista de Peladeiros","","(*.txt);;(*.csv)");
    time.clear();

    if(manipulaarquivo::carregarElenco(nomeArquivo,time)){

        ui->tbl_dados->clearContents();
        for(int i=0;i<time.size();i++){

            if(i >= ui->tbl_dados->rowCount())
                ui->tbl_dados->insertRow(i);

            inserirJogadorNaTabela(time[i],i);
        }
    }
}

void MainWindow::on_actionSalvar_triggered()
{
    Salvar();
}

void MainWindow::on_actionCarregar_triggered()
{
    Carregar();
    atualizarEstatisticas();
}

void MainWindow::on_tbl_dados_cellDoubleClicked(int row, int column)
{
    if(column == 0){
        QString nome = QInputDialog::getText(this,"Editar Jogador","O que deseja adicionar: ",QLineEdit::Normal);
        atleta.setNome(nome);
        time.inserirjogador(atleta);
        ui->tbl_dados->clearContents();
        int qnt_row = ui->tbl_dados->rowCount();

        ui->tbl_dados->insertRow(qnt_row);
        inserirJogadorNaTabela(atleta, qnt_row);

        atualizarEstatisticas();
        qDebug() << "Atualizou" << "\n";
    }
    else if(column == 1){
        QString matricula = QInputDialog::getText(this,"Editar Jogador","O que deseja adicionar: ",QLineEdit::Normal);
        atleta.setMatricula(matricula);
        time.inserirjogador(atleta);
        ui->tbl_dados->clearContents();
        ui->tbl_dados->setItem(row,0,new QTableWidgetItem(atleta.getNome()));
        ui->tbl_dados->setItem(row,1,new QTableWidgetItem(atleta.getMatricula()));
        ui->tbl_dados->setItem(row,2,new QTableWidgetItem(QString::number(atleta.getNumero())));
        ui->tbl_dados->setItem(row,3,new QTableWidgetItem(atleta.getCargo()));
        atualizarEstatisticas();
        qDebug() << "Atualizou" << "\n";
    }
    else if(column == 2){
        int numero = QInputDialog::getInt(this,"Editar Jogador","O que deseja adicionar: ");
        atleta.setNumero(numero);

        ui->tbl_dados->clearContents();
        ui->tbl_dados->setItem(row,0,new QTableWidgetItem(time[row].getNome()));
        ui->tbl_dados->setItem(row,1,new QTableWidgetItem(time[row].getMatricula()));
        ui->tbl_dados->setItem(row,2,new QTableWidgetItem(QString::number(time[row].getNumero())));
        ui->tbl_dados->setItem(row,3,new QTableWidgetItem(time[row].getCargo()));
        atualizarEstatisticas();
        qDebug() << "Atualizou" << "\n";
    }
    else{
        QMessageBox::information(this,"Editar jogador","Impossível alterar essas informações!");
    }
}
