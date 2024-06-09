/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:21:20 by csakamot          #+#    #+#             */
/*   Updated: 2024/06/09 19:42:23 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"

const int Form::_highGrade = 1;
const int Form::_middleGrade = 75;
const int Form::_lowGrade = 150;

Form::Form(void)
:_name("nameless"), _sign(), _requiredGrade(Form::_middleGrade), _execGrade(Form::_middleGrade)
{}

Form::Form(const std::string& name, const int& required, const int& exec)
:_name(name), _sign(), _requiredGrade(required), _execGrade(exec)
{
  if (this->_requiredGrade < this->_highGrade || this->_execGrade < this->_highGrade)
    throw Form::GradeTooHighException();
  else if (this->_requiredGrade > this->_lowGrade || this->_execGrade > this->_lowGrade)
    throw Form::GradeTooLowException();
}

Form::Form(const Form& obj)
:_name (obj.getName()), _sign(), _requiredGrade(obj.getRequired()), _execGrade(obj.getExec())
{
  *this = obj;
}

Form::~Form()
{}

const char* Form::GradeTooHighException::what(void) const throw()
{
  return ("\e[1;38;5;182mError: Grade too high.\e[0m");
}

const char* Form::GradeTooLowException::what(void) const throw()
{
  return ("\e[1;38;5;182mError: Grade too low.\e[0m");
}

const char* Form::FormNotSigned::what(void) const throw()
{
  return ("\e[1;38;5;182mError: The form has not been signed.\e[0m");
}

const std::string&  Form::getName(void) const
{
  return (this->_name);
}

const bool& Form::isSigned(void) const
{
  return (this->_sign);
}

const int&  Form::getRequired(void) const
{
  return (this->_requiredGrade);
}

const int&  Form::getExec(void) const
{
  return (this->_execGrade);
}

void  Form::beSigned(const Bureaucrat& obj)
{
  if (obj.getGrade() > this->getRequired())
    throw Form::GradeTooLowException();
  else
  {
    this->_sign = true;
    std::cout << "\e[1;92m" << obj.getName() << " signed "
              << this->getName() << "\e[0m\n";
  }
  return ;
}

Form& Form::operator=(const Form& obj)
{
  if (this != &obj)
    this->_sign = obj.isSigned();
  else
  {
    std::cout << "\e[1;31mError: "
              << "Attempted self-assignment in copy assignment operator.\e[0m"
              << std::endl;
  }
  return (*this);
}

std::ostream& operator<<(std::ostream& out, const Form& obj)
{
  std::cout << "\e[38;5;82mForm\e[0m " << obj.getName();
  if (obj.isSigned())
    std::cout << " signed: ○ ";
  else
    std::cout << " signed: ✗ ";
  std::cout << "requiredGrade: " << obj.getRequired() << " "
            << "execGrade: " << obj.getExec() << std::endl;
  return (out);
}
