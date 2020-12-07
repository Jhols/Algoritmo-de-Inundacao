#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>

#define MAX_VERTICES 6

int main(int argc, char const *argv[])
{
    FILE *FD = NULL; //Arquivo de leitura da matriz de adjacencias
    char *arq = "matriz_adjacencias.txt"; //Nome do arquivo que possui a matriz de adjacencias a ser lida

    int adjacencias[MAX_VERTICES][MAX_VERTICES];
    int vertices[MAX_VERTICES+1];
    int ponteiro = 0; //Aponta para um vertice

    //Zera todas as adjacencias dos vertices para limpar sujeira de buffer.
    for (int i = 0; i < MAX_VERTICES; i++)
        for (int j = 0; j < MAX_VERTICES; j++)
            adjacencias[i][j] = 0;

    printf("Realizando leitura do arquivo...\n");

    FD = fopen(arq, "r"); //Abre o arquivo para leitura da matriz de adjacencias.
    if (FD == NULL)
    {
        printf ("Erro na abertura do arquivo.\n");
        exit(1);
    }
    else //Realiza a leitura da matriz de adjacencias pelo arquivo "matriz_adjacencias.txt".
    {
        int apontador_arq = 16;
        char g = 0;
        fseek(FD, apontador_arq, SEEK_SET);

        for (int i = 0; i < MAX_VERTICES; i++)
        {
            for (int j = 0; j < MAX_VERTICES; j++)
            {
                fscanf(FD, "%c", &g);
                if (g != '0' && g != '1')
                {
                    printf("Esta matriz nao esta' consistente!\n");
                    printf("Erro na leitura dos dados. Verifique se a matriz esta' formatada corretamente no arquivo \"%s\"\n", arq);
                    fclose(FD);
                    exit(1);
                }
                adjacencias[i][j] = g-48; //Armazena na memoria o valor lido do arquivo. "48" representa o inteiro 0 na tabela ASCII
                fseek(FD, 1, SEEK_CUR);
            }
            fseek(FD, 2, SEEK_CUR);
        }
        
    }
    fclose(FD);
    printf("Esta matriz esta' consistente!\n\n");

    char c = 65;
    //Imprime matriz de adjacencias
    printf("--- ALGORITMO DE INUNDACAO ---\n\n");

    printf("Matriz de Adjacencias:\n");
    printf(" ");
    for (int i = 0; i < MAX_VERTICES; i++)
    {
        printf(" %c", c+i);
    }
    printf("\n");

    for (int i = 0; i < MAX_VERTICES; i++)
    {
        printf("%c ", c+i);
        for (int j = 0; j < MAX_VERTICES; j++)
        {
            printf("%d ", adjacencias[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    //Algoritmo de Inundacao
    printf("Escolha um vertice de A a %c para iniciar\n> ", MAX_VERTICES+64);
    char opc = '\0';
    scanf("%c", &opc); //Usuario digita o caractere de um vertice para dar inicio 'a inundacao.
    fflush(stdin);
    opc = toupper(opc);

    if (opc < 65 || opc > 65 + MAX_VERTICES) {
        printf("\nVertice Invalido! Reinicie o programa e tente novamente.\n");
        return -1;
    }
    else
    {
        vertices[0] = opc-65; //Escolhe o primeiro vertice para comecar o algoritmo. 65 representa o caractere 'A' na tabela ASCII.
        vertices[1] = -1; //O Valor "-1" e' a condicao de parada da iteracao no vetor de vertices.
        ponteiro = vertices[0]; //Aponta para o primeiro vertice escolhido para o inicio do algoritmo.
        int pos = 0; //Posicao de leitura do vetor de vertices.

        while (vertices[pos] != -1) //Enquanto o ponteiro apontar para vertices no vetor de vertices, ele fara' as proximas instrucoes.
        {
            for (int i = 0; i < MAX_VERTICES; i++) //Percorre as colunas da matriz de vertices.
            {
                if (adjacencias[ponteiro][i] == 1) //Condicao para caso haja adjacencia entre dois vertices.
                {
                    int j=0;
                    //Percorre o vetor de vertices pesquisando se o vertice adjacente ao apontado ja esta' inserido.
                    while (vertices[j] != i && vertices[j] != -1)
                    {
                        j++;
                    }
                    if (vertices[j] == -1) //Se o vertice adjacente nao faz parte do vetor de vertices, ele é inserido.
                    {
                        vertices[j] = i; //Insere o novo vertice ao vetor de vertices.
                        vertices[j+1] = -1; //Faz com que a proxima posicao do vetor nao aponte para um vertice valido.
                    }
                    
                }
                
            }
            
            pos++;
            ponteiro = vertices[pos];
        }

        //Imprime o vetor de vertices encontrados na inundacao.
        printf("\n");
        for (int i = 0; vertices[i] != -1; i++)
        {
            printf("%c ", vertices[i]+65);
        }
        
        //Confere se o grafo em questao esta conexo ou nao.
        printf("\n\n");
        printf("Numero de Vertices Encontrados: %d\n", pos);
        if (pos == MAX_VERTICES)
            printf("Este grafo e' CONEXO!\n");
        else
            printf("Este grafo e' DESCONEXO!\n");    
    }
    
    return 0;
}
