/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 06:12:00 by lucperei          #+#    #+#             */
/*   Updated: 2024/02/17 06:37:15 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ShrubberyCreationForm.hpp"

/* 
Construtor padrão, que inicializa um objeto ShrubberyCreationForm com um valor padrão 
para o atributo _target e chama o construtor da classe base AForm com os valores específicos 
para o formulário de criação.
*/
ShrubberyCreationForm::ShrubberyCreationForm(void)
	: AForm("ShrubberyCreationForm", 145, 137), _target("default") {}

/*
Construtor sobrecarregado que permite inicializar um objeto ShrubberyCreationForm com um valor 
específico para o atributo _target. Ele chama o construtor da classe base AForm com os valores 
específicos para o formulário de criação.
*/
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

/*
Construtor de cópia da classe ShrubberyCreationForm. Ele cria uma cópia de outro objeto 
ShrubberyCreationForm, copiando o valor do atributo _target e chamando o construtor de cópia 
da classe base AForm.
*/
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& form)
	: AForm("ShrubberyCreationForm", 145, 137), _target(form._target) {}

/*
Operador de atribuição da classe ShrubberyCreationForm. Ele permite atribuir o valor de outro 
objeto ShrubberyCreationForm a este objeto, copiando o valor do atributo _target e chamando o 
operador de atribuição da classe base AForm.
*/
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& form)
{
	AForm::operator=(form);
	return (*this);
}

/*
Destrutor da classe ShrubberyCreationForm. Ele é chamado quando um objeto ShrubberyCreationForm é 
destruído e libera quaisquer recursos alocados dinamicamente, mas neste caso, parece não haver 
alocação dinâmica.
*/
ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

/*
Método execute da classe ShrubberyCreationForm, que implementa a execução do formulário de criação. 
Ele recebe um objeto Bureaucrat como parâmetro, que representa quem está executando o formulário. 
O método verifica se o executor tem a classificação necessária para executar o formulário. Se o 
executor tiver uma classificação adequada, o método abre um arquivo e escreve uma representação de 
um arbusto em ASCII. Se a classificação do executor for muito baixa, uma exceção GradeTooLowException 
é lançada e tratada dentro do método. O método retorna true se a execução for bem-sucedida e false 
se o executor tiver uma classificação/nota muito baixa.
*/
bool	ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	try {
		if (executor.getGrade() > getGradeToExecute() || executor.getGrade() < 0)
			throw  AForm::GradeTooLowException();
		std::ofstream file((_target + "_shrubbery").c_str());
		file << "       ^" << std::endl;
		file << "      / \\" << std::endl;
		file << "     /   \\" << std::endl;
		file << "    /     \\" << std::endl;
		file << "   /       \\" << std::endl;
		file << "  /         \\" << std::endl;
		file << " /           \\" << std::endl;
		file << "/             \\" << std::endl;
		file << "     |" << std::endl;
		file.close();
	}
	catch (AForm::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
		return (false);
	}
	return (true);
}
