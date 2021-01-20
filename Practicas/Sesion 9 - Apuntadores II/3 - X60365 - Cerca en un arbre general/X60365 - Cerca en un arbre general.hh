    static bool buscar_elem(node_arbreGen* a, const T& x) {
        if (a != NULL) {
            if (a->info == x) return true;
            else {
                for (int i = 0; i < a->seg.size(); i++) {
                    if (buscar_elem(a->seg[i], x)) return true;
                }
            }
        }
        return false;
    }

    /* Pre: cert */
    /* Post: el resultat indica si x es troba al p.i. o no */
    bool buscar(const T& x) const {
        return buscar_elem(primer_node, x);
    }
