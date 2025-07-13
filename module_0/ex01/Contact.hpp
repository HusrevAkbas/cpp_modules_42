#ifndef	CONTACT_H
# define	CONTACT_H
# include "iostream"

class Contact
{
	private:
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nick_name;
		std::string	_secret;
		int			_phone_number;
	public:
		void	set_first_name(std::string first_name);
		void	set_last_name(std::string last_name);
		void	set_nick_name(std::string nick_name);
		void	set_secret(std::string secret);
		void	set_phone_number(int phone_number);
		const std::string	get_first_name();
		const std::string	get_last_name();
		const std::string	get_nick_name();
		const std::string	get_secret();
		int					get_phone_number();
};

#endif // CONTACT_H