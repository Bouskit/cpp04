#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter{
    public:
        Character();
        Character(const Character& other);
        Character& operator=(const Character& other);
        virtual ~Character();

        virtual std::string const & getName() const;
        virtual void equip(AMateria *m);
        virtual void unequip(int idx);
        virtual void use(int idx, ICharacter& target);

    private:
        std::string _name;
        AMateria* _inventory[4];
        AMateria* _unequipped[100];
};

#endif