#include "AForm.hpp"

AForm::AForm() : name(""), signGrade(0), execGrade(0)
{
    this->sign = false;
    std::cout << "AForm default constructor called\n";
}

AForm::AForm(std::string formName, int formSignGrade, int formExecGrade) : name(formName), signGrade(formSignGrade), execGrade(formExecGrade)
{
    std::cout << "AForm parametrized constructor called\n";
    this->sign = false;
    if (formSignGrade < 1 || formExecGrade < 1)
        throw AForm::GradeTooHighException();
    else if (formSignGrade > 150 || formExecGrade > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &other) : name(other.name), signGrade(other.signGrade), execGrade(other.execGrade)
{
    (*this) = other;
    std::cout << "AForm copy constructor called\n";
}

AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
        this->sign = other.sign;
    std::cout << "AForm copy assignment operator called\n";
    return (*this);
}

AForm::~AForm()
{
    std::cout << "AForm destructor called\n";
}

std::string AForm::getName() const
{
    return (this->name);
}

bool AForm::getIsSigned() const
{
    return (this->sign);
}

int AForm::getSignGrade() const
{
    return (this->signGrade);
}

int AForm::getExecGrade() const
{
    return (this->execGrade);
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->signGrade)
        throw AForm::GradeTooLowException();
    this->sign = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return ("Form is not signed");
}

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
    os << "Form name : " << form.getName() << "\n";
    os << "Form sign : " << form.getIsSigned() << "\n";
    os << "Form sign grade : " << form.getSignGrade() << "\n";
    os << "Form exec grade : " << form.getExecGrade() << "\n";
    return (os);
}
