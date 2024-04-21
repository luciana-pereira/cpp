<a href="" target="_blank">Potuguês **🇧🇷**</a> | <a href="./README_en.md" target="_blank">English **🇺🇸**</a>

# Modulo 03
Neste módulo do CPP02, implementamos 4 programas divididos em 4 exercícios:

#### Exerício 00: Aaaaand OPEN!
Diretorio: _**ex00**_</br></br>
Esse exercício serve para nos familiarizar conceitos básicos de orientação a objetos, como encapsulamento, construtores, métodos e mensagens de saída.
De forma geral  implementaremos uma classe chamada ClapTrap, que representa um robô, com atributos privados como nome, pontos de vida, pontos de energia e dano de ataque. Além disso, a classe deve ter métodos públicos para realizar ações como atacar um alvo, receber dano e ser reparado.

#### Exerício 01: Serena, my love!
Diretorio: _**ex01**_</br></br>
Esse exercício serve é para praticar conceitos de herança em programação orientada a objetos, utilizando C++98. Ele propõe a criação de uma classe derivada chamada ScavTrap, que herda da classe base ClapTrap. A classe ScavTrap terá seus próprios construtores, destrutores e uma função attack() com mensagens diferentes da classe base(ClapTrap).

Além disso, o exercício pede para inicializar os atributos específicos do ScavTrap, como o nome, pontos de vida, pontos de energia e dano de ataque, e adicionar uma nova função membro chamada guardGate() que exibe uma mensagem informando que o ScavTrap está no modo de guardião do portão.

É mencionado que a correta cadeia de construção/destruição deve ser demonstrada nos testes, e sugere-se adicionar mais testes ao programa para garantir o funcionamento adequado da classe derivada ScavTrap.

#### Exerício 02: Repetitive work
Diretorio: _**ex02**_</br></br>
Esse exercício é continuar a prática de herança em C++98, porém desta vez criando uma _**classe chamada FragTrap**_ que também herda da _**classe base ClapTrap**_. Assim como no exercício anterior com ScavTrap, o FragTrap terá seus próprios construtores, destrutores e uma função membro chamada attack() com mensagens diferentes da classe base.

Os construtores e destrutores devem imprimir mensagens específicas para o FragTrap, e a cadeia de construção/destruição adequada deve ser demonstrada nos testes.

Além disso, o FragTrap terá atributos específicos inicializados com valores diferentes dos do ScavTrap, incluindo um aumento no dano de ataque para 30 pontos.

Por fim, o FragTrap também terá sua própria função membro chamada highFivesGuys(), que exibirá uma mensagem solicitando um "high five" no padrão de saída. Mais testes devem ser adicionados para garantir o correto funcionamento da classe FragTrap
