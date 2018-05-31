#ifndef MARCA_H
#define MARCA_H

#include <oid.h>
#include <QString>
#include <idados.h>
#include <llde.h>

namespace Lobo {
class Marca;
}

class Marca : public IDados
{
protected:
    oid<int> id;
    int descricao;
    QString foto;
public:
    Marca();
    Marca(oid id, int descricao, QString foto);

    int getId()const{return id;}
    int getDescricao()const{return descricao;}
    QString getFoto()const{return foto;}

    void setId(oid<int> id){this->id = id;}
    void setDescricao(int descricao){this->descricao = descricao;}
    void setFoto(QString foto){this->foto = foto;}

    QString desmontarDados()const;
    void montarDados(QString &str);
};

#endif // MARCA_H
