<a href="" target="_blank">Potuguês **🇧🇷**</a> | <a href="./README_en.md" target="_blank">English **🇺🇸**</a>

# Modulo 06
Neste módulo do CPP06, implementamos 3 programas divididos em 3 exercícios:

#### Exerício 00:   Conversion of scalar types
Diretorio: _**ex00**_</br></br>
Neste exercício, criei a classe chamada **ScalarConverter** que tenha um método estático chamado convert em **ScalarConverter.cpp**. Esse método deve receber como parâmetro uma representação de string de um literal em C++98 em sua forma mais comum e deve produzir seu valor em vários tipos escalares, como char, int, float e double. O desafio foi inclui e lidar com diferentes tipos de literais, como literais de char, int, float e double, bem como "pseudo literais" como -inff, +inff e nanf.

Dentro dos requisitos da implementação temos:
- [x] Criar uma classe ScalarConverter com um método estático chamado convert.
- [x] Detectar o tipo do literal passado como parâmetro.
- [x] Converter o literal de string para seu tipo real.
- [x] Converter explicitamente o literal para os outros três tipos de dados (char, int, float e double).
- [x] Exibir os resultados conforme especificado no exemplo fornecido, incluindo mensagens informativas em caso de conversão impossível ou overflow.

O desafio final foi implementar no _**arquivo ScalarConverterFunctionsUtils.cpp**_ funç~ções que auxilião na hora de converter uma representação de string de um literal em C++98 para diferentes tipos escalares e exibir os resultados de forma adequada, lidando com diferentes casos de entrada e saída, como literais normais, pseudo literais e caracteres não exibíveis. Como por exemplo:

- **detectType:** Esta função é responsável por determinar o tipo do literal fornecido como entrada. Ela percorre cada caractere da string literal e verifica se o literal corresponde a um número, se contém um ponto decimal (indicando um float ou double) ou se contém o sufixo 'f' (indicando um float). Além disso, ela também identifica pseudo literais (como "nan", "+inf", "-inf") e caracteres não imprimíveis. Com base na análise, ela retorna um enum correspondente ao tipo do literal.

- **containsNonPrintable:** Esta função verifica se a string literal contém caracteres não imprimíveis. Ela itera sobre cada caractere da string e verifica se seu código ASCII está fora do intervalo de caracteres imprimíveis.

- **displayConversion:** Esta função recebe o literal e o tipo detectado como entrada e chama a função de conversão apropriada com base no tipo. Ela utiliza uma instrução switch para chamar a função de conversão correspondente.

- **convertChar:** Esta função converte o literal para os tipos char, int, float e double, e imprime os resultados formatados adequadamente. Ela verifica se o caractere é imprimível e se seu valor está dentro dos limites do tipo de dados.

- **convertInt:** Esta função converte o literal para os tipos int, float e double, e imprime os resultados formatados adequadamente. Ela verifica se o valor está dentro dos limites do tipo de dados.

- **convertFloat:** Esta função converte o literal para os tipos float e double, e imprime os resultados formatados adequadamente. Ela verifica se o valor está dentro dos limites do tipo de dados.

- **convertDouble:** Esta função converte o literal para o tipo double e imprime o resultado formatado adequadamente. Ela verifica se o valor está dentro dos limites do tipo de dados.

- **handlePseudoLiterals:** Esta função lida com os pseudo literais (como "nan", "+inf", "-inf") e imprime os resultados formatados adequadamente para float e double.

Neste arquivo tambem utilizo de _**função/métodos auxiliares**_ como:

- **std::setprecision(1):** Este método é usado para definir a precisão das casas decimais ao exibir valores float e double. Neste caso, ele é utilizado para garantir que apenas uma casa decimal seja exibida ao converter valores para float e double, conforme especificado nos exemplos de saída fornecidos.

- **std::isdigit():** Esta função é usada para verificar se um caractere é um dígito decimal. Ela é usada dentro da função detectType() para determinar se um caractere em uma string literal é um dígito.

- **std::atol():** Esta função converte uma string para um tipo long int representando o número na base 10. É utilizada em várias partes do código para converter as strings literais para tipos numéricos (como int, float, double) antes de efetuar operações matemáticas ou compará-los com os limites dos tipos escalares.

