/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:21:20 by csakamot          #+#    #+#             */
/*   Updated: 2024/06/09 20:05:17 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RobotomyRequestForm.hpp"

const int RobotomyRequestForm::_sign = 72;
const int RobotomyRequestForm::_exec = 45;

RobotomyRequestForm::RobotomyRequestForm(void):
Form::Form("RobotomyRequestForm", this->_sign, this->_exec), _target("noTarget")
{}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target):
Form::Form("RobotomyRequestForm", this->_sign, this->_exec), _target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj):
Form::Form(obj), _target(obj.getTarget())
{
  *this = obj;
}

RobotomyRequestForm::~RobotomyRequestForm()
{}

const std::string&  RobotomyRequestForm::getTarget(void) const
{
  return (this->_target);
}

void  RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
  try
  {
    if (executor.getGrade() > this->getExec())
      throw RobotomyRequestForm::GradeTooLowException();
    if (!this->isSigned())
      throw RobotomyRequestForm::FormNotSigned();
    std::cout << "\e[38;5;82m" << executor.getName() << "\e[0m"
              << " executed " << this->getName() << std::endl;
    std::cout << "vrrrrrrr....\n";
    std::srand(std::time(0));
    if (rand() % 2)
      std::cout << "\e[1;31m" << this->getTarget()
                << " has been successfully lobotomised.\e[0m" << std::endl;
    else
      std::cout << "\e[1;31m" << this->getTarget()
                << " failed to lobotomise.\e[0m" << std::endl;
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }
  
  return ;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& obj)
{
  if (this != &obj)
    return *this;
  std::cout << "\e[1;31mError: "
            << "Attempted self-assignment in copy assignment operator.\e[0m"
            << std::endl;
  return *this;
}

std::ostream& operator<<(std::ostream& out, const RobotomyRequestForm& obj)
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
