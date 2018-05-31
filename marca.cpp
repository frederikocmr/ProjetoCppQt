#include "marca.h"

Marca::Marca():
    id(0),
    descricao(0),
    foto("")
{}

Marca::Marca(oid id, int descricao, QString foto):
    id(id),
    descricao(descricao),
    foto(foto)
{}

QString Marca::desmontarDados()const
{
    QString saida = QString::number(id);
    saida += ";";
    saida += QString::number(descricao);
    saida += ";";
    saida += foto;
    return saida;
}

void Marca::montarDados(QString &str)
{
    try{
        QStringList strList = str.split(';');
        if(strList.length()!=3) throw ;
        id = strList[0].toInt();
        descricao = strList[1].toInt();
        foto = strList[2];

    } catch (...) {
        throw QString("Erro no metodo Materializar classe Marca");
    }
}
