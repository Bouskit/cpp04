#include "Animal.hpp"

// ─────────────────────────────────── CONSTRUCTORS ───────────────────────────────────

Animal::Animal() : _type("?") {
    std::cout << "A new Animal is born, we dont know his type" << std::endl;
}

Animal::Animal(const Animal& other) {
    _type = other._type;
    std::cout << "Animal is replaced by another one" << std::endl;
}

// ─────────────────────────────────── DESTRUCTORS ────────────────────────────────────

Animal::~Animal() {
    std::cout << "This poor little Animal has left" << std::endl;
}

// ───────────────────────────────────── OPERATORS ─────────────────────────────────────

Animal& Animal::operator=(const Animal& other) {
    if (this != &other) {
        _type = other._type;
        std::cout << "Animal = Animal" << std::endl;
    }
    return *this;
}

// ─────────────────────────────────── GETTERS | SETTERS ───────────────────────────────

const std::string& Animal::getType() const {
    return _type;
}

// ───────────────────────────────────── FUNCTIONS ─────────────────────────────────────

void Animal::makeSound() const {
    std::cout << "[woamiakoakjfew] what Animal does that strange sound ?" << std::endl;
}
