#ifndef Ice_HPP
#define Ice_HPP

#include "AMateria.hpp"

class Ice : public AMateria {
    public:
        Ice();
        ~Ice();
        Ice(const Ice& other);
        Ice& operator=(const Ice& other);

        virtual AMateria* clone() const;
        virtual void use(ICharacter& target);

};

#endif