/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 19:21:54 by lucperei          #+#    #+#             */
/*   Updated: 2024/05/12 18:25:24 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Intern.hpp"

// Construtor padrão da classe Intern
Intern::Intern(void) {}

/*
Construtor de cópia da classe Intern. No entanto, ele não realiza nenhuma operação significativa além 
de aceitar um objeto Intern como parâmetro e descartá-lo imediatamente usando (void)obj;. Isso impede 
que o compilador gere um aviso de "variável não utilizada" quando você cria um objeto Intern usando o 
construtor de cópia.
*/
Intern::Intern(Intern &obj)
{
	(void)obj;
}

/*
Operador de atribuição da classe Intern. Novamente, ele não realiza nenhuma operação significativa 
além de aceitar um objeto Intern como parâmetro, descartá-lo imediatamente usando (void)obj; e 
retornar uma referência para o próprio objeto. Isso significa que o operador de atribuição não faz 
nada de útil em termos de atribuir valores de um objeto Intern para outro
*/
Intern&	Intern::operator=(Intern &obj)
{
	(void)obj;
	return (*this);
}

/*
Destrutor da classe Intern. Ele não realiza nenhuma operação específica além de ser definido. 
Isso significa que quando um objeto Intern é destruído, não há liberação de recursos específicos 
realizados pelo destrutor.
*/
Intern::~Intern() {}

// Implementações de funções para criar formulários
AForm* createPresidentialPardonForm(const std::string& target)
{
	return new PresidentialPardonForm(target);
}

AForm* createRobotomyRequestForm(const std::string& target)
{
	return new RobotomyRequestForm(target);
}

AForm* createShrubberyCreationForm(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}

/*
Método makeForm da classe Intern. Ele recebe dois parâmetros: formName, que é uma string 
representando o nome do formulário a ser criado, e target, que é uma string representando o alvo do 
formulário a ser criado. O método retorna um ponteiro para um objeto AForm
*/
AForm*	Intern::makeForm(const std::string& formName, const std::string& target)
{
	// Cria um ponteiro form
	AForm* form = NULL;

	/*
 	Lista de informações de criação de formulário estatico com ponteiro para uma função que 
	cria o respectivo formulário.
	*/
	static const FormCreationInfo formCreationInfo[] = {
		{"presidential pardon", createPresidentialPardonForm},
		{"robotomy request", createRobotomyRequestForm},
		{"shrubbery creation", createShrubberyCreationForm}
	};
	
	// Loop sobre a lista de informações de criação de formulário
	for (size_t i = 0; i < 3; ++i) 
	{
		// Verifique se o nome do formulário corresponde
		if (formName == formCreationInfo[i].formName)
		{
			std::cout << "Intern creates " << formName << std::endl;
			// Chame a função de criação apropriada
			form = formCreationInfo[i].createForm(target);
			break ;
		}
	}
	std::cout << "Error: Form " << formName << " does not exist." << std::endl;
	
	return (form);
}
