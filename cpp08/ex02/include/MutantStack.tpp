template<typename T>
MutantStack<T>::MutantStack(void) : std::stack<T>() { } // Construtor padrão da classe MutantStack que chama o construtor padrão da classe base std::stack<T>

template<typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &other) : // Construtor de cópia da classe MutantStack que recebe outra instância de MutantStack como parâmetro
	std::stack<T>() { *this = other; } // Chama o construtor padrão da classe base std::stack<T> e, em seguida, realiza a cópia profunda da outra instância de MutantStack

template<typename T>
MutantStack<T>::~MutantStack(void) { } // Destrutor da classe MutantStack, não realiza nenhuma operação específica

template<typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &other) // Sobrecarga do operador de atribuição da classe MutantStack
{
	if (this != &other) // Verifica se a instância atual é diferente da instância passada como parâmetro
		std::stack<T>::operator=(other); // Chama o operador de atribuição da classe base std::stack<T>
	return (*this); // Retorna a referência para a instância atual
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin(void) // Retorna um iterador para o início da pilha
{
	return (this->c.begin()); // Retorna um iterador para o início da sequência interna da pilha
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end(void) // Retorna um iterador para o final da pilha
{
	return (this->c.end()); // Retorna um iterador para o final da sequência interna da pilha
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::cbegin(void) const // Retorna um iterador constante para o início da pilha
{
	return (this->c.begin()); // Retorna um iterador constante para o início da sequência interna da pilha
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::cend(void) const // Retorna um iterador constante para o final da pilha
{
	return (this->c.end()); // Retorna um iterador constante para o final da sequência interna da pilha
}

template<typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin(void) // Retorna um iterador reverso para o início da pilha
{
	return (this->c.rbegin()); // Retorna um iterador reverso para o início da sequência interna da pilha
}

template<typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend(void) // Retorna um iterador reverso para o final da pilha
{
	return (this->c.rend()); // Retorna um iterador reverso para o final da sequência interna da pilha
}

template<typename T>
typename MutantStack<T>::const_reverse_iterator
	MutantStack<T>::crbegin(void) const // Retorna um iterador reverso constante para o início da pilha
{
	return (this->c.rbegin()); // Retorna um iterador reverso constante para o início da sequência interna da pilha
}

template<typename T>
typename MutantStack<T>::const_reverse_iterator
	MutantStack<T>::crend(void) const // Retorna um iterador reverso constante para o final da pilha
{
	return (this->c.rend()); // Retorna um iterador reverso constante para o final da sequência interna da pilha
}
