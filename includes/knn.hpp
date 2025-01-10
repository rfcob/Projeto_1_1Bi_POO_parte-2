#ifndef KNN_HPP
#define KNN_HPP

#include "calc.hpp"
#include "read_csv.h"
#include <string>

class KNNModel {
private:
    float** treino;
    int* rotTreino;
    int linesTreino;
    int cols;
    int k; // Número de vizinhos
    int numClasses; 

public:
    
    KNNModel() : treino(nullptr), rotTreino(nullptr), linesTreino(0), cols(0), k(5) {}

    KNNModel(int vizinhos) : treino(nullptr), rotTreino(nullptr), linesTreino(0), cols(0), k(vizinhos) {}
  
    ~KNNModel() {

        for (int i = 0; i < linesTreino; i++) {
            delete[] treino[i];
        }

        delete[] treino;

        delete[] rotTreino;
    }

    // Métodos principais
    void fit(float** data, int* rot, int lines, int cols); // Armazena dados de treino
    int* predict(float** teste, int linesTeste); // Classifica exemplos no conjunto de teste
};

#endif