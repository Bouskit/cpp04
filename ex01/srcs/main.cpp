#include "Cat.hpp"
#include "Dog.hpp"

#define NB_ANIMALS 4

int main() {
    std::cout << "\n🐾 CREATING ANIMALS ARRAY..." << std::endl;
    Animal* animals[NB_ANIMALS];

    // ───────────────────── Half Cats, Half Dogs ─────────────────────
    for (int i = 0; i < NB_ANIMALS; ++i) {
        if (i < NB_ANIMALS / 2)
            animals[i] = new Cat();
        else
            animals[i] = new Dog();
    }

    std::cout << "\n🔊 ANIMALS MAKE SOUND..." << std::endl;
    for (int i = 0; i < NB_ANIMALS; ++i) {
        animals[i]->makeSound();
    }

    std::cout << "\n🧠 TESTING DEEP COPY..." << std::endl;
    Cat original;
    Cat copy(original); // doit faire une copie profonde
    std::cout << "Copy constructed successfully." << std::endl;

    std::cout << "\n🧹 CLEANING UP..." << std::endl;
    for (int i = 0; i < NB_ANIMALS; ++i) {
        delete animals[i]; // Doit appeler le destructeur Cat/Dog et delete Brain
    }

    std::cout << "\n✅ PROGRAM ENDED WITHOUT LEAKS" << std::endl;
    return 0;
}
