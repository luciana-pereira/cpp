<a href="" target="_blank">Potuguês **🇧🇷**</a> | <a href="./README_en.md" target="_blank">English **🇺🇸**</a>

# Modulo 08
Neste módulo do CPP08, implementamos 3 programas divididos em 3 exercícios que podemos utilizar o STL, Containers e Algorithm, além de lidam com:

**Estruturas de dados para armazenar e manipular coleções de elementos**</br>
1. **Array (vetor):** </br>
Arrays são estruturas de dados simples que armazenam uma coleção fixa de elementos do mesmo tipo em ordem sequencial na memória. Em C++98, os arrays têm um tamanho fixo que deve ser especificado em tempo de compilação.

```
int myArray[5]; // Declarando um array de inteiros com tamanho 5
```

2. **Vector (vetor dinâmico):** </br>
Os vetores dinâmicos são semelhantes aos arrays, mas têm tamanho dinâmico, o que significa que podem crescer ou diminuir conforme necessário. Em C++98, muitas vezes as pessoas usavam arrays dinâmicos ou implementavam seus próprios vetores dinâmicos, já que a STL ainda não era tão amplamente adotada.

```
#include <vector>
std::vector<int> myVector; // Declarando um vetor dinâmico de inteiros
```

3. **List (lista duplamente encadeada):** </br>
Uma lista duplamente encadeada é uma estrutura de dados que armazena uma coleção de elementos onde cada elemento tem um ponteiro para o próximo e para o anterior na lista. Isso permite inserções e remoções eficientes em qualquer posição da lista.

```
#include <list>
std::list<int> myList; // Declarando uma lista de inteiros
```

4. **Map (mapa):** </br>
Um mapa é uma estrutura de dados que armazena uma coleção de pares chave-valor, onde cada chave é única. Os mapas são geralmente implementados usando árvores binárias de busca balanceadas, como árvores rubro-negras.
```
#include <map>
std::map<std::string, int> myMap; // Declarando um mapa de string para int
```

5. **Set (conjunto):** </br>
Um conjunto é uma coleção de elementos únicos, onde a ordem dos elementos geralmente não é importante. Internamente, os conjuntos geralmente são implementados usando árvores binárias de busca balanceadas.

```
#include <set>
std::set<int> mySet; // Declarando um conjunto de inteiros
```

6. **Templates Containers:** </br>
_**Templates Containers ou contêineres com modelos, são estruturas de dados que podem armazenar e organizar coleções de elementos**_. Esses contêineres são "templated" porque são criados usando modelos de classes, permitindo que sejam parametrizados por tipo. Alguns exemplos comuns de contêineres em C++98 incluem _**std::vector, std::list, std::map, e std::set**_.

7. **Iterators:** </br>
_**Os iteradores são objetos que fornecem uma maneira de acessar sequencialmente os elementos dentro de um contêiner**_. Eles são essenciais para percorrer os elementos de um contêiner e podem ser usados para ler ou modificar os elementos. Em C++98, os iteradores são conceitualmente separados em cinco categorias: input iterators, output iterators, forward iterators, bidirectional iterators e random access iterators, cada um oferecendo diferentes funcionalidades e garantias de desempenho

8. **Algorithms:** </br>
_**Os algoritmos são funções que operam em sequências de elementos**_. Esses algoritmos podem ser aplicados a contêineres, usando iteradores para percorrer os elementos. Alguns _**exemplos de algoritmos comuns incluem std::sort, std::find, std::transform, e std::accumulate.**_ Esses algoritmos fornecem funcionalidades para ordenar elementos, buscar por elementos específicos, transformar elementos de uma forma específica, e realizar operações de redução em uma sequência, respectivamente.

De forma geral, em conjunto, os contêineres, iteradores e algoritmos fornecem uma maneira poderosa e flexível de manipular e processar dados em C++98. Eles são a base da Biblioteca Padrão do C++, permitindo aos desenvolvedores escrever código eficiente e expressivo para uma ampla gama de tarefas.

## Sobre a implementação dos exercicíos:

#### Exercício 00: Easy find
Diretorio: _**ex00**_</br></br>

Neste exercício escrevi uma **função template** chamada _**easyfind**_ que aceita um tipo _**T**_. Esta função recebe dois parâmetros: o primeiro é do tipo T e o segundo é um inteiro. _**A função easyfind deve procurar a primeira ocorrência do segundo parâmetro no primeiro parâmetro**_.

Porém o subject pede que T deve ser um contêiner de inteiros. Isso significa que T deve ser um tipo de contêiner como std::vector<int>, std::list<int>, ou algo similar que e recebido pelo easyfind.

No _**main.cpp**_, se a _**função easyfind encontrar a ocorrência do segundo parâmetro no contêiner, ela deve retornar a posição (índice) onde o elemento foi encontrado**_. Caso contrário, a função pode sinalizar a ausência de uma ocorrência lançando uma exceção ou retornando um valor de erro, conforme especificado pelo exercício, mas no caso desta implementação retorna uma execeção.

A inspiração para a implementação da função easyfind é sugerida ser derivada do comportamento dos contêineres padrão do C++. Isto é, o funcionamento da função deve se assemelhar ao comportamento das funções de busca fornecidas pelos contêineres padrão da linguagem.

O **subjct tambem exige que utilizemos o STL(Standard Template Library)**, e utilizamos na função easyfind, _**std::find()**_ é usado para procurar o valor dentro do contêiner especificado. Este algoritmo percorre os elementos do contêiner e retorna um iterador apontando para a primeira ocorrência do valor no contêiner, ou para o final do contêiner se o valor não for encontrado. 

