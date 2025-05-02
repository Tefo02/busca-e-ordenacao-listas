#pragma once

// Biblioteca de entrada/saída e de geração de valores aleatórios.
#include <iostream>
#include <random>

class DoubleList {
    public:
    // Construtores e Destrutores.
    DoubleList();
    ~DoubleList();
    
    // Definição da estrutura do Nó Simples.
    struct DoubleNode {
        int data;
        DoubleNode* next;
        DoubleNode* previous;
    };

    // Métodos Públicos da Classe.
    void getList(size_t size);
    void getRandomList(size_t size, int minimumValue, int maximumValue);
    bool insertAt(int value, DoubleNode* previous);
    bool swapValue(DoubleNode* nodeA, DoubleNode* nodeB);
    DoubleNode* search(int value, unsigned& numberOfAccess);
    DoubleNode* findMinimum(unsigned& numberOfAccess);
    void displayList();
    void displayReversedList();

private:
    // Define o Nó Cabeça.
    DoubleNode* head;
    // Métodos Privados da Classe.
    
    void printfReversedOrder();
    void clean();
};