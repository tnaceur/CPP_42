#ifndef AFORM_HPP
#define AFORM_HPP

#include <fstream>
#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class	AForm
{
    const   std::string name;
    bool    signe;
    const int grade;
    const int grade_exec;
    public:
        AForm(const std::string&, const int, const int);
        AForm ();
        ~AForm ();
        AForm (const AForm&);
        AForm &operator=(const AForm&);
        const std::string getName() const;
        bool getSigne() const;
        int getGrade() const;
        int getExec() const;
        void    beSigned(const Bureaucrat&);
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
};

std::ostream& operator<<(std::ostream&, AForm&);

#endif