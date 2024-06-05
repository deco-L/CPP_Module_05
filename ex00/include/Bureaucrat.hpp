/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:21:20 by csakamot          #+#    #+#             */
/*   Updated: 2024/06/05 16:00:41 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <cstdlib>
#include <iostream>

class Bureaucrat
{
private:
  const std::string _name;
  int               _grade;

public:
  Bureaucrat( void );
  Bureaucrat( const std::string& name );
  Bureaucrat( const std::string& name, int grade );
  Bureaucrat( const Bureaucrat& obj );
  ~Bureaucrat();

  class GradeTooHighException : public std::exception {
  public:
    virtual const char* what( void ) const throw();
  };

  class GradeTooLowException : public std::exception {
  public:
    virtual const char* what( void ) const throw();
  };

  const std::string&  getName( void ) const;
  int                 getGrade( void ) const;

  Bureaucrat& operator=( const Bureaucrat& obj );
};

#endif
