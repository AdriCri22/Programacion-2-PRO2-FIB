    /* Pre: cert */
    /* Post: el resultat és una llista que conté els mateixos 
            elements que el p.i. tal que tots els més petits o iguals 
            que x al p.i. precedeixen als més grans que x al p.i. però 
            sempre respectant l'ordre que hi havia entre ells al p.i. 
            L'element actual de la llista retornada és el primer dels 
            més grans que x, si existeix, sinó es situa a la detra del 
            tot. El p.i. no es modifica */
    Llista reorganitzar_out(const T& x) const {
        Llista l;
        if (longitud == 0) return l;
        
        node_llista* ultim_menor = NULL;
        l.act = l.ultim_node = l.primer_node = NULL;
        l.longitud = longitud;
        node_llista* rec = primer_node;
        while (rec != NULL) {
            if (rec->info <= x) {
                if (ultim_menor == NULL) {
                    ultim_menor = new node_llista;      
                    l.primer_node = ultim_menor;  
                    l.primer_node->ant = NULL;
                } else {
                    ultim_menor->seg = new node_llista; 
                    (ultim_menor->seg)->ant = ultim_menor;
                    ultim_menor = ultim_menor->seg;
                }  
                ultim_menor->info = rec->info;
            } else {
            if (l.ultim_node == NULL) {
                    l.ultim_node = new node_llista;        
                    l.act = l.ultim_node; 
                    l.act->ant = NULL; 
                } else {
                    l.ultim_node->seg = new node_llista; 
                    (l.ultim_node->seg)->ant = l.ultim_node; 
                    l.ultim_node = l.ultim_node->seg; 
                }
                l.ultim_node->info = rec->info;
            }
            rec = rec->seg;
        }
        if (l.primer_node == NULL) 
            l.primer_node = l.act;
        else if (l.act == NULL) 
            l.ultim_node = ultim_menor;
        else {
            ultim_menor->seg = l.act; 
            l.act->ant = ultim_menor; 
        }
        l.ultim_node->seg = NULL;
        return l; 
    }
