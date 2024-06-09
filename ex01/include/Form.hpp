/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:21:20 by csakamot          #+#    #+#             */
/*   Updated: 2024/06/09 13:17:38 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <cstdlib>
#include <iostream>

class Bureaucrat;

class Form
{
private:
  const std::string _name;
  bool              _sign;
  const int         _requiredGrade;
  const int         _execGrade;
  static const int  _highGrade;
  static const int  _middleGrade;
  static const int  _lowGrade;

public:
  Form( void );
  Form( const std::string& name, const int& required, const int& exec );
  Form( const Form& obj );
  ~Form();

  class GradeTooHighException : public std::exception
  {
  public:
    virtual const char* what( void ) const throw();
  };

  class GradeTooLowException : public std::exception
  {
  public:
    virtual const char* what( void ) const throw();
  };

  const std::string&  getName( void ) const;
  const bool&         isSigned( void ) const;
  const int&          getRequired( void ) const;
  const int&          getExec( void ) const;
  void                beSigned( const Bureaucrat& obj );

  Form&               operator=( const Form& obj );
};

std::ostream&         operator<<( std::ostream& out, const Form& obj );

#endif
