#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
#include "IMateriaSource.hpp"

class	MateriaSource : public IMateriaSource {

public:

	MateriaSource( void );
	MateriaSource( MateriaSource const &src );
	~MateriaSource( void );

	void learnMateria(AMateria*);
	AMateria* createMateria(std::string const & type);

	MateriaSource	&operator=( MateriaSource const &rhs );

protected:

	AMateria	*_inventory[4];
};

//std::ostream	&operator<<( std::ostream &o, MateriaSource const &i );

#endif
