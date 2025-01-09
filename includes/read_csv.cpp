#include <fstream> 
#include <iostream> 
#include <sstream>
#include <string>
#include <iomanip>
//#include <algorithm>
#include "read_csv.h"

using namespace std;


// metodos numero de linhas e colunas________________________________________________________________________________________________________
int read_csv::get_nroLinhas(){
    return nroLinhas;
}

float** read_csv::mydataFloat(){
    return sheet;
}

int** read_csv::mydataInt(){
    return data;
}

int read_csv::get_nroColunas(){
    return nroColunas;
}


/*float** read_csv::getFloatMatrix() {
    return sheet;
}

int** read_csv::getIntMatrix() {
    return data;
}
*/

//metodo imprime a matriz/dataframe__________________________________________________________________________________________________________

void read_csv::imprimeData() const{ 
    //cout << data[0][1] << endl;
    for (int i = 0; i < nroLinhas; i++) {
         //cout << setw(5) << i+1; //Caso seja útil mostrar o número de linhas
         for (int j = 0; j < nroColunas; j++) {
            if(tipoArquivo=="int"){ 
                cout << setw(14) << data[i][j] << " ";
            }else if(tipoArquivo=="float"){
                cout << fixed << setprecision(4) << setw(14) << sheet[i][j] << " ";
            }else{
                cout << "type erro" << endl;
            } 
        } 
        cout << endl; 
    }
}

//metodo calcula o tamanho do arquivo csv____________________________________________________________________________________________________
int read_csv::tamanho(const string& filename) {
    
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file!" << endl;
        return 1;
    }
    
    string line;
    while (getline(file, line)) {
        nroLinhas++;
        stringstream ss(line);
        string cell;
        int cols = 0;
        while (getline(ss, cell, delimitador)) {
            cols++;
        }
        if (cols > nroColunas) {
            nroColunas = cols;
        }
    }
    //file.close();

    return 0;
}

//metodo calcula o tamanho do arquivo csv____________________________________________________________________________________________________

// precisa ser reavaliada a utilidade dessa função uma vez que não tem objeto instanciado sem o nome do arquivo

int read_csv::tamanho() {
    
    ifstream file(nomeArquivo);
    if (!file.is_open()) {
        cerr << "Error opening file!" << endl;
        return 1;
    }
    
    string line;
    while (getline(file, line)) {
        nroLinhas++;
        stringstream ss(line);
        string cell;
        int cols = 0;
        while (getline(ss, cell, delimitador)) {
            cols++;
        }
        if (cols > nroColunas) {
            nroColunas = cols;
        }
    }
    file.close();
    return 0;
}


//Medoto convertendo para lista(arrays) o arquivo csv________________________________________________________________________________________________________________
void* read_csv::toList(const string& filename) {
    // Determina o tamanho
    tamanho(nomeArquivo);

    if (tipoArquivo == "int") {
        // Alocando memória e inicializando a matriz com zeros//não funcionava sem isso
        data = new int*[nroLinhas];
        for (int i = 0; i < nroLinhas; i++) {
            data[i] = new int[nroColunas];
            for (int j = 0; j < nroColunas; j++) {
                data[i][j] = 0;
            }
        }

        ifstream file(nomeArquivo);
        if (!file.is_open()) {
            cerr << "Não é possível abrir o arquivo!" << endl;
            return nullptr;
        }

        string header;
        getline(file, header); // Ignora o cabeçalho

        string line;
        int countLinhas = 0;
        while (getline(file, line) && countLinhas < nroLinhas) {
            stringstream ss(line);
            string cell;

            int Colunas = 0;
            while (getline(ss, cell, delimitador) && Colunas < nroColunas) {
                if (cell.empty()) {
                    data[countLinhas][Colunas] = 0;
                } else {
                    data[countLinhas][Colunas] = stoi(cell);
                }
                Colunas++;
            }
            countLinhas++;
        }

        file.close();
        return static_cast<void*>(data);

    } else if (tipoArquivo == "float") {
      
        sheet = new float*[nroLinhas];
        for (int i = 0; i < nroLinhas; i++) {
            sheet[i] = new float[nroColunas];
            for (int j = 0; j < nroColunas; j++) {
                sheet[i][j] = 0.0f;
            }
        }

        ifstream file(nomeArquivo);
        if (!file.is_open()) {
            cerr << "Não é possível abrir o arquivo!" << endl;
            return nullptr;
        }

        string header;
        getline(file, header); 

        string line;
        int countLinhas = 0;
        while (getline(file, line) && countLinhas < nroLinhas) {
            stringstream ss(line);
            string cell;

            int Colunas = 0;
            while (getline(ss, cell, delimitador) && Colunas < nroColunas) {
                if (cell.empty()) {
                    sheet[countLinhas][Colunas] = 0.0f;
                } else {
                    sheet[countLinhas][Colunas] = stof(cell);
                }
                Colunas++;
            }
            countLinhas++;
        }

        file.close();
        return static_cast<void*>(sheet);

    } else {
        cout << "Tipo não suportado!" << endl;
        return nullptr;
    }
}


