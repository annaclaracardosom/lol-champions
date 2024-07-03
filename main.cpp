
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const int Max = 99; //quantidade máxima de caracteres para o nome do personagem
const int n = 60; //quantidade máxima de personagens

struct Campeao
{
    char nome[Max], raca;
    int altura;
    int forca;
    char funcao;
};

int menuOpcoes()
{
    int op;
    cout << "Menu de opções" << endl;
    cout << "Pressione a tecla correspondente à  opção escolhida" << endl;
    cout << "1 - Buscar um champion pelo nome" << endl;
    cout << "2 - Ordenar champions por força, em ordem crescente" << endl;
    cout << "3 - Editar nome do champion" << endl;
    cout << "4 - Deletar champion" << endl;
    cout << "0 - Sair" << endl;
    cin >> op;
    return op;
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

void troca(&forca1, &forca2)
{
    int aux;
    aux = forca1;
    forca1 = forca2;
    forca2 = aux;
}

void ordenarPorForca(Campeao c[60])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-1; j++)
        {
            if (c[i].forca > c[i + 1].forca)
                troca(c[i].forca, c[i + 1].forca);
        }
    }
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

void busca_campeao(Campeao c[60])
{
    char nomeBusca[20];
    cout << "Digite o nome do personagem que deseja buscar: ";
    cin >> nomeBusca;

    for(int i = 0; i < Max; i++) {
        if(c[i].nome == nomeBusca) carrega_registro();
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
        switch (menuOpcoes)
        {
        case 1: cadastra_campeao(); break;
        case 2: busca_campeao(); break;
        case 3: edita_nome_campeao(); break;
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

        ofstream fout("lolchampions.csv");

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