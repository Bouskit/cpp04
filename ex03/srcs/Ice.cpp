#include "Ice.hpp"

// ─────────────────────────────────── CONSTRUCTORS ───────────────────────────────────

Ice::Ice() : AMateria("ice") {
    std::cout << "❄️ Creation of an Ice materia" << std::endl;
}

Ice::Ice(const Ice& other) : AMateria(other) {
    std::cout << "❄️ Copy of Ice" << std::endl;
}

// ─────────────────────────────────── DESTRUCTORS ────────────────────────────────────

Ice::~Ice() {
    std::cout << "❄️ Destruction of Ice" << std::endl;
}

// ───────────────────────────────────── OPERATORS ─────────────────────────────────────

Ice& Ice::operator=(const Ice& other) {
    if (this != &other) {
        AMateria::operator=(other);
    }
    std::cout << "❄️ Affectation = of Ice" << std::endl;
    return *this;
}

// ─────────────────────────────────── FUNCTIONS ───────────────────────────────

AMateria* Ice::clone() const {
    return new Ice(*this);
}

void Ice::use(ICharacter& target) {
    std::cout << "❄️ * shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
