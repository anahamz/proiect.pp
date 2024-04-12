#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct istoric{
 char isto[100];
}istoric[200];

int main()
{

    char *arr[100];
    int count = 0;
     FILE* file = fopen("istoric.txt", "r");

     char *currentline;

     currentline = (char *)malloc(100 * sizeof(char));
     size_t len=0;
     while (  fgets(currentline,100, file) != NULL)
        {

        arr[count] = currentline;
        count++;
        currentline = (char *)malloc(100 * sizeof(char));

        }

    fclose(file);
    while (1 == 1)
    {

        system("cls");
        printf("-- MENIU PRINCIPAL --\n");
        printf("1. Vizualizare restaurante\n");
        printf("2. Istoric comenzi\n");
        printf("3. Iesiti\n");

        int choice;
        do
        {
            printf("Introdu varianta dorita :");
            scanf("%d", &choice);
        } while (choice < 1 || choice > 3);

        system("cls");

        if (choice == 1)
        {
            while (1 == 1)
            {
                system("cls");
                printf("Selectati produsul dorit: \n");
                printf("1. Zaza\n");
                printf("2. Mamamia\n");
                printf("3. Pizza\n");
                printf("0. Iesiti\n");
                int choice2;
                do
                {
                    printf("Introdu varianta dorita :");
                    scanf("%d", &choice2);

                } while (choice2 < 0 || choice2 > 3);
                system("cls");
                // Zaza
                if (choice2 == 1)
                {
                    while (1 == 1)
                    {
                        system("cls");
                        printf("Selectati produsul dorit: \n");
                        printf("1. salata\n");
                        printf("2. paste\n");
                        printf("3. pizza\n");
                        printf("0. Intoarcere la lista restaurante\n");
                        int choice3;
                        do
                        {
                            printf("Introdu varianta dorita :");
                            scanf("%d", &choice3);
                            switch (choice3)
                            {
                            case 0:
                                break;
                            case 1:
                                {arr[count] = "Zaza, salata";
                                count++;

                                FILE *pFile2=fopen("istoric.txt", "a");
                                fprintf(pFile2, "Zaza, salata\n");
                                fclose(pFile2);

                                break;}
                            case 2:
                                {arr[count] = "Zaza, paste";
                                count++;
                                FILE *pFile2=fopen("istoric.txt", "a");
                                fprintf(pFile2, "Zaza, paste\n");
                                fclose(pFile2);
                                break;}
                            case 3:
                                {arr[count] = "Zaza, pizza";
                                count++;
                                FILE *pFile2=fopen("istoric.txt", "a");
                                fprintf(pFile2, "Zaza, pizza\n");
                                fclose(pFile2);
                                break;}
                            }
                        } while (choice3 < 0 || choice3 > 3);

                        system("cls");
                        break;
                    }
                }
                // Mamamia
                if (choice2 == 2)
                {
                    while (1 == 1)
                    {
                        system("cls");
                        printf("Selectati produsul dorit: \n");
                        printf("1. shaorma\n");
                        printf("2. hamburger\n");
                        printf("3. pizza\n");
                        printf("0. Intoarcere la lista restaurante\n");
                        int choice4;
                        do
                        {
                            printf("Introdu varianta dorita :\n");
                            scanf("%d", &choice4);
                            switch (choice4)
                            {
                            case 0:
                                break;
                            case 1:
                                {arr[count] = "Mamamia, shaorma";
                                count++;

                                FILE *pFile2=fopen("istoric.txt", "a");
                                fprintf(pFile2, "Mamamia, shaorma\n");
                                fclose(pFile2);
                                break;}
                            case 2:
                                {arr[count] = "Mamamia, hamburger";
                                count++;

                                FILE *pFile2=fopen("istoric.txt", "a");
                                fprintf(pFile2, "Mamamia, hamburger\n");
                                fclose(pFile2);
                                break;}
                            case 3:
                                {arr[count] = "Mamamia, pizza";
                                count++;

                                FILE *pFile2=fopen("istoric.txt", "a");
                                fprintf(pFile2, "Mamamia, pizza\n");
                                fclose(pFile2);
                                break;}
                            }
                        } while (choice4 < 0 || choice4 > 3);
                        system("cls");
                        break;
                    }
                }
                // Pizza
                if (choice2 == 3)
                {
                    char temp;
                    scanf("%c", &temp);
                    char *ingrediente;
                    ingrediente = (char *)malloc(1000 * sizeof(char));
                    int lungime;
                    printf("Introdu ingriedente :\n");
                    scanf("%[^\n]", ingrediente);
                    printf("introdu lungimea :");
                    scanf("%d", &lungime);
                    char charLungime[10];
                    char descriere[10000] = "";
                    sprintf(charLungime, "%d", lungime);
                    strcat(descriere, "Pizza:");
                    strcat(descriere, ingrediente);
                    strcat(descriere, ",Lungime: ");
                    strcat(descriere, charLungime);
                    arr[count] = &descriere;
                    count++;

                    FILE *pFile2=fopen("istoric.txt", "a");
                    fprintf(pFile2, "%s\n", &descriere);
                    fclose(pFile2);
                }
                if (choice2 == 0)
                {
                    break;
                }
            }

            char *locatie;
            locatie = (char *)malloc(1000 * sizeof(char));
            char temp;
            printf("Finalizare comanda: Introduceti locatie :");
            scanf("%c", &temp);
            scanf("%[^\n]", locatie);
            arr[count] = locatie;
            count++;
            arr[count] = "----------";
            count++;
            FILE *pFile2=fopen("istoric.txt", "a");
                    fprintf(pFile2, "Locatie: %s\n", locatie);
                    fclose(pFile2);
        }
        else if (choice == 2)
        {
            printf("Istoric comanda:\n");
            for (int i = 0; i < count; i++)
            {
                printf("%s\n", arr[i]);
            }
            printf("Apasati enter pentru a reveni la meniul anterior:\n");
            char locatie[1000];
            scanf("%s", &locatie);
        }
        else if (choice == 3)
        {
            break;
        }
    }
    return 0;
}
