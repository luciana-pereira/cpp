<a href="" target="_blank">Potuguês **🇧🇷**</a> | <a href="./README_en.md" target="_blank">English **🇺🇸**</a>

Neste módulo do CPP01, implementamos 7 programas divididos em 7 exercícios:

#### Exerício 00: BraiiiiiiinnnzzzZ
Diretorio: _**ex00**_</br></br>
O objetivo e criar um programa é demostrar atraves dele o uso das classes em c++98, para representar Zombies, além da capacidade de criar Zombies de duas maneiras diferentes:
1. Atraves de **alocação dinâmica de memória (heap)**, usando a _**função newZombie**_.
2. Atraves da **alocação automática de memória (stack)** usando a _**função randomChump**_.</br>

Além disso, o programa ilustra o uso de destrutores para imprimir mensagens quando os zombies são destruidos.

Ou seja, os **métodos da classe Zombie (Zombie.cpp)**, incluindo o construtor, o destruidor e o método announce, que são responsáveis por criar, destruir e anunciar um zumbi, respectivamente. A **função newZombie (newZombie.cpp)** é responsável por _**criar dinamicamente um novo objeto da classe Zombie**_, utilizando o _**operador new**_, com o nome especificado e retornar um ponteiro para esse objeto. A **função randomChump (randomChump.cpp)** é responsável por _**cria um objeto Zombie localmente na pilha de execução**_, inicializado com o nome fornecido como parâmetro, e então chama o método announce() desse objeto para que o zombie anuncie sua presença.

De forma geral, teremos que criar zombie, e definir em que caso é melhor alocar os zombies na heap ou stack e destruir os zombies quando não precisar mais deles, mas o objetivo principal e a definição da alocação.

#### Exerício 01: Moar brainz!
Diretorio: _**ex01**_</br></br>
O objetivo deste programa é criar uma "horda" de zumbis, alocando memoria para vários objetos Zombie, inicializando-os com um nome especifico e em seguida, chamando a função announce() para cada zumbi. O programa termina após a limpeza da memória e cada zumbi anuncia seu nome.

De forma geral a essa **classe Zombie (Zombie.cpp)** permite criar objetos que representam zombies com nomes específicos, e também fornece métodos para que esses zombies anunciem-se e informa quando eles são destruídos. A **função zombieHorde (zombieHorde.cpp)** cria dinamicamente um número especificado de objetos Zombie, cada um com o mesmo nome, e retorna um ponteiro para o primeiro elemento do array criado.

#### Exerício 02: Hi this is brain!
Diretorio: _**ex02**_</br></br>
O objetivo deste programa é demonstrar o conceito de ponteiros e referências em c++98, mostrando como eles se relacionam com variáveis e como acessar valores e endereços de memória. Ou seja, lidar com ponteiros e refencias e a sintaxe.

O programa sera capaz de imprimir os endereços de memória e os valores de uma variável std::string, um ponteiro para essa variável e uma referência para ela.

#### Exerício 03: Unnecessary violence
Diretorio: _**ex03**_</br></br>
O objetivo deste programa é implementar duas classes, HumanA e HumanB, que possuem um membro do tipo Weapon (arma) e um nome. Ambas as classes têm uma função de membro attack() que exibe uma mensagem indicando que o humano está atacando com sua arma.

A classe Weapon possui um atributo privado do tipo string para armazenar o tipo de arma e métodos para obter e definir o tipo da arma.

A diferença entre HumanA e HumanB está na forma como eles lidam com a arma:
- HumanA recebe a arma no construtor e sempre estará armado.
- HumanB não recebe a arma no construtor e pode ou não ter uma arma.

Para verificar a implementação, o código fornecido executa dois casos de teste:
1. Cria um objeto HumanA chamado Bob, que é inicializado com uma arma e ataca duas vezes.
2. Cria um objeto HumanB chamado Jim, que é inicializado sem arma, mas depois recebe uma arma e ataca duas vezes.

Para evitar vazamentos de memória, é necessário garantir que os recursos alocados dinamicamente sejam liberados adequadamente.

Quanto à escolha entre ponteiro e referência para a Weapon:
- Usar um ponteiro para Weapon seria mais adequado para HumanB, pois ele pode não ter uma arma. O ponteiro poderia ser inicializado como nulo e, se uma arma fosse atribuída a ele posteriormente, poderia ser verificado se ele é diferente de nulo antes de usar a arma.
- Usar uma referência para Weapon seria mais adequado para HumanA, pois ele sempre terá uma arma e não precisará lidar com casos de nulidade. Além disso, usar uma referência tornaria o código mais simples e mais seguro, pois não precisaria verificar a nulidade do ponteiro.

De forma geral, estamos utilizando os conceitos aprendidos da ex02 e aplicando. neste exercício, como os ponteiros e refências

#### Exerício 04: Sed is for losers
Diretorio: _**ex04**_</br></br>
O objetivo deste programa e realizar a substituição de letras ou texto de acordo com argumento passado para ser substituido no arquivo indicado como argumento.

A implementação precisa ser realizada idealmente para que utilizemos _**ifstream**_ ou equivalente para realizar a leitura do arquivo e _**ofstream**_ ou equivalente para gravar no novo arquivo com a substituição.

#### Exerício 05: Harl 2.0
Diretorio: _**ex05**_</br></br>
O objetivo deste programa e implementer a a classe Harl, com métodos para imprimir mensagens de log com diferentes níveis de gravidade: debug, info, warning e error. O programa fornece a capacidade de chamar um desses métodos com base em uma string que representa o nível de log desejado que e passado como argumento.

#### Exerício 06: Harl 2.0
Diretorio: _**ex06**_</br></br>
O objetivo deste programa e identico ao execício ex05, porem ele toma como parâmetro um dos qautro níveis debug, info, warning e error e exibir as mensagens porem devera utilizar um filtro em switch case.
