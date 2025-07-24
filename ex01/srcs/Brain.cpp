#include "Brain.hpp"

// ─────────────────────────────────── CONSTRUCTORS ───────────────────────────────────

Brain::Brain() {
    for(int i = 0; i < 100; i++) {
        _ideas[i] = "[empty]";
    }
    std::cout << "🧠 Brain created" << std::endl;
}

Brain::Brain(const Brain& other) {
    for(int i = 0; i < 100; i++) {
        _ideas[i] = other._ideas[i];
    }
    std::cout << "🧠 Brain copied" << std::endl;
}

// ─────────────────────────────────── DESTRUCTORS ────────────────────────────────────

Brain::~Brain() {
    std::cout << "🧠 Brain destroyed" << std::endl;
}

// ───────────────────────────────────── OPERATORS ─────────────────────────────────────

Brain& Brain::operator=(const Brain& other) {
    if (this != &other) {
        for(int i = 0; i < 100; i++) {
        _ideas[i] = other._ideas[i];
        }
    }
    std::cout << "🧠 Brain = Brain" << std::endl;
    return *this;
}