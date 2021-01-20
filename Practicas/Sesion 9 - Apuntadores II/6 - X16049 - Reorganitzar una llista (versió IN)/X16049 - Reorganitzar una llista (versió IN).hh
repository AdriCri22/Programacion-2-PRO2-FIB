    /* Pre: p.i. = L */
    /* Post: el p.i. conté els mateixos elements que L però
            reorganitzats de manera que primer apareixen els més petits
            o iguals que x, en el mateix ordre que en L, seguits pels 
            més grans que x, en el mateix ordre que en L.
            L'element actual del p.i. és el primer del més grans que x, si
            existeix, sinó es situa a la dreta de tot */
    void reorganitzar_in(const T& x) {
        if (longitud == 0) return;
        node_llista* n = primer_node;
        node_llista* menor = NULL;
        node_llista* major = NULL;
        while (n != NULL) {
            if (n->info <= x) {  //més petit que x
                if (menor == NULL) primer_node = n;
                else {
                    n->ant = menor;
                    menor->seg = n;
                }
                menor = n;
            } else if (n->info > x) { //més gran que x
                if (major == NULL) act = n;
                else {
                    major->seg = n;
                    n->ant = major;
                }
                major = n;
            }
            n = n->seg;
        }
        
        if (major != NULL) ultim_node = major;
        else ultim_node = menor;
        
        if (major != NULL and menor != NULL) {
            menor->seg = act;
            act->ant = menor;
        }
        ultim_node->seg = NULL;
        primer_node->ant = NULL;
    }
    
    void escriure() {
        node_llista* n = primer_node;
        while (n != NULL) {
            if (n == primer_node) cout << n->info << ' ' << n->seg->info << endl;
            else if (n == ultim_node) cout << n->info << ' ' << n->ant->info << endl;
            else cout << n->info << ' ' << n->seg->info << ' ' << n->ant->info << endl;
            n = n->seg;
        }
    }
