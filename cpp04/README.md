<a href="" target="_blank">Potuguês **🇧🇷**</a> | <a href="./README_en.md" target="_blank">English **🇺🇸**</a>

# Modulo 04
Neste módulo do CPP02, implementamos 4 programas divididos em 4 exercícios:

#### Exerício 00: Polymorphism
Diretorio: _**ex00**_</br></br>
Esse exercício sera o primeiro que iremos começar a praticar o conceito de polimorfismo em C++98, criando uma hierarquia de classes relacionadas e demonstrando como o comportamento pode variar com base no tipo real do objeto em tempo de execução.

- **Classe Base Animal:**
  - A classe base **Animal** tem um atributo protegido chamado **type**, que armazena o tipo do animal.
  - Ela possui um _**método virtual puro**_, o que quer dizer que esté metodo pode ser sobrescrito pelo método da classe derivada para produzir o próprio som proprio de Cat e Dog, o método se chama **makeSound()**, e ele será implementado por cada uma das pelas classes derivadas.
- **Classe Dog e Cat:**
  - **Dog** e **Cat** herdam de **Animal**.
  -  No construtor de cada classe, o atributo type é inicializado com "Dog" para Dog e "Cat" para Cat.
  - Cada classe deve implementar o método makeSound() para produzir o som apropriado para o animal.
- **Testes**:
  - O teste principal no main() cria instâncias de Animal, Dog e Cat e chama makeSound() para cada um.
  - O objetivo é garantir que cada classe produza o som esperado e que o polimorfismo funcione corretamente.
- **Classe WrongCat e WrongAnimal**:
  - Uma vez entendido o conceito de polimorfismo, é proposto um desafio adicional com as classes WrongCat e WrongAnimal.
  - WrongCat herda de WrongAnimal.
  - O objetivo é observar que, se as classes base e derivada não estiverem corretamente relacionadas na hierarquia de herança, o polimorfismo não funcionará como esperado.
