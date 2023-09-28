#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Função para ordenar nomes usando o algoritmo Bubble Sort
void ordenarNomes(vector<string>& nomes, vector<float>& notas) {
    int tamanho = nomes.size();

    for (int i = 0; i < tamanho - 1; ++i) {
        for (int j = 0; j < tamanho - i - 1; ++j) {
            if (nomes[j] > nomes[j + 1]) {
                // Trocar nomes
                swap(nomes[j], nomes[j + 1]);
                // Trocar notas correspondentes
                swap(notas[j], notas[j + 1]);
            }
        }
    }
}

int main() {
    int N;
    cout << "Digite o limite de alunos (N): ";
    cin >> N;

    vector<string> nomes;
    vector<float> notas1;
    vector<float> notas2;

    char continuar;
    do {
        string nome;
        float nota1, nota2;

        // Verificar se já atingimos o limite de alunos
        if (nomes.size() >= N) {
            cout << "Limite de alunos atingido. Não é possível adicionar mais alunos." << endl;
            break;
        }

        // Solicitar nome e notas
        cout << "Digite o nome do aluno: ";
        cin >> nome;
        cout << "Digite a primeira nota do aluno: ";
        cin >> nota1;
        cout << "Digite a segunda nota do aluno: ";
        cin >> nota2;

        // Adicionar nome e notas aos vetores
        nomes.push_back(nome);
        notas1.push_back(nota1);
        notas2.push_back(nota2);

        // Perguntar se deseja incluir mais alunos
        cout << "Deseja incluir mais alunos (s/n)? ";
        cin >> continuar;
    } while (continuar == 's' || continuar == 'S');

    // Ordenar os nomes lexicograficamente
    ordenarNomes(nomes, notas1);
    ordenarNomes(nomes, notas2);

    // Etapa 3: Inclusão e exclusão de alunos
    char incluir, excluir;
    do {
        // Perguntar se deseja incluir mais alunos
        cout << "Deseja incluir mais alunos (s/n)? ";
        cin >> incluir;

        if (incluir == 's' || incluir == 'S') {
            string nome;
            float nota1, nota2;

            // Verificar se já atingimos o limite de alunos
            if (nomes.size() >= N) {
                cout << "Limite de alunos atingido. Não é possível adicionar mais alunos." << endl;
                break;
            }

            // Solicitar nome e notas
            cout << "Digite o nome do aluno: ";
            cin >> nome;
            cout << "Digite a primeira nota do aluno: ";
            cin >> nota1;
            cout << "Digite a segunda nota do aluno: ";
            cin >> nota2;

            // Adicionar nome e notas aos vetores
            nomes.push_back(nome);
            notas1.push_back(nota1);
            notas2.push_back(nota2);

            // Ordenar os nomes lexicograficamente
            ordenarNomes(nomes, notas1);
            ordenarNomes(nomes, notas2);
        }

        // Perguntar se deseja excluir algum aluno
        cout << "Deseja excluir algum aluno (s/n)? ";
        cin >> excluir;

        if (excluir == 's' || excluir == 'S') {
            string nomeExcluir;
            cout << "Digite o nome do aluno que deseja excluir: ";
            cin >> nomeExcluir;

            bool encontrado = false;
            for (size_t i = 0; i < nomes.size(); ++i) {
                if (nomes[i] == nomeExcluir) {
                    encontrado = true;
                    // Remover o aluno
                    nomes.erase(nomes.begin() + i);
                    notas1.erase(notas1.begin() + i);
                    notas2.erase(notas2.begin() + i);
                    cout << "Aluno removido com sucesso." << endl;
                    break;
                }
            }

            if (!encontrado) {
                cout << "Aluno não encontrado." << endl;
            }
        }
    } while (incluir == 's' || incluir == 'S' || excluir == 's' || excluir == 'S');

    // Etapa 4: Listar alunos, notas e médias
    char alterarNota;
    do {
        cout << "Lista de alunos e notas:" << endl;
        for (size_t i = 0; i < nomes.size(); ++i) {
            cout << "Nome: " << nomes[i] << " | Nota 1: " << notas1[i] << " | Nota 2: " << notas2[i] << endl;
        }

        // Verificar se deseja alterar alguma nota
        cout << "Deseja alterar alguma nota (s/n)? ";
        cin >> alterarNota;

        if (alterarNota == 's' || alterarNota == 'S') {
            string nomeAluno;
            cout << "Digite o nome do aluno cuja nota deseja alterar: ";
            cin >> nomeAluno;

            bool encontrado = false;
            for (size_t i = 0; i < nomes.size(); ++i) {
                if (nomes[i] == nomeAluno) {
                    encontrado = true;
                    cout << "Notas atuais do aluno:" << endl;
                    cout << "Nota 1: " << notas1[i] << " | Nota 2: " << notas2[i] << endl;

                    int opcao;
                    do {
                        cout << "Alterar a primeira nota (1), a segunda nota (2) ou nenhuma (0)? ";
                        cin >> opcao;

                        if (opcao == 1) {
                            cout << "Digite a nova primeira nota: ";
                            cin >> notas1[i];
                            cout << "Nota alterada com sucesso." << endl;
                        } else if (opcao == 2) {
                            cout << "Digite a nova segunda nota: ";
                            cin >> notas2[i];
                            cout << "Nota alterada com sucesso." << endl;
                        } else if (opcao != 0) {
                            cout << "Opção inválida. Tente novamente." << endl;
                        }
                    } while (opcao != 0);

                    break;
                }
            }

            if (!encontrado) {
                cout << "Aluno não encontrado." << endl;
            }
        }
    } while (alterarNota == 's' || alterarNota == 'S');

    // Etapa 5: Listar alunos e médias
    cout << "Lista de alunos e médias:" << endl;
    for (size_t i = 0; i < nomes.size(); ++i) {
        float media = (notas1[i] + notas2[i]) / 2;
        cout << "Nome: " << nomes[i] << " | Média: " << media << " | Situação: ";
        if (media >= 7) {
            cout << "Aprovado";
        } else {
            cout << "Reprovado";
        }
        cout << endl;
    }

    return 0;
}
