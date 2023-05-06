#include "Harl.hpp"

Harl::Harl()
{
	std::cout << "Object created successfully !!!\n";
}

Harl::~Harl()
{
	std::cout << "Object destroyed successfully !!!\n";
}

void	Harl::debug(void)
{
	std::cout << "[DEBUG]: I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!\n";
}

void	Harl::info(void)
{
	std::cout << "[INFO]: I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}

void	Harl::warning(void)
{
	std::cout << "[WARNING]: I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n";
}

void	Harl::error(void)
{
	std::cout << "[ERROR]: This is unacceptable! I want to speak to the manager now.\n";
}

void	Harl::complain(std::string level)
{
    std::string	lvl[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	myFuncPtr	ptrs[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (int i = 0; i < 4; i++)
	{
		if (lvl[i] == level)
		{
			(this->*ptrs[i])();
			return ;
		}
	}
	std::cout <<  "Invalid level entered. Please enter a valid level !!!\n";
}
