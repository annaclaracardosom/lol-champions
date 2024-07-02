
#include <iostream>
#include <fstream>
#include <cstring>
#include <stdlib.h>

using namespace std;

const int Max = 20; //quantidade máxima de caracteres para o nome do personagem
const int n = 60; //quantidade máxima de personagens

struct Campeao
{
    char nome[Max], raca;
    int altura;
    int forca;
    char funcao;
};

void carrega_tela_operacoes() {
    cout << "Selecione uma das operações para manipular a lista de campeões:" << endl;
    cout << "         CADASTRAR [1] | BUSCAR [2] | DELETAR [3]\n\n\n\n" << endl;
    cout << "ENCERRAR [4]\n";
}

void substring(char buff[Max], char aux[Max], int &i, char delim)
{
    int k = 0;
    while(buff[i] != delim)
    {
        aux[k] = buff[i];
        i++;
        k++;
    }
    aux[k] = '\0';
    i++;
}

void imprime_campeoes(Campeao c[], int tam)
{
    for(int i=0; i<tam; i++)
    {

        cout << i+1 << " - " << c[i].nome << endl;
        cout << "Altura: " << c[i].altura << endl;
        cout << "Força: " << c[i].forca << endl;
        cout << "Raça: " << c[i].raca << endl;
        cout << "Função: " << c[i].funcao << endl << endl;

        system("pause");
    }
}

void carrega_registro(char buff[Max], Campeao &c)
{
    char aux[Max];
    int i=0;

    substring(buff, aux, i, ','); strcpy(c.nome, aux);

    substring(buff, aux, i, ','); c.altura=atoi(aux);

    substring(buff, aux, i, ','); c.forca=atoi(aux);

    substring(buff, aux, i, ','); c.raca=atoi(aux);

    substring(buff, aux, i, '\0'); c.funcao=atoi(aux);
}

void cadastra_campeao()
{
    Campeao c;
    cout << "Cadastro de personagem\n";

    cout << "Nome: "; cin >> c.nome;

    cout << "Altura: "; cin >> c.altura;

    cout << "Força: "; cin >> c.forca;

    cout << "Raça: "; cin >> c.raca;

    cout << "Função: "; cin >> c.funcao;
}

int busca_campeao(Campeao c[60])
{
    char nomeBusca[20];
    cout << "Digite o nome do personagem que deseja buscar: ";
    cin >> nomeBusca;

    for(int i = 0; i < Max; i++) {
        if(c[i].nome == nomeBusca) return i;
    }
}

void edita_nome_campeao(Campeao c[60])
{
    char novoNome[20];
    cout << "Digite o novo nome do personagem: ";
    cin >> novoNome;
}

int main()
{
    Campeao c[60];
    setlocale(LC_ALL, "Portuguese");

    ifstream fin("lolchampions.csv");

    while(fin.is_open())
    {
        int op;
        carrega_tela_operacoes();
        cin >> op;
        
        switch (op)
        {
        case 1: cadastra_campeao(); break;
        case 2: busca_campeao(); break;
        case 3: 

            break;
        default: fin.close();
            break;
        }
        int j=0;
        char buff[Max];

        fin.getline(buff, Max); // ignora a primeira linha do arquivo (cabeçalho)
        while(fin.getline(buff, Max))
        {
            carrega_registro(buff, c[j]);
            j++;
        }

        imprime_campeoes(c, j);

        ofstream fout("Personagens_Marvel_acima2m.csv");

        if(fout.is_open())
        {
            fout << "nome,altura,forca,raça,função\n";
            for(int i=0; i<j; i++)
                if(c[i].altura>200)
                {
                    fout << c[i].nome << "," << c[i].altura << "," << c[i].forca << "," << c[i].funcao << "," << c[i].raca << endl;
                }
            fout.close();
        }
        else cout << "Não conseguiu abrir o arquivo de saída!";
    }
 
    return 0;
}