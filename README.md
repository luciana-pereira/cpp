<a href="" target="_blank">Potuguês **🇧🇷**</a> | <a href="./README_en.md" target="_blank">English **🇺🇸**</a>

# CPP

O CPP e constituido por módulos, listas de exercicios que vão do módulo 00 ao módulo 09 sobre conceitos clássicos de Programação Orientada a Objetos (POO).

- #### [Modulo 00](https://github.com/luciana-pereira/cpp/tree/master/cpp00)
Os exercicios do módulo 00 contem a implementação de Namespaces, classes, funções de membro, fluxos stdio, listas de inicialização, static, const e alguns outros itens básicos, clique no modulo para saber mais.

- #### [Modulo 01](https://github.com/luciana-pereira/cpp/tree/master/cpp01)
Os exercicios do módulo 01 contem a implementação de programas que lidam com:

**Alocação de memoria (dinâmica e automatica):**</br>
A alocação de memória pode ser classificada em duas categorias principais:

 **) Alocação Automática (ou Armazenamento Automático):** </br>
 São variáveis locais em C++, geralmente são alocadas automaticamente na pilha de execução do programa. Quando uma função é chamada, suas variáveis locais são criadas e alocadas na pilha. Essas variáveis são automaticamente desalocadas quando a função retorna.
Exemplo:
```
void foo() {
    int x = 10; // Alocado automaticamente na pilha
    // ...
}
```
ponteiros para membros, referências, instrução switch, clique no modulo para saber mais.

- #### [Modulo 02](https://github.com/luciana-pereira/cpp/tree/master/cpp02)
Os exercicios do módulo 01 contem a implementação de programas que lidam com:</br>
**1. Polimorfismo ad-hoc**:
Também conhecido como sobrecarga de funções ou operadores, que é uma forma de polimorfismo em que uma função ou operador tem diferentes implementações dependendo dos tipos de argumentos ou operandos que são passados a ela. Em C++98, a sobrecarga de funções e operadores é uma das formas mais comuns de polimorfismo ad-hoc.
Na sobrecarga de funções, podemos ter várias funções com o mesmo nome, mas com diferentes listas de parâmetros. Quando chamamos essa função, o compilador determina qual versão da função deve ser chamada com base nos tipos dos argumentos passados. 

**2. Sobrecarga de Operador**: 

**3. Forma de classe canônica ortodoxa**:

- #### [Modulo 03](https://github.com/luciana-pereira/cpp/tree/master/cpp03)
Os exercicios do _**módulo 03 da versão 7**_ contem a implementação de programas que lidam com herança (inheritance), que é um conceito fundamental que permite que uma classe (conhecida como classe derivada ou subclasse) herde atributos e métodos de outra classe (conhecida como classe base ou superclasse). Isso significa que a classe derivada pode acessar e utilizar os membros da classe base, além de adicionar novos membros próprios ou substituir os membros herdados.

Existem três tipos principais de herança em C++:

1. **Herança Pública (public inheritance):** Nesse tipo de herança, os membros públicos e protegidos da classe base tornam-se membros públicos e protegidos da classe derivada, respectivamente. Os membros privados da classe base não são herdados. A herança pública é a forma mais comum de herança e é usada para estabelecer uma relação "é um" entre a classe derivada e a classe base.

2. **Herança Protegida (protected inheritance):** Nesse tipo de herança, os membros públicos e protegidos da classe base tornam-se membros protegidos da classe derivada. Os membros privados da classe base não são herdados. A herança protegida é menos comum e é usada principalmente para restringir o acesso aos membros da classe base na classe derivada e suas subclasses.

3. **Herança Privada (private inheritance):** Nesse tipo de herança, os membros públicos e protegidos da classe base tornam-se membros privados da classe derivada. Os membros privados da classe base não são herdados. A herança privada é usada quando a classe derivada precisa acessar os membros da classe base, mas não deve expor essa relação de herança para o mundo externo.

De forma geral, herança em C++98 permite a reutilização de código, promova a modularidade e facilite a criação de hierarquias de classes, onde classes mais especializadas (derivadas) podem estender o comportamento de classes mais genéricas (base).

- #### Modulo 04
- #### Modulo 05
- #### Modulo 06
- #### Modulo 07
- #### Modulo 08
- #### Modulo 09

Referência: [Documentação C++](https://cplusplus.com/)
