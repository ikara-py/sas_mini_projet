#include "booksmanagment.h"
#include <stdio.h>



int main() {
    int choice;

    while (1) {
        menu();
        scanf("%d", &choice);
        while(getchar() !='\n');

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                viewBooks();
                break;
            case 3:
                findBook();
                break;
            case 4:
                updateQuantite();
                break;
            case 5:
                deleteBook();
                break;
            case 6:
                printf("\nNombre total de livres en stock: %d\n", count());
                break;
            case 7:
                isbndeleteBook();
                break;
            case 8:
                isbnfindBook();
                break;
            case 9:
                idfindBook();
                break;
            case 0:
                printf("Fermeture du programme. Au revoir !\n");
                return 0;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }
    }
    return 0;
}