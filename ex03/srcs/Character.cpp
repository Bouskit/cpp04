#include "Character.hpp"

// ─────────────────────────────────── CONSTRUCTORS ───────────────────────────────────

Character::Character() {
    _name = "?";
    for (int i = 0; i < 4; i++) {
        _inventory[i] = NULL;
    }
    for (int i = 0; i < 100; i++) {
        _unequipped[i] = NULL;
    }
    std::cout << "🤴🏻 Character created" << std::endl;
}

Character::Character(const Character& other) {
    _name = other._name;
    for (int i = 0; i < 4; i++) {
        if (other._inventory[i])
            _inventory[i] = other._inventory[i]->clone();
        else 
            _inventory[i] = NULL;
    }
    for (int i = 0; i < 100; i++) {
        _unequipped[i] = NULL;
    }
    std::cout << "🤴🏻 Copy of Character" << std::endl;
}

// ─────────────────────────────────── DESTRUCTORS ────────────────────────────────────

Character::~Character() {
    for (int i = 0; i < 4; ++i)
        delete _inventory[i];
    for (int i = 0; i < 100; ++i)
        delete _unequipped[i];
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
    }
    std::cout << "🤴🏻 Affectation = of Character" << std::endl;
    return *this;
}

// ─────────────────────────────────── SETTERS / GETTERS ───────────────────────────────

std::string const & Character::getName() const {
    return _name;
}

// ─────────────────────────────────── SETTERS / GETTERS ───────────────────────────────

void Character::equip(AMateria *m) {
    if (!m) {
        return ;
    }

    for (int i = 0; i < 4; i++) {
        if (!_inventory[i]) {
            _inventory[i] = m;
            return ;
        }
    }
}

void Character::unequip(int idx) {
    if (idx >= 0 && idx < 4) {
        if (_inventory[idx]) {
            for (int i = 0; i < 100; ++i) {
                if (!_unequipped[i]) {
                _unequipped[i] = _inventory[idx];
                break;
                }
            }
            _inventory[idx] = NULL;
        }
        else
            std::cout << "⚠️ Nothing to unequip" << std::endl;
    }
    else
        std::cout << "⚠️ The inventory has just 4 places" << std::endl;
}

void Character::use(int idx, ICharacter& target) {
    if (idx >= 0 && idx < 4) {
        if (_inventory[idx]) {
            _inventory[idx]->use(target);
        }
        else
            std::cout << "⚠️ Nothing to use" << std::endl;
    }
    else 
        std::cout << "⚠️ The inventory has just 4 places" << std::endl;
}