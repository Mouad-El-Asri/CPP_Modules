#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
	private:
		typedef AForm* (Intern::*formCreator)(std::string target);

		AForm	*createShrubberyCreationForm(std::string target);
		AForm	*createRobotomyRequestForm(std::string target);
		AForm	*createPresidentialPardonForm(std::string target);

	public:
		Intern();
		Intern(const Intern &other);
		Intern	&operator=(const Intern &other);
		~Intern();

		AForm	*makeForm(std::string formName, std::string target);

	public:
		class FormNotFoundException : public std::exception
		{
			public:
				const char	*what() const throw();
		};
};

#endif