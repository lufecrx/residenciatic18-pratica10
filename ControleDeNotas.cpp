#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

void exibirBoletins(const vector<string> &nomes, const vector<float> &notas1, const vector<float> &notas2)
{
    cout << "===============================" << endl;
    cout << "      Boletim dos Alunos      " << endl;
    cout << "===============================" << endl;

    cout << "Nome\t\tNota 1\tNota 2\tMédia\tSituação" << endl;

    for (size_t i = 0; i < nomes.size(); i++)
    {
        float media = (notas1[i] + notas2[i]) / 2;
        string situacao = (media >= 7) ? "Aprovado" : "Reprovado";

        cout << nomes[i] << "\t\t" << fixed << setprecision(1) << notas1[i] << "\t" << notas2[i] << "\t" << media << "\t" << situacao << endl;
    }

    cout << "===============================" << endl;
    cout << endl;
}

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

    exibirBoletins(nomes, notas1, notas2);

    return 0;
}