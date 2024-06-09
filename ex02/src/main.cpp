/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:21:20 by csakamot          #+#    #+#             */
/*   Updated: 2024/06/09 19:56:36 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
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
  try
  {
    Bureaucrat  human("yamada", 1);
    ShrubberyCreationForm bery("Gold");
    RobotomyRequestForm victim("42tokyo_student");
    PresidentialPardonForm  tmp("people");

    human.signForm(bery);
    human.signForm(victim);
    human.signForm(tmp);
    human.executeForm(bery);
    human.executeForm(victim);
    human.executeForm(tmp);
    human.executeForm(bery);
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }
  draw_terminal_line();
  try
  {
    Bureaucrat  human("yamada", 150);
    ShrubberyCreationForm bery("Silver");
    RobotomyRequestForm victim("42tokyo_student");
    PresidentialPardonForm  tmp("people");

    human.signForm(bery);
    human.signForm(victim);
    human.signForm(tmp);
    human.executeForm(bery);
    human.executeForm(victim);
    human.executeForm(tmp);
    human.executeForm(bery);
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }
  draw_terminal_line();
  try
  {
    Bureaucrat  human("yamada", 50);
    ShrubberyCreationForm bery("Bronze");
    RobotomyRequestForm victim("42tokyo_student");
    PresidentialPardonForm  tmp("people");

    human.signForm(bery);
    human.signForm(victim);
    human.signForm(tmp);
    human.executeForm(bery);
    human.executeForm(victim);
    human.executeForm(tmp);
    human.executeForm(bery);
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }
  draw_terminal_line();
  return (EXIT_SUCCESS);
}