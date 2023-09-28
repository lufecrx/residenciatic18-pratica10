#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<string> nomes;
    vector<float> notas1;
    vector<float> notas2;

    int N;

    // Solicita um limite de alunos N e os nomes e notas de cada um dos alunos
    cout << "Digite o limite de alunos: ";
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string nome;
        float n1, n2;
        cout << "Digite o nome do aluno: ";
        cin >> nome;
        cout << "Digite a primeira nota do aluno: ";
        cin >> n1;
        cout << "Digite a segunda nota do aluno: ";
        cin >> n2;
        nomes.push_back(nome);
        notas1.push_back(n1);
        notas2.push_back(n2);
    }

    return 0;

}