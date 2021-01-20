static void suma_arb(node_arbreNari* a, node_arbreNari* &n, int &suma) {
    if (a == NULL) suma = 0;
    else {
        suma = a->info;
        n = new node_arbreNari;
        n->seg = vector<node_arbreNari*>(a->seg.size());
        for (int i = 0; i < a->seg.size(); i++) {
            node_arbreNari* aux = NULL;
            int suma2 = 0;
            suma_arb(a->seg[i], aux, suma2);
            suma += suma2;
            n->seg[i] = aux;
        }
        
        n->info = suma;
    }
}

/* Pre: cert */
/* Post: asum és un arbre amb la mateixa estructura que el p.i.
         i cada node és la suma del node corresponent al p.i
         i tots els seus descendents al p.i. */
void arbsuma(ArbreNari& asum) const {
    int suma = 0;
    asum.N = N;
    suma_arb(primer_node, asum.primer_node, suma);
}
