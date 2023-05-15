#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include <exception>
#include <string>

class	Intern
{
    std::string check[3];
    public:
        Intern ();
        ~Intern ();
        Intern (const Intern&);
        Intern &operator=(const Intern&);
        AForm* makeForm(const std::string&, const std::string&);
        class NoForm : public std::exception{
            public:
                const char * what() const throw();
        };
        AForm* Robotomy(const std::string&) const;
        AForm* Shrubbery(const std::string&) const;
        AForm* Presidential(const std::string&) const;
};

#endif