//Medoto convertendo para lista(arrays) o arquivo csv________________________________________________________________________________________________________________
void* read_csv::toList() {
    // Determina o tamanho
    tamanho(nomeArquivo);

    if (tipoArquivo == "int") {
        // Alocando memória e inicializando a matriz com zeros//não funcionava sem isso
        data = new int*[nroLinhas];
        for (int i = 0; i < nroLinhas; i++) {
            data[i] = new int[nroColunas];
            for (int j = 0; j < nroColunas; j++) {
                data[i][j] = 0;
            }
        }

        ifstream file(nomeArquivo);
        if (!file.is_open()) {
            cerr << "Não é possível abrir o arquivo!" << endl;
            return nullptr;
        }

        string header;
        getline(file, header); // Ignora o cabeçalho

        string line;
        int countLinhas = 0;
        while (getline(file, line) && countLinhas < nroLinhas) {
            stringstream ss(line);
            string cell;

            int Colunas = 0;
            while (getline(ss, cell, delimitador) && Colunas < nroColunas) {
                if (cell.empty()) {
                    data[countLinhas][Colunas] = 0;
                } else {
                    data[countLinhas][Colunas] = stoi(cell);
                }
                Colunas++;
            }
            countLinhas++;
        }

        file.close();
        return static_cast<void*>(data);

    } else if (tipoArquivo == "float") {
      
        sheet = new float*[nroLinhas];
        for (int i = 0; i < nroLinhas; i++) {
            sheet[i] = new float[nroColunas];
            for (int j = 0; j < nroColunas; j++) {
                sheet[i][j] = 0.0f;
            }
        }

        ifstream file(nomeArquivo);
        if (!file.is_open()) {
            cerr << "Não é possível abrir o arquivo!" << endl;
            return nullptr;
        }

        string header;
        getline(file, header); 

        string line;
        int countLinhas = 0;
        while (getline(file, line) && countLinhas < nroLinhas) {
            stringstream ss(line);
            string cell;

            int Colunas = 0;
            while (getline(ss, cell, delimitador) && Colunas < nroColunas) {
                if (cell.empty()) {
                    sheet[countLinhas][Colunas] = 0.0f;
                } else {
                    sheet[countLinhas][Colunas] = stof(cell);
                }
                Colunas++;
            }
            countLinhas++;
        }

        file.close();
        return static_cast<void*>(sheet);

    } else {
        cout << "Tipo não suportado!" << endl;
        return nullptr;
    }
}

//Metodo Show  original data______________________________________________________________________________________________________________
void read_csv::show(){ 
    ifstream file(nomeArquivo); 
    
    
    if (!file.is_open()) { 
        cerr << "Error opening file!" << endl; 
    } 
    
 
    string** arquivo = new string*[MAX_LINHAS];
    for (int i = 0; i < MAX_LINHAS; ++i) {
      arquivo[i] = new string[MAX_COLS];
    }

    string line; 
    int nroLinhas = 0; 

    
    
    while (getline(file, line) && nroLinhas < MAX_LINHAS) { 
        stringstream ss(line); 
        string cell; 
        int col = 0; 
        while (getline(ss, cell, delimitador) && col < MAX_COLS) { 
            arquivo[nroLinhas][col] = cell; 
            col++; 
        } 
        nroLinhas++; 
    } 


    //file.close(); 
    
    for (int i = 0; i < nroLinhas; i++) { 
        for (int j = 0; j < MAX_COLS && !arquivo[i][j].empty(); j++) { 
            cout << setw(14) << arquivo[i][j] << " "; 
        } 
        cout << endl; 
    } 

    for (int i = 0; i < MAX_LINHAS; ++i) {
        delete[] arquivo[i];
    }

    delete[] arquivo;

}


//metodo calcula media de coluna expecífica_________________________________________________________________________________________________
float read_csv::mediaDeclar(int index){
    if(index > nroColunas){
        cout <<" Indice inválido" << endl;
        exit(-1);
    }

    float soma=0, media;
    for (int i = 0; i < nroLinhas; i++) {
        if(tipoArquivo=="int"){
            soma += data[i][index];
        }else if(tipoArquivo=="float"){
            soma += sheet[i][index];
        }else{
            cout << "type error" << endl;
        }
    }

    media=soma/nroLinhas;
    return media;
    
};

//