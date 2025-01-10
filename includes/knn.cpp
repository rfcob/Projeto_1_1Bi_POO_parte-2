
#include "knn.hpp"
#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

/ Método auxiliar para calcular o número de classes
int calcularNumClasses(int* rotulos, int lines) {
    int maxClasse = 0;
    for (int i = 0; i < lines; i++) {
        if (rotulos[i] > maxClasse) {
            maxClasse = rotulos[i];
        }
    }
    return maxClasse + 1; // Classes começam de 0
}

// Método fit: armazena dados de treino e rótulos
void KNNModel::fit(float** data, int* rot, int lines, int cols) {
    this->linesTreino = lines;
    this->cols = cols;

    treino = new float*[lines];
    for (int i = 0; i < lines; i++) {
        treino[i] = new float[cols];
        for (int j = 0; j < cols; j++) {
            treino[i][j] = data[i][j];
        }
    }

    rotTreino = new int[lines];
    for (int i = 0; i < lines; i++) {
        rotTreino[i] = rot[i];
    }

    // Calcula o número de classes únicas
    numClasses = calcularNumClasses(rotTreino, lines);
}

// Método predict: classifica exemplos no conjunto de teste
int* KNNModel::predict(float** teste, int linesTeste) {
    int* predicoes = new int[linesTeste];

    for (int i = 0; i < linesTeste; i++) {
        // Inicializa os arrays de vizinhos com os primeiros k pontos
        float* kDistancias = new float[k];
        int* kIndices = new int[k];

        for (int n = 0; n < k; n++) {
            float soma = 0;
            for (int c = 0; c < cols; c++) {
                soma += pow(teste[i][c] - treino[n][c], 2);
            }
            kDistancias[n] = sqrt(soma);
            kIndices[n] = n;
        }

        // Processa os restantes pontos
        for (int j = k; j < linesTreino; j++) {
            float soma = 0;
            for (int c = 0; c < cols; c++) {
                soma += pow(teste[i][c] - treino[j][c], 2);
            }
            float distancia = sqrt(soma);

            // Substitui a maior das k distâncias se a atual for menor
            int maxIdx = 0;
            for (int n = 1; n < k; n++) {
                if (kDistancias[n] > kDistancias[maxIdx]) {
                    maxIdx = n;
                }
            }
            if (distancia < kDistancias[maxIdx]) {
                kDistancias[maxIdx] = distancia;
                kIndices[maxIdx] = j;
            }
        }

        // Votações
        int* votos = new int[numClasses]();
        for (int n = 0; n < k; n++) {
            int classe = rotTreino[kIndices[n]];
            votos[classe]++;
        }

        // Determina a classe com mais votos
        int classe = -1;
        int maxVotos = 0;
        for (int c = 0; c < numClasses; c++) {
            if (votos[c] > maxVotos) {
                maxVotos = votos[c];
                classe = c;
            }
        }
        predicoes[i] = classe;

        delete[] kDistancias;
        delete[] kIndices;
        delete[] votos;
    }

    return predicoes;
}