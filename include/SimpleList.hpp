#pragma once

// Biblioteca de entrada/saída e de geração de valores aleatórios.
#include <iostream>
#include <random>

class SimpleList {
    public:

    // Construtores e Destrutores.
    SimpleList();
    ~SimpleList();
    
    // Definição da estrutura do Nó Simples.
    struct SimpleNode {
        int data;
        SimpleNode* next;
    };

    void getList(size_t size);
    void getRandomList(size_t size, int minimumValue, int maximumValue);
    void insertAt(int value, SimpleNode* previous);
    bool swapValue(SimpleNode* nodeA, SimpleNode* nodeB);
    SimpleNode* search(int value, unsigned& numberOfAccess);
    SimpleNode* findMinimum(unsigned& numberOfAccess, int& lowest_value);
    void displayList();
    void displayReversedList();
    SimpleNode* getNodeByIndex(unsigned index);
    unsigned getIndexOfNode(SimpleNode* node);

    // Métodos Públicos da Classe.


private:
    // Define o Nó Cabeça.
    SimpleNode* head;

    // Métodos Privados da Classe.
    SimpleNode* newNode(int value);
    void printfReverseOrder(SimpleNode* node);
    void clean();
};