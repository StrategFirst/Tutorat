/*
 * Exemples de primitives d'une file via une liste simplement chaînée
 */


using element = int;

struct maillon {
	maillon* suiv;
	element val;
};
using file = maillon*;


// O(1)
void creer(file & l) {
	l = nullptr;
}

// O(1)
bool estVide(file l) {
	return l == nullptr;
}

// O(n)
unsigned int taille(file l) {
	if( l == nullptr ) return 0;
	else return taille(l->suiv) + 1;
}

// O(1)
void ajouter(file & l,element e) {
	file a = new maillon;
	a->suiv = l;
	a->val = e;
	l = a;
}


// O(n)
element retirer(file & l) {

	if( l != nullptr ) {
		file A = l;
		file B = l->suiv;

		while( B != nullptr ) {
			A = A->suiv;
			B = B->suiv;
		}

		A->suiv = nullptr;
		element e = B->val;
		delete B;
		return e;
	}

}

// O(n)
void vider(file & l) {
	if( l != nullptr ) {
		vider( l->suiv );
		delete l;
	}
}