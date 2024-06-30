/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:21:20 by csakamot          #+#    #+#             */
/*   Updated: 2024/06/30 19:30:29 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PresidentialPardonForm.hpp"

const int PresidentialPardonForm::_sign = 25;
const int PresidentialPardonForm::_exec = 5;

PresidentialPardonForm::PresidentialPardonForm(void):
Form::Form("PresidentialPardonForm", this->_sign, this->_exec), _target("noTarget")
{}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target):
Form::Form("PresidentialPardonForm", this->_sign, this->_exec), _target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj):
Form::Form(obj), _target(obj.getTarget())
{
  *this = obj;
}

PresidentialPardonForm::~PresidentialPardonForm()
{}

const std::string&  PresidentialPardonForm::getTarget(void) const
{
  return (this->_target);
}

void  PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
  try
  {
    if (executor.getGrade() > this->getExec())
      throw PresidentialPardonForm::GradeTooLowException();
    if (!this->isSigned())
      throw PresidentialPardonForm::FormNotSigned();
    std::cout << "\e[38;5;82m" << executor.getName() << "\e[0m"
              << " executed " << this->getName() << std::endl;
    std::cout << "\e[38;5;82m" << this->getTarget() << "\e[0m"
              << " has been pardoned by Zaphod Beeblebrox." << std::endl;
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }
  
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& obj)
{
  if (this != &obj)
    return *this;
  std::cout << "\e[1;31mError: "
            << "Attempted self-assignment in copy assignment operator.\e[0m"
            << std::endl;
  return *this;
}

std::ostream& operator<<(std::ostream& out, const PresidentialPardonForm& obj)
{
  std::cout << "\e[38;5;82m" << obj.getName() << "\e[0m";
  if (obj.isSigned())
    std::cout << " signed: ○ ";
  else
    std::cout << " signed: ✗ ";
  std::cout << "requiredGrade: " << obj.getRequired() << " "
            << "execGrade: " << obj.getExec() << " "
            << "target: " << obj.getTarget() << std::endl;
  return (out);
}
