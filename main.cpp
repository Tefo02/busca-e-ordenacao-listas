#include "include/Operations.hpp"


//Membros da equipe: Robert Afonso Aquino e Stefano Lopes Delgado
int main(){

    while(true){
        ListType listType = menu();
        if(listType == ListType:: QUIT){
            break;
        }
        listOperations(listType);
        std::cout << "\nRetornando ao menu principal...\n";

    }
    
    std::cout << "Fim do Programa.\n";
    return 0;
}


