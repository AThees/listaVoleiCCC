#ifndef FILAENCAD_H_INCLUDED
#define FILAENCAD_H_INCLUDED
#include "No.h"
#include <string>


using namespace std;

class FilaEncad
{
private:
    No *inicio;
    No *fim;      /// ponteiros para os No's extremos
public:
    FilaEncad();
    ~FilaEncad();
    string getInicio();           /// retorna valor do primeiro No
    void enfileira(string val);   /// insere No no fim
    string desenfileira();        /// elimina No do inicio
    bool vazia();              /// verifica se fila esta vazia
    void imprime();            /// imprime todos os valores da fila
    int numJogadores();        /// retorna o numero de jogadores na fila
    void removeUm(string nome);            /// remove um jogador da fila
    void adicionaNoInicio(string val);    /// insere no inicio da fila
    string desenfileiraFinal();           /// remove o ultimo No da fila
};

#endif // FILAENCAD_H_INCLUDED
