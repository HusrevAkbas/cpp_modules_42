/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 16:45:50 by huakbas           #+#    #+#             */
/*   Updated: 2025/08/13 18:16:26 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include "Form.hpp"

# define	RED		"\e[31m"
# define	GREEN	"\e[32m"
# define	GREEN2	"\e[1;32m"
# define	YELLOW	"\e[33m"
# define	BLUE	"\e[34m"
# define	MAGENT	"\e[35m"
# define	CYAN	"\e[36m"
# define	RESET	"\e[0m"
# define	BOLD	"\e[1m"
# define	ITALIC	"\e[3m"

class	Form;

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;
	public:
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &a);
		Bureaucrat& operator=(const Bureaucrat &a);
		const std::string	getName() const;
		int	getGrade() const;
		void	promote();
		void	demote();
		void	signForm(Form &form) const;
		class GradeTooHighException : public std::exception
		{
			public:
				const char	*what() const throw ();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char	*what() const throw ();
		};
	};

std::ostream& operator<< (std::ostream &o, Bureaucrat &b);
