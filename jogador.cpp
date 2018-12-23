#include "jogador.h"

jogador::jogador()
{
    
}

jogador::jogador(QString nm, QString m, int n, QString c)
{
        nome = nm;
        matricula = m;
        numero = n;
        cargo = c;
}

QString jogador::getNome() const
{
    return nome;
}

void jogador::setNome(const QString &value)
{
    nome = value;
}

QString jogador::getMatricula() const
{
    return matricula;
}

void jogador::setMatricula(const QString &value)
{
    matricula = value;
}

int jogador::getNumero()
{
    return numero;
}

void jogador::setNumero(int value)
{
    numero = value;
}

QString jogador::getCargo()
{
    if(matricula.size() == 11){
        cargo = "Dependente";
        return cargo;
    }
    else if(matricula.size() == 7){
        cargo = "Servidor";
        return cargo;
    }
    else if(matricula == "0"){
        return cargo = "Convidado";
    }
    else{
        return cargo = "Inválido";
    }
}










