#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

#include <iostream>

int main() {
	std::cout << "🔧 Initialisation de la source de materia..." << std::endl;
	IMateriaSource* src = new MateriaSource();

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	// Test : trop de learnMateria
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure()); // Ignoré car inventaire plein

	std::cout << "\n🧙 Création du personnage 'me'..." << std::endl;
	ICharacter* me = new Character("me");

	std::cout << "\n🧪 Création de materia depuis la source..." << std::endl;
	AMateria* tmp1 = src->createMateria("ice");
	AMateria* tmp2 = src->createMateria("cure");
	AMateria* tmp3 = src->createMateria("fire"); // Inconnue

	me->equip(tmp1); // slot 0
	me->equip(tmp2); // slot 1
	me->equip(tmp3); // NULL, rien ne se passe

	std::cout << "\n🧍 Création du personnage 'bob'..." << std::endl;
	ICharacter* bob = new Character("bob");

	std::cout << "\n✨ Utilisation des Materias..." << std::endl;
	me->use(0, *bob); // ice
	me->use(1, *bob); // cure
	me->use(2, *bob); // vide

	std::cout << "\n❌ Unequip de la materia slot 1..." << std::endl;
	me->unequip(1); // Ne delete pas la materia
	delete tmp2;     // À gérer manuellement

	std::cout << "\n🧬 Test de copie profonde..." << std::endl;
	Character copy = *(dynamic_cast<Character*>(me));
	copy.use(0, *bob); // ice
	copy.use(1, *bob); // slot 1 est vide car tmp2 a été unequip

	std::cout << "\n🧹 Nettoyage..." << std::endl;
	delete bob;
	delete me;
	delete src;

	return 0;
}
