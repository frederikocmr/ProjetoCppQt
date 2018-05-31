#ifndef LLDE_H
#define LLDE_H
#include<no.h>
#include<QString>
#include<string>

namespace Lobo{
    class LLDE;
}

template <class tipo>
class LLDE
{
private:
    No<tipo>* ptFim;
    No<tipo>* ptInicio;
protected:
    int qElementos;
public:
    LLDE(): ptFim(0), ptInicio(0), qElementos(0){}
    ~LLDE();
    int getqElementos()const{return qElementos;}
    void inserirInicio(tipo elemento);
    tipo retirarInicio();
    void inserirFim(tipo elemento);
    tipo retirarFim();
    tipo operator[](int posicao);
    void inserirPosicao(int posicao, tipo elemento);
    void inserirOrdenado(tipo elemento);
    QString girarHorario(int laps);
    QString girarAntiHorario(int laps);
    int buscarElemento(tipo elemento);
    void inserirOrdenadoX(tipo elemento);
};

template <class tipo>
void LLDE<tipo>::inserirInicio(tipo elemento)
{
    try{
        No<tipo> *ptAux = new No<tipo>(elemento);//criar o No
        if(!qElementos){//se for o primeiro elemento
            ptInicio=ptFim=ptAux;
            ptInicio->setProximo(ptInicio);
            ptFim->setAnterior(ptFim);
        }
        ptAux->setProximo(ptInicio);//aux aponta proximo para inicio
        ptInicio->setAnterior(ptAux);//inicio aponta anterior para aux
        ptInicio=ptAux;
        ptInicio->setAnterior(ptFim);
        ptFim->setProximo(ptInicio);
        qElementos++;
        return;
    } catch(std::bad_alloc&){
        throw QString ("Nao foi possivel criar o No");
    }
}

template <class tipo>
tipo LLDE<tipo>::retirarInicio()
{
    if(!qElementos){//se ponteiro para inicio for 0
        throw QString("LLDE vazia");
    }
    No<tipo> *ptAux=ptInicio;
    ptInicio=ptInicio->getProximo();
    ptFim->setProximo(ptInicio);
    ptInicio->setAnterior(ptFim);
    tipo valor=ptAux->getInformacao();//armazena o valor do ponteiro auxiliar
    delete ptAux;
    qElementos--;
    return valor;
}

template <class tipo>
void LLDE<tipo>::inserirFim(tipo elemento)
{
    try{
        No<tipo> *ptAux = new No<tipo>(elemento);

        if(!qElementos){
            ptInicio=ptFim=ptAux;
            ptInicio->setProximo(ptInicio);
            ptFim->setAnterior(ptFim);

        }
        ptFim->setProximo(ptAux);
        ptAux->setAnterior(ptFim);
        ptInicio->setAnterior(ptAux);
        ptAux->setProximo(ptInicio);
        ptFim=ptAux;
        qElementos++;
        return;
    } catch(std::bad_alloc&){
        throw QString ("Nao foi possivel criar o No");
    }
}

template <class tipo>
tipo LLDE<tipo>::retirarFim()
{
    if(qElementos == 0) throw QString ("Lista Vazia");

    No<tipo> *ptAux = ptFim;
    if(qElementos == 1)
    {
        ptInicio = 0;
        ptFim = 0;
        tipo valor = ptAux->getInformacao();
        delete ptAux;
        qElementos--;
        return valor;
    }

    ptFim = ptAux->getAnterior();
    ptFim->setProximo(ptInicio);
    ptInicio->setAnterior(ptFim);
    qElementos--;
    tipo valor = ptAux->getInformacao();
    delete ptAux;
    return valor;
}


template <class tipo>
tipo LLDE<tipo>::operator [](int posicao)
{
    if(!ptInicio){
        throw QString("LLSE Vazia");
    }
    if(posicao<0 || posicao>=qElementos){
        throw QString("Posicao invalida a Acessar\n");
    }
    No<tipo> *ptAux=ptInicio;
    for(int i=0;i<posicao;i++){
        ptAux=ptAux->getProximo();
    }
    tipo valor=ptAux->getInformacao();//armazena o valor do ponteiro auxiliar

    return valor;
}

