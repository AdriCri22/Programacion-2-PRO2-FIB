    static void sum_elem(node_arbreGen* a, const T& x, int &sum) {
        if (a != NULL) {
            if (a->info == x) sum++;
            for (int i = 0; i < a->seg.size(); i++)
                sum_elem(a->seg[i], x, sum);
        }
    }

    /* Pre: cert */
    /* Post: el resultat indica el nombre d'aparicions de x en el p.i. */
    int freq(const T& x) const {
        int sum = 0;
        sum_elem(primer_node, x, sum);
        return sum;
    }
