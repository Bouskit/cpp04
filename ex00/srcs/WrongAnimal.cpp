#include "WrongAnimal.hpp"

// ─────────────────────────────────── CONSTRUCTORS ───────────────────────────────────

WrongAnimal::WrongAnimal() : _type("??") {
    std::cout << "A new WrongAnimal is born, we dont know his type" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
    _type = other._type;
    std::cout << "WrongAnimal is replaced by another one" << std::endl;
}

// ─────────────────────────────────── DESTRUCTORS ────────────────────────────────────

WrongAnimal::~WrongAnimal() {
    std::cout << "This poor little WrongAnimal has left" << std::endl;
}

// ───────────────────────────────────── OPERATORS ─────────────────────────────────────

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    if (this != &other) {
        _type = other._type;
        std::cout << "WrongAnimal = WrongAnimal" << std::endl;
    }
    return *this;
}

// ─────────────────────────────────── GETTERS | SETTERS ───────────────────────────────

const std::string& WrongAnimal::getType() const {
    return _type;
}

// ───────────────────────────────────── FUNCTIONS ─────────────────────────────────────

void WrongAnimal::makeSound() const {
    std::cout << "[458465485158] what WrongAnimal does that strange sound ?" << std::endl;
}