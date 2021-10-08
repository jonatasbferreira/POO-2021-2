#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <cstdlib>
#include "busca.hpp"
#include "melhorcaso.hpp"
#include "contagem.hpp"

void clear_terminal() 
{
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #else
        system("clear");
    #endif
}

void modificar_fila(std::vector<int> &fila)
{
    clear_terminal();
    std::cout << "\n-> MODIFICAR FILA\n";
    int qtd, estresse;

    std::cout << "Digite a quantidade de pessoas na fila: ";
    std::cin >> qtd;

    fila.clear();
    for (int i = 0; i < qtd; i++) {
        std::cout << "Estresse " << i + 1 << ": ";
        std::cin >> estresse;
        fila.push_back(estresse);
    }

    std::cout << '\n';
}

void mostrar_fila(std::vector<int> fila)
{
    printf("\n[ ");
    for (int x : fila) std::cout << x << " ";
    printf("]\n\n");
}

void busca(std::vector<int> fila)
{
    clear_terminal();
    std::cout << "\n-> BUSCA";
    mostrar_fila(fila);

    int num, posicao;
    std::cout << "Digite um valor: ";
    std::cin >> num;

    std::cout << "Digite um index: ";
    std::cin >> posicao;

    std::cout << "\n";
    std::cout << "O valor " << num << " existe: " << existe(fila, num) << '\n';
    std::cout << "O valor " << num << " aparece " << contar(fila, num) << " vez(es)" << '\n';
    std::cout << "O valor " << num << " aparece, pela primeira vez, no index: " << procurar_valor(fila, num) << '\n';
    std::cout << "O valor " << num << " aparece, pela primeira vez a partir do index "
              << posicao << ", no index: " << procurar_valor_a_partir(fila, num, posicao) << "\n\n";
}

void melhor_caso(std::vector<int> fila)
{
    clear_terminal();
    std::cout << "\n-> MELHOR CASO";
    mostrar_fila(fila);
    
    int posicao;
    std::cout << "Digite um index: ";
    std::cin >> posicao;

    std::cout << '\n';
    std::cout << "Menor valor: " << procurar_menor(fila) << '\n';
    std::cout << "Posicao do menor valor: " << procurar_menor_pos(fila) << '\n';
    std::cout << "Posicao do menor valor a partir do index " << posicao << ": " << procurar_menor_pos_a_partir(fila, posicao) << '\n';
    std::cout << "Posicao do homem mais calmo: " << procurar_homem_mais_calmo_pos(fila) << "\n\n";
}

void contagem(std::vector<int> fila)
{
    clear_terminal();
    std::cout << "\n->CONTAGEM";    
    mostrar_fila(fila);

    printf ("Estresse medio da fila: %.2f\n", calcular_estresse_medio(fila));
    std::cout << "Genero que mais aparece na fila: " << mais_homens_ou_mulheres(fila) << '\n';
    std::cout << "Metade mais estressada da fila: " << qual_metade_eh_mais_estressada(fila) << '\n';
    std::cout << "Os homens sao mais estressados que as mulheres? " << homens_sao_mais_estressados_que_mulheres(fila) << "\n\n";
}

int main()
{
    clear_terminal();
    std::cout.setf(std::ios::boolalpha);
    std::vector<int> fila = {99, 50, 1, -1, -50, -99};

    int escolha = 1;
    while (escolha != 0) {
        std::cout << "-=-=-FILA DOS ESTRESSADOS-=-=- \n";
        std::cout << "[1] - Modificar Fila \n";
        std::cout << "[2] - Busca \n";
        std::cout << "[3] - Melhor Caso \n";
        std::cout << "[4] - Contagem \n";
        std::cout << "[0] - Sair :( \n";

        std::cout << "Sua escolha: ";
        std::cin >> escolha;

        switch (escolha) {
            case 1:
                modificar_fila(fila);
                break;
            case 2:
                busca(fila);
                break;
            case 3:
                melhor_caso(fila);
                break;
            case 4:
                contagem(fila);
                break;
        }
    }
    std::cout << "\nSaindo . . .\n";

    return 0;
}