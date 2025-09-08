#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BOOKS 50
#define slots 4 
#define inner_string_size 50

char book[MAX_BOOKS][slots][inner_string_size];
int book_count = 0;
int total;

void addBook();
void findBook();
void viewBooks();
void updateQuantite();
void deleteBook();
void menu();
int count();

int main() {
    int choice;

    while (1) {
        menu();
        scanf("%d", &choice);
        getchar();

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
            case 0:
                printf("Fermeture du programme. Au revoir !\n");
                return 0;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }
    }
    return 0;
}

void menu(){
    printf("\n--Stock de livres dans une librairie--\n");
    printf("\n");
    printf("1. Ajouter un livre au stock.\n");
    printf("2. Afficher tous les livres disponibles.\n");
    printf("3. Rechercher un livre par son titre.\n");
    printf("4. Mettre a jour la quantite d'un livre.\n");
    printf("5. Supprimer un livre du stock.\n");
    printf("6. Afficher le nombre total de livres en stock.\n");
    printf("0. Exit.\n");
    printf("Enter votre choice: ");
    
    return;
}

void addBook() {
    if (book_count >= MAX_BOOKS) {
        printf("Pas d'espace disponible.\n");
        return;
    }
    printf("\nLivre #%d: \n", book_count+1);

    printf("\nEntrez le titre du livre: ");
    fgets(book[book_count][0], inner_string_size, stdin);
    book[book_count][0][strcspn(book[book_count][0], "\n")] = 0;

    printf("Entrez le nom de l'auteur : ");
    fgets(book[book_count][1], inner_string_size, stdin);
    book[book_count][1][strcspn(book[book_count][1], "\n")] = 0;

    printf("Entrez le prix du livre: ");
    fgets(book[book_count][2], inner_string_size, stdin);
    book[book_count][2][strcspn(book[book_count][2], "\n")] = 0;

    printf("Entrez la quantite en stock: ");
    fgets(book[book_count][3], inner_string_size, stdin);
    book[book_count][3][strcspn(book[book_count][3], "\n")] = 0;

    printf("Livre ajoute avec succes.\n");
    book_count++;
}

void viewBooks() {
    if (book_count == 0) {
        printf("\nAucun livre en stock.\n");
        return;
    }

    printf("\n--- Available Books ---\n");
    for (int i = 0; i < book_count; i++) {
        printf("\nBook #%d\n", i + 1);
        printf("  Titre: %s\n", book[i][0]);
        printf("  Auteur: %s\n", book[i][1]);
        printf("  Prix: %s\n", book[i][2]);
        printf("  Quantite: %s\n", book[i][3]);
    }
}

void findBook() {
    if (book_count == 0) {
        printf("\nAucun livre en stock a rechercher .\n");
        return;
    }

    char search_book[inner_string_size];
    printf("\nntrez le titre a rechercher : ");
    fgets(search_book, inner_string_size, stdin);
    search_book[strcspn(search_book, "\n")] = 0;

    for (int i = 0; i < book_count; i++) {
        if (strcmp(book[i][0], search_book) == 0) {
            printf("\nLivre trouve\n");
            printf("Titre: %s\n", book[i][0]);
            printf("Auteur: %s\n", book[i][1]);
            printf("Prix: %s\n", book[i][2]);
            printf("Quantite: %s\n", book[i][3]);
            return;
        }
    }
    printf("Livre non trouve.\n");
}

void updateQuantite() {
    char search_title[inner_string_size];
    int found = 0;

    printf("Entrez le titre du livre: ");
    fgets(search_title, inner_string_size, stdin);
    search_title[strcspn(search_title, "\n")] = 0;

    for (int i = 0; i < book_count; i++) {
        if (strcmp(book[i][0], search_title) == 0) {
            char new_Quantite[inner_string_size];
            printf("Enter new Quantite: ");
            fgets(new_Quantite, inner_string_size, stdin);
            new_Quantite[strcspn(new_Quantite, "\n")] = 0;

            strcpy(book[i][3], new_Quantite);
            printf("Quantite updated successfully.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Livre non trouve.\n");
    }
}

void deleteBook() {
    char search_title[inner_string_size];
    int found = 0;

    printf("Entrez le titre du livre: ");
    fgets(search_title, inner_string_size, stdin);
    search_title[strcspn(search_title, "\n")] = 0;

    for (int i = 0; i < book_count; i++) {
        if (strcmp(book[i][0], search_title) == 0) {
            for (int j = i; j < book_count - 1; j++) {
                for (int k = 0; k < slots; k++) {
                    strcpy(book[j][k], book[j + 1][k]);
                }
            }
            book_count--;
            printf("Livre supprimé avec succes.\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Livre non trouvé.\n");
    }
}

int count(){
    int total = 0;
    for (int i = 0; i < book_count; i++) {
        total += atoi(book[i][3]);
        }
    return total;
}