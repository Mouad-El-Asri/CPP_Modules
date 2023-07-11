#include "Form.hpp"

Form::Form() : name(""), signGrade(0), execGrade(0)
{
    this->sign = false;
    std::cout << "Form default constructor called\n";
}

Form::Form(std::string formName, int formSignGrade, int formExecGrade) : name(formName), signGrade(formSignGrade), execGrade(formExecGrade)
{
    std::cout << "Form parametrized constructor called\n";
    this->sign = false;
    if (formSignGrade < 1 || formExecGrade < 1)
        throw Form::GradeTooHighException();
    else if (formSignGrade > 150 || formExecGrade > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form &other) : name(other.name), signGrade(other.signGrade), execGrade(other.execGrade)
{
    (*this) = other;
    std::cout << "Form copy constructor called\n";
}

Form &Form::operator=(const Form &other)
{
    if (this != &other)
        this->sign = other.sign;
    std::cout << "Form copy assignment operator called\n";
    return (*this);
}

Form::~Form()
{
    std::cout << "Form destructor called\n";
}

std::string Form::getName() const
{
    return (this->name);
}

bool Form::getIsSigned() const
{
    return (this->sign);
}

int Form::getSignGrade() const
{
    return (this->signGrade);
}

int Form::getExecGrade() const
{
    return (this->execGrade);
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->signGrade)
        throw Form::GradeTooLowException();
    this->sign = true;
}

void Form::signForm(const Bureaucrat &bureaucrat) const
{
    if (this->sign)
        std::cout << bureaucrat.getName() << " signed " << this->name << "\n";
    else
        std::cout << bureaucrat.getName() << " couldn't sign " << this->name << " because his/her grade is too low\n";
}

const char *Form::GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
    os << "Form name : " << form.getName() << "\n";
    os << "Form sign : " << form.getIsSigned() << "\n";
    os << "Form sign grade : " << form.getSignGrade() << "\n";
    os << "Form exec grade : " << form.getExecGrade() << "\n";
    return (os);
}
