#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

# define PRESIDENTIALPARDONFORM_NAME "Presidential Pardon Form"
# define PRESIDENTIALPARDONFORM_SIGN_GRADE 25
# define PRESIDENTIALPARDONFORM_EXEC_GRADE 5

class PresidentialPardonForm : public AForm
{
    private:
        std::string target;

    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(const PresidentialPardonForm& other);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
        virtual                 ~PresidentialPardonForm();

        std::string             getTarget() const;
		void					execute(const Bureaucrat &executor) const;
};

#endif