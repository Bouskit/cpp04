#include "WrongCat.hpp"

// ─────────────────────────────────── CONSTRUCTORS ───────────────────────────────────

WrongCat::WrongCat() {
    _type = "WrongCat";
    std::cout << "🐱 A curious little WrongCat has just appeared!" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) {
    _type = other._type;
    std::cout << "🐱 WrongCat just clone itself !" << std::endl;
}

// ─────────────────────────────────── DESTRUCTORS ────────────────────────────────────

WrongCat::~WrongCat() {
    std::cout << "🐱 The WrongCat has crossed the road..." << std::endl;
}

// ───────────────────────────────────── OPERATORS ─────────────────────────────────────

WrongCat& WrongCat::operator=(const WrongCat& other) {
    if (this != &other) {
        _type = other._type;
        std::cout << "🐱 WrongCat = WrongCat" << std::endl;
    }
    return *this;
}

// ─────────────────────────────────── GETTERS | SETTERS ───────────────────────────────

const std::string& WrongCat::getType() const {
    return _type;
}

// ───────────────────────────────────── FUNCTIONS ─────────────────────────────────────

void WrongCat::makeSound() const {
    std::cout << "😺 MEOOOOOW <3" << std::endl;
}
