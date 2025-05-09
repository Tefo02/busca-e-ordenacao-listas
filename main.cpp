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
void arrayOperations(enum Option option, ArrayList& array);
void simpleListOperations(enum Option option, SimpleList& simpleList);
void doubleListOperations(enum Option option, DoubleList& doubleList);

int getInt(std::string message);
unsigned getUnsigned(std::string message);


int main(){

    while(true){
        ListType listType = menu();
        if(listType == ListType::QUIT){
            break;
        }
        listOperations(listType);
        std::cout << "\nRetornando ao menu principal...\n";

    }
    
    std::cout << "Fim do Programa.\n";
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

void listOperations(enum ListType listType){
    ArrayList array;
    SimpleList simpleList;
    DoubleList doubleList;
    
    while(true){
        Option option = submenu(listType);
        
        if(option == Option::QUIT){
            break;
        }

        switch(listType){
            case ListType::ARRAY_LIST:
                arrayOperations(option, array);
            break;
            case ListType::SIMPLE_LIST:
                simpleListOperations(option, simpleList);
            break;
            case ListType::DOUBLE_LIST:
                doubleListOperations(option, doubleList);
            break;
        }
    }
    return;
}

void arrayOperations(enum Option option, ArrayList& array){ 
    switch(option){
        case Option::GET_LIST: {
            unsigned size;
            size = getUnsigned("Digite o tamanho da lista: ");

            array.getList(size);

            break;
        }
        case Option::GENERATE_RANDOM_LIST: {
            unsigned size;
            int minimumValue, maximumValue;
            size = getUnsigned("Digite o tamanho da lista: ");
            do{
                minimumValue = getInt("Digite o intervalo inferior: "); 
                maximumValue = getInt("Digite o intervalo superior: "); 
                if(minimumValue > maximumValue){
                    std::cout << "O intervalo inferior deve ser maior do que o superior.\nDigite novamente.\n";
                }
            }while(minimumValue > maximumValue);

            array.getRandomList(size, minimumValue, maximumValue);

            break;
        }
        case Option::INSERT_AT: {
            int value = getInt("Digite o valor a ser inserido: ");
            unsigned index = getUnsigned("Digite o indice a ser inserido: ");
            
            bool inserted = array.insertAt(value, index);
            std::cout << (inserted ? "Valor inserido.\n" : "Valor nao foi inserido.\n");
            
           break;
        }
        case Option::SWAP_VALUE: {
            while(true){
                unsigned indexA = getUnsigned("Digite o primeiro indice: "), 
                indexB = getUnsigned("Digite o segundo indice: ");
                
                if(array.swapValue(indexA, indexB)){
                    break;
                }
                
                std::cout << "Indices invalidos.\n";
            }
            std::cout << "Valores Trocados.\n";
            break;
        }
        case Option::SEARCH: {
            int value = getInt("Digite o valor a ser procurado: ");
            unsigned numberOfAccess = 0;
            unsigned position = array.search(value, numberOfAccess); 
            if(position == std::numeric_limits<unsigned>::max()){
                std::cout << "Valor nao encontrado\n";
            } else {
                std::cout << "Valor encontrado na posicao " << position << ".\n";
            }
            std::cout << "Numero de acessos: " << numberOfAccess << '\n';
            break;
        }
        case Option::FIND_MIN: {
            unsigned numberOfAccess = 0;
            int minimum; 
            int position = array.findMinimum(numberOfAccess, minimum);
            if(position != -1){
                std::cout << "Valor " << minimum << " encontrado na posicao " << position << ".\n";
            } else {
                std::cout << "A Lista esta vazia.\n";
            }
            std::cout << "Numero de acessos: " << numberOfAccess;
            break;
        }
        case Option::PRINT: 
            array.displayList();
            break;
        case Option::PRINT_REVERSE:
            array.displayReversedList();
            break;
    }
}

void simpleListOperations(enum Option option, SimpleList& simpleList){
    switch(option){
        case Option::GET_LIST: {
            unsigned size;
            size = getUnsigned("Digite o tamanho da lista: ");

            simpleList.getList(size);

            break;
        }
        case Option::GENERATE_RANDOM_LIST: {
            unsigned size;
            int minimumValue, maximumValue;
            size = getUnsigned("Digite o tamanho da lista: ");
            do{
                minimumValue = getInt("Digite o intervalo inferior: "); 
                maximumValue = getInt("Digite o intervalo superior: "); 
                if(minimumValue > maximumValue){
                    std::cout << "O intervalo inferior deve ser maior do que o superior.\nDigite novamente.\n";
                }
            }while(minimumValue > maximumValue);

            simpleList.getRandomList(size, minimumValue, maximumValue);

            break;
        }
        case Option::INSERT_AT: {
            int value = getInt("Digite o valor a ser inserido: ");
            SimpleList::SimpleNode *pointer = nullptr;
            while(true) {
                unsigned index = getUnsigned("Digite o indice a ser inserido: ");
                if(index == 0) {
                    pointer = nullptr;
                } else {
                    pointer = simpleList.getNodeByIndex(index);
                    if(pointer != nullptr) {
                        break;
                    }
                }
                std::cout << "Erro: Indice invalido. Digite novamente." << std::endl;
            }
            
            simpleList.insertAt(value, pointer);
            std::cout << "Valor inserido.\n";
           break;
        }
        case Option::SWAP_VALUE: {
            while(true){
                unsigned indexA = getUnsigned("Digite o primeiro indice: "), 
                indexB = getUnsigned("Digite o segundo indice: ");
                SimpleList::SimpleNode *pointerA = simpleList.getNodeByIndex(indexA);
                SimpleList::SimpleNode *pointerB = simpleList.getNodeByIndex(indexB);

                if(simpleList.swapValue(pointerA, pointerB)){
                    break;
                }
                
                std::cout << "Indices invalidos.\n";
            }
            std::cout << "Valores Trocados.\n";
            break;
        }
        case Option::SEARCH: {
            int value = getInt("Digite o valor a ser procurado: ");
            unsigned numberOfAccess = 0;
            SimpleList::SimpleNode *pointer = simpleList.search(value, numberOfAccess); 
            if(pointer == nullptr) {
                std::cout << "Valor nao encontrado\n";
            } else {
                std::cout << "Valor encontrado na posicao " << simpleList.getIndexOfNode(pointer) << ".\n";
            }
            std::cout << "Numero de acessos: " << numberOfAccess << '\n';
            break;
        }
        case Option::FIND_MIN: {
            unsigned numberOfAccess = 0;
            int minimum; 
            SimpleList::SimpleNode *pointer = simpleList.findMinimum(numberOfAccess, minimum);
            if(pointer != nullptr){
                std::cout << "Valor " << minimum << " encontrado na posicao " << simpleList.getIndexOfNode(pointer) << ".\n";
            } else {
                std::cout << "A Lista esta vazia.\n";
            }
            std::cout << "Numero de acessos: " << numberOfAccess;
            break;
        }
        case Option::PRINT: 
            simpleList.displayList();
            break;
        case Option::PRINT_REVERSE:
            simpleList.displayReversedList();
            break;
    }
}

void doubleListOperations(enum Option option, DoubleList& doubleList){
    switch(option){
        case Option::GET_LIST: {
            unsigned size;
            size = getUnsigned("Digite o tamanho da lista: ");

            doubleList.getList(size);

            break;
        }
        case Option::GENERATE_RANDOM_LIST: {
            unsigned size;
            int minimumValue, maximumValue;
            size = getUnsigned("Digite o tamanho da lista: ");
            do{
                minimumValue = getInt("Digite o intervalo inferior: "); 
                maximumValue = getInt("Digite o intervalo superior: "); 
                if(minimumValue > maximumValue){
                    std::cout << "O intervalo inferior deve ser maior do que o superior.\nDigite novamente.\n";
                }
            }while(minimumValue > maximumValue);

            doubleList.getRandomList(size, minimumValue, maximumValue);

            break;
        }
        case Option::INSERT_AT: {
            int value = getInt("Digite o valor a ser inserido: ");
            DoubleList::DoubleNode *pointer = nullptr;
            while(true) {
                unsigned index = getUnsigned("Digite o indice a ser inserido: ");
                pointer = doubleList.getNodeByIndex(index);
                if(pointer != nullptr) {
                    break;
                }
                std::cout << "Erro: Indice invalido. Digite novamente." << std::endl;
            }
            
            doubleList.insertAt(value, pointer->previous);
            std::cout << "Valor inserido.\n";
           break;
        }
        case Option::SWAP_VALUE: {
            while(true){
                unsigned indexA = getUnsigned("Digite o primeiro indice: "), 
                indexB = getUnsigned("Digite o segundo indice: ");
                DoubleList::DoubleNode *pointerA = doubleList.getNodeByIndex(indexA);
                DoubleList::DoubleNode *pointerB = doubleList.getNodeByIndex(indexB);

                if(doubleList.swapValue(pointerA, pointerB)){
                    break;
                }
                
                std::cout << "Indices invalidos.\n";
            }
            std::cout << "Valores Trocados.\n";
            break;
        }
        case Option::SEARCH: {
            int value = getInt("Digite o valor a ser procurado: ");
            unsigned numberOfAccess = 0;
            DoubleList::DoubleNode *pointer = doubleList.search(value, numberOfAccess); 
            if(pointer == nullptr) {
                std::cout << "Valor nao encontrado\n";
            } else {
                std::cout << "Valor encontrado na posicao " << doubleList.getIndexOfNode(pointer) << ".\n";
            }
            std::cout << "Numero de acessos: " << numberOfAccess << '\n';
            break;
        }
        case Option::FIND_MIN: {
            unsigned numberOfAccess = 0;
            int minimum; 
            DoubleList::DoubleNode *pointer = doubleList.findMinimum(numberOfAccess, minimum);
            if(pointer != nullptr){
                std::cout << "Valor " << minimum << " encontrado na posicao " << doubleList.getIndexOfNode(pointer) << ".\n";
            } else {
                std::cout << "A Lista esta vazia.\n";
            }
            std::cout << "Numero de acessos: " << numberOfAccess;
            break;
        }
        case Option::PRINT: 
            doubleList.displayList();
            break;
        case Option::PRINT_REVERSE:
            doubleList.displayReversedList();
            break;
    }
}