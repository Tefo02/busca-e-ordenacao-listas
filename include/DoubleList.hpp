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

    // TODO.
    

private:
    // Define o Nó Cabeça.
    DoubleNode* head;

    // Métodos Privados da Classe.

    // TODO.
};