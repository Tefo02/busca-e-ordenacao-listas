#pragma once

// Biblioteca de entrada/saída e de geração de valores aleatórios.
#include <iostream>
#include <random>

class ArrayList {
public:
    // Construtores e Destrutores.
    ArrayList();
    ~ArrayList();

    // Métodos Públicos da Classe.

    void getList(size_t size);
    void getRandomList(int sizeRandom, int minimumValue, int maximumValue);
    bool insertAt(int value, int position);
    bool swapValue(int firstPosition, int secondPosition);
    int search(int value, unsigned& numberOfAccess);
    int findMinimum(unsigned& numberOfAccess, int& minimum);
    void displayList();
    void displayReversedList();

private:
    // Definição da estrutura.
    int *array = nullptr;
    size_t capacity = 8;
    size_t size = 0;

    // Métodos Privados da Classe.
    void clean();
    // TODO.
};