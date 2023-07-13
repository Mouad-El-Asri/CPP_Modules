#include "AForm.hpp"

Bureaucrat::Bureaucrat() : name("Default Bureaucrat")
{
	this->grade = 1;
	std::cout << "Bureaucrat default constructor called\n";
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	std::cout << "Bureaucrat parameterized constructor called\n";
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name)
{
	(*this) = other;
	std::cout << "Bureaucrat copy constructor called\n";
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		this->grade = other.grade;
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
	std::cout << "Incrementing the bureaucrat grade\n";
	if ((this->grade - 1) < 1)
		throw Bureaucrat::GradeTooHighException();
    this->grade--;
}

void	Bureaucrat::decrementGrade()
{
	std::cout << "Decrementing the bureaucrat grade\n";
	if ((this->grade + 1) > 150)
		throw Bureaucrat::GradeTooLowException();
    this->grade++;
}

void    Bureaucrat::signForm(AForm& form) const
{
    form.beSigned(*this);
    std::cout << this->name << " signed " << form.getName() << '\n';
}

void  Bureaucrat::executeForm(AForm const & form) const
{
    form.execute(*this);
    std::cout << this->name << " executed " << form.getName() << '\n';
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (os);
}
