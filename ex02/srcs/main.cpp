#include "Cat.hpp"
#include "Dog.hpp"

int main() {

    /*Animal* a = new Animal();
    Animal b;*/

    std::cout << "\n🐶 Creating a Dog and a Cat via Animal*:\n" << std::endl;

    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << "\n🔊 Sounds via base class pointer:\n" << std::endl;
    dog->makeSound(); // should call Dog::makeSound()
    cat->makeSound(); // should call Cat::makeSound()

    std::cout << "\n🧹 Cleaning up:\n" << std::endl;
    delete dog;
    delete cat;

    return 0;
}