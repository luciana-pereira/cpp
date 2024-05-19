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

// Defini��o da classe PmergeMe
class PmergeMe {
public:
    // Construtor padr�o
    PmergeMe(void);
    // Destrutor
    ~PmergeMe(void);
    // Construtor de c�pia
    PmergeMe(PmergeMe const &others);
    // Operador de atribui��o
    PmergeMe& operator=(PmergeMe const &others);
    
    // Fun��o para ordenar e imprimir uma sequ�ncia armazenada em um deque
    void    sortAndPrint(const std::deque<int>& sequence);
    // Fun��o para ordenar e imprimir uma sequ�ncia armazenada em uma lista
    void    sortAndPrint(const std::list<int>& sequence);

private:
    // Fun��o de classifica��o por mesclagem e inser��o
    template<typename Container>
    void    mergeInsertSort(Container& container);

    // Fun��o para imprimir o conte�do de um cont�iner com uma mensagem
    template<typename Container>
    void    printContainer(const std::string& message, const Container& container);

    // Fun��o para medir o tempo de execu��o da ordena��o de um cont�iner
    template<typename Container>
    void    measureTimeAndSort(const std::string& containerName, Container& container);
    
    // Fun��o para verificar se h� duplicatas em um cont�iner
    template<typename Container>
    bool hasDuplicates(const Container& container);
};

#endif
