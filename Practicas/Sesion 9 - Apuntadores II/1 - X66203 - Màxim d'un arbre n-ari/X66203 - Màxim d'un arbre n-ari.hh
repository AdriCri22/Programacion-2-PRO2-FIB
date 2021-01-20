void trobar_min(node_arbreNari* a, T &max) const {
    if (a != NULL) {
        if (max < a->info) 
            max = a->info;
        for (int i = 0; i < a->seg.size(); i++)
            trobar_min(a->seg[i], max);
    }
}

/* Pre: el p.i. no és buit */
/* Post: el resultat indica el valor més gran que conté el p.i. */
T maxim() const {
    T max = primer_node->info;
    trobar_min(primer_node, max);
    return max;
}
