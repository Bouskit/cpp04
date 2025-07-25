#include "MateriaSource.hpp"

// ─────────────────────────────────── CONSTRUCTORS ───────────────────────────────────

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; i++) {
        _inventory[i] = NULL;
    }
    std::cout << "📚 MateriaSource created" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& other) {
    for (int i = 0; i < 4; i++) {
        if (other._inventory[i])
            _inventory[i] = other._inventory[i]->clone();
        else 
            _inventory[i] = NULL;
    }
    std::cout << "📚 Copy of MateriaSource" << std::endl;
}

// ─────────────────────────────────── DESTRUCTORS ────────────────────────────────────

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; i++) {
        if (_inventory[i])
            delete _inventory[i];
    }
    std::cout << "📚 Destruction of MateriaSource" << std::endl;
}

// ───────────────────────────────────── OPERATORS ─────────────────────────────────────

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    if (this != &other) {
        for (int i = 0; i < 4; i++) {
            if (_inventory[i])
                delete _inventory[i];

            if (other._inventory[i])
                _inventory[i] = other._inventory[i]->clone();
            else  
                _inventory[i] = NULL;
        }   
    }
    std::cout << "📚 Affectation = of MateriaSource" << std::endl;
    return *this;
}

// ─────────────────────────────────── FUNCTIONS ───────────────────────────────

void MateriaSource::learnMateria(AMateria *materia) {
    if (!materia)
        return ;

    for (int i = 0; i < 4; i++) {
        if (!_inventory[i]) {
            _inventory[i] = materia;
            std::cout << "📚 Learned new materia : " << materia->getType() << " in slot : " << i << std::endl;
            return ;
        }
    }
    std::cout << "⚠️ Inventory full, cannot learn new materia." << std::endl;

    delete materia;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; ++i) {
		if (_inventory[i] && _inventory[i]->getType() == type) {
			std::cout << "📚 Creating materia of type [" << type << "]" << std::endl;
			return _inventory[i]->clone();
		}
	}
	std::cout << "❌ Unknown materia type: [" << type << "]" << std::endl;
	return NULL;
}
