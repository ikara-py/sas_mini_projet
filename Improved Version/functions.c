#include "booksmanagment.h"

int book_count = 0;

void menu(){ // menu.
    printf("\n--Stock de livres dans une librairie--\n");
    printf("\n");
    printf("1. Ajouter un livre au stock.\n");
    printf("2. Afficher tous les livres disponibles.\n");
    printf("3. Rechercher un livre par son titre.\n");
    printf("4. Mettre a jour la quantite d'un livre.\n");
    printf("5. Supprimer un livre du stock.\n");
    printf("6. Afficher le nombre total de livres en stock.\n");
    printf("7. Supprimer un livre du stock (ISBN).\n");
    printf("8. Rechercher un livre par son ISBN.\n");
    printf("9. Rechercher un livre par son ID.\n");

    printf("0. Exit.\n");
    printf("Enter votre choice: ");
    
    return;
}


void addBook() { //add book

    if (book_count >= MAX_BOOKS) { //check if there is space for a new book
        printf("Pas d'espace disponible.\n");
        return;
    }

    printf("\nLivre #%d: \n", book_count+1); //print the endex of the book

                    //ask the user for input
    printf("\nEntrez le titre du livre: ");
    fgets(book[book_count].book_name, inner_string_size, stdin); 
    book[book_count].book_name[strcspn(book[book_count].book_name, "\n")] = 0; //remove new line

    printf("Entrez le nom de l'auteur : ");
    fgets(book[book_count].book_author, inner_string_size, stdin);
    // book[book_count].book_author[strcspn(book[book_count].book_author, "\n")] = 0;
    

    printf("Entrez le prix du livre: ");
    scanf("%f", &book[book_count].book_price);

    getchar();

    printf("Entrez la quantite en stock: ");
    scanf("%d", &book[book_count].book_quantity);

    getchar();

    printf("Entrez 13 chiffres ISBN  Utilise un tiret (-) pour séparer les nombres ");
    scanf("%d-%d-%d-%d-%d", &book[book_count].book_isbn.ig,
        &book[book_count].book_isbn.ce, 
        &book[book_count].book_isbn.na,
        &book[book_count].book_isbn.nd, 
        &book[book_count].book_isbn.cde);

    getchar();

    printf("Livre ajoute avec succes.\n");
    book_count++; //add 1 to the total of books

}


void viewBooks() {         // view the aviable books
    if (book_count == 0) {
        printf("\nAucun livre en stock.\n");   //if there was no books show a message
        return;
    }

    printf("\n--- Available Books ---\n");
    for (int i = 0; i < book_count; i++) {
        printf("\nBook #%d\n", i + 1);
        printf("Titre: %s\n", book[i].book_name);
        printf("Auteur: %s\n", book[i].book_author);
        printf("Prix: %.2f\n", book[i].book_price);
        printf("Quantite: %d\n", book[i].book_quantity);
        printf("ISBN : %d-%d-%d-%d-%d", book[i].book_isbn.ig,
        book[i].book_isbn.ce, 
        book[i].book_isbn.na,
        book[i].book_isbn.nd, 
        book[i].book_isbn.cde);
        
    }
}

void findBook() {
    if (book_count == 0) {
        printf("\nAucun livre en stock a rechercher .\n");
        return;
    }

    char search_book[inner_string_size];
    printf("\nntrez le titre a rechercher : ");    //search by name
    scanf("%[^\n]s", search_book);

    for (int i = 0; i < book_count; i++) {
        if (strcasecmp(book[i].book_name, search_book) == 0) {    //if its true
            printf("\nLivre trouve\n");
            printf("\nBook #%d\n", i + 1);
            printf("Titre: %s\n", book[i].book_name);
            printf("Auteur: %s\n", book[i].book_author);
            printf("Prix: %.2f\n", book[i].book_price);
            printf("Quantite: %d\n", book[i].book_quantity);
            printf("ISBN : %d-%d-%d-%d-%d", book[i].book_isbn.ig,
            book[i].book_isbn.ce, 
            book[i].book_isbn.na,
            book[i].book_isbn.nd, 
            book[i].book_isbn.cde);

            return;
        }
    }
    printf("Livre non trouve.\n");
}

