#include "AMateria.hpp"

// ─────────────────────────────────── CONSTRUCTORS ───────────────────────────────────

AMateria::AMateria() : _type("?") {
    std::cout << "🔮 Creation of amateria. Type = " << _type << std::endl;
}

AMateria::AMateria(const AMateria& other) {
    //_type = other._type;
    //std::cout << "🔮 Copy of amateria" << std::endl;
}

AMateria::AMateria(std::string const& type) : _type(type) {
    std::cout << "🔮 Creation of amateria. Type = " << _type << std::endl;
}

// ─────────────────────────────────── DESTRUCTORS ────────────────────────────────────

AMateria::~AMateria() {
    std::cout << "🔮 Destruction of amateria" << std::endl;
}

// ───────────────────────────────────── OPERATORS ─────────────────────────────────────

AMateria& AMateria::operator=(const AMateria& other) {
    if (this != &other) {
        //_type = other._type;
        //std::cout << "🔮 Affectation = of amateria" << std::endl;
    }
    return *this;
}

// ─────────────────────────────────── GETTERS | SETTERS ───────────────────────────────

std::string const& AMateria::getType() const {
    return _type;
}

// ─────────────────────────────────── FUNCTIONS ───────────────────────────────

void AMateria::use(ICharacter& target) {
    std::cout << "🔮 * tries to use an undefined materia on " << target.getName() << ". Nothing happens *" << std::endl;
}
