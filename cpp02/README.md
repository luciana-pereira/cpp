<a href="" target="_blank">Potuguês **🇧🇷**</a> | <a href="./README_en.md" target="_blank">English **🇺🇸**</a>

# Modulo 02
Neste módulo do CPP02, implementamos 4 programas divididos em 4 exercícios:

#### Exerício 00: My First Class in Orthodox Canonical Form
Diretorio: _**ex00**_</br></br>
Esse exercício serve para nos familiarizar com a implementação de uma classe em C++98, na forma canônica ortodoxa (Orthodox Canonical Form), essa forma envolve seguir certas práticas de codificação, que são consideradas boas práticas. A ideia por trás da forma canônica ortodoxa é promover a consistência, legibilidade e facilidade de uso das classes. </br>

Em termos práticos, a forma canônica ortodoxa inclui:
1. **Construtor padrão (default constructor):** Um construtor que pode ser chamado sem argumentos e inicializa os membros da classe a valores padrão.
2. **Construtor de cópia (copy constructor):** Um construtor que cria um novo objeto copiando os valores de outro objeto da mesma classe.
3. **Operador de atribuição (assignment operator):** Um operador que permite atribuir valores de um objeto a outro objeto da mesma classe.
4. **Destrutor:** Um método especial que é chamado quando um objeto é destruído, geralmente usado para liberar recursos alocados dinamicamente.
5. **Métodos de acesso:** Métodos públicos que permitem acessar e modificar os membros privados da classe de forma controlada.

Ou seja, a classe deve ser criada seguindo a forma canônica ortodoxa (Orthodox Canonical Form), que represente um tipo de número fixo (fixed-point number) e deve incluir membros privados para armazenar o valor do número fixo e o número de bits fracionários, além de membros públicos para construtores, destrutores, operador de atribuição, operador de cópia e funções para acessar e definir o valor bruto do número fixo. Este tipo de número é útil em diversas áreas, como gráficos de computador, processamento de som e programação científica, devido ao seu equilíbrio entre desempenho, precisão, intervalo e precisão.

#### Exerício 01: Towards a more useful fixed-point number class
Diretorio: _**ex01**_</br></br>
Esse exercício ira expandir a classe Fixed para que ela possa representar valores de ponto fixo mais úteis e permitir operações básicas com esses valores, como conversões para e de números flutuantes, inicialização a partir de inteiros e números de ponto flutuante, e sobrecarga do operador de inserção (<<) para permitir a impressão dos valores de ponto fixo.

Porem para isso precisamos realizar a implementação dos seguintes recursos na classe Fixed:
1. **Construtores** que inicializam um objeto Fixed com valores inteiros ou de ponto flutuante.
2. **Funções membro toFloat() e toInt()** que convertem o valor de ponto fixo para um número flutuante ou inteiro, respectivamente.
3. **Sobrecarga do operador <<** para permitir a impressão dos valores de ponto fixo em uma std::ostream.

#### Exerício 02: Now we´re talking
Diretorio: _**ex02**_</br></br>
Esse exercício ira expandir a funcionalidade da classe Fixed, adicionando sobrecargas de operadores e funções para realizar operações matemáticas, comparações e manipulações com números de ponto fixo. 

As principais tarefas a serem realizadas são:

1. Sobrecarregar os operadores de comparação: >, <, >=, <=, == e !=.
2. Sobrecarregar os operadores aritméticos: +, -, * e /.
3. Sobrecarregar os operadores de incremento e decremento: ++ e --.
4. Implementar as funções membro estáticas min e max para encontrar o mínimo e o máximo entre dois números de ponto fixo.

Ou seja, criara objetos Fixed, realiza operações matemáticas e comparações, e imprime os resultados na saída padrão. O main verificara se a implementação dos operadores e funções está correta e se a classe Fixed funciona conforme o esperado.

#### Exerício 03: 
Diretorio: _**ex03**_</br></br>
O objetivo deste programa é implementar e verificar se determinado ponto (Point) está dentro de um triângulo utilizando o conceito de particionamento binário de espaço (BSP - Binary Space Partitioning). A implementação desta funcionalidade esta na **função bsp** que determina se um ponto está dentro de um triângulo com o (BSP). De forma geral, se trata da implementação de algoritmos geométricos simples e o uso da classe Fixed para manipulação de números fixos, que são essenciais em muitas aplicações gráficas e de jogos.

**Entrada:** A = (0, 0), B = (10, 30), C = (20, 0), P(10, 15)</br>
**Saída:** Dentro</br>
**Explicação:**
```
             B(10,30)
                / \
               /   \
              /     \
             /   P   \      P'
            /         \
     A(0,0) ----------- C(20,0) 
```

**Entrada:** A = (0, 0), B = (10, 30), C = (20, 0), P(30, 15)</br>
**Saída:** Fora</br>
**Explicação:**
```
             B(10,30)
                / \
               /   \
              /     \
             /   P   \      P'
            /         \
     A(0,0) ----------- C(20,0) 
```

**Solução:** As coordenadas dos três cantos (x1, y1), (x2, y2) e (x3, y3). E as coordenadas do ponto dado P são (x, y).
Calcule a área do triângulo fornecido, ou seja, a área do triângulo ABC no diagrama acima.</br>

Área **A = [ x1(y2 – y3) + x2(y3 – y1) + x3(y1-y2) ] / 2**

Devemos calcular a área do triângulo **PAB**, podemos usar a mesma fórmula acima para isso e determinar a área como **A1**.</br>
Calcular a área do triângulo **PBC**, e determinar a área como **A2**.</br>
Calcular a área do triângulo **PAC**, e determinar a área como **A3**.</br>
Se **P** estiver dentro do triângulo, então **A1 + A2 + A3** deve ser igual a **A**.</br>

O exercício também inclui a implementação da classe Point para representar um ponto 2D usando a classe Fixed fornecida.

Aqui está uma visão geral do que precisou ser realizado:
1. Implementar a classe Point em conformidade com a forma canônica ortodoxa, o que inclui atributos privados para as coordenadas x e y, construtores, operadores de cópia e de atribuição, e um destrutor.
2. Implementar a função bool bsp(Point const a, Point const b, Point const c, Point const point) que verifica se um ponto point está dentro do triângulo formado pelos pontos a, b e c. Se o ponto estiver dentro do triângulo, a função retorna true; caso contrário, retorna false.
3. Criar testes para garantir que a classe Point e a função bsp estejam implementadas corretamente e que o comportamento esperado seja observado.
