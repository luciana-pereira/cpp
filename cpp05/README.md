<a href="" target="_blank">Potuguês **🇧🇷**</a> | <a href="./README_en.md" target="_blank">English **🇺🇸**</a>

# Modulo 05
Neste módulo do CPP05, implementamos 4 programas divididos em 4 exercícios:

#### Exerício 00:  Mommy, when I grow up, I want to be a bureaucrat!
Diretorio: _**ex00**_</br></br>
Esse exercício sera o primeiro que começaremos com o _**tratamento de exceções para lidar com tentativas de criar um Bureaucrat**_ com uma classificação inválida, seja muito alta ou muito baixa. Ou seja começamos implementando a classe Bureaucrat, que representa um funcionário em uma burocracia fictícia. Esta classe possui um nome constante e uma classificação (grade) que varia de 1 (mais alta) a 150 (mais baixa).  

Além disso, forneceremos métodos para obter o nome e a classificação do burocrata (getName() e getGrade()) e implementar funções membro para incrementar ou decrementar a classificação. Se a classificação estiver fora do intervalo válido, essas funções devem lançar as mesmas exceções mencionadas anteriormente.

Devemos tambem implementar a sobrecarregar o operador de inserção (<<) para imprimir o nome e a classificação do burocrata em um formato específico. 

#### Exerício 01:  Mommy, when I grow up, I want to be a bureaucrat!
Diretorio: _**ex01**_</br></br>
Neste exercício implementaremos a classe Form, que representa um formulário a ser preenchido e assinado pelos burocratas. A classe Form possui os seguintes atributos privados:
- Um nome constante.
- Um booleano indicando se o formulário está assinado (inicialmente não está).
- Uma nota constante requerida para assinar o formulário.
- Uma nota constante requerida para executar o formulário.
  
A classe Form também deve lançar exceções GradeTooHighException e GradeTooLowException se a nota do formulário estiver fora dos limites permitidos, seguindo as mesmas regras aplicadas à classe Bureaucrat.

Além disso, a classe Form deve ter os seguintes métodos:

- Métodos getters para todos os atributos.
- Um _**método beSigned()**_, que recebe um burocrata como parâmetro e muda o status do formulário para assinado se a nota do burocrata for alta o suficiente. Se a nota for muito baixa, lança uma exceção GradeTooLowException.
- Um _**método signForm()**_ na classe Bureaucrat, que imprime uma mensagem indicando se o formulário foi assinado com sucesso ou não

#### Exerício 02:  No, you need form 28B, not 28C...
Diretorio: _**ex02**_</br></br>
Neste exercício expandi o sistema de formulários já existente, adicionando formulários concretos que realizam ações específicas quando executados. Os principais pontos da implementação deste exercício são:

1. **Renomear a classe base:**
 - A classe base Form deve ser renomeada para AForm e ser uma classe abstrata.
2. **Adicionar formulários concretos:**
 - Adicionar três novas classes concretas de formulários: **ShrubberyCreationForm**, **RobotomyRequestForm** e **PresidentialPardonForm**.
 - Cada classe deve ter atributos privados que representam os requisitos de grau para assinar e executar o formulário, bem como o alvo do formulário.
 - Cada formulário deve ter uma função para executar sua ação específica.
3. **Implementar a execução do formulário:**
 - Adicionar uma função execute(Bureaucrat const & executor) const à classe base AForm para executar a ação do formulário.
 - Verificar se o formulário foi assinado e se o burocrata que tenta executá-lo possui um grau suficientemente alto.
 - Decidir se os requisitos devem ser verificados em cada classe concreta ou na classe base.
4. **Adicionar função de execução ao Bureaucrat:**
 - Adicionar uma função **executeForm(AForm const & form)** ao **Bureaucrat** para tentar executar o formulário.
 - Se a execução for bem-sucedida, imprimir uma mensagem indicando isso; caso contrário, imprimir uma mensagem de erro explícita.

O objetivo final é garantir que os formulários possam ser corretamente assinados, executados e que as ações correspondentes sejam realizadas conforme especificado para cada tipo de formulário.

#### Exerício 03:   At least this beats coffee-making
Diretorio: _**ex03**_</br></br>
Neste exercício
   