- **std::atoi():** Esta função converte uma sequência de caracteres representando um número inteiro em uma representação numérica. Ela é usada nas funções convertChar(), convertInt(), convertFloat() e convertDouble() para converter uma string literal em um valor numérico inteiro.

- **std::atof():** Esta função converte uma sequência de caracteres representando um número de ponto flutuante em uma representação numérica. Ela é usada nas funções convertFloat() e convertDouble() para converter uma string literal em um valor numérico de ponto flutuante.

- **std::isprint():** Esta função é usada para verificar se um caractere é um caractere imprimível, ou seja, se ele é exibido quando impresso na tela. Ela é usada nas funções convertChar(), convertInt(), convertFloat() e convertDouble() para garantir que o caractere resultante da conversão seja imprimível.

- **std::numeric_limits:** Esta é uma classe de template que fornece informações sobre os limites dos tipos numéricos em C++. Ela é usada nas funções convertChar(), convertInt(), convertFloat() e convertDouble() para verificar se os valores convertidos estão dentro dos limites permitidos para cada tipo numérico.

- **std::fixed:** Este manipulador de fluxo de saída é usado para imprimir números em notação decimal fixa. Ele é utilizado em conjunto com std::setprecision() para controlar a formatação da saída de números float e double.

#### Exerício 01:   Serialization
Diretorio: _**ex00**_</br></br>
Neste exercício, implementei a classe chamada Serializer, que será responsável por serializar e deserializar ponteiros de uma estrutura de dados chamada Data.

***Serialização** e **desserialização*** são processos importantes em ciência da computação e engenharia de software que envolvem a conversão de dados em um formato que pode ser facilmente armazenado, transmitido ou manipulado de alguma forma. Aqui está uma explicação mais detalhada de cada conceito:

**1. Serialização:**
Serialização é o processo de _**converter uma estrutura de dados em um formato serializado, geralmente uma sequência de bytes**_. O objetivo da serialização é tornar os dados persistentes ou transferíveis, ou seja, capazes de serem armazenados em um arquivo, transmitidos pela rede ou mantidos em memória de forma que possam ser recuperados posteriormente. Durante a serialização, os dados são organizados de uma maneira específica que permita que sejam reconstruídos posteriormente, mantendo sua estrutura e conteúdo originais.

**2. Desserialização:**
_**Desserialização é o processo inverso da serialização. Envolve a reconstrução dos dados a partir de sua representação serializada**_. Durante a desserialização, os dados serializados são lidos e interpretados de acordo com o formato em que foram serializados, e então são convertidos de volta para a estrutura de dados original. O _**objetivo da desserialização é recuperar os dados em sua forma original, de modo que possam ser manipulados ou processados ​​como antes da serialização.**_

Em resumo, serialização e desserialização são técnicas essenciais para armazenar, transmitir e manipular dados de forma eficiente e flexível em sistemas de software. Elas permitem que os dados sejam transferidos entre diferentes sistemas ou persistidos em armazenamento de longo prazo de uma maneira que preserve sua integridade e estrutura original.

Mas os principais pontos da implentação do exercicio é: 

**1. Classe Serializer:**
- Onde implemento a classe chamada Serializer, que não pode ser inicializada pelo usuário de qualquer forma.
- A classe tem de conter dois métodos estáticos:
  - <b>uintptr_t serialize(Data* ptr):</b> Recebe um ponteiro para um objeto Data e o converte para o tipo de inteiro sem sinal uintptr_t.
  - <b>Data* deserialize(uintptr_t raw):</b> Recebe um parâmetro do tipo inteiro sem sinal uintptr_t e o converte de volta para um ponteiro para um objeto Data.
    
**Teste da classe Serializer:**
No main, escrevialguns testes para a classe Serializer, e verificar se funciona conforme o esperado no subject:
- Onde crio uma estrutura de dados não vazia chamada Data.
- Utilizo o método serialize() no endereço do objeto Data e passar seu valor de retorno para o método deserialize().
- Verifico se o valor retornado pelo método deserialize() é igual ao ponteiro original.

**Definição de entregue**
Além dos arquivos relacionados à implementação da classe Serializer, também é necessário entregar os arquivos relacionados à estrutura de dados Data.

Em resumo, neste exercício tem atingi o objetivo de aprender a lidar com a implementação de serialização e desserialização de ponteiros de objetos de uma determinada estrutura de dados, garantindo que os dados possam ser transmitidos e reconstruídos corretamente em diferentes contextos.
