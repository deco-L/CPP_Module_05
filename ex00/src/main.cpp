/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:21:20 by csakamot          #+#    #+#             */
/*   Updated: 2024/05/19 18:41:03 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
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
		std::cout << "\e[38;5;"<< i + 20 << "m=\e[0m";
	std::cout << std::endl;
	return ;
}

int main(void) {
  draw_terminal_line();
  return (EXIT_SUCCESS);
}