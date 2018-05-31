#include "oid.h"

oid::oid()
{

}
int oid::geradorID()
{
    QString nomeDoArquivoNoDisco= "id.csv";

    int IDatual;
    int IDbkp;
    QString str, ID;
    try{

        std::ifstream arquivoID;
        arquivoID.open(nomeDoArquivoNoDisco.toStdString().c_str(),
                       std::ios::out|std::ios::app);
        if(!arquivoID.is_open())//verificação de abertura de arquivo
        {
            throw QString("Arquivo de Agenda nao foi aberto");//LE
        }
        std::string linha;
        std::getline(arquivoID,linha);
        while (!arquivoID.eof()){
            str = QString::fromStdString(linha);
            std::getline(arquivoID,linha);
        }
        if(str ==NULL){
            IDatual=1;
        }

        IDbkp=  str.toInt();
        arquivoID.close();

        std::ofstream arquivoID2;
        arquivoID2.open(nomeDoArquivoNoDisco.toStdString().c_str());
        if(!arquivoID2.is_open())
        {
            throw QString("Arquivo de Agenda nao foi aberto");
        }
        if(IDatual == 1){
            ID= QString::number(IDatual);
        } else {
            IDbkp++;
            IDatual= IDbkp;
            ID= QString::number(IDbkp);
        }

        arquivoID2<<ID.toStdString()+"\n";
        arquivoID2.close();

        return IDatual;


    } catch (QString &erro) {
        throw (erro);
    }
}

