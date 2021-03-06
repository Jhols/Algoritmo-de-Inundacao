# Algoritmo-de-Inundacao

Universidade do Estado da Bahia
Disciplina: Teoria dos Grafos
Professor: Ernesto Massa
Aluno: João Pedro Hegouet


			Algoritmo de Inundação

	Ao iniciar o programa, é lido um arquivo chamado
"matriz_adjacencias.txt".  Confere-se se o arquivo em questão possui a matriz
de adjacências de um grafo devidamente formatado de acordo com o padrão em que
se encontra escrito:
	- Intersessoes entre vertices com 0 (zero) representam que não há
	  relação de adjacências entre eles.
	- Intersessoes entre vertices com 1 (um) representam que há relação de
	  adjacências entre eles.  A conferência do arquivo analisa se o grafo
está consistente para dar prosseguimento ao algoritmo e armazena os valores
recebidos dentro de uma matriz chamada "adjacecencias[][]". Após a leitura do
arquivo, a matriz é impressa no programa com os dados armazenados em
"adjacencias[][]".

	Em seguida, o usuário digita uma letra, de A a F, que representa um
vértice do grafo, para que, inicie a inundação e busque todas as conexões
possíveis a partir do vértice escolhido.  Ao encontrar todos os vértices que
estão contidos no grafo, o programa retorna a validação informando que o grafo
é conexo, ou seja, todos os vértices possuem alguma conexão entre si. Caso
contrário, uma mensagem é emitida informando que o grafo não é conexo, já que
há a presença de algum componente desconexo (Um ou mais vértices que não
possuem ligação nenhuma com outro conjunto de vértices do mesmo grafo). 

	Para que ocorra o funcionamento do algoritmo, é necessário percorrer,
dentro de um laço, os vértices que são adjacentes ao vértice escolhido pelo
usuário e armazená-los num vetor. Neste algoritmo, foi utilizado, para isso, um
vetor chamado "vertices[]" e um ponteiro que aponta para um vértice dentro
desse vetor. Foram utilzados também outros ponteiros "i" e "j" apenas para
auxiliar a percorrer a matriz e o vetor dentro dos laços. Inicialmente a primeira
posição do vetor se encontra o vértice escolhido e o ponteiro aponta para ele.
As demais posições vão sendo preenchidas com outros vértices, a medida que
relações de adjacências são encontradas no vértice apontado. A cada adjacência
encontrada, verifica-se se o vértice adjacente ao apontado faz parte do vetor
"vertices[]", ignorando e passando para o próximo vértice caso já faça, ou
inserido-o ao vetor caso ainda não faça. Ao final de cada iteração, o ponteiro
aponta para o próximo vértice disponível dentro do vetor para que suas adjacências
sejam analisadas. Este laço continua repetindo até que não se consiga mais
procurar por vértices adjacentes disponíveis a serem apontados.

	Por fim, os vértices encontrados na inundação são impressos e ocorre a
confimação se o grafo é ou não conexo, isto é, se todos os vértices do grafo
são encontrados após uma inundação a partir de um deles.
