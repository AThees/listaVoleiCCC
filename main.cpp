#include <iostream>
#include "FilaEncad.h"
#include <string>

using namespace std;

int main()
{
    int escolha;

    FilaEncad deFora;
    FilaEncad timeA;
    FilaEncad timeB;

    while (true)
    {
        cout << "Escolha uma opcao: " << endl;
        cout << "1 - Adicionar jogadores a lista" << endl;
        cout << "2 - Gerar 2 times iniciais" << endl;
        cout << "3 - Remover um jogador" << endl;
        cout << "4 - Informar time vencedor e gerar a proxima partida"<< endl;
        cout << "5 - Imprimir lista dos jogadores de fora em ordem" << endl;

        cin >> escolha;


        if(escolha == 1){

            int numJogadoresAdd;
            string jogadorAdd;

            cout << "Quantos jogadores deseja adicionar?" << endl;
            cin >> numJogadoresAdd;

            for(int i = 0; i < numJogadoresAdd; i++){

                cout << "Digite o nome do jogador (Primeira letra maiúscula)" << i + 1 << ": ";

                cin >> jogadorAdd;

                deFora.enfileira(jogadorAdd);

            }

        }

        if (escolha == 2){

            int totalJogadores;

            totalJogadores = deFora.numJogadores() + timeA.numJogadores() + timeB.numJogadores();

            if(!(timeA.vazia()) || !(timeB.vazia())){
                cout << "Times ja iniciados!" << endl;
                continue;
            }
            if(totalJogadores < 12){
                cout << "Jogadores insuficientes para iniciar a partida!" << endl;
                continue;
            }

            else{
                // Generate team 1 with 6 players
                for(int i = 0; i < 6; i++)
                {
                    timeA.enfileira(deFora.desenfileira());
                }
                cout << "Time A:" << endl;
                timeA.imprime();
                // Generate team 2 with 6 players
                for(int i = 0; i < 6; i++)
                {
                    timeB.enfileira(deFora.desenfileira());
                }
                cout << "Time B:" << endl;
                timeB.imprime();
            }
        }

        if (escolha == 3){
            string jogadorRemove;

            cout << "Digite o nome do jogador que deseja remover: ";
            cin >> jogadorRemove;

            timeA.removeUm(jogadorRemove);
            timeB.removeUm(jogadorRemove);
            deFora.removeUm(jogadorRemove);

            cout << "Time A:" << endl;
            timeA.imprime();
            cout << "Time B:" << endl;
            timeB.imprime();
            cout << "De fora:" << endl;
            deFora.imprime();
        }

        if (escolha == 4)
        {
            int timeVencedor;

            cout << "Escolha o time vencedor" << endl;
            cout << "1 - Time A" << endl;
            cout << "2 - Time B" << endl;

            cin >> timeVencedor;

            if (timeVencedor == 1){

                //Coloca os 6 jogadores do time A de fora
                for(int i = 0; i < timeA.numJogadores(); i++)
                {
                    deFora.enfileira(timeA.desenfileira());
                }
                //Coloca os 6 jogadores do time B de fora
                for(int i = 0; i < timeB.numJogadores(); i++)
                {
                    deFora.enfileira(timeB.desenfileira());
                }
                
            }

            else if (timeVencedor == 2){

                //Coloca os 6 jogadores do time B de fora
                for(int i = 0; i < 6; i++)
                {
                    deFora.enfileira(timeB.desenfileira());
                }
                //Coloca os 6 jogadores do time A de fora
                for(int i = 0; i < 6; i++)
                {
                    deFora.enfileira(timeA.desenfileira());
                }

            }

            else{
                cout << "ERRO: Time invalido!" << endl;
                continue;
            }

            // Gera o time A com 6 jogadores de fora 
            for(int i = 0; i < 6; i++)
            {
                timeA.enfileira(deFora.desenfileira());
            }

            // Gera o time B com 6 jogadores de fora

            for(int i = 0; i < 6; i++)
            {
                timeB.enfileira(deFora.desenfileira());
            }

            // Imprime os dois times gerados
            cout << "Time A:" << endl;
            timeA.imprime();

            cout << "Time B:" << endl;
            timeB.imprime();


        }

        if (escolha == 5) {

            cout << "Lista de jogadores de fora:" << endl;

            deFora.imprime();

        }
        
    }
    
    


    return 0;
}

