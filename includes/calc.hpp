#ifndef CALC_H
#define CALC_H

#include <iostream>
#include<string>
//#include <vector>
using namespace std;

class calc{

    private:
        int linhas;
        int colunas;
        int numLin;
        int numCol;
        float** mat; //atributo matriz;
        float** transposta;//atributo transpota
        int tam_matriz;

    public:
    

    void set_linhasMatriz(int lin);
    void set_colunasMatriz(int col);
    int  get_linhasMatriz();
    int  get_colunasMatriz();

    void exibirmatriz();
    void exibirmatriz(float* mat, int linhas, int colunas);
    void ematrizP(float* matriz, int lin, int cols);
    void ematriz(float** matriz);

    void init(int tam1,int tam2);
    void instanciarMatriz();
    float instanciarmatriz(float* mat);

    void ordenar(int index);
    void preencher(); 
    
    float mediaDeclar(float** matriz, int index);
    float media(int index);

    
    float mediana(int index);
    float maximo(int index);
    float minimo(int index);

    float** tranposta();

    void setMatrix(float** matriz, int linhas, int colunas);

    calc(){
    }

    calc(int m, int n): linhas(m), colunas(n){
          instanciarMatriz();
    }

};

#endif // CALC_H



