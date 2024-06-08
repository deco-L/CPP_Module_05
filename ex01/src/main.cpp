/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:21:20 by csakamot          #+#    #+#             */
/*   Updated: 2024/06/08 20:49:06 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
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
    Bureaucrat  human("yamada", 10);
    Form        licence("rooftopAccess", 50, 10);

    std::cout << human;
    std::cout << licence;
    human.signForm(licence);
    std::cout << human;
    std::cout << licence;
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }
  draw_terminal_line();
  draw_terminal_line();
  try
  {
    Bureaucrat  human("yamada", 140);
    Form        licence("rooftopAccess", 50, 10);

    std::cout << human;
    std::cout << licence;
    human.signForm(licence);
    std::cout << human;
    std::cout << licence;
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }
  draw_terminal_line();
  try
  {
    Form  licence("error", -1, 30);

    std::cout << licence;
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }
  draw_terminal_line();
  try
  {
    Form  licence("error", 10, 0);

    std::cout << licence;
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }
  draw_terminal_line();
  try
  {
    Form  licence("error", 151, 30);

    std::cout << licence;
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }
  draw_terminal_line();
  try
  {
    Form  licence("error", 10, 151);

    std::cout << licence;
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }
  draw_terminal_line();
  return (EXIT_SUCCESS);
}