#include "elenco.h"

int elenco::getCont_serv() const
{
    return cont_serv;
}

void elenco::setCont_serv(int value)
{
    cont_serv = value;
}

int elenco::getCont_dep() const
{
    return cont_dep;
}

void elenco::setCont_dep(int value)
{
    cont_dep = value;
}

int elenco::getCont_conv() const
{
    return cont_conv;
}

void elenco::setCont_conv(int value)
{
    cont_conv = value;
}

elenco::elenco(QObject *parent) : QObject(parent)
{
    setCont_conv(0);
    setCont_dep(0);
    setCont_serv(0);
}

void elenco::inserirjogador(jogador a)
{
    Elenco.push_back(a);
    if(a.getCargo() == "Servidor"){
        setCont_serv(getCont_serv()+1);
    }
    else if(a.getCargo() == "Dependente"){
        setCont_dep(getCont_dep()+1);
    }
    else if(a.getCargo() == "Convidado"){
        setCont_conv(getCont_conv()+1);
    }
}

QString elenco::maiorAssiduidade()
{
    jogador *maior = std::max_element(Elenco.begin(),Elenco.end(),[](jogador a, jogador b){ return a.getNumero() < b.getNumero();});
    return maior->getNome();
}

QString elenco::menorAssiduidade()
{
    jogador *menor = std::min_element(Elenco.begin(),Elenco.end(),[](jogador a, jogador b){ return a.getNumero() < b.getNumero();});
    return menor->getNome();
}

float elenco::porcentagemServ()
{
    return ((getCont_serv()*100.0)/Elenco.size());
}

float elenco::porcentagemDep()
{
    return ((getCont_dep()*100.0)/Elenco.size());
}

float elenco::porcentagemConv()
{
    return ((getCont_conv()*100.0)/Elenco.size());
}

void elenco::ordenarPorNome()
{
    std::sort(Elenco.begin(), Elenco.end(), [](jogador a, jogador b){return a.getNome()<b.getNome();});
}

void elenco::ordenarPorAssiduidade()
{
    std::sort(Elenco.begin(), Elenco.end(), [](jogador a, jogador b){return a.getNumero()>b.getNumero();});
}


void elenco::ordenarPorPrioridade()
{
    std::sort(Elenco.begin(), Elenco.end(), [](jogador a, jogador b){return a.getCargo()>b.getCargo();});
}

int elenco::size()
{
    return Elenco.size();
}

void elenco::clear()
{
    Elenco.clear();
}

jogador elenco::operator[](int i)
{
    return Elenco[i];
}





