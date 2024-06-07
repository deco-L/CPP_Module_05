/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:21:20 by csakamot          #+#    #+#             */
/*   Updated: 2024/06/07 14:28:37 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Form.hpp"

const int Form::_highGrade = 1;
const int Form::_middleGrade = 75;
const int Form::_lowGrade = 150;

Form::Form(void):_name("nameless"), _sign(),
_requiredGrade(Form::_middleGrade), _consumeGrade(Form::_middleGrade)
{}

Form::Form(const std::string& name, const int& required, const int& consume):
_name(name), _sign(), _requiredGrade(required), _consumeGrade(consume)
{
  try
  {
    if (this->_requiredGrade < this->_highGrade || this->_consumeGrade < this->_highGrade)
      throw Form::GradeTooHighException();
    else if (this->_requiredGrade > this->_lowGrade || this->_consumeGrade > this->_consumeGrade)
      throw Form::GradeTooLowException();
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }
}

Form& Form::operator=(const Form& obj)
{
  
}
