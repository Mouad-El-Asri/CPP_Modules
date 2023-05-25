#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class	Animal
{
	protected:
		std::string	type;

	public:
		Animal();
		Animal(std::string type);
		Animal(const Animal& other);
		Animal&		operator=(const Animal& other);
		~Animal();

		std::string	getType() const;
		void	makeSound() const;
};

#endif