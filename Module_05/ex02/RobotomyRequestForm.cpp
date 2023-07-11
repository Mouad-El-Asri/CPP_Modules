#include "RobotomyRequestForm.hpp"

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
