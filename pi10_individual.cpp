#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int N;
    cout << "Digite o limite de alunos (N): ";
    cin >> N;

    // Verificando se N é um valor válido
    if (N <= 0) {
        cout << "O limite de alunos deve ser um número positivo." << endl;
        return 1;
    }

    vector<string> nomes;
    vector<vector<float>> notas;

    for (int i = 0; i < N; i++) {
        string nome;
        float nota1, nota2;

        cout << "Digite o nome do aluno " << i + 1 << ": ";
        cin.ignore(); // Limpar o buffer de entrada
        getline(cin, nome);

        cout << "Digite a primeira nota do aluno " << i + 1 << ": ";
        cin >> nota1;

        cout << "Digite a segunda nota do aluno " << i + 1 << ": ";
        cin >> nota2;

        nomes.push_back(nome);
        vector<float> notas_aluno = {nota1, nota2};
        notas.push_back(notas_aluno);
    }

    // Exibindo os dados dos alunos
    cout << "\nDados dos alunos:\n";
    for (int i = 0; i < N; i++) {
        cout << "Aluno " << i + 1 << ": " << nomes[i] << endl;
        cout << "Notas: " << notas[i][0] << " " << notas[i][1] << endl;
    }

    return 0;
}
