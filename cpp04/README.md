<a href="" target="_blank">Potuguês **🇧🇷**</a> | <a href="./README_en.md" target="_blank">English **🇺🇸**</a>

# Modulo 04
Neste módulo do CPP02, implementamos 4 programas divididos em 4 exercícios:

#### Exerício 00: Polymorphism
Diretorio: _**ex00**_</br></br>
Esse exercício sera o primeiro que iremos começar a praticar o conceito de polimorfismo em C++98, criando uma hierarquia de classes relacionadas e demonstrando como o comportamento pode variar com base no tipo real do objeto em tempo de execução. Ou seja, no _**polimorfismo de subtipo permite que objetos de classes derivadas sejam tratados como objetos de classes base durante a execução do programa**_. Isso significa que, se uma classe derivada sobrescrever um método (função) de sua classe base com virtual, o método da classe derivada será chamado quando uma instância da classe derivada for acessada através de um ponteiro ou referência à classe base.

- **Classe Base Animal:**
  - A classe base **Animal** tem um atributo protegido chamado **type**, que armazena o tipo do animal.
  - Ela possui um _**método virtual puro**_, o que quer dizer que esté metodo pode ser sobrescrito pelo método da classe derivada para produzir o próprio som proprio de Cat e Dog, o método se chama **makeSound()**, e ele será implementado por cada uma das pelas classes derivadas.
- **Classe Dog e Cat:**
  - **Dog** e **Cat** herdam de **Animal**.
  -  No construtor de cada classe, o atributo type é inicializado com "Dog" para Dog e "Cat" para Cat.
  - Cada classe deve implementar o método makeSound() para produzir o som apropriado para o animal.
- **Testes**:
  - O teste principal no main() cria instâncias de Animal, Dog e Cat e chama makeSound() para cada um.
  - O objetivo é garantir que cada classe produza o som esperado e que o polimorfismo (a sobreencrição do metodo) funcione corretamente.
- **Classe WrongCat e WrongAnimal**:
  - Uma vez entendido o conceito de polimorfismo, é proposto um desafio adicional com as classes WrongCat e WrongAnimal.
  - WrongCat herda de WrongAnimal.
  - O objetivo é observar que, se as classes base e derivada não estiverem corretamente relacionadas na hierarquia de herança, o polimorfismo não funcionará como esperado.

#### Exerício 01: I don’t want to set the world on fire
Diretorio: _**ex01**_</br></br>
Neste exercício iremos praticar os conceitos de herança, alocação dinâmica de memória (objeto Brain), construtores, destrutores e cópia profunda em C++98.

Nela implementamos:
- [x] Uma classe chamada Brain que contenha um array de 100 strings chamado ideas.
- [x] As classes Dog e Cat, que devem ter um atributo privado do tipo Brain*.
- [x] No construtor de Dog e Cat, criar um objeto Brain utilizando new.
- [x] No destrutor de Dog e Cat, deletar o objeto Brain utilizando delete.
- [x] Criar um programa principal (main) onde você cria e preenche um array de objetos Animal, sendo metade deles objetos Dog e a outra metade objetos Cat.
- [x] No final do programa, iterar sobre o array de Animal e deletar cada objeto. Isso deve chamar os destrutores corretamente na ordem esperada.
- [ ] Garantir que as cópias de objetos Dog ou Cat não sejam rasas, ou seja, garantir que uma cópia de Dog ou Cat, incluIR uma cópia independente de todos os recursos dinamicamente alocados (como Brain), precisamos implementar corretamente o construtor de cópia ("copy constructor") e o operador de atribuição(operator=).

**Garanta que não haja vazamento de memória verificando por possíveis memory leaks.

#### Exerício 02: Abstract class
Diretorio: _**ex02**_</br></br>
Neste exercício _**transformamos a classe Animal em uma classe abstrata**_, ou seja, uma classe que não pode ser instanciada diretamente(intanciamos geralmente no main), mas pode ser _**usada como base para outras classes derivadas**_. Isso é feito adicionando um método virtual puro à classe Animal, o que a torna abstrata.

Ou seja, ao fazer isso, garantimos que ninguém poderá criar instâncias da classe Animal diretamente, mas ainda poderemos herdar dela para criar outras classes, como Dog e Cat, que continuarão a funcionar como antes.

Para indicar que a classe Animal e abstrata renomos adicionando um  um prefixo "A". Isso é uma prática comum para tornar mais claro que a classe não pode ser instanciada diretamente.

#### Exerício 03: Interface & recap
Diretorio: _**ex03**_</br></br>
Neste exercício além de trabalharmos com classes abstratas lidaremos também com interfaces em C++98. Onde criaremos três classes principais:

1. **AMateria:** Uma classe abstrata que representa um tipo genérico de material (materia). Ela possui uma função virtual pura clone() para criar uma cópia do material e uma função virtual use(ICharacter& target) para usar o material em um personagem.

2. **Ice e Cure:** Implementações concretas da classe AMateria, representando tipos específicos de materiais. Elas implementam as funções virtuais puras clone() e use(ICharacter& target) de acordo com as descrições dadas no exercício.

3. **Character:** Uma classe que implementa a interface ICharacter, que representa um personagem no jogo. O personagem possui um inventário de até 4 slots de materiais, onde ele pode equipar diferentes tipos de materiais. Ele também pode usar e desequipar materiais de seu inventário.

4. **MateriaSource:** Uma classe que implementa a interface IMateriaSource, que permite que personagens aprendam e criem novos materiais. Ela possui uma função para aprender um novo material (learnMateria) e uma função para criar um material específico com base em seu tipo (createMateria).

No final o programa principal usara essas classes para criar personagens, equipá-los com materiais, usá-los e desequipá-los, demonstrando assim o funcionamento correto das classes implementadas.
