<a href="" target="_blank">Potuguês **🇧🇷**</a> | <a href="./README_en.md" target="_blank">English **🇺🇸**</a>

# Modulo 09
Neste módulo do CPP08 da versão 2 do pdf, implementamos 3 programas divididos em 3 exercícios que podemos utilizar o STL:

**STL(Standard Template Library)**</br>
<b>*O STL, abreviação de "Standard Template Library" (Biblioteca Padrão de Modelos)</b>, é uma parte fundamental da biblioteca padrão do C++. Ele fornece um conjunto de classes e funções que implementam estruturas de dados e algoritmos comuns de forma genérica, ou seja, independentes do tipo de dado.

O STL é composto por três componentes principais:

1. **Contêineres (Containers):** Os contêineres do STL são estruturas de dados que fornecem maneiras de armazenar e organizar coleções de elementos. Alguns exemplos de contêineres incluem vetores (std::vector), listas (std::list), filas (std::queue), pilhas (std::stack), conjuntos (std::set), mapas (std::map), entre outros.

2. **Iteradores (Iterators):** Os iteradores do STL são objetos que fornecem uma maneira de acessar sequencialmente os elementos dentro de um contêiner. Eles são usados para percorrer os elementos de um contêiner e podem ser usados para ler ou modificar os elementos. Os iteradores permitem que os algoritmos do STL operem em diferentes tipos de contêineres de maneira uniforme.

3. **Algoritmos (Algorithms):** Os algoritmos do STL são funções que operam em sequências de elementos. Eles podem ser aplicados a contêineres usando iteradores para percorrer os elementos. Alguns exemplos de algoritmos do STL incluem ordenação (std::sort), busca (std::find), transformação (std::transform), e operações de conjunto (std::set_union, std::set_intersection, etc.).

<b>**Para realizar cada um destes exercícios, devemos utilizar de containers, porem apos a utilização de um container, não poderemos no próximo exercício. com execeção do ex02 que precisara de dois tipos de containers.</b>

#### Exercício 00: Bitcoin Exchange
Diretorio: _**ex00**_</br></br>

Neste exercício escrevi um programa chamado "btc" que recebe como entrada um arquivo contendo datas e valores associados a essas datas. O programa calcula o valor de uma certa quantidade de bitcoins em uma determinada data, usando um banco de dados em formato CSV chamado data.csv, que representa o preço do bitcoin ao longo do tempo. O programa respeita várias regras, como o formato das datas e valores, lida com possíveis erros e usar pelo menos um contêiner no código.

_**Ele traz como resultado o valor multiplicado pela taxa de câmbio de acordo com a data indicada no banco de dados (data.csv). Se a data usada na entrada não existir no banco de dados, o programa deve usa a data mais próxima contida no banco de dados (a data mais baixa)**_. O programa lidar com vários casos de erro, como não ser possível abrir o arquivo de entrada, valores não positivos, datas inválidas e números muito grandes.

De forma geral, com este exercicio pude,  realizar a manipulação de arquivos, processamento de dados em formato CSV, manipulação de datas, tratamento de erros e uso de contêinere map em C++98.

- Executando o programa
```
./btc input.csv
```

#### Exercício 01:  Reverse Polish Notation
Diretorio: _**ex01**_</br></br>

Neste exercício escrevi um programa que avalia expressões matemáticas em RPN. Esse tipo de notação é uma maneira de escrever expressões matemáticas em que os operadores seguem seus operandos, o que elimina a necessidade de parênteses para determinar a ordem das operações.

Este programa recebe como argumento uma expressão matemática em notação polonesa reversa. Os números utilizados na expressão devem sempre ser menores que 10. Esta restrição se aplica aos números invidualmente na expressão, mas o calculo e o resultado final não precisão respeitar esta regra.

O programa realiza operações com +, -, /, * e utiliza container e não precisa lidar com parênteses  ou número decimal.</br></br>

**Cálculo em Notação Polonesa Reversa (RPN - Reverse Polish Notation)**</br>
Na Notação Polonesa Reversa para realizar o calculo os numeros são empilhados, devem estar separados por espaço e o operador inserido na sequencia realizara o calculo do numero. _**Ou seja, a cada dois numeros deve ter um operador, caso contrario gera um erro**_.

**Exemplo: ./RPN "3 4 + 2 * 7 /"**
```
$> ./RPN "3 4 + 2 * 7 /"
$> 2
```
O token sera lido da esquerda para direita, _**vai empilhar o numero 3 e 4, vai identificar que o proximo e um operador**_ e vai realizar a soma _**3 + 4 = 7**_, na sequencia empilha o 2 e pega o operador de multiplicação e faz a operação _**7 * 2 = 14**_, depois faz o mesmo processo com o restante, empilha o 7, pega o operador de divisão / e realiza a operação _**14 / 7 = 2**_.

#### Exercício 02:  Reverse Polish Notation
Diretorio: _**ex02**_</br></br>

Neste exercício escrevi um programa que recebe uma sequência de números inteiros positivos e a ordena utilizando o _**algoritmo de "merge-insert sort", também conhecido como o algoritmo de Ford-Johnson**_. 

<b>
**O algoritmo de Ford-Johnson é uma técnica de ordenação híbrida que combina os algoritmos de ordenação por fusão (merge sort) e de inserção (insertion sort). Ele utilizando o algoritmo de inserção para ordenar os subconjuntos menores e o algoritmo de fusão para mesclar esses subconjuntos ordenados. Ou seja, o o _algoritmo de merge-insertion sort_ ele combina estes algoritmos para:</b>

1. Dividir a a lista recursivamente em sublista
2. Ordena
3. Mescla

**A complexidade do tempo do algoritmo de merge-insertion sort pode depender do contêiner e de sua estrutura subjacente. A complexidade de tempo pode variar com base em como os elementos são acessados, inseridos e removidos do contêiner.


Este programa e capaz de lidar e identificar erros exibindo mensagens, como o tratamento para numeros duplicados, ele e capaz de manipular e ordenar pelo menos 3000 números inteiros diferentes.

O programa exibi a sequência de números antes e depois da ordenação e o tempo gasto para ordenar a sequência, exibindo para cada contêiner utilizado. A exibição do tempo e precisa o suficiente para permitir a comparação entre os dois contêineres.

**Exemplo:**</br>
```
$> ./PmergeMe 3 5 9 7 4
Before: 3 5 9 7 4
After: 3 4 5 7 9
Time to process a range of 5 elements with std::[..] : 0.00031 us
Time to process a range of 5 elements with std::[..] : 0.00014 us
```
Esse exemplo ilustra a exibição da sequência antes e depois da ordenação e medir o tempo de processamento para cada contêiner usado.

Neste programa utilizo o container list e deque, que teram uma _**diferença no tempo devido a diferença na estrutura de cada um**_:
- **List (std::list):** </br>
List armazena elementos em uma lista duplamente encadeada, ou seja _**uma estrutura de dados linear na qual cada elemento é um nó**_ que contém dois ponteiros: um para o próximo nó na sequência e outro para o nó anterior. A inserção e exclusão de elementos no meio da lista são eficientes, mas o acesso aleatório aos elementos é mais lento devido sua estrutura.

- **Deque (std::deque):** </br>
E mais rápido devido ao seu desempenho de acesso aleatório eficiente, ele _**armazena elementos em blocos de memória separados(uma matriz (array) de blocos de memória, onde cada bloco é uma estrutura de dados (como um vetor) que armazena um número fixo de elementos)**_, permitindo acesso eficiente tanto no início quanto no final do contêiner.
