#include "Cat.hpp"

// ─────────────────────────────────── CONSTRUCTORS ───────────────────────────────────

Cat::Cat() {
    _type = "Cat";
    _brain = new Brain();
    std::cout << "🐱 A curious little Cat has just appeared!" << std::endl;
}

Cat::Cat(const Cat& other) {
    _type = other._type;
    _brain = new Brain(*other._brain);
    std::cout << "🐱 Cat just cloned itself !" << std::endl;
}

// ─────────────────────────────────── DESTRUCTORS ────────────────────────────────────

Cat::~Cat() {
    delete _brain;
    std::cout << "🐱 The Cat has crossed the road..." << std::endl;
}

// ───────────────────────────────────── OPERATORS ─────────────────────────────────────

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        _type = other._type;
        delete _brain;
        _brain = new Brain(*other._brain);
    }
    std::cout << "🐱 Cat = Cat" << std::endl;
    return *this;
}

// ─────────────────────────────────── GETTERS | SETTERS ───────────────────────────────

const std::string& Cat::getType() const {
    return _type;
}

// ───────────────────────────────────── FUNCTIONS ─────────────────────────────────────

void Cat::makeSound() const {
    std::cout << "😺 MEOOOOOW <3" << std::endl;
}
