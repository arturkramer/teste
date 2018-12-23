#include "manipulaarquivo.h"

manipulaarquivo::manipulaarquivo()
{

}

bool manipulaarquivo::salvarElenco(QString &arquivo, elenco &Elenco)
{
    QFile file(arquivo);

    if(!file.open(QIODevice::WriteOnly)){
        return false;
    }

    QTextStream out(&file);

    for(int i=0;i<Elenco.size();i++){
        out << Elenco[i].getNome()<<","<<Elenco[i].getMatricula()<<","<<Elenco[i].getNumero() <<  "," << Elenco[i].getCargo() << "\n";
    }
    file.close();
    return true;

}

bool manipulaarquivo::carregarElenco(QString &arquivo, elenco &Elenco)
{
    QFile file(arquivo);

    if(!file.open(QIODevice::ReadOnly)){
        return false;
    }

    QTextStream in(&file);

    QString linha;

    while(!in.atEnd()){
        linha = in.readLine();

        QStringList dados = linha.split(",");

        jogador a(dados[0],dados[1],dados[2].toInt(),dados[3]);
        Elenco.inserirjogador(a);

    }
    return true;
}




