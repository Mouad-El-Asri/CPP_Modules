#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon
{
	private:
		std::string		type;

	public:
		Weapon();
		Weapon(std::string type);
		~Weapon();

		const std::string&	getType(void);
		void			setType(std::string type);
}

#endif

