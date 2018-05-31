#ifndef ICRUD_H
#define ICRUD_H
#include "marca.h"

namespace Lobo {
class Icrud;
}

class Icrud{
    virtual void incluir(Marca objeto) const=0;
    virtual std::list<Marca>* listagem() const=0;
    virtual void alterar(oid ID) const=0;
};

#endif // ICRUD_H
