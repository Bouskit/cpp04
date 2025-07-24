#include "Dog.hpp"

// ─────────────────────────────────── CONSTRUCTORS ───────────────────────────────────

Dog::Dog() {
    _type = "Dog";
    std::cout << "🐶 A wild Dog bursts in !" << std::endl;
}

Dog::Dog(const Dog& other) {
    _type = other._type;
    std::cout << "🐶 Double the bark, double the chaos!" << std::endl;
}

// ─────────────────────────────────── DESTRUCTORS ────────────────────────────────────

Dog::~Dog() {
    std::cout << "🐶 Never give chocolate to a Dog..." << std::endl;
}

// ───────────────────────────────────── OPERATORS ─────────────────────────────────────

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        _type = other._type;
        std::cout << "🐶 Dog = Dog" << std::endl;
    }
    return *this;
}

// ─────────────────────────────────── GETTERS | SETTERS ───────────────────────────────

const std::string& Dog::getType() const {
    return _type;
}

// ───────────────────────────────────── FUNCTIONS ─────────────────────────────────────

void Dog::makeSound() const {
    std::cout << "🐶 WOOF! WOOF! (You'd better back off.)" << std::endl;
}
