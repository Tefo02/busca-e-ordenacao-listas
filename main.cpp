#include "include/ArrayList.hpp"
#include "include/SimpleList.hpp"
#include "include/DoubleList.hpp"

#include <iostream>

enum class ListType {
    QUIT = 0,
    ARRAY_LIST = 1,
    SIMPLE_LIST = 2,
    DOUBLE_LIST = 3
};

enum class Option {
    QUIT = 0,
    GET_LIST = 1,
    GENERATE_RANDOM_LIST = 2,
    INSERT_AT = 3,
    SWAP_VALUE = 4,
    SEARCH = 5,
    FIND_MIN = 6,
    PRINT = 7,
    PRINT_REVERSE = 8
};

enum ListType menu();
enum Option operacaoDaLista();
void submenu();


int main(){
    do{
        
    }
    
    return 0;
}

ListType menu() {
    int opc;
    while (true) {
        std::cout << "\n\t+----------------+ Menu +----------------+\n";
        std::cout << "\t| - Digite o tipo de lista:              |\n";
        std::cout << "\t|      1. Lista por Contiguidade Fisica  |\n";
        std::cout << "\t|      2. Lista Ligada Simples           |\n";
        std::cout << "\t|      3. Lista Duplamente Ligada        |\n";
        std::cout << "\t|      0. Sair do Programa               |\n";
        std::cout << "\t+----------------------------------------+\n";
        std::cout << "Digite a opcao desejada: ";

        if (std::cin >> opc && opc >= 0 && opc <= 3) {
            return static_cast<ListType>(opc);
        }

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Opcao invalida. Tente novamente.\n";
    }
}

