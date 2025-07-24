#include "Cure.hpp"

// ─────────────────────────────────── CONSTRUCTORS ───────────────────────────────────

Cure::Cure() : AMateria("cure") {
    std::cout << "✨ Creation of a Cure materia" << std::endl;
}

Cure::Cure(const Cure& other) : AMateria(other) {
    std::cout << "✨ Copy of Cure" << std::endl;
}

// ─────────────────────────────────── DESTRUCTORS ────────────────────────────────────

Cure::~Cure() {
    std::cout << "✨ Destruction of Cure" << std::endl;
}

// ───────────────────────────────────── OPERATORS ─────────────────────────────────────

Cure& Cure::operator=(const Cure& other) {
    if (this != &other) {
        AMateria::operator=(other);
    }
    std::cout << "✨ Affectation = of Cure" << std::endl;
    return *this;
}

// ─────────────────────────────────── FUNCTIONS ───────────────────────────────

AMateria* Cure::clone() const {
    return new Cure(*this);
}

void Cure::use(ICharacter& target) {
    std::cout << "✨ * heals " << target.getName() << "'s wounds *" << std::endl;
}