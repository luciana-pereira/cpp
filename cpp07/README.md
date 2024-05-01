<a href="" target="_blank">Potuguês **🇧🇷**</a> | <a href="./README_en.md" target="_blank">English **🇺🇸**</a>

# Modulo 07
Neste módulo do CPP07, implementamos 3 programas divididos em 3 exercícios:

#### Exerício 00: Start with a few functions
Diretorio: _**ex00**_</br></br>
Esse exercício e o primeiro que começa lidando com o uso de template, iremos praticar a  implementação de funções em C++98 utilizando os modelos (templates). Especificamente, este exercício requer a implementação de três funções template: swap, min e max.

1. **swap:** Esta função trocara os valores de dois argumentos fornecidos. Não retornando nenhum valor, pois a troca é feita diretamente nas variáveis passadas por referência.
2. **min:** Esta função comparara dois valores passados como argumentos e retornara o menor deles. Se os dois valores forem iguais, retornara o segundo valor.
3. **max:** Esta função comparara dois valores passados como argumentos e retornara o maior deles. Se os dois valores forem iguais, retornara o segundo valor.

Estas funções foram implementadas de forma genérica, para que possam ser chamadas com qualquer tipo de argumento, desde que os argumentos tenham o mesmo tipo e suportem todos os operadores de comparação necessários.

**Ex:**
```
template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}
```
Neste exemplo, template <typename T> indica que T é um parâmetro de tipo genérico. Quando a função max é chamada com argumentos de um tipo específico, como int, double, char, etc., o compilador substitui T com esse tipo e gera uma versão específica da função para aquele tipo. Então, se chamarmos max(5, 10) ou max(3.14, 2.71), o compilador irá gerar código para uma função max específica para inteiros ou para números de ponto flutuante, respectivamente.

#### Exerício 01: Iter
Diretorio: _**ex01**_</br></br>
Esse exercício lidaremos tabém com **funções  template** em C++98, bem como o conceito de iterar sobre elementos de um array e aplicar uma função a cada um deles.

Aqui implementaremos uma função template chamada iter que aceita três parâmetros e não retorna nada. Os parâmetros são:

1. O endereço de um array.
2. O comprimento do array.
3. Uma função que será chamada em cada elemento do array.
   
A função iter deve iterar sobre os elementos do array e aplicar a função especificada a cada elemento.

Por exemplo, se tivermos um array de inteiros e uma função que imprime os elementos, podemos usar a função iter para aplicar essa função a cada elemento do array e imprimir todos os elementos. Essa flexibilidade permite que diferentes tipos de funções sejam aplicadas a diferentes tipos de arrays.

#### Exerício 02: Array
Diretorio: _**ex02**_</br></br>
Neste exercício implementaremos uma **classe template chamada Array**, que representa um array dinâmico de elementos de tipo T. A classe Array deve ter as seguintes funcionalidades e comportamentos:

1. Construção sem parâmetros: Cria um array vazio.
2. Construção com um parâmetro do tipo unsigned int n: Cria um array com n elementos inicializados por padrão.
3. Construção por cópia e operador de atribuição: A classe deve suportar construção por cópia e operador de atribuição, garantindo que a modificação de um array não afete o outro.
4. Utilização do operador new[] para alocar memória dinamicamente para o array. É proibido fazer alocação preventiva (alocar memória com antecedência). O programa não deve acessar memória não alocada.
5. Acesso aos elementos do array através do operador de subscrito [].
6. Quando acessar um elemento com o operador [], se o índice estiver fora dos limites, uma exceção std::exception deve ser lançada.
7. Uma função membro size() que retorna o número de elementos no array. Essa função não deve receber parâmetros e não deve modificar a instância atual.

