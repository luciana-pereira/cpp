<a href="" target="_blank">Potuguês **🇧🇷**</a> | <a href="./README_en.md" target="_blank">English **🇺🇸**</a>

# Modulo 09
Neste módulo do CPP08 da versão 2 do pdf, implementamos 3 programas divididos em 3 exercícios que podemos utilizar o STL:

**STL(Standard Template Library)**
<b>*O STL, abreviação de "Standard Template Library" (Biblioteca Padrão de Modelos)</b>, é uma parte fundamental da biblioteca padrão do C++. Ele fornece um conjunto de classes e funções que implementam estruturas de dados e algoritmos comuns de forma genérica, ou seja, independentes do tipo de dado.

O STL é composto por três componentes principais:

1. **Contêineres (Containers):** Os contêineres do STL são estruturas de dados que fornecem maneiras de armazenar e organizar coleções de elementos. Alguns exemplos de contêineres incluem vetores (std::vector), listas (std::list), filas (std::queue), pilhas (std::stack), conjuntos (std::set), mapas (std::map), entre outros.

2. **Iteradores (Iterators):** Os iteradores do STL são objetos que fornecem uma maneira de acessar sequencialmente os elementos dentro de um contêiner. Eles são usados para percorrer os elementos de um contêiner e podem ser usados para ler ou modificar os elementos. Os iteradores permitem que os algoritmos do STL operem em diferentes tipos de contêineres de maneira uniforme.

3. **Algoritmos (Algorithms):** Os algoritmos do STL são funções que operam em sequências de elementos. Eles podem ser aplicados a contêineres usando iteradores para percorrer os elementos. Alguns exemplos de algoritmos do STL incluem ordenação (std::sort), busca (std::find), transformação (std::transform), e operações de conjunto (std::set_union, std::set_intersection, etc.).

<b>**Para realizar cada um destes exercícios, devemos utilizar de containers, porem apos a utilização de um container, não poderemos no próximo exercício. com execeção do ex02 que precisara de dois tipos de containers.</b>

#### Exercício 00: Bitcoin Exchange
Diretorio: _**ex00**_</br></br>

Neste exercício escrevi um programa chamado "btc" que recebe como entrada um arquivo contendo datas e valores associados a essas datas. O programa calcula o valor de uma certa quantidade de bitcoins em uma determinada data, usando um banco de dados em formato CSV chamado data.csv, que representa o preço do bitcoin ao longo do tempo. O programa respeita várias regras, como o formato das datas e valores, lida com possíveis erros e usar pelo menos um contêiner no código.

Ele traz como resultado o valor multiplicado pela taxa de câmbio de acordo com a data indicada no banco de dados. Se a data usada na entrada não existir no banco de dados, o programa deve usa a data mais próxima contida no banco de dados (a data mais baixa). O programa lidar com vários casos de erro, como não ser possível abrir o arquivo de entrada, valores não positivos, datas inválidas e números muito grandes.

De forma geral, com este exercicio pude,  realizar a manipulação de arquivos, processamento de dados em formato CSV, manipulação de datas, tratamento de erros e uso de contêineres em C++98.
