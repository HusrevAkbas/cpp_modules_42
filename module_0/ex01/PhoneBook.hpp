/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 12:21:33 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/07/29 15:13:12 by huakbas          ###   ########.fr       */
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
		PhoneBook ();
		void	add_contact(
			std::string	first_name,
			std::string	last_name,
			std::string	nick_name,
			std::string	secret,
			std::string	phone_number
		);
		void	print_contact_list();
		Contact get_contact(int index);
		int		get_index();
};

#endif	//	PHONEBOOK_H