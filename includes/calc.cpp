

// metodos2.cpp
#include "calc.hpp"
#include <iostream>
#include <cmath>
#include <string>

//#include <vector>

//metodo instanciar matriz dinâmicamente
void calc::instanciarMatriz(){

     mat = new float*[linhas];
      for(int i = 0; i < linhas; i++){
          mat[i] = new float[colunas];
      }

      numLin=linhas;
      numCol=colunas;
}

//metodo entrada de dados
void calc::preencher() { 

    numLin=linhas;
    numCol=colunas;
    
    for(int i = 0; i < linhas; i++){
      for(int j = 0; j < colunas; j++){
         cout << "Entre com os valores: " << (i+1) << (j+1) << endl;
         cin >> mat[i][j];
      }
    }
}

// Metodo exibir quando instanciada dinamicamente, com entrada pelo usuario
void calc::exibirmatriz(){

    for(int i=0;i<linhas;i++){
        for(int j = 0; j<colunas; j++){
        cout << mat[i][j] << " ";
        }
    cout << endl;
    }
   
}


// função exibir/imprimir os arrays na tela
void calc::exibirmatriz(float* matriz, int lin, int cols){

    for(int i=0;i<lin;i++){
        for(int j = 0; j<cols; j++){
        cout << matriz[i * cols + j] << " ";
        }
    cout << endl;
    }
   
}

//metodo exibir matriz** enviando o ponteiro
void calc::ematrizP(float* matriz, int lin, int cols){

    for(int i=0;i<lin;i++){
        for(int j = 0; j<cols; j++){
        cout << mat[i][j] << " ";
        }
    cout << endl;
    }
   
}

//metodo exibir matriz** enviando o ponteiro
void calc::ematriz(float** matriz){

    for(int i=0;i<linhas;i++){
        for(int j = 0; j<colunas; j++){
        cout << mat[i][j] << " ";
        }
    cout << endl;
    }
   
}

//metods gets e sets

void calc::set_linhasMatriz(int lin){
    this-> linhas = lin;
}
    
void calc::set_colunasMatriz(int col){
   this -> colunas = col;
}

int calc::get_linhasMatriz(){
    return numLin;
}
    
int calc::get_colunasMatriz(){
    return numCol;
}



//metodo media para a matriz não dinamica
float calc::mediaDeclar(float** matriz, int index){
    float soma=0, media;
    for (int i = 0; i < linhas; i++) {
        soma += mat[i][index];
    }
    media=soma/linhas;
    return media;

}


//metodo media por coluna
float calc::media(int index){
    float soma=0, media;
    for (int i = 0; i < linhas; i++) {
        soma += mat[i][index];
    }
    media=soma/linhas;
    return media;

}

/*//metodo maximo geral
float calc::maximo( ) { 
    float maior = mat[0][0]; 
    for (int i = 0; i < linhas; i++) { 
        for (int j = 0; j < colunas; j++) { 
            if (mat[i][j] > maior) {
                 maior = mat[i][j]; 
            } 
        } 
    } return maior;
}*/


//metodos maximo e minimo

float calc::maximo( int index) { 
    float maior = mat[0][index]; 
    for (int i = 0; i < linhas; i++) {
         if (mat[i][index] > maior) {
             maior = mat[i][index]; 
        } 
    } return maior;
}



float calc::minimo( int index) { 
    float minimo = mat[0][index]; 
    for (int i = 0; i < linhas; i++) {
         if (mat[i][index] < minimo) {
             minimo = mat[i][index]; 
        } 
    } return minimo;
}



//metodo bubble - ordenar

void calc::ordenar(int index) {
    for (int i = 0; i < linhas - 1; i++) {
        for (int j = i + 1; j < linhas; j++) {
            if (mat[i][index] > mat[j][index]) {
                int temp = mat[i][index];
                mat[i][index] = mat[j][index];
                mat[j][index] = temp;
            }
        }
    }
}


//metodo para a mediana
float calc::mediana(int index) {
    ordenar(index); 

    if (linhas % 2 == 0) {
        return (mat[linhas / 2 - 1][index] + mat[linhas / 2][index]) / 2.0;
    } else {
        return mat[linhas / 2][index];
    }
}


//método para a transposta
float** calc::tranposta() {

    transposta = new float*[numCol];
    
    for (int i = 0; i < numCol; ++i) {
        transposta[i] = new float[numLin];
    }

 
    for (int i = 0; i < numLin; i++) {
        for (int j = 0; j < numCol; j++) {
            transposta[j][i] = mat[i][j];
        }
    }
    return transposta;
}

//Método para selecionar matriz e conectar com a classe read_csv
void calc::setMatrix(float** matriz, int linhas, int colunas) {
    mat = matriz;
    this->linhas = linhas;
    this->colunas = colunas;
    exibirmatriz();
}
