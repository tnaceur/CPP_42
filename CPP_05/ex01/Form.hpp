#ifndef FORM_HPP
#define FORM_HPP

#include <fstream>
#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class	Form
{
    const   std::string name;
    bool    signe;
    const int grade;
    const int grade_exec;
    public:
        Form(const std::string&, const int, const int);
        Form ();
        ~Form ();
        Form (const Form&);
        Form &operator=(const Form&);
        const std::string getName() const;
        bool getSigne() const;
        int getGrade() const;
        int getExec() const;
        void    setSign(bool sign);
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

std::ostream& operator<<(std::ostream&, Form&);

#endif