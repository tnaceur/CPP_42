#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class	PresidentialPardonForm : public AForm
{
    std::string target;
    public:
        PresidentialPardonForm (const std::string&);
        PresidentialPardonForm ();
        ~PresidentialPardonForm ();
        PresidentialPardonForm (const PresidentialPardonForm&);
        PresidentialPardonForm &operator=(const PresidentialPardonForm&);
        void execute(Bureaucrat const &) const;
};

#endif