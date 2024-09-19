#include "PhoneBook.hpp"


PhoneBook::PhoneBook(void)
{
	exited = false;
	counter = 0;
	create_list();
}
PhoneBook::~PhoneBook(void)
{
	return ;
}
void PhoneBook::create_list(void){
	for (int i = 0; i <= 8; i++)
		_contact_list[i].index = i;
}

void PhoneBook::add_contact(void)
{
	Contact& cur_contact = _contact_list[counter % 8];
	std::cout << CYAN << "ADDING NEW CONTACT..." << RESET << std::endl;
	save_input("first name", cur_contact.first_name);
	save_input("last name", cur_contact.last_name);
	save_input("nickname", cur_contact.nickname);
	save_input("phone number", cur_contact.phone_number);
	save_input("darkest secret", cur_contact.darkest_secret);
	std::cout << BLUE << "CONTACT SAVED SUCCESSFULLY!" << RESET << std::endl;
	counter++;
}
void PhoneBook::save_input(std::string value, std::string& placeholder)
{
	while (1)
	{
		std::cout << "Enter " << value << ":" << std::endl;
		std::getline(std::cin, placeholder);
		if (placeholder.empty()) //add check for spaces(chars and nums?)
			std::cout << RED <<"Fields can't be empty!"<< RESET << std::endl;
		else
			break ;
	}
}

void PhoneBook::search_contact(void)
{
	std::string index;
	int i = 0;
	//display_contacts
	std::cout << CYAN << "CURRENT CONTACTS:" << RESET << std::endl;
	while (i < 8)
	{
		std::cout << "        " << _contact_list[i].index << " | ";
		display_in_column(_contact_list[i].first_name);
		display_in_column(_contact_list[i].last_name);
		display_in_column(_contact_list[i].nickname);
		std::cout << std::endl;
		i++;
	}
	std::cout << "Enter the index of the contact:" << std::endl;
	std::getline(std::cin, index);
}
void PhoneBook::display_in_column(std::string field_name)
{
	int chars_left = 0;
	if (field_name.length() > 8)
	{
		field_name = field_name.substr(0, 7);
		field_name += '.';
	}
	chars_left = 8 - field_name.length();
	while (chars_left-- > 0)
		std::cout << " ";
	std::cout << field_name <<  " | ";
	
}