#ifndef MANIPULAARQUIVO_H
#define MANIPULAARQUIVO_H

#include <QObject>
#include <QFile>
#include <QTextStream>
#include <fstream>
#include <QDebug>

#include "elenco.h"
#include "jogador.h"


class manipulaarquivo
{
public:
    manipulaarquivo();
    static bool salvarElenco(QString &arquivo, elenco &Elenco);
    static bool carregarElenco(QString &arquivo, elenco &Elenco);
};


#endif // ARQUIVO_H
