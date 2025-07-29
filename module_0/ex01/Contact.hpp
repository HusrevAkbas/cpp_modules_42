#ifndef		CONTACT_H
# define	CONTACT_H

# include "iostream"
# include "iomanip"

class Contact
{
	private:
		int			_index;
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nick_name;
		std::string	_secret;
		std::string	_phone_number;
	public:
		Contact ();
		void	set_contact(
			int			index,
			std::string	first_name,
			std::string	last_name,
			std::string	nick_name,
			std::string	secret,
			std::string	phone_number
		);
		void	print_contact();
		void	print_contact_oneline();
		int		get_index();
		const std::string	get_first_name();
		const std::string	get_last_name();
		const std::string	get_nick_name();
		const std::string	get_secret();
		const std::string	get_phone_number();
		const std::string	make_short( std::string str);
};

#endif // CONTACT_H