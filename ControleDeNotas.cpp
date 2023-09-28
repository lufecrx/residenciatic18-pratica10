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

        cout << endl;
    }

    // Ordena alunos e suas notas em ordem alfabética
    bool trocou;
    do
    {
        trocou = false;
        for (size_t i = 0; i < nomes.size() - 1; i++)
        {
            if (nomes[i] > nomes[i + 1])
            {
                swap(nomes[i], nomes[i + 1]);
                swap(notas1[i], notas1[i + 1]);
                swap(notas2[i], notas2[i + 1]);
                trocou = true;
            }
        }
    } while (trocou);

    // Inclusão e/ou exclusão de algum aluno
    char resposta1, resposta2;
    string nome;
    float n1, n2;
    do
    {
        cout << "Deseja incluir mais alunos? (s/n) ";
        cin >> resposta1.tolower();

        if (resposta1 == 's' && nomes.size() < N) // se a resposta for sim e tiver vaga
        {
            cout << "Nome do novo aluno: ";
            cin >> nome;

            cout << "Digite a primeira nota do aluno: ";
            cin >> n1;
            cout << "Digite a segunda nota do aluno: ";
            cin >> n2;

            cout << "---" << endl;

            size_t pos = 0;
            while (pos < nomes.size() && nome > nomes[pos])
            {
                pos++;
            }

            nomes.insert(nomes.begin() + pos, nome);
            notas1.insert(notas1.begin() + pos, n1);
            notas2.insert(notas2.begin() + pos, n2);
        }
        else if (resposta1 == 's' && nomes.size() >= N) // se a resposta for sim mas não tiver vaga
        {
            cout << "Limite de alunos atingido." << endl;
            resposta1 = 'n';
        }

        cout << "Deseja excluir algum aluno? (s/n)";
        cin >> resposta2;

        if (resposta2 == 's')
        {
            cout << "Nome do aluno que vai ser removido: ";
            cin >> nome;

            bool encontrado = false; // Variável de sinalização

            for (int i = 0; i < nomes.size(); i++)
            {
                if (nomes[i] == nome)
                {
                    nomes.erase(nomes.begin() + i);
                    notas1.erase(notas1.begin() + i);
                    notas2.erase(notas2.begin() + i);
                    cout << nome << " removido(a) com sucesso." << endl;
                    cout << "---" << endl;
                    encontrado = true; // o aluno foi encontrado e removido
                    break;
                }
            }

            if (!encontrado)
            {
                cout << "Aluno inexistente." << endl;
                cout << "---" << endl;
            }
        }
    } while (resposta1 == 's' || resposta2 == 's');

    cout << "====================" << endl;

    // Exibir boletins, com médias e se estão aprovados ou reprovados (media >= 7)
    float media;
    for (size_t i = 0; i < nomes.size(); i++)
    {
        media = (notas1[i] + notas2[i]) / 2;
        if (media >= 7)
        {
            cout << nomes[i] << ": " << media << " -- aprovado" << endl;
        }
        else
        {
            cout << nomes[i] << ": " << media << " -- reprovado" << endl;
        }
    }

    // Mostra alunos e notas
    cout << "Alunos e suas notas:" << endl;
    for (size_t i = 0; i < nomes.size(); i++)
    {
        cout << nomes[i] << " " << notas1[i] << " " << notas2[i] << endl;
    }

    return 0;
}