Ou seja, **std::find() é uma função da STL que é utilizada para a busca de elementos em sequências (como vetores e listas)** e é fundamental para a implementação da solução no código.

<b>*O STL, abreviação de "Standard Template Library" (Biblioteca Padrão de Modelos)</b>, é uma parte fundamental da biblioteca padrão do C++. Ele fornece um conjunto de classes e funções que implementam estruturas de dados e algoritmos comuns de forma genérica, ou seja, independentes do tipo de dado.

O STL é composto por três componentes principais:

1. **Contêineres (Containers):** Os contêineres do STL são estruturas de dados que fornecem maneiras de armazenar e organizar coleções de elementos. Alguns exemplos de contêineres incluem vetores (std::vector), listas (std::list), filas (std::queue), pilhas (std::stack), conjuntos (std::set), mapas (std::map), entre outros.

2. **Iteradores (Iterators):** Os iteradores do STL são objetos que fornecem uma maneira de acessar sequencialmente os elementos dentro de um contêiner. Eles são usados para percorrer os elementos de um contêiner e podem ser usados para ler ou modificar os elementos. Os iteradores permitem que os algoritmos do STL operem em diferentes tipos de contêineres de maneira uniforme.

3. **Algoritmos (Algorithms):** Os algoritmos do STL são funções que operam em sequências de elementos. Eles podem ser aplicados a contêineres usando iteradores para percorrer os elementos. Alguns exemplos de algoritmos do STL incluem ordenação (std::sort), busca (std::find), transformação (std::transform), e operações de conjunto (std::set_union, std::set_intersection, etc.).

##### Implementação do código:
1. **Função easyfind:** A função easyfind é uma função template que aceita um tipo de contêiner T, aceita um contêiner mutável (T&) e outra que aceita um contêiner constante (const T&) e um valor inteiro como parâmetros. Ela usa o algoritmo std::find da STL para procurar a primeira ocorrência do valor no contêiner. Se o valor for encontrado, a função retorna um iterador para a posição onde o valor foi encontrado. Caso contrário, ela lança uma exceção std::runtime_error, como especificado no exercício.

2. **Teste main:** O teste main demonstra o uso da função easyfind com dois tipos de contêineres diferentes (std::vector e std::list), como solicitado pelo exercício. Ele preenche os contêineres com valores e testa a função easyfind para encontrar ou não encontrar os valores especificados, conforme descrito no objetivo do exercício. Além disso, o teste também demonstra o tratamento de exceções quando o valor não é encontrado no contêiner, **ele so lida com conteiners de inteiro porque a busca e atraves de um valor de int**.

<b>**Importante: Este exercício é um template de função e não precisa estar na forma canonica ortodoxa. Em resumo, sua _o easyfind é um wrapper para a função std::find_, que por sua vez não envolve gerenciamento de recursos complexos. Assim, para este caso específico, não é necessária uma implementação explícita dos métodos da forma canônica ortodoxa. Não há nenhuma classe além da classe de template easyfind, que é uma função, não uma classe.</b>

#### Exercício 01: Span
Diretorio: _**ex01**_</br></br>
Neste exercício escrevi uma classe chamada **Span** que pode armazenar um máximo de N inteiros, onde N é passado como parâmetro para o construtor da classe. Para cumprir os requisitos do subject (pdf) foi criado os seguintes métodos na classe Span:

1. **Método addNumber():** Este método permite adicionar um único número ao Span. Se houver já N elementos armazenados e uma tentativa de adicionar um novo elemento for feita, a classe deve lançar uma exceção.
2. **Método shortestSpan():** Este método encontra o menor intervalo (ou diferença) entre todos os números armazenados no Span e o retorna. Se não houver números armazenados ou apenas um número, nenhum intervalo pode ser encontrado, portanto, a classe deve lançar uma exceção.
3. **Método longestSpan():** Este método encontra o maior intervalo (ou diferença) entre todos os números armazenados no Span e o retorna. Novamente, se não houver números armazenados ou apenas um número, nenhum intervalo pode ser encontrado, então a classe deve lançar uma exceção.

De forma geral, a classe Span armazenara os números e fornecera métodos para calcular o menor e o maior intervalo entre esses números, além de permitir adicionar números de forma eficiente utilizando um intervalo de iteradores.

#### Exercício 02: Mutated abomination
Diretorio: _**ex02**_</br></br>
Neste exercício escrevi uma classe chamada MutantStack que estende a funcionalidade do contêiner std::stack fornecendo iteradores, tornando-o iterável.

O std::stack é uma estrutura de dados que fornece uma interface de pilha (LIFO - Last In, First Out, ou seja o último elemento inserido na pilha é o primeiro a ser removido, e o primeiro elemento a ser adicionado à pilha será o último a ser removido) sobre outro contêiner subjacente da STL, geralmente um std::deque, std::vector ou std::list. **_No entanto, o std::stack em si não é iterável, o que significa que não é possível percorrê-lo usando loops for ou while como faria com outros contêineres da STL_**.

<b>*Para corrigir essa limitação, foi criada uma classe chamada MutantStack, que herda de std::stack, e adiciona a funcionalidade de iteradores. Os iteradores permitem percorrer os elementos da pilha de forma sequencial, semelhante a como percorreriamos os elementos de uma lista ou vetor.</b>


