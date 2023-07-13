#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const			std::string name;
        bool			sign;
        const int		signGrade;
        const int		execGrade;

    public:
        AForm();
        AForm(std::string formName, int formSignGrade, int formExecGrade);
        AForm(const AForm &other);
        AForm			&operator=(const AForm &other);
        virtual			~AForm();

        std::string		getName() const;
        bool			getIsSigned() const;
        int				getSignGrade() const;
        int				getExecGrade() const;

		virtual void	execute(const Bureaucrat &executor) const = 0;
        void			beSigned(const Bureaucrat &bureaucrat);

    public:
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

		class FormNotSignedException : public std::exception
        {
			public:
        	    const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif
