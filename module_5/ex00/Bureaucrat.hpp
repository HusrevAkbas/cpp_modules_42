/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 16:45:50 by huakbas           #+#    #+#             */
/*   Updated: 2025/08/02 16:58:00 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	BUREAUCRAT_H
# define	BUREAUCRAT_H

# include <iostream>

# define	RED		"\e[31m"
# define	GREEN	"\e[32m"
# define	YELLOW	"\e[33m"
# define	RESET	"\e[0m"
# define	BOLD	"\e[1m"
# define	ITALIC	"\e[3m"

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
		const std::string	getName();
		int	getGrade();
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

#endif	//	BUREAUCRAT_H