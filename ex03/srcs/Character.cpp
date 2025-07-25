#include "Character.hpp"

// ─────────────────────────────────── CONSTRUCTORS ───────────────────────────────────

Character::Character() : _name("?") {
    for (int i = 0; i < 4; i++) _inventory[i] = NULL;
    for (int i = 0; i < 100; i++) _unequipped[i] = NULL;
    std::cout << "🤴🏻 Character : " << _name << " created" << std::endl;
}

Character::Character(const std::string& name) : _name(name) {
    for (int i = 0; i < 4; i++) _inventory[i] = NULL;
    for (int i = 0; i < 100; i++) _unequipped[i] = NULL;
    std::cout << "🤴🏻 Character : " << _name << " created" << std::endl;
}

Character::Character(const Character& other) : _name(other._name) {
    for (int i = 0; i < 4; i++) {
        if (other._inventory[i])
            _inventory[i] = other._inventory[i]->clone();
        else
            _inventory[i] = NULL;
    }

    for (int i = 0; i < 100; i++) {
        if (other._unequipped[i])
            _unequipped[i] = other._unequipped[i]->clone();
        else
            _unequipped[i] = NULL;
    }

    std::cout << "🤴🏻 Copy of Character" << std::endl;
}

// ─────────────────────────────────── DESTRUCTORS ────────────────────────────────────

Character::~Character() {
    for (int i = 0; i < 4; i++) {
        delete _inventory[i];
        _inventory[i] = NULL;
    }

    for (int i = 0; i < 100; i++) {
        delete _unequipped[i];
        _unequipped[i] = NULL;
    }

    std::cout << "🤴🏻 Destruction of Character" << std::endl;
}

// ───────────────────────────────────── OPERATORS ─────────────────────────────────────

Character& Character::operator=(const Character& other) {
    if (this != &other) {
        _name = other._name;

        for (int i = 0; i < 4; i++) {
            delete _inventory[i];
            if (other._inventory[i])
                _inventory[i] = other._inventory[i]->clone();
            else
                _inventory[i] = NULL;
        }

        for (int i = 0; i < 100; i++) {
            delete _unequipped[i];
            if (other._unequipped[i])
                _unequipped[i] = other._unequipped[i]->clone();
            else
                _unequipped[i] = NULL;
        }
    }

    std::cout << "🤴🏻 Affectation = of Character" << std::endl;
    return *this;
}

// ─────────────────────────────────── SETTERS / GETTERS ───────────────────────────────

std::string const & Character::getName() const {
    return _name;
}

// ─────────────────────────────────── FUNCTIONS ───────────────────────────────

void Character::equip(AMateria *m) {
    if (!m)
        return;

    for (int i = 0; i < 4; i++) {
        if (!_inventory[i]) {
            _inventory[i] = m;
            return;
        }
    }
    std::cout << "⚠️ Inventory full, cannot equip materia" << std::endl;
    delete m;
}

void Character::unequip(int idx) {
    if (idx >= 0 && idx < 4 && _inventory[idx]) {
        for (int i = 0; i < 100; i++) {
            if (!_unequipped[i]) {
                _unequipped[i] = _inventory[idx];
                break;
            }
        }
        _inventory[idx] = NULL;
    } else {
        std::cout << "⚠️ Invalid unequip index or empty slot" << std::endl;
    }
}

void Character::use(int idx, ICharacter& target) {
    if (idx >= 0 && idx < 4 && _inventory[idx]) {
        _inventory[idx]->use(target);
    } else {
        std::cout << "⚠️ Invalid index or empty materia" << std::endl;
    }
}
