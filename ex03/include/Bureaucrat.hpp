/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:21:20 by csakamot          #+#    #+#             */
/*   Updated: 2024/06/09 20:04:29 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <cstdlib>
#include <iostream>

class Form;

class Bureaucrat
{
private:
  const std::string _name;
  int               _grade;
  static const int  _highGrade;
  static const int  _middleGrade;
  static const int  _lowGrade;

public:
  Bureaucrat( void );
  Bureaucrat( const std::string& name, int grade );
  Bureaucrat( const Bureaucrat& obj );
  ~Bureaucrat();

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
  int                 getGrade( void ) const;
  void                upGrade( void );
  void                downGrade( void );
  void                signForm( Form& obj );
  void                executeForm( Form const & form );

  Bureaucrat& operator=( const Bureaucrat& obj );
};

std::ostream& operator<<( std::ostream& out, const Bureaucrat& obj );

#endif
