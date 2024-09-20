#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream> 
#include "Contact.hpp"

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */

class Contact;

class PhoneBook
{
	private:
		Contact _contact_list[8];
	public:
		PhoneBook(void);
		~PhoneBook(void);
		int counter;
		bool exited;
		void create_list(void);
		void add_contact(void);
		void search_contact(void);
		void display_in_column(std::string field_name);
		void save_input(std::string value, std::string& placeholder);
		int is_valid_input(std::string input, int option);
};


#endif

