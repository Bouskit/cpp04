#ifndef ANIMAL_HPP 
#define ANIMAL_HPP

#include <iostream>

class Animal {
    public:
        Animal();
        virtual ~Animal();
        Animal(const Animal& other);
        Animal& operator=(const Animal& other);

        const std::string& getType() const;
        virtual void makeSound() const = 0;

    protected:
        std::string _type;
};

#endif