Neste módulo do CPP00, implementamos 3 programas divididos em 3 exercícios:

#### Exerício 00: Megafone
Diretorio: _**ex00**_</br></br>
O objetivo e criar um programa que receba por argumento um texto, que ira realizar a conversão de cada caracter para maiúsculo e o imprima em tela separando por espaços.</br></br>
Este exercício sera o primeiro contato para lidar com o fluxos básicos de entrada/saída (E/S) em C++98, mecanismos fundamentais para interagir com entrada e saída de dados. Eles são implementados através dos objetos de fluxo da biblioteca padrão do C++. 
E com a função **std::toupper()** para converter caracteres individuais para maiúsculas.</br></br>

Existem três fluxos básicos de E/S em C++98:</br></br>
**1. Fluxo de entrada (istream):** </br>
Este fluxo é usado para ler dados de uma fonte externa para o programa. Normalmente, essa fonte externa é o teclado (entrada padrão), mas também pode ser um arquivo ou outro dispositivo de entrada.

**2. Fluxo de saída (ostream):** </br>
Este fluxo é usado para enviar dados do programa para uma saída externa. Normalmente, essa saída externa é a tela (saída padrão), mas também pode ser um arquivo ou outro dispositivo de saída.

**3. Fluxo de erro (cerr):** </br>
Este é um fluxo de saída especializado que é usado exclusivamente para enviar mensagens de erro para a saída padrão de erro. Ele é utilizado para exibir mensagens de erro no console, independentemente de qualquer redirecionamento de saída.</br>

Neste exercicio especificamente, _**lidamos com o fluxo básico de saída (ostream)**_ em C++98. Ele usa o objeto **std::cout** para enviar dados para a saída padrão, que geralmente é o console.

De forma geral, no programa **std::cout** é usado para enviar os caracteres convertidos para maiúsculas para a saída padrão e **std::endl** é usado para inserir uma nova linha na saída padrão, indicando o final de uma linha de texto.</br></br>

#### Exerício 01: Minha Lista Telefônica Incrível
Diretorio: _**ex01**_</br></br>
O objetivo e criar um programa que se comporte como um software de lista telefônica incrivel e de baixa qualidade que possua tratamento de erros. Para faze-lo, criamos duas classes, a classe Contact que que representa um contato na agenda telefônica e PhoneBook que gerencia uma lista de contatos.

O programa deve ter:
- [x] Tratamento de erros.
- [x] Os atributos da Classe Contact devem ser privados.
- [x] A classe deve ter os acessadores correspondentes expostos, ou seja, que os métodos de acesso como **"getters"** e **"setters"** disponíveis para acessar e modificar os membros privados da classe, que são acessíveis apenas dentro da própria classe e não podem ser acessados diretamente por objetos externos à classe. Quando os "acessadores correspondentes" são expostos, isso significa que para cada membro de dados privados (private) da classe, deve haver pelo menos dois métodos públicos **"getter"** e **"setter"**.</br> 
A exposição desses **"acessadores correspondentes"** permitem que outros objetos acessem e modifiquem os dados encapsulados (as propriedades privadas, os membros de dados privados de uma classe) da classe de maneira controlada e consistente, seguindo os princípios de encapsulamento e abstração de dados.
Ou seja, somente pelo **"acessadores correspondentes"**, "métodos de acesso", os métodos públicos controlados pela classe que podem interagir com esses dados que são protegidos pelo encapsulamento.
- [x] Devem garantir que métodos que somente são utilizados dentro da classe sejam privados, e os que são utilizados fora da classe sejam público.
- [x] A classe Contact deve ter atributos para cada contato.
- [x] A Classe PhoneBook deve ter uma matriz de contatos.
- [x] Deve conter um loop que lê as entradas e processa.
- [x] O loop deve ser feito em C++98 utilizansdo do _**std::cin**_, ou seja, no main ele sera utilizado para ler a entrada do usuário. O std::cin é o fluxo de entrada padrão.
- [x] Os comandos ADD, SEARCH e EXIT devem agir conforme subject.

