#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
const int Max = 20; //quantidade m�xima de caracteres para o nome do personagem
const int n = 60; //quantidade m�xima de personagens

struct championsLol
{
    char nome[Max], raca;
    int altura;
    int forca;
    char funcao;
};

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

void imprime_champions(championsLol c[], int tam)
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

void carrega_registro(char buff[Max], championsLol &l)
{
    char aux[Max];
    int i=0;

    substring(buff, aux, i, ',');
    strcpy(l.nome, aux);

    substring(buff, aux, i, ',');
    l.altura=atoi(aux);

    substring(buff, aux, i, ',');
    l.forca=atoi(aux);

    substring(buff, aux, i, ',');
    l.raca=atoi(aux);

    substring(buff, aux, i, '\0');
    l.funcao=atoi(aux);
}

void cadastrarCampeao()
{
    championsLol champ;
    cout << "Cadastro de personagem\n";

    cout << "Nome: ";
    cin >> champ.nome;

    cout << "Altura: ";
    cin >> champ.altura;

    cout << "Força: ";
    cin >> champ.forca;

    cout << "Raça: ";
    cin >> champ.raca;

    cout << "Função: ";
    cin >> champ.funcao;
}

char buscarCampeao(championsLol[])
{
    championsLol champ;
    char nomeBusca[20];
    cout << "Digite o nome do personagem que deseja buscar: ";
    cin >> nomeBusca;

    for (int i = 0; i < Max; i++)
    {
        if (champ[i].nome == nomeBusca)
            return champ[i];
    }
}

void editarNomeCampeao(championsLol[])
{
    championsLol champ;
    char novoNome[20];
    buscarCampeao(champ[]);
    cout << "Digite o novo nome do personagem: ";
    cin >> novoNome;

}

int main()
{
    championsLol c[60];
    setlocale(LC_ALL, "Portuguese");

    ifstream fin("lolChampions.csv");

    if(fin.is_open())
    {
        int j=0;
        char buff[Max];

        fin.getline(buff, Max); // ignora a primeira linha do arquivo (cabe�alho)
        while(fin.getline(buff, Max))
        {
            carrega_registro(buff, c[j]);
            j++;
        }

        imprime_champions(c, j);

        ofstream fout("Personagens_Marvel_acima2m.csv");

        if(fout.is_open())
        {
            fout << "nome,altura,forca,raça,função\n";
            for(int i=0; i<j; i++)
                if(c[i].altura>200)
                    fout << p[i].nome << "," << p[i].altura << "," << p[i].inteligencia << "," << p[i].forca << "," << p[i].velocidade << "," << p[i].habilidade << endl;
            fout.close();
        }
        else
            cout << "Não conseguiu abrir o arquivo de saída!";

        fin.close();
    }
    else
        cout << "N�o conseguiu abrir o arquivo de entrada!";

    return 0;
}
