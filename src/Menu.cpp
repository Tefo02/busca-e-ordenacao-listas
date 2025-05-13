#include "../include/Menu.hpp"

ListType menu() {
    int opc;
    while (true) {
        std::cout << "\n\t+----------------+ Menu +----------------+\n";
        std::cout << "\t| - Tipos de lista:                      |\n";
        std::cout << "\t|      1. Lista por Contiguidade Fisica  |\n";
        std::cout << "\t|      2. Lista Ligada Simples           |\n";
        std::cout << "\t|      3. Lista Duplamente Ligada        |\n";
        std::cout << "\t|      0. Sair do Programa               |\n";
        std::cout << "\t+----------------------------------------+\n";


        opc = getInt("Digite a opcao desejada: ");
        if (opc >= 0 && opc <= 3) {
            return static_cast<ListType>(opc);
        }

        std::cout << "Opcao invalida. Tente novamente.\n";
    }
}

Option submenu(const ListType& listType){
    int opc;
    while (true) {
        std::cout << "\n\t+--------------+ Submenu +--------------+\n";
        std::cout << "\t| - Operacoes:                          |\n";
        std::cout << "\t|      1. Ler Lista                     |\n";
        std::cout << "\t|      2. Gerar Lista Aleatoria         |\n";
        std::cout << "\t|      3. Inserir valor                 |\n";
        std::cout << "\t|      4. Fazer transposicao de Valores |\n";
        std::cout << "\t|      5. Procurar um valor             |\n";
        std::cout << "\t|      6. Procurar o menor valor        |\n";
        std::cout << "\t|      7. Mostrar Lista                 |\n";
        std::cout << "\t|      8. Mostrar em ordem inversa      |\n";
        std::cout << "\t|      0. Voltar para o menu            |\n";
        std::cout << "\t+---------------------------------------+\n";

        opc = getInt("Digite a opcao desejada: ");
        if (opc >= 0 && opc <= 8) {
            return static_cast<Option>(opc);
        }

        std::cout << "Opcao invalida. Tente novamente.\n";
    }
}

int getInt(const std::string& message){
    int newInt;
    while(true){
        std::cout << message;
        if(std::cin >> newInt){
            break;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Entrada invalida. Tente novamente.\n";
    }
    return newInt;
}

unsigned getUnsigned(const std::string& message){
    unsigned newUnsigned;
    while(true){
        std::cout << message;
        if(std::cin >> newUnsigned){
            break;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Entrada invalida. Tente novamente.\n";
    }
    return newUnsigned;
}

