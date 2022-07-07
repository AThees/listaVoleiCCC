#include <iostream>
#include <cstdlib>
#include <string>
#include "FilaEncad.h"

using namespace std;

FilaEncad::FilaEncad()
{
    cout << "Criando FilaEncad" << endl;
    inicio = NULL;
    fim = NULL;
}

FilaEncad::~FilaEncad()
{
    cout << "Destruindo FilaEncad" << endl;
    No* p = inicio;
    while(inicio != NULL)
    {
        inicio = p->getProx();
        delete p;
        p = inicio;
    }
    fim = NULL;
}

bool FilaEncad::vazia()
{
    if(inicio == NULL)
        return true;
    else
        return false;
}

void FilaEncad::enfileira(string val)
{
    No* p = new No();
    p->setInfo(val);
    p->setProx(NULL);
    if(fim == NULL)
        inicio = p;
    else
        fim->setProx(p);
    fim = p;
}

string FilaEncad::getInicio()
{
    if(inicio != NULL)
        return inicio->getInfo();
    else
    {
        cout << "Fila vazia!" << endl;
        exit(1);
    }
}

string FilaEncad::desenfileira()
{
    No* p;
    if(inicio != NULL)
    {
        p = inicio;
        inicio = p->getProx();
        if(inicio == NULL)
            fim = NULL;
        string val = p->getInfo();
        delete p;
        return val;
    }
    else
    {
        cout << "ERRO: Fila Vazia!" << endl;
        exit(1);
    }
}

void FilaEncad::imprime()
{
    No* p = inicio;
    while(p != NULL)
    {
        cout << p->getInfo() << endl;
        p = p->getProx();
    }
    cout << endl;
}

int FilaEncad::numJogadores(){ 
    // conta quantos itens estão na fila
    int cont = 0;
    No* p = inicio;
    while(p != NULL)
    {
        cont++;
        p = p->getProx();
    }
    return cont;
}

void FilaEncad::removeUm(string nome){
    // remove um jogador da fila
    No* p = inicio;
    No* ant = NULL;
    while(p != NULL)
    {
        if(p->getInfo() == nome)
        {
            if(ant == NULL)
                inicio = p->getProx();
            else
                ant->setProx(p->getProx());
            delete p;
            break;
        }
        ant = p;
        p = p->getProx();
    }

    // se o jogador nao estiver nessa lista, nao faz nada
    if(p == NULL)
        cout << "Jogador nao encontrado!" << endl;
}

void FilaEncad::adicionaNoInicio(string val){
    // insere no inicio da fila
    No* p = new No();
    p->setInfo(val);
    p->setProx(inicio);
    inicio = p;
}

string FilaEncad::desenfileiraFinal(){ 
    // desenfileira pelo final da fila
    No* p = inicio;
    No* ant = NULL;
    while(p->getProx() != NULL)
    {
        ant = p;
        p = p->getProx();
    }
    string val = p->getInfo();
    if(ant == NULL)
        inicio = NULL;
    else
        ant->setProx(NULL);
    delete p;
    return val;
}