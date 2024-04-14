#include "../include/Harl.hpp"

/*
A classe Harl, que possui métodos para imprimir mensagens de log com diferentes níveis de gravidade: 
debug, info, warning e error. O programa fornece a capacidade de chamar um desses métodos com base em 
uma string que representa o nível de log desejado.
*/
Harl::Harl(void) {}

Harl::~Harl(void) {}
/*
Abaixo temos métodos para imprimir mensagens de log com diferentes níveis de gravidade, 
como debug, info, warning e error, que serão executados conforme validação.
*/
void	Harl::debug(void)
{
	std::cout << "[ " << "DEBUG" << " ]" << std::endl;
	std::cout << "I love having extra bacon for my ";
	std::cout << "7XL-double-cheese-triple-pickle-special-ketchup burger. ";
	std::cout << "I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[ " << "INFO" << " ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. ";
	std::cout << "You didn’t put enough bacon in my burger! If you did, ";
	std::cout << "I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[ " << "WARNING" << " ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. ";
	std::cout << "I’ve been coming for years whereas you started "; 
	std::cout << "working here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ " << "ERROR" << " ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::argNotValid(void)
{
	std::cerr << "You need to specify a valid log level for Harl! ";
	std::cerr << "Available options: DEBUG, INFO, WARNING, ERROR" << std::endl;
}

/*
 Recebe uma string representando o nível de log desejado.
*/
void	Harl::complain(std::string level)
{
	/*
 	Definido um array de ponteiros para os métodos da classe Harl que correspondem aos diferentes níveis de log.
 	*/
	void (Harl::*functions[5])() = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error,
		&Harl::argNotValid
	};
	// Definido um array de strings contendo os níveis de log válidos.
	std::string	validLevels[4] = {
		"debug",
		"info",
		"warning",
		"error"
	};
	int	index;

	index = 0;
	/*
 	Itera sobre o array de níveis de log válidos para encontrar o índice correspondente ao nível de 
  	log especificado na entrada.

	Chama o método correspondente ao nível de log encontrado, usando ponteiros para função e a sintaxe 
 	de ponteiro para membro (.*).

  	Se a string do nível de log não corresponder a nenhum dos níveis válidos, imprime uma mensagem de 
   	erro usando std::cerr  que conta na main.c.
 	*/
	while (index < 4 && validLevels[index].compare(level) != 0)
	{
		index++;
	}
	(this->*functions[index])();
	return ;
}
