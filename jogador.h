#ifndef JOGADOR_H
#define JOGADOR_H

#include <QObject>
#include <QMessageBox>


class jogador
{
    
private:
    QString nome,matricula;
    int numero;
    QString cargo;
    
public:
    jogador();
    jogador(QString nm,QString m,int n,QString c);
    
    QString getNome() const;
    void setNome(const QString &value);

    QString getMatricula() const;
    void setMatricula(const QString &value);
    
    int getNumero();
    void setNumero(int value);

    QString getCargo();
};

#endif // JOGADOR_H
