#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    vector<string> listaNome;
    vector<float> listaNota1;
    vector<float> listaNota2;

     int N;

    cout << "Digite o limite de Alunos da turma" << endl;
    cin >> N;
    char sn;
    do{
        string nome;
        float n1, n2;
    cout << "Deseja adicionar um aluno? (s/n)" <<  endl;
    cin >> sn;
    if(listaNome.size()>=N){
        cout << "limite de alunos atingidos" << endl;
        break;
    }
    cout << "Digite o nome do aluno" << endl;
    cin >> nome;
    cout << "Digite as notas do aluno" << endl;
    cin >> n1 >> n2;
    listaNome.push_back(nome);
    listaNota1.push_back(n1);
    listaNota2.push_back(n2);
    }while(sn != 'n');

    return 0;
}