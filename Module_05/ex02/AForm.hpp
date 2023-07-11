#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class AForm
{
private:
    const std::string name;
    bool sign;
    const int signGrade;
    const int execGrade;

protected:
    class GradeTooHighException : public std::exception
    {
    public:
        const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
    public:
        const char *what() const throw();
    };

public:
    AForm();
    AForm(std::string formName, int formSignGrade, int formExecGrade);
    AForm(const AForm &other);
    AForm &operator=(const AForm &other);
    virtual ~AForm();

    std::string getName() const;
    bool getIsSigned() const;
    int getSignGrade() const;
    int getExecGrade() const;

    void beSigned(const Bureaucrat &bureaucrat);
    void signForm(const Bureaucrat &bureaucrat) const;
    void execute(const Bureaucrat &executor) const;
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif
