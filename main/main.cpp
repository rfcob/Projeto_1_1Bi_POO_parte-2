

#include <fstream> 
#include <iostream> 
#include <sstream> 
#include <iomanip>
#include "../includes/calc.cpp"
#include "../includes/read_csv.cpp"
#include "../includes/knn.cpp"


using namespace std; 

/*
int main(){
    //instanciando objeto________________________________________

    //string file_int = "../data/features-Aula 13 - Projeto 1 - dataset1.csv"; // nomeando arquivo (tipo inteiro)
    //string file_float = "../data/features-Aula 13 - Projeto 1 - dataset2.csv"; // nomeando arquivo (tipo float)
    read_csv base("../data/features-Aula 13 - Projeto 1 - dataset2.csv", "float");
    read_csv base("/home/rafael/Documentos/GitHub repositories/Projeto_1_1Bi_POO_parte-2/data/label-Aula 13 - Projeto 1 - dataset2.csv", "float");
    //read_csv label;
    //read_csv fit;
    



    // Visualizando os dados ainda no formato string
    cout << " Visualizando: " << endl << "\n";
    base.show();

    // Convertendo para algum formato (declarado na instanciação)
    base.toList("../data/features-Aula 13 - Projeto 1 - dataset2.csv", 1);

    // visualizando o numero de linhas e colunas
    cout << endl;
    cout << "Numero de Linhas do base: "<< base.get_nbrLines();
    
    cout << endl;
    cout << "Numero de colunas do base: " << base.get_nbrCols() << endl;

    // visualizando a matriz de inteiros e/ou float
    cout << endl;
    cout << " Os dados são da matriz convertida: " << endl << "\n";
    //base.imprimeData();
    cout << endl;

    //aplicando o método de média para testar a conversão
    // cout <<"\n" << " A media da coluna escohida é: " << base.mediaDeclar(1)<< endl << "\n";
    // cout<<endl;
    // cout<<    base.toList();
    // cout<<endl;
    // cout<<    base.mydataFloat();


//________________________________________________________________

    calc knn;

    knn.setMatrix(base.get_floatMatrix(), base.get_nbrLines(), base.get_nbrCols()); 
    // Utilizando o método mediaDeclar da classe knn 
    cout<<endl;
    //cout << "Media da coluna 3 é " <<  knn.mediaDeclar(base.mydataFloat(), 2) << endl << "\n";

    //knn.exibirmatriz();

    return 0;
} */






int main() {
    string dataFile = "../data/features-Aula 13 - Projeto 1 - dataset2.csv"; // Substitua pelo caminho do arquivo de dados
    string rotFile = "/home/rafael/Documentos/GitHub repositories/Projeto_1_1Bi_POO_parte-2/data/label-Aula 13 - Projeto 1 - dataset2.csv"; // Substitua pelo caminho do arquivo de rótulos

    // Leitura dos dados
    read_csv leitorData(dataFile, "float", ',');
    leitorData.toList(1); // Ignora o cabeçalho
    float** data = leitorData.get_floatMatrix();
    int lines = leitorData.get_nbrLines();
    int cols = leitorData.get_nbrCols();

    read_csv leitorRot(rotFile, "int", ',');
    leitorRot.toList(1);
    int* rot = leitorRot.get_intMatrix()[0]; // Obtém o vetor de rótulos

    // Instancia o modelo
    KNNModel modelo(5);
    modelo.fit(data, rot, lines, cols);

    // Testa o modelo
    int* predicoes = modelo.predict(data, lines); // Aqui usando os mesmos dados para simplicidade

    // Exibe as previsões
    cout << "Previsões:" << endl;
    for (int i = 0; i < lines; i++) {
        cout << "Exemplo " << i + 1 << ": Classe " << predicoes[i] << endl;
    }

    delete[] predicoes;

    return 0;
}