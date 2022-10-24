/*
 * Exemples de primitives de liste doublement chaînées
 */


using element = int;

struct maillon {
	maillon* prec;
	element val;
	maillon* suiv;
};

struct listeDoublementChainee {
	maillon* debut;
	maillon* fin;
};


// O(1)
void creer(listeDoublementChainee & l) {
	l.debut = nullptr;
	l.fin = nullptr;
}

// O(1)
bool estVide(listeDoublementChainee l) {
	return l.debut == nullptr;
}

// O(n)
unsigned int taille(listeDoublementChainee l) {
	if( l.debut == nullptr ) return 0;

	l.debut = l.debut->suiv;
	return taille(l) + 1;
}

// O(1)
void ajouter_tete(listeDoublementChainee & l,element e) {
	maillon* a = new maillon;
	a->suiv = l.debut;
	a->prec = nullptr;
	a->val = e;
	l.debut->prec = a;
	l.debut = a;
}

// O(1)
void ajouter_queue(listeDoublementChainee & l,element e) {
	maillon* a = new maillon;
	a->prec = l.fin;
	a->suiv = nullptr;
	a->val = e;
	l.fin->suiv = a;
	l.fin = a;
}

// O(n)
maillon* valeur_par_position(listeDoublementChainee l,int position) {
	while( (position > 0) && (l.debut != nullptr) ) {
		l.debut = l.debut->suiv;
	}
	return l.debut;
}

// O(n)
int position_par_valeur(listeDoublementChainee l,element valeur) {
	int i = 0;
	while( (l.debut != nullptr) && (l.debut->val != valeur) ) {
		l.debut = l.debut->suiv;
		i++;
	}
	if( l.debut == nullptr ) {
		return -1;
	} else {
		return i;
	}
}

// O(1)
void retirer_tete(listeDoublementChainee & l) {

	if( l.debut != nullptr ) {
		maillon* toDelete = l.debut;

		l.debut = l.debut->suiv;

		if( l.debut == nullptr ) {
			l.fin = nullptr;
		} else {
			l.debut->prec = nullptr;
		}
		
	}

}

// O(1)
void retirer_queue(listeDoublementChainee & l) {

	if( l.fin != nullptr ) {
		maillon* toDelete = l.fin;

		l.fin = l.fin->prec;

		if( l.fin == nullptr ) {
			l.debut = nullptr;
		} else {
			l.fin->suiv = nullptr;
		}

	}

}

// O(n)
void retirer_valeur(listeDoublementChainee & l,element e) {

	if( l.debut != nullptr ) {

		if( l.debut->val == e ) {

			maillon* toDelete = l.debut;

			// Gestion du précédent
			if( toDelete->prec == nullptr ) {
				l.debut = toDelete->suiv;
			} else {
				toDelete->prec->suiv = toDelete->suiv;
			}

			// Gestion du suivant
			if( toDelete->suiv == nullptr ) {
				l.fin = toDelete->prec;
			} else {
				toDelete->suiv->prec = toDelete->prec;
			}

			delete toDelete;

		} else {

			listeDoublementChainee n = l;
			n.debut = n.debut->suiv;
			retirer_valeur(n,e);

		}

	}
}


// O(n)
void retirer_position(listeDoublementChainee & l,unsigned int position) {

	if( l.debut != nullptr ) {

		if( position == 0 ) {

			maillon* toDelete = l.debut;

			// Gestion du précédent
			if( toDelete->prec == nullptr ) {
				l.debut = toDelete->suiv;
			} else {
				toDelete->prec->suiv = toDelete->suiv;
			}

			// Gestion du suivant
			if( toDelete->suiv == nullptr ) {
				l.fin = toDelete->prec;
			} else {
				toDelete->suiv->prec = toDelete->prec;
			}

			delete toDelete;

		} else {

			listeDoublementChainee n = l;
			n.debut = n.debut->suiv;
			retirer_valeur(n,position-1);

		}

	}
}

// O(n)
void vider(listeDoublementChainee & l) {
	if( l.debut != nullptr ) {
		maillon* k = l.debut;
		l.debut = l.debut->suiv; 
		vider( l );
		delete k;
	}
}