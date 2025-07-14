/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husrevakbas <husrevakbas@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 12:21:33 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/07/14 13:35:25 by husrevakbas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PHONEBOOK_H
# define	PHONEBOOK_H

# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact	_contacts[8];
		int		_index;
	public:
		PhoneBook () {}
		void	add_contact(
			std::string	_first_name,
			std::string	_last_name,
			std::string	_nick_name,
			std::string	_secret,
			std::string	_phone_number
		);
		Contact get_contact(int index);
		int		get_index();
};

#endif	//	PHONEBOOK_H