void idfindBook() {
    if (book_count == 0) {
        printf("\nAucun livre en stock a rechercher .\n");
        return;
    }

    int idbook;
    printf("\nntrez le ID par rechercher : ");    //search by ID
    scanf("%d", &idbook);

    for (int i = 0; i < book_count; i++) {
        if (idbook == i+1) {    //if its true
            printf("\nLivre trouve\n");
            printf("\nBook #%d\n", i + 1);
            printf("Titre: %s\n", book[i].book_name);
            printf("Auteur: %s\n", book[i].book_author);
            printf("Prix: %.2f\n", book[i].book_price);
            printf("Quantite: %d\n", book[i].book_quantity);
            printf("ISBN : %d-%d-%d-%d-%d", book[i].book_isbn.ig,
            book[i].book_isbn.ce, 
            book[i].book_isbn.na,
            book[i].book_isbn.nd, 
            book[i].book_isbn.cde);

            return;
        }
    }
    printf("Livre non trouve.\n");
}

void isbnfindBook() {
    if (book_count == 0) {
        printf("\nAucun livre en stock a rechercher .\n");
        return;
    }

    int search_ig;
    int search_ce;
    int search_na;
    int search_nd;
    int search_cde;

    printf("\nntrez ISBN pour rechercher : ");    //search by ISBN
    scanf("%d-%d-%d-%d-%d", &search_ig, &search_ce, &search_na, &search_nd, &search_cde);

    for (int i = 0; i < book_count; i++) {
        if (book[i].book_isbn.ig == search_ig && book[i].book_isbn.ce == search_ce && book[i].book_isbn.na == search_na && book[i].book_isbn.cde == search_cde && book[i].book_isbn.nd == search_nd){
            printf("\nLivre trouve\n");
            printf("\nBook #%d\n", i + 1);
            printf("Titre: %s\n", book[i].book_name);
            printf("Auteur: %s\n", book[i].book_author);
            printf("Prix: %.2f\n", book[i].book_price);
            printf("Quantite: %d\n", book[i].book_quantity);
            printf("ISBN : %d-%d-%d-%d-%d", book[i].book_isbn.ig,
            book[i].book_isbn.ce, 
            book[i].book_isbn.na,
            book[i].book_isbn.nd, 
            book[i].book_isbn.cde);
            return;
        } 
    }
    printf("Livre non trouve.\n");
}


void updateQuantite() {
    char search_book[inner_string_size];
    int found = 0;

    printf("Entrez le titre du livre: ");      // search by name
    scanf("%[^\n]s", search_book);

    for (int i = 0; i < book_count; i++) {
        if (strcasecmp(book[i].book_name, search_book) == 0) {

            int new_Quantite;

            printf("Enter new Quantite: ");
            scanf("%d", &new_Quantite);

            book[i].book_quantity = new_Quantite;       // change quantity
            printf("Quantite updated successfully.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Livre non trouve.\n");   // if not found print 
    }
}


void deleteBook() {
    char search_book[inner_string_size];
    int found = 0;


    printf("Entrez le titre du livre: ");
    scanf("%[^\n]s", search_book);


    for (int i = 0; i < book_count; i++) {
        if (strcasecmp(book[i].book_name, search_book) == 0) {          //search
            book[i]= book[i+1];
            for (int j = i; j < book_count - 1; j++) {
                book[j] = book[j + 1];
            }

            book_count--;
            printf("Livre supprime avec succes.\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Livre non trouve.\n");
    }
}


void isbndeleteBook() {
    int found = 0;
    int search_ig;
    int search_ce;
    int search_na;
    int search_nd;
    int search_cde;
    printf("\nntrez ISBN pour rechercher : ");    //search by isbn
    scanf("%d-%d-%d-%d-%d", &search_ig, &search_ce, &search_na, &search_nd, &search_cde);

    for (int i = 0; i < book_count; i++) {
        if (book[i].book_isbn.ig == search_ig && book[i].book_isbn.ce == search_ce && book[i].book_isbn.na == search_na && book[i].book_isbn.cde == search_cde && book[i].book_isbn.nd == search_nd) { //search
            book[i]= book[i+1];
            for (int j = i; j < book_count - 1; j++) {
                book[j] = book[j + 1];
            }

            book_count--;
            printf("Livre supprime avec succes.\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Livre non trouve.\n");
    }
}



int count(){
    int total = 0;
    for (int i = 0; i < book_count; i++) {       //calculate how many books do we have
        total += book[i].book_quantity;
        }
    return total;
}