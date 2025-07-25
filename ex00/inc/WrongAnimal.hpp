#ifndef WRONGANIMAL_HPP 
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {
    public:
        WrongAnimal();
        ~WrongAnimal();
        WrongAnimal(const WrongAnimal& other);
        WrongAnimal& operator=(const WrongAnimal& other);

        const std::string& getType() const;
        void makeSound() const;

    protected:
        std::string _type;
};

#endif