#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern default constructor called\n";
}

Intern::Intern(const Intern &other)
{
	(*this) = other;
	std::cout << "Intern copy constructor called\n";
}

Intern	&Intern::operator=(const Intern &other)
{
	if (this != &other)
		std::cout << "Intern copy assignment operator called\n";
	return (*this);
}

Intern::~Intern()
{
	std::cout << "Intern destructor called\n";
}

const char	*Intern::FormNotFoundException::what() const throw()
{
	return ("Form not found");
}

AForm	*Intern::createShrubberyCreationForm(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm	*Intern::createRobotomyRequestForm(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm	*Intern::createPresidentialPardonForm(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm	*Intern::makeForm(std::string formName, std::string target)
{
	AForm		*form;
	std::string	formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	formCreator	creators[3] = {&Intern::createShrubberyCreationForm, &Intern::createRobotomyRequestForm, &Intern::createPresidentialPardonForm};

	for (int i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
		{
			form = (this->*creators[i])(target);
			std::cout << "Intern creates " << formName << " form\n";
			return (form);
		}
	}
	throw Intern::FormNotFoundException();
	return (NULL);
}
