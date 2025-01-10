

#include <fstream> 
#include <iostream> 
#include <sstream> 
#include <iomanip>
#include "../includes/calc.cpp"
#include "../includes/read_csv.cpp"


using namespace std; 


int main(){
    //instanciando objeto________________________________________

    //string file_int = "../data/features-Aula 13 - Projeto 1 - dataset1.csv"; // nomeando arquivo (tipo inteiro)
    //string file_float = "../data/features-Aula 13 - Projeto 1 - dataset2.csv"; // nomeando arquivo (tipo float)
    read_csv base("../data/features-Aula 13 - Projeto 1 - dataset2.csv", "float");
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
} 