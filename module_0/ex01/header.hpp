/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husrevakbas <husrevakbas@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 13:12:21 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/07/14 23:05:41 by husrevakbas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "Contact.hpp"
# include "PhoneBook.hpp"
# include "iostream"

# define RED	"\e[1;31m"
# define GREEN	"\e[1;32m"
# define YELLOW	"\e[1;33m"
# define BLUE	"\e[1;34m"
# define MAGENT	"\e[1;35m"
# define CYAN	"\e[1;37m"
# define BG		"\e[1;107m"
# define RESET	"\e[0m"

const	std::string fields[5] = {
	"Firstname",
	"Lastname",
	"Nickname",
	"Phone Number",
	"Darkest Secret"
};

#endif