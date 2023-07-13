#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm(ROBOTOMYREQUESTFORM_NAME, ROBOTOMYREQUESTFORM_SIGN_GRADE, ROBOTOMYREQUESTFORM_EXEC_GRADE)
{
    this->target = "default";
    std::cout << "RobotomyRequestForm Default Constructor Called\n";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(ROBOTOMYREQUESTFORM_NAME, ROBOTOMYREQUESTFORM_SIGN_GRADE, ROBOTOMYREQUESTFORM_EXEC_GRADE)
{
    this->target = target;
    std::cout << "RobotomyRequestForm parameterized Constructor Called\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other)
{
    this->target = other.target;
    std::cout << "RobotomyRequestForm Copy Constructor Called\n";
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this != &other)
        this->target = other.target;
    std::cout << "RobotomyRequestForm Copy Assignment Operator Called\n";
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm Destructor Called\n";
}

std::string RobotomyRequestForm::getTarget() const
{
    return (this->target);
}

void	RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	if (this->getIsSigned() == false)
		throw AForm::FormNotSignedException();
	else if (executor.getGrade() > this->getExecGrade())
		throw AForm::GradeTooLowException();
	srand(time(NULL));
	bool isSuccess = ((std::rand() % 100 + 1) % 2) == 0;
	if (isSuccess)
        std::cout << this->target << " has been robotomized successfully!\n";
    else
        std::cout << this->target << " has been failed to robotomy!\n";
}
