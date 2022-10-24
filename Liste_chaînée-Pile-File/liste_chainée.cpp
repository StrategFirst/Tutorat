/*
 * Exemples de primitives de liste simplement chaînée
 */


using element = int;

struct maillon {
	maillon* suiv;
	element val;
};
using liste = maillon*;


// O(1)
void creer(liste & l) {
	l = nullptr;
}

// O(1)
bool estVide(liste l) {
	return l == nullptr;
}

// O(n)
unsigned int taille(liste l) {
	if( l == nullptr ) return 0;
	else return taille(l->suiv) + 1;
}

// O(1)
void ajouter_tete(liste & l,element e) {
	liste a = new maillon;
	a->suiv = l;
	a->val = e;
	l = a;
}

// O(n)
void ajouter_queue(liste & l,element e) {
	if( estVide(l) ) ajouter_tete(l,e);
	else {
		liste k = l;

		while( k->suiv != nullptr ) {
			k = k->suiv;
		}

		liste a = new maillon;
		a->suiv = nullptr;
		a->val = e;
		k->suiv = a;
	}
}

// O(n)
void ajouter_position(liste & l,int position,element e) { /* Ajoute en fin si position supérrieur à la taille */
	
	if( l == nullptr ) {
		ajouter_tete(l,e);
	} else {

		liste A = l;

		while( (A->suiv != nullptr) && (position > 0) ) {
			A = A->suiv;
			position--;
		}

		liste nv = new maillon;
		nv->suiv = A->suiv;
		nv->val = e;
		A->suiv = nv;
	}

}

// O(n)
liste valeur_par_position(liste l,int position) {
	while( (position > 0) && (l != nullptr) ) {
		l = l->suiv;
	}
	return l;
}

// O(n)
int position_par_valeur(liste l,element valeur) {
	int i = 0;
	while( (l != nullptr) && (l->val != valeur) ) {
		l = l->suiv;
		i++;
	}
	if( l == nullptr ) {
		return -1;
	} else {
		return i;
	}
}

// O(1)
void retirer_tete(liste & l) {
	if( l != nullptr ) {
		liste a = l;
		l = l->suiv;
		delete a;
	}
}

// O(n)
void retirer_queue(liste & l) {

	if( l != nullptr ) {
		liste A = l;
		liste B = l->suiv;

		while( B != nullptr ) {
			A = A->suiv;
			B = B->suiv;
		}

		A->suiv = nullptr;
		delete B;
	}

}

// O(n)
void retirer_valeur(liste & l,element e) {

	if( l != nullptr ) {

		if( l->val == e ) { retirer_tete(l); }
		else {

			liste A = l;
			liste B = l->suiv;

			while( (B != nullptr) && (B->val != e ) ) {
				A = A->suiv;
				B = B->suiv;
			}

			if( B != nullptr ) {
				A->suiv = B->suiv;
				delete B;
			}

		}
	}
}


// O(n)
void retirer_position(liste & l,int position) {
	if( l != nullptr ) {

		if( position == 0 ) { retirer_tete(l); }
		else {

			liste A = l;
			liste B = l->suiv;

			while( (B != nullptr) && (position > 0) ) {
				A = A->suiv;
				B = B->suiv;
				position--;
			}

			if( B != nullptr ) {
				A->suiv = B->suiv;
				delete B;
			}

		}
	}
}

// O(n)
void vider(liste & l) {
	if( l != nullptr ) {
		vider( l->suiv );
		delete l;
	}
}