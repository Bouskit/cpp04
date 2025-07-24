#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

#define SEP std::cout << "\n──────────────────────────────────────────────────────────\n" << std::endl;

int main() {

    SEP

    std::cout << "✨ Creating real animals with virtual functions:\n" << std::endl;

    const Animal* random = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    SEP

    std::cout << "📦 Types:\n\n";
    std::cout << "random : " << random->getType() << std::endl;
    std::cout << "dog : " << dog->getType() << std::endl;
    std::cout << "cat : " << cat->getType() << std::endl;

    SEP

    std::cout << "🔊 Sounds:\n\n";
    random->makeSound();
    dog->makeSound();
    cat->makeSound();

    SEP

    std::cout << "🧹 Cleaning real animals:\n\n";
    delete random;
    delete dog;
    delete cat;

    SEP

    std::cout << "🚨 Creating WRONG animals (no virtual functions):\n" << std::endl;

    const WrongAnimal* wrongBase = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    SEP

    std::cout << "📦 Types:\n\n";
    std::cout << "wrongBase: " << wrongBase->getType() << std::endl;
    std::cout << "wrongCat : " << wrongCat->getType() << std::endl;

    SEP

    std::cout << "🔊 Sounds:\n\n";
    wrongBase->makeSound();
    wrongCat->makeSound();

    // The wrong cat doesnt use his makeSound because its not virtual

    SEP

    std::cout << "🧹 Cleaning wrong animals:\n\n";
    delete wrongBase;
    delete wrongCat;

    SEP
    SEP
    SEP

    std::cout << "🎯 Local wrong cat\n" << std::endl;

    
    WrongCat localWrongCat;
    localWrongCat.makeSound();
    // good cat sound because no need to virtual for local

    SEP
    std::cout << "🎯 Local wrong animal = local Wrong cat\n" << std::endl;

    WrongAnimal slicedWrong = localWrongCat;
    slicedWrong.makeSound();

    SEP
    std::cout << "🎯 Local animal = local cat\n" << std::endl;

    Cat localCat;
    Animal sliced = localCat;
    sliced.makeSound();
    //J'ai perdu la partie Cat en stockant dans animal

    //"Le slicing arrive quand je copie un objet dérivé dans une variable de type base par valeur. 
    // Je perds alors tout ce qui faisait la spécificité de l'objet dérivé. 
    // C’est pour ça qu’on passe toujours par des pointeurs ou des références pour le polymorphisme."

    SEP
    std::cout << "✅ All tests done.\n" << std::endl;

    return 0;
}

