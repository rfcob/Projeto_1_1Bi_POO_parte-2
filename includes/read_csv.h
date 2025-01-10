
#ifndef READ_CSV_H
#define READ_CSV_H

#include <iostream>
#include <vector>
using namespace std;

class read_csv{

    private:
      int nroLinhas;
      int nroColunas;
      float** sheet;
      int** data;
      string** arquivo;
      string nomeArquivo;
      int MAX_LINHAS;
      int MAX_COLS;
      string tipoArquivo; 
      char delimitador;

    public:

    read_csv(
      const string& fileName = "", 
      int maxLinhas = 1000, 
      int maxColunas = 10,
      const string tipo= "int",
      const char delimiter= ','):
         nomeArquivo(fileName), 
         MAX_LINHAS(maxLinhas),
         MAX_COLS(maxColunas),
         tipoArquivo(tipo),
         delimitador(delimiter)
     {
       nroLinhas=0;
       nroColunas=0;
       data = nullptr;
      }

      
    read_csv(const string& fileName, const string& tipo)
        : read_csv(fileName, 1000, 10, tipo, ',') {}

    read_csv(const string& fileName)
        : read_csv(fileName, 1000, 10, "int", ',' ) {}

    read_csv(const string& fileName, const char delimiter)
        : read_csv(fileName, 1000, 10, "int", delimiter) {}
    
    read_csv(const string& fileName, const string& tipo, const char delimiter)
        : read_csv(fileName, 1000, 10, tipo, delimiter) {}


    ~read_csv() {

      if(tipoArquivo=="int"){
        for (int i = 0; i < nroLinhas; i++) {
            delete[] data[i];
        }
        delete[] data;
        }else if(tipoArquivo=="float"){
          for (int i = 0; i < nroLinhas; i++) {
              delete[] sheet[i];
        }
        delete[] sheet;
      }

    }


    void show();
    int** mydataInt();
    float** mydataFloat();
    //float** getFloatMatrix();
    //int** getIntMatrix();
    int tamanho(int skip_line);
    int tamanho(const string& filename, int skip_line);
    int get_nroLinhas();
    int get_nroColunas();
    void* toList(int skip_line);
    void* toList(const string& filename, int skip_line);
    void imprimeData() const;
    float mediaDeclar(int index);


};


#endif