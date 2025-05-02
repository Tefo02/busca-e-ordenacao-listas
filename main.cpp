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
enum Option submenu(enum ListType listType);
void listOperations(enum ListType listType);
void arrayOperations(enum Option option);
void simpleListOperations(enum Option option);
void doubleListOperations(enum Option option);

int getInt(std::string message);
unsigned getUnsigned(std::string message);


int main(){

    while(true){
        ListType listType = menu();
        if(listType == ListType::QUIT){
            break;
        }
        listOperations(listType);
    }
    
    return 0;
}

int getInt(std::string message){
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

unsigned getUnsigned(std::string message){
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

Option submenu(enum ListType listType){
    /*
    std::string title;
    switch(listType){
    case ListType::ARRAY_LIST:
        title = "Lista Contigua";
    break;
    case ListType::SIMPLE_LIST:
        title = "Lista Ligada Simples";
    break;
    case ListType::DOUBLE_LIST:
        title = "Lista Duplamente Ligada";
    break;
    default:
        std::cerr << "Erro: Tipo de lista invalido.\n";
        return;
    }
    */

    int opc;
    while (true) {
        std::cout << "\n\t+--------------+ Submenu +--------------+\n";
        std::cout << "\t| - Operacoes:                          |";
        std::cout << "\t|      1. Ler Lista                     |";
        std::cout << "\t|      2. Gerar Lista Aleatoria         |";
        std::cout << "\t|      3. Inserir valor                 |";
        std::cout << "\t|      4. Fazer trasnposicao de Valores |";
        std::cout << "\t|      5. Procurar um valor             |";
        std::cout << "\t|      6. Procurar o menor valor        |";
        std::cout << "\t|      7. Mostrar Lista                 |";
        std::cout << "\t|      8. Mostrar em ordem inversa      |";
        std::cout << "\t|      0. Voltar para o menu            |";
        std::cout << "\t+---------------------------------------+";

        opc = getInt("Digite a opcao desejada: ");
        if (opc >= 0 && opc <= 8) {
            return static_cast<Option>(opc);
        }

        std::cout << "Opcao invalida. Tente novamente.\n";
    }
}

void listOperations(enum ListType listType){
    while(true){
        Option option = submenu(listType);
        
        if(option == Option::QUIT){
            break;
        }

        switch(listType){
        case ListType::ARRAY_LIST:
            arrayOperations(option);
        break;
        case ListType::SIMPLE_LIST:
            simpleListOperations(option);
        break;
        case ListType::DOUBLE_LIST:
            doubleListOperations(option);
        break;
        }
    }
    return;
}

void arrayOperations(enum Option option){
    ArrayList list;
    
    switch(option){
        case Option::GET_LIST: {
            unsigned size;
            size = getUnsigned("Digite o tamanho da lista: ");

            list.getList(size);

            break;
        }
        case Option::GENERATE_RANDOM_LIST: {
            unsigned size;
            int minimumValue, maximumValue;
            size = getUnsigned("Digite o tamanho da lista");
            bool valid = false;
            do{
                minimumValue = getInt("Digite o intervalo inferior: "); 
                maximumValue = getInt("Digite o intervalo superior: "); 
                if(minimumValue > maximumValue){
                    std::cout << "O intervalo inferior deve ser maior do que o superior.\nDigite novamente.\n";
                }
            }while(minimumValue > maximumValue);

            list.getRandomList(size, minimumValue, maximumValue);

            break;
        }
        case Option::INSERT_AT: {
            int value = getInt("Digite o valor a ser inserido: ");
            unsigned index = getUnsigned("Digite o indice a ser inserido: ");
            
            bool inserted = list.insertAt(value, index);
            std::cout << inserted ? "Valor inserido.\n" : "Valor nao foi inserido.\n";
            
           break;
        }
        case Option::SWAP_VALUE: {
            while(true){
                unsigned indexA = getUnsigned("Digite o primeiro indice: "), 
                indexB = getUnsigned("Digite o segundo indice: ");
                
                if(list.swapValue(indexA, indexB)){
                    break;
                }
                
                std::cout << "Indices invalidos.\n";
            }
            std::cout << "Valores Trocados.\n";
        }
        case Option::SEARCH: {
            int value = getInt("Digite o valor a ser procurado: ");
            unsigned numberOfAccess = 0;
            unsigned position = list.search(value, numberOfAccess); 
            if(position == -1){
                std::cout << "Valor nao encontrado\n";
            } else {
                std::cout << "Valor encontrado na " << position << "posicao.\n";
            }
            std::cout << "Numero de acessos: " << numberOfAccess;
        }
        case Option::FIND_MIN: {
            unsigned numberOfAccess = 0;
            int minimum; 
            int position = list.findMinimum(numberOfAccess, minimum);
            if(position != -1){
                std::cout << "Valor encontrado na " << position << "posicao.\n";
            } else {
                std::cout << "A Lista esta vazia.\n";
            }
            std::cout << "Numero de acessos: " << numberOfAccess;
        }
        case Option::PRINT: 
            list.displayList();
            break;
        case Option::PRINT_REVERSE:
            list.displayReversedList();
            break;
    }
}

void simpleListOperations(enum Option option){
    return;
}

void doubleListOperations(enum Option option){
    return;
}