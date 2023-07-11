#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

# define ROBOTOMYREQUESTFORM_NAME "Robotomy Request Form"
# define ROBOTOMYREQUESTFORM_SIGN_GRADE 72
# define ROBOTOMYREQUESTFORM_EXEC_GRADE 45

class RobotomyRequestForm : public AForm
{
    private:
        std::string target;

    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(const RobotomyRequestForm& other);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
        virtual                 ~RobotomyRequestForm();

        std::string             getTarget() const;
};

#endif