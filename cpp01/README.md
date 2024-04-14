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