template <class tipo>
void LLDE<tipo>::inserirPosicao(int posicao, tipo elemento)
{
    if(posicao<0 || posicao>qElementos){
        throw QString ("Posicao Invalida");
    }
    if(posicao==0){
        this->inserirInicio(elemento);
        return;
    }
    if(posicao==qElementos){
        this->inserirFim(elemento);
        return;
    }
    No<tipo> *ptBlack = ptInicio;
    for(int i=1;i<posicao;i++){
        ptBlack = ptBlack->getProximo();
    }
    No<int> *ptAux = new No<int>(elemento);
    ptAux->setProximo(ptBlack->getProximo());
    ptAux->setAnterior(ptBlack->getAnterior());
    ptBlack->setProximo(ptAux);
    ptBlack->setAnterior(ptAux);
    qElementos++;
    return;
}

template <class tipo>
void LLDE<tipo>::inserirOrdenado(tipo elemento)
{
    No<tipo> *ptAux = new No<tipo>(elemento);
    if(qElementos==0 || ptInicio->getInformacao()>elemento){
        inserirInicio(elemento);
        return;
    }

    if(ptFim->getInformacao()<elemento){
        inserirFim(elemento);
        return;
    }
    No<tipo> *ptBlack = ptInicio,*ptRed = ptInicio;
    int i=0;
    while(ptBlack!=0 && ptBlack->getInformacao()<elemento && i <qElementos){
        ptRed=ptBlack;
        ptBlack=ptBlack->getProximo();
        i++;
    }

    ptRed->setProximo(ptAux);
    ptAux->setAnterior(ptRed);
    ptAux->setProximo(ptBlack);
    ptBlack->setAnterior(ptAux);

    qElementos++;
    return;
}

template <class tipo>
QString LLDE<tipo>::girarHorario(int laps)
{
    QString show="";
    for(int i=0;i<laps;i++)
    {
        No<tipo> *ptBlack = ptInicio->getAnterior();
        for(int j=0;j<qElementos;j++)
        {
            ptBlack=ptBlack->getProximo();
            show+=QString::number(ptBlack->getInformacao());
            show+="/";
        }
        show+="\n";
    }
    return show;
}

template <class tipo>
QString LLDE<tipo>::girarAntiHorario(int laps)
{
    QString show="";
    for(int i=0;i<laps;i++)
    {
        No<tipo> *ptBlue = ptFim;
        for(int j=0;j<qElementos;j++)
        {
            show+=QString::number(ptBlue->getInformacao());
            ptBlue=ptBlue->getAnterior();
            show+="/";
        }
        show+="\n";
    }
    return show;
}

template <class tipo>
int LLDE<tipo>::buscarElemento(tipo elemento)
{
    No<tipo> *ptBlack = ptInicio;
    No<tipo> *ptRed = ptFim;
    for(int i=0;i<qElementos/2;i++)
    {
        if(ptBlack->getInformacao()==elemento)
        {
            return i;
        }
        ptBlack=ptBlack->getProximo();
        if(ptRed->getInformacao()==elemento)
        {
            return qElementos-i;
        }
        ptRed=ptRed->getAnterior();
    }
    throw QString("Elemento nao encontrado");
}

template <class tipo>
void LLDE<tipo>::inserirOrdenadoX(tipo elemento)
{
    No<tipo> *ptAux = new No<tipo>(elemento);

    if(qElementos==0 || ptInicio->getInformacao()>elemento){
        inserirInicio(elemento);
        return;
    }

    if(ptFim->getInformacao()<elemento){
        inserirFim(elemento);
        return;
    }
    No<tipo> *ptBlack = ptInicio,*ptRed = ptInicio;
    if(ptBlack->getInformacao()==elemento)
    {
        throw QString("Elemento repetido\n");
    }
    int i=0;
    while(ptBlack!=0 && ptBlack->getInformacao()<elemento && i <qElementos){
        ptRed=ptBlack;
        ptBlack=ptBlack->getProximo();
        i++;
        if(ptBlack->getInformacao()==elemento)
        {
            throw QString("Elemento repetido\n");
        }
    }

    ptRed->setProximo(ptAux);
    ptAux->setAnterior(ptRed);
    ptAux->setProximo(ptBlack);
    ptBlack->setAnterior(ptAux);

    qElementos++;
    return;
}

template <class tipo>
LLDE<tipo>::~LLDE(){

}



#endif // LLDE_H
