/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:21:20 by csakamot          #+#    #+#             */
/*   Updated: 2024/07/14 15:11:36 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/Intern.hpp"
#include <unistd.h>
#include <sys/ioctl.h>

static size_t get_term_line() {
	winsize	terminal_size;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &terminal_size);
	return (terminal_size.ws_col);
}

static void draw_terminal_line() {
	size_t	terminal_col;

	terminal_col = get_term_line();
	for (size_t i = 0; i < terminal_col; i++)
		std::cout << "=";
	std::cout << std::endl;
	return ;
}

int main(void) {
  draw_terminal_line();
  {
    Bureaucrat  human("42student", 1);
    Intern      slave;
    Form        *tmp;

    tmp = slave.makeForm("presidential pardon", "yamada");
    if (tmp)
      std::cout << tmp->getName() << ": " << tmp->getTarget() << std::endl;
    human.signForm(*tmp);
    human.executeForm(*tmp);
    delete tmp;
  }
  draw_terminal_line();
  {
    Bureaucrat  human("42student", 1);
    Intern      slave;
    Form        *tmp;

    tmp = slave.makeForm("robotomy request", "yamada");
    if (tmp)
      std::cout << tmp->getName() << ": " << tmp->getTarget() << std::endl;
    human.signForm(*tmp);
    human.executeForm(*tmp);
    delete tmp;
  }
  draw_terminal_line();
  {
    Bureaucrat  human("42student", 1);
    Intern      slave;
    Form        *tmp;

    tmp = slave.makeForm("shrubbery creation", "yamada");
    if (tmp)
      std::cout << tmp->getName() << ": " << tmp->getTarget() << std::endl;
    human.signForm(*tmp);
    human.executeForm(*tmp);
    delete tmp;
  }
  draw_terminal_line();
  {
    Intern  slave;
    Form    *tmp;

    tmp = slave.makeForm("nothing", "yamada");
    delete tmp;
  }
  draw_terminal_line();
  return (EXIT_SUCCESS);
}