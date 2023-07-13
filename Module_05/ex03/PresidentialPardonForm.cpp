#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm(PRESIDENTIALPARDONFORM_NAME, PRESIDENTIALPARDONFORM_SIGN_GRADE, PRESIDENTIALPARDONFORM_EXEC_GRADE)
{
    this->target = "default";
    std::cout << "PresidentialPardonForm default constructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(PRESIDENTIALPARDONFORM_NAME, PRESIDENTIALPARDONFORM_SIGN_GRADE, PRESIDENTIALPARDONFORM_EXEC_GRADE)
{
    this->target = target;
    std::cout << "PresidentialPardonForm parameterized constructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other)
{
    (*this) = other;
    std::cout << "PresidentialPardonForm copy constructor called\n";
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    if (this != &other)
        this->target = other.target;
    std::cout << "PresidentialPardonForm copy assignment operator called\n";
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm destructor called\n";
}

std::string PresidentialPardonForm::getTarget() const
{
    return (this->target);
}

void	PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (this->getIsSigned() == false)
		throw AForm::FormNotSignedException();
	else if (executor.getGrade() > this->getExecGrade())
		throw AForm::GradeTooLowException();
	std::cout << this->getTarget() << " has been pardoned by Zafod Beeblebrox\n";
}
