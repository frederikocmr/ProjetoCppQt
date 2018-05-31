#ifndef IDADOS_H
#define IDADOS_H

#include <QString>

namespace Lobo {
class IDados;
}

//Interface
class IDados{
    virtual QString desmontarDados()const = 0;
    virtual void montarDados(QString &str) = 0;
};

#endif // IDADOS_H
