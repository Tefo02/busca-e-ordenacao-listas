#pragma once

// Biblioteca de entrada/saída e de geração de valores aleatórios.
#include <iostream>
#include <random>



class SimpleList {
    public:

    // Definição da estrutura do Nó Simples.
    struct SimpleNode {
        int data;
        SimpleNode* next;
    };

    // Construtores e Destrutores.
    SimpleList();
    ~SimpleList();

    // Métodos Públicos da Classe.

    // TODO.
    

private:
    // Define o Nó Cabeça.
    SimpleNode* head;

    // Métodos Privados da Classe.

    // TODO.
};