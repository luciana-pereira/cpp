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

De forma geral, no programa **std::cout** é usado para enviar os caracteres convertidos para maiúsculas para a saída padrão e **std::endl** é usado para inserir uma nova linha na saída padrão, indicando o final de uma linha de texto.
