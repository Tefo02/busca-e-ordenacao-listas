#include "../include/Operations.hpp"

void arrayOperations(const Option& option, ArrayList& array){ 
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

void simpleListOperations(const Option& option, SimpleList& simpleList){
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
                    break;
                } else {
                    pointer = simpleList.getNodeByIndex(index - 1);
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

void doubleListOperations(const Option& option, DoubleList& doubleList){
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
                if(index == 0){
                    break;
                }
                pointer = doubleList.getNodeByIndex(index - 1);
                if(pointer != nullptr) {
                    break;
                }
                std::cout << "Erro: Indice invalido. Digite novamente." << std::endl;
            }
            if(pointer != nullptr){
                doubleList.insertAt(value, pointer);  
            } else {
                doubleList.insertAt(value, pointer);
            }
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

void listOperations(const ListType& listType){
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