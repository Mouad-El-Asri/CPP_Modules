#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default Bureaucrat")
{
	this->grade = 0;
	std::cout << "Bureaucrat default constructor called\n";
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	this->grade = grade;
	std::cout << "Bureaucrat parameterized constructor called\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
	(*this) = other;
	std::cout << "Bureaucrat copy constructor called\n";
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		(std::string)this->name = other.name;
		this->grade = other.grade;
	}
	std::cout << "Bureaucrat copy assignment operator called\n";
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called\n";
}

std::string	Bureaucrat::getName() const
{
	return(this->name);
}

int	Bureaucrat::getGrade() const
{
	return (this->grade);
}

void	Bureaucrat::incrementGrade()
{
	if (grade > 1)
		grade--;
	else
		// throw exception
}

void	Bureaucrat::decrementGrade()
{
	if (grade < 150)
		grade++;
	else
		// throw exception
}
