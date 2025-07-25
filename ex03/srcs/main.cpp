#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

#include <iostream>

void printSeparator(std::string title) {
	std::cout << "\n🔻🔻🔻 " << title << " 🔻🔻🔻\n" << std::endl;
}

int main() {
	printSeparator("INITIALISATION");
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	// Inventaire plein → devrait delete la materia automatiquement
	src->learnMateria(new Cure()); // 🔥 test overflow

	printSeparator("CREATION DE PERSONNAGES");
	ICharacter* me = new Character("Hero");
	ICharacter* dummy = new Character("Dummy");

	printSeparator("CREATION DE MATERIAS");
	AMateria* ice = src->createMateria("ice");
	AMateria* cure = src->createMateria("cure");
	AMateria* ghost = src->createMateria("ghost"); // 🔥 inconnu, NULL

	me->equip(ice);      // slot 0
	me->equip(cure);     // slot 1
	me->equip(NULL);     // 🔥 test de protection
	me->equip(ghost);
	me->equip(src->createMateria("ice"));  // slot 2
	me->equip(src->createMateria("cure")); // slot 3
	me->equip(src->createMateria("cure")); // 🔥 test overflow inventaire

	printSeparator("UTILISATION DES MATERIAS");
	me->use(0, *dummy);  // ice
	me->use(1, *dummy);  // cure
	me->use(2, *dummy);  // ice
	me->use(3, *dummy);  // cure
	me->use(4, *dummy);  // 🔥 index invalide
	me->use(-1, *dummy); // 🔥 index invalide

	printSeparator("UNEQUIP & RÉUTILISATION");
	me->unequip(1);      // remove cure
	me->use(1, *dummy);  // 🔥 slot vide
	me->equip(src->createMateria("ice"));  // reprendre un slot libre
	me->use(1, *dummy);  // ice

	printSeparator("COPIE PROFONDE");
	Character deepCopy = *(dynamic_cast<Character*>(me));
	deepCopy.use(0, *dummy); // ice
	deepCopy.use(1, *dummy); // ice (nouvel objet)
	deepCopy.unequip(0);
	deepCopy.use(0, *dummy); // 🔥 vide

	printSeparator("ASSIGNATION =");
	Character assigned("Newbie");
	assigned = *(dynamic_cast<Character*>(me));
	assigned.use(0, *dummy); // ice
	assigned.unequip(0);
	assigned.use(0, *dummy); // 🔥 vide

	printSeparator("CLEANUP");
	delete me;
	delete dummy;
	delete src;

	std::cout << "\n✅ Fin du test : aucune fuite mémoire attendue." << std::endl;
	return 0;
}

