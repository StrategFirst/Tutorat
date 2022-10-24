/*
 * Exemples de primitives d'une pile via une liste simplement chaînée
 */


using element = int;

struct maillon {
	maillon* suiv;
	element val;
};
using pile = maillon*;


// O(1)
void creer(pile & l) {
	l = nullptr;
}

// O(1)
bool estVide(pile l) {
	return l == nullptr;
}

// O(1)
void empiler(pile & l,element e) {
	pile a = new maillon;
	a->suiv = l;
	a->val = e;
	l = a;
}

// O(1)
element depiler(pile & l) {
	if( l != nullptr ) {
		pile a = l;
		element e = a->val;
		l = l->suiv;
		delete a;
		return e;
	}
}

// O(1)
element sommet(pile & l) {
	return l->val;
}

// O(n)
void vider(pile & l) {
	if( l != nullptr ) {
		vider( l->suiv );
		delete l;
	}
}