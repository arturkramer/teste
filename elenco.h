#ifndef ELENCO_H
#define ELENCO_H

#include <QObject>
#include <QVector>
#include <numeric>
#include <algorithm>

#include "jogador.h"

class elenco : public QObject
{
    Q_OBJECT
private:
    QVector<jogador> Elenco;
    int cont_serv;
    int cont_dep;
    int cont_conv;
   
public:
    explicit elenco(QObject *parent = nullptr);
    void inserirjogador(jogador a);
    QString maiorAssiduidade();
    QString menorAssiduidade();
    float porcentagemServ();
    float porcentagemDep();
    float porcentagemConv();
    void ordenarPorNome();
    void ordenarPorAssiduidade();
    void ordenarPorPrioridade();
    
    int size();
    void clear();

    jogador operator[](int i);

    int getCont_serv() const;
    void setCont_serv(int value);

    int getCont_dep() const;
    void setCont_dep(int value);

    int getCont_conv() const;
    void setCont_conv(int value);

signals:

public slots:
};

#endif // ELENCO_H
