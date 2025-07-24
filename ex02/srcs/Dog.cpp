#include "Dog.hpp"

// ─────────────────────────────────── CONSTRUCTORS ───────────────────────────────────

Dog::Dog() {
    _type = "Dog";
    _brain = new Brain();
    std::cout << "🐶 A wild Dog bursts in !" << std::endl;
}

Dog::Dog(const Dog& other) {
    _type = other._type;
    _brain = new Brain(*other._brain);
    std::cout << "🐶 Double the bark, double the chaos!" << std::endl;
}

// ─────────────────────────────────── DESTRUCTORS ────────────────────────────────────

Dog::~Dog() {
    delete _brain;
    std::cout << "🐶 Never give chocolate to a Dog..." << std::endl;
}

// ───────────────────────────────────── OPERATORS ─────────────────────────────────────

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        _type = other._type;
        delete _brain;
        _brain = new Brain(*other._brain);
    }
    std::cout << "🐶 Dog = Dog" << std::endl;
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
