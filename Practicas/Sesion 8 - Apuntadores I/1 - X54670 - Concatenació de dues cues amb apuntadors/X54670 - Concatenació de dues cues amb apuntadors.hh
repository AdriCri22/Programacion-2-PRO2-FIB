/* Pre: c=C */
/* Post: el p.i. passa a ser la concatenació de C al paràmetre implícit, c és buida */
void concat(Cua &c) {
    if (c.longitud > 0) { // c ha de contenir algo per cambiar p.i.
        /* Si p.i. es buida llavors crea una c */
        if (longitud == 0) {
            longitud = c.longitud;
            primer_node = c.primer_node;
            ultim_node = c.ultim_node;
        } 
        /* Si p.i. no es buida llavors l'últim node apunta al primer de c */
        else {
            longitud += c.longitud;
            ultim_node->seguent = c.primer_node;
            ultim_node = c.ultim_node;
        }
        /* c deixa d'apuntar a cap iterador */
        c.longitud = 0;
        c.primer_node = NULL;
        c.ultim_node = NULL;
    }
}
