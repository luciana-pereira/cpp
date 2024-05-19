#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <deque>
#include <list>
#include <string>
#include <stdexcept>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <ctime> 
#include <cstdlib>

// Definição da classe PmergeMe
class PmergeMe {
public:
    // Construtor padrão
    PmergeMe(void);
    // Destrutor
    ~PmergeMe(void);
    // Construtor de cópia
    PmergeMe(PmergeMe const &others);
    // Operador de atribuição
    PmergeMe& operator=(PmergeMe const &others);
    
    // Função para ordenar e imprimir uma sequência armazenada em um deque
    void    sortAndPrint(const std::deque<int>& sequence);
    // Função para ordenar e imprimir uma sequência armazenada em uma lista
    void    sortAndPrint(const std::list<int>& sequence);

private:
    // Função de classificação por mesclagem e inserção
    template<typename Container>
    void    mergeInsertSort(Container& container);

    // Função para imprimir o conteúdo de um contêiner com uma mensagem
    template<typename Container>
    void    printContainer(const std::string& message, const Container& container);

    // Função para medir o tempo de execução da ordenação de um contêiner
    template<typename Container>
    void    measureTimeAndSort(const std::string& containerName, Container& container);
    
    // Função para verificar se há duplicatas em um contêiner
    template<typename Container>
    bool hasDuplicates(const Container& container);
};

#endif
