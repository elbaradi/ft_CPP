#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"

class Phonebook
{
	private:
		Contact	contacts[8];
		int		oldest;
		int		size;

	public:
		int		getOldest(void);
		void	setOldest(int nbr);
		int		getSize(void);
		void	setSize(int nbr);
		void	updateSize(void);
		void	updateOldest(void);
		void	addContact(void);
		Contact *findContactSpace(void);
		Contact	*getContact(int i);
		void	getContacts(void);
		void	printHeader(void);
		void	printFooter(void);
		void	promptFollowUp(void);

	Phonebook(void);
	~Phonebook(void);
};

#endif
