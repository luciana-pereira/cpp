#include "../include/Harl.hpp"

Harl::Harl(void) {
}

Harl::~Harl(void) {
}

void	Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my ";
	std::cout << "7XL-double-cheese-triple-pickle-special-ketchup burger. ";
	std::cout << "I really do!" << std::endl;
	std::cout << std::endl;
}

void Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. ";
	std::cout << "You didn’t put enough bacon in my burger! If you did, ";
	std::cout << "I wouldn’t be asking for more!" << std::endl;
	std::cout << std::endl;
}

void Harl::warning(void)
{
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. ";
    std::cout << "I’ve been coming for years whereas you started ";
    std::cout << "working here since last month." << std::endl;
    std::cout << std::endl;
}

void Harl::error(void)
{
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
    std::cout << std::endl;
}

void Harl::complain(std::string level)
{
	std::string validLevels[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	void (Harl::*functions[5])() = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error,
		NULL 
	};
    for (int i = 0; i < 4; i++) {
        if (level == validLevels[i]) {
            if (functions[i] != NULL) {
                (this->*(functions[i]))();
            } else {
                std::cout << "Invalid level" << std::endl;
            }
            return ;
        }
    }
    std::cout << "Invalid level" << std::endl;
	std::cerr << "You need to specify a valid log level for Harl! ";
}
