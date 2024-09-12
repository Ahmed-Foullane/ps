#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct
{
    int jour, mois, annee;
} DateDeNaissance;

typedef struct
{
    char dpart[20];
    float noteGenerale;
} Departement;

typedef struct
{
    char nom[30], prenom[30];
    int numeroUnique;
    DateDeNaissance date;
    Departement departement;
} Etudiants;

Etudiants etudiants[200];
int currentIndex = 0;

void ajouterEtudiant()
{
    int choix;
    float noteGenerale;
    if (currentIndex >= 200)
    {
        printf("La liste des étudiants est pleine.\n");
        return;
    }

    printf("Entrez le prenom : ");
    scanf("%s", etudiants[currentIndex].prenom);

    printf("Entrez le nom : ");
    scanf("%s", etudiants[currentIndex].nom);

    int jour, mois, annee;

    // Input day
    printf("Entrez le jour (1-31) : ");
    scanf("%d", &jour);
    while (jour < 1 || jour > 31) {
        printf("Jour invalide. Entrez un nombre entre 1 et 31 : ");
        scanf("%d", &jour);
    }

    // Input month
    printf("Entrez le mois (1-12) : ");
    scanf("%d", &mois);
    while (mois < 1 || mois > 12) {
        printf("Mois invalide. Entrez un nombre entre 1 et 12 : ");
        scanf("%d", &mois);
    }

    // Input year
    printf("Entrez l'annee (1900-2005) : ");
    scanf("%d", &annee);
    while (annee < 1900 || annee > 2005) {  // Assuming a reasonable year range
        printf("Annee invalide. Entrez une annee valide (1900-2005) : ");
        scanf("%d", &annee);
    }

    // Store the date in the structure
    etudiants[currentIndex].date.jour = jour;
    etudiants[currentIndex].date.mois = mois;
    etudiants[currentIndex].date.annee = annee;

    printf("Entrez le departement.\n");
    printf("1. Pour MATH\n");
    printf("2. Pour PC\n");
    printf("3. Pour SVT\n");
    printf("Entrez votre choix : ");
    scanf("%d", &choix);
    while (choix < 1 || choix > 3)
    {
        printf("\nChoix invalide. Entrez un nombre entre 1 et 3 : ");
        scanf("%d", &choix);
    }

    switch (choix)
    {
    case 1:
        strcpy(etudiants[currentIndex].departement.dpart, "MATH");
        break;
    case 2:
        strcpy(etudiants[currentIndex].departement.dpart, "PC");
        break;
    case 3:
        strcpy(etudiants[currentIndex].departement.dpart, "SVT");
        break;
    default:
        printf("Choix invalide, département non defini.\n");
        break;
    }

    printf("Entrez la note generale (entre 0 et 20) : ");
    scanf("%f", &noteGenerale);

    // Simple input validation
    while (noteGenerale < 0 || noteGenerale > 20)
    {
        printf("Note invalide. Entrez une note entre 0 et 20 : ");
        scanf("%f", &noteGenerale);
    }
    etudiants[currentIndex].departement.noteGenerale = noteGenerale;
    printf("Entrez le numero unique : ");
    scanf("%d", &etudiants[currentIndex].numeroUnique);

    currentIndex++;
}

void afficher()
{
    for (int i = 0; i < currentIndex; i++)
    {
        printf("Etudiant numero : %d", i + 1);
        printf("\nPrenom : %s", etudiants[i].prenom);
        printf("\nNom : %s", etudiants[i].nom);
        printf("\nDate de naissance : %d/%d/%d", etudiants[i].date.jour, etudiants[i].date.mois, etudiants[i].date.annee);
        printf("\nDepartement : %s", etudiants[i].departement.dpart);
        printf("\nNote generale : %.2f", etudiants[i].departement.noteGenerale);
        printf("\nNumero unique : %d", etudiants[i].numeroUnique);
        printf("\n----------------------------------------------------------------");
    }
}


//to do handle errors in date an department
void modifier()
{
    int uniqueNombre;
    int choix;
    int found = 0;

    printf("Entrez le numéro unique de l'étudiant : ");
    scanf("%d", &uniqueNombre);

    for (int i = 0; i < currentIndex; i++)
    {
        if (uniqueNombre == etudiants[i].numeroUnique)
        {
            found = 1;

            printf("Entrez le nouveau prénom : ");
            scanf("%s", etudiants[i].prenom);

            printf("Entrez le nouveau nom : ");
            scanf("%s", etudiants[i].nom);

            printf("Entrez la nouvelle date de naissance.\n");
            printf("Entrez le nouveau jour (1-31) : ");
            scanf("%d", &etudiants[i].date.jour);
            while (etudiants[i].date.jour < 1 || etudiants[i].date.jour > 31) {
                printf("Jour invalide. Entrez un nombre entre 1 et 31 : ");
                scanf("%d", &etudiants[i].date.jour);
            }

            printf("Entrez le nouveau mois (1-12) : ");
            scanf("%d", &etudiants[i].date.mois);
            while (etudiants[i].date.mois < 1 || etudiants[i].date.mois > 12) {
                printf("Mois invalide. Entrez un nombre entre 1 et 12 : ");
                scanf("%d", &etudiants[i].date.mois);
            }

            printf("Entrez l'année (1900-2005) : ");
            scanf("%d", &etudiants[i].date.annee);
            while (etudiants[i].date.annee < 1900 || etudiants[i].date.annee > 2005) {
                printf("Année invalide. Entrez une année valide (1900-2005) : ");
                scanf("%d", &etudiants[i].date.annee);
            }

            printf("Entrez le nouveau département.\n");
            printf("1. Pour MATH\n");
            printf("2. Pour PC\n");
            printf("3. Pour SVT\n");
            printf("Entrez votre choix : ");
            scanf("%d", &choix);

            switch (choix)
            {
            case 1:
                strcpy(etudiants[i].departement.dpart, "MATH");
                break;
            case 2:
                strcpy(etudiants[i].departement.dpart, "PC");
                break;
            case 3:
                strcpy(etudiants[i].departement.dpart, "SVT");
                break;
            default:
                printf("Choix invalide, département non défini.\n");
                strcpy(etudiants[i].departement.dpart, "Non");
                break;
            }

            printf("Entrez la nouvelle note générale (entre 0 et 20) : ");
            scanf("%f", &etudiants[i].departement.noteGenerale);
            while (etudiants[i].departement.noteGenerale < 0 || etudiants[i].departement.noteGenerale > 20)
            {
                printf("Note invalide. Entrez une note entre 0 et 20 : ");
                scanf("%f", &etudiants[i].departement.noteGenerale);
            }

            // Handle updating the unique number
            int newUnique;
            printf("Entrez le nouveau numéro unique : ");
            scanf("%d", &newUnique);

            // Check for duplicates
            int duplicate = 0;
            for (int j = 0; j < currentIndex; j++) {
                if (newUnique == etudiants[j].numeroUnique && newUnique != uniqueNombre) {
                    duplicate = 1;
                    break;
                }
            }

            if (duplicate) {
                printf("Le numéro unique est déjà utilisé. Modifiez le numéro unique.\n");
            } else {
                etudiants[i].numeroUnique = newUnique;
                printf("Les informations de l'étudiant ont été mises à jour avec succès.\n");
            }

            break;
        }
    }

    if (!found) {
        printf("Numéro unique invalide.\n");
    }
}


void afficherUnEtudiant()
{
    int uniqueNumber;
    printf("entrez unique numero");
    scanf("%d", &uniqueNumber);
    for (int i = 0; i < currentIndex; i++)
    {
        if (uniqueNumber == etudiants[i].numeroUnique)
        {
            printf("\nPrenom : %s", etudiants[i].prenom);
            printf("\nNom : %s", etudiants[i].nom);
            printf("\nDate de naissance : %d/%d/%d", etudiants[i].date.jour, etudiants[i].date.mois, etudiants[i].date.annee);
            printf("\nDepartement : %s", etudiants[i].departement.dpart);
            printf("\nNote generale : %.2f\n", etudiants[i].departement.noteGenerale);
            printf("\nNumero  unique : %d\n", etudiants[i].numeroUnique);
        }
    }
}

void supprimer()
{
    int uniquNumber;
    printf("entrez unique number: ");
    scanf("%d", &uniquNumber);

    for (int i = 0; i < currentIndex; i++)
    {
        if (uniquNumber == etudiants[i].numeroUnique)
        {
            for (int j = i; j < currentIndex - 1; j++)
            {
                etudiants[j] = etudiants[j + 1];
            }
            currentIndex--;
            printf("\netudiant supprime avec succes.\n");
            return;
        }
    }

    printf("etudiant introuvable!!\n");
}

void moyenneGeneraleDeChaqueDepartement()
{

    float math = 0, svt = 0, pc = 0, moyenneGeneraleDeLuniversite = 0;
    int mathEtudiant = 0, svtEtudiant = 0, pcEtudiant = 0, nombreDeDepartement = 0;
    for (int i = 0; i < currentIndex; i++)
    {
        if (strcmp(etudiants[i].departement.dpart, "MATH") == 0)
        {
            math += etudiants[i].departement.noteGenerale;
            mathEtudiant++;
        }
        else if (strcmp(etudiants[i].departement.dpart, "PC") == 0)
        {
            pc += etudiants[i].departement.noteGenerale;
            pcEtudiant++;
        }
        else if (strcmp(etudiants[i].departement.dpart, "SVT") == 0)
        {
            svt += etudiants[i].departement.noteGenerale;
            +svtEtudiant++;
        }
    }

    if (mathEtudiant > 0)
    {
        math = math / mathEtudiant;
        printf("\n le moyenne general de math est: %f", math);
        moyenneGeneraleDeLuniversite += math;
        nombreDeDepartement++;
    }
    if (pcEtudiant > 0)
    {
        pc = pc / pcEtudiant;
        printf("\n le moyenne general de pc est: %f", pc);
        moyenneGeneraleDeLuniversite += pc;
        nombreDeDepartement++;
    }
    if (svtEtudiant > 0)
    {
        svt = svt / svtEtudiant;
        printf("\n le moyenne general de svt est: %f", svt);
        moyenneGeneraleDeLuniversite += svt;
        nombreDeDepartement++;
    }
    if (moyenneGeneraleDeLuniversite > 0)
    {
        moyenneGeneraleDeLuniversite = moyenneGeneraleDeLuniversite / nombreDeDepartement;
        printf("\n le moyenne general de luniversite est: %f", moyenneGeneraleDeLuniversite);
    }
}

void afficherLeNombreTotalDetudiantsInscrits()
{
    printf("\nle nombre total d'etudiants inscrits est: %d", currentIndex);
}

void afficherLeNombreDetudiantsDansChaqueDepartement()
{
    int mathEtudiatn = 0, svtEtudiant = 0, pcEtudiant = 0;
    for (int i = 0; i < currentIndex; i++)
    {
        if (strcmp(etudiants[i].departement.dpart, "MATH") == 0)
        {
            mathEtudiatn++;
        }
        else if (strcmp(etudiants[i].departement.dpart, "PC") == 0)
        {
            pcEtudiant++;
        }
        else if (strcmp(etudiants[i].departement.dpart, "SVT") == 0)
        {
            svtEtudiant++;
        }
    }

    printf("\nle nombre d'étudiants dans chaque departement");
    printf("\npour MATH: %d ", mathEtudiatn);
    printf("\npour PC: %d ", pcEtudiant);
    printf("\npour SVT: %d ", svtEtudiant);
}

void EtudiantsAyantMoyenneSeuil()
{
    float moyenneSeuil;
    int numbreDetudaint = 0;
    printf("\nentrez le moyenne seuil: ");
    scanf("%f", &moyenneSeuil);
    for (int i = 0; i < currentIndex; i++)
    {
        if (moyenneSeuil <= etudiants[i].departement.noteGenerale)
        {
            printf("etudiant numero : %d", i + 1);
            printf("\nPrenom : %s", etudiants[i].prenom);
            printf("\nNom : %s", etudiants[i].nom);
            printf("\nDate de naissance : %d/%d/%d", etudiants[i].date.jour, etudiants[i].date.mois, etudiants[i].date.annee);
            printf("\nDepartement : %s", etudiants[i].departement.dpart);
            printf("\nNote generale : %.2f", etudiants[i].departement.noteGenerale);
            printf("\nNumero  unique : %d", etudiants[i].numeroUnique);
            numbreDetudaint++;
        }
    }

    if (numbreDetudaint == 0)
    {
        printf("aucan etudiant");
    }
}

void les3EtudiantsAyantLesMeilleuresNotes()
{
    system("@cls || clear");
    if (currentIndex < 3)
    {
        printf("Il n'y a pas 3 etudiants pour afficher.\n");
        return; // Exit the function if there are fewer than 3 students
    }

    // Simple bubble sort for top 3
    for (int i = 0; i < currentIndex - 1; i++) {
        for (int j = i + 1; j < currentIndex; j++) {
            if (etudiants[j].departement.noteGenerale > etudiants[i].departement.noteGenerale) {
                Etudiants swap = etudiants[i];
                etudiants[i] = etudiants[j];
                etudiants[j] = swap;
            }
        }
    }

    // Print top 3 students
    printf("\nles etudiant sont");
    for (int i = 0; i < 3; i++) {
        printf("Etudiant %d:\n", i + 1);
        printf("Prenom : %s\n", etudiants[i].prenom);
        printf("Nom : %s\n", etudiants[i].nom);
        printf("Date de naissance : %d/%d/%d\n", etudiants[i].date.jour, etudiants[i].date.mois, etudiants[i].date.annee);
        printf("Departement : %s\n", etudiants[i].departement.dpart);
        printf("Note generale : %.2f\n", etudiants[i].departement.noteGenerale);
        printf("Numero unique : %d\n", etudiants[i].numeroUnique);
        printf("----------------------------------------------------------------\n");
    }
}


void etudiantSuperieureA10DansChaqueDepartement()
{
    int mathEtudiatn = 0, svtEtudiant = 0, pcEtudiant = 0;
    for (int i = 0; i < currentIndex; i++)
    {
        if (strcmp(etudiants[i].departement.dpart, "MATH") == 0)
        {
            if (etudiants[i].departement.noteGenerale >= 10)
            {
                mathEtudiatn++;
            }
        }
        else if (strcmp(etudiants[i].departement.dpart, "PC") == 0)
        {
            if (etudiants[i].departement.noteGenerale >= 10)
            {
                pcEtudiant++;
            }
        }
        else if (strcmp(etudiants[i].departement.dpart, "SVT") == 0)
        {
            if (etudiants[i].departement.noteGenerale >= 10)
            {
                svtEtudiant++;
            }
        }
    }

    printf("\nle nombre d'etudiant superieure a 10 dans chaque departement");
    printf("\npour MATH: %d ", mathEtudiatn);
    printf("\npour PC: %d ", pcEtudiant);
    printf("\npour SVT: %d ", svtEtudiant);
}

void recherUnEtudiantParSonNom()
{
    char nome[30];
    int etudiantExist = 0 ;
    printf("entrez le nome d'etudiant: ");
    scanf("%s", nome);

    for (int i = 0; i < currentIndex; i++)
    {
        if (strcmp(etudiants[i].nom, nome) == 0)
        {
            printf("etudiant numero : %d", i + 1);
            printf("\nPrenom : %s", etudiants[i].prenom);
            printf("\nNom : %s", etudiants[i].nom);
            printf("\nDate de naissance : %d/%d/%d", etudiants[i].date.jour, etudiants[i].date.mois, etudiants[i].date.annee);
            printf("\nDepartement : %s", etudiants[i].departement.dpart);
            printf("\nNote generale : %.2f", etudiants[i].departement.noteGenerale);
            printf("\nNumero  unique : %d", etudiants[i].numeroUnique);
            etudiantExist = 1;
        }
    }

    if (!etudiantExist)
    {
        printf("\nil n'y a aucn utilisateur avec ce nom");
    }
    
}

void afficherEtudiantParDepartement()
{
    int choix;
    char departement[10];
    printf("Entrez le departement.\n");
    printf("1. Pour MATH\n");
    printf("2. Pour PC\n");
    printf("3. Pour SVT\n");
    printf("Entrez votre choix : ");
    scanf("%d", &choix);

    if (choix == 1)
    {
        strcpy(departement, "MATH");
    }
    else if (choix == 2)
    {
        strcpy(departement, "PC");
    }
    else if (choix == 3)
    {
        strcpy(departement, "SVT");
    }

    for (int i = 0; i < currentIndex; i++)
    {
        if (strcmp(etudiants[i].departement.dpart, departement) == 0)
        {
            printf("\nPrenom : %s", etudiants[i].prenom);
            printf("\nNom : %s", etudiants[i].nom);
            printf("\nDate de naissance : %d/%d/%d", etudiants[i].date.jour, etudiants[i].date.mois, etudiants[i].date.annee);
            printf("\nDepartement : %s", etudiants[i].departement.dpart);
            printf("\nNote generale : %.2f\n", etudiants[i].departement.noteGenerale);
            printf("\nNumero  unique : %d\n", etudiants[i].numeroUnique);
        }
    }
}

void trierParNom()
{
    for (int i = 0; i < currentIndex - 1; i++)
    {
        for (int j = i + 1; j < currentIndex; j++)
        {
            if (strcmp(etudiants[i].nom, etudiants[j].nom) > 0)
            {
                Etudiants temp = etudiants[i];
                etudiants[i] = etudiants[j];
                etudiants[j] = temp;
            }
        }
    }

    printf("Etudiants trier par nom:\n");
    afficher();
}

void trierParMoyenneGenerale()
{
    for (int i = 0; i < currentIndex - 1; i++)
    {
        for (int j = i + 1; j < currentIndex; j++)
        {
            if (etudiants[j].departement.noteGenerale > etudiants[i].departement.noteGenerale)
            {
                Etudiants swap = etudiants[i];
                etudiants[i] = etudiants[j];
                etudiants[j] = swap;
            }
        }
    }

    printf("Etudiants tries par moyenne generale :\n");
    afficher();
}

void triEtudiantsSelonMoyenn10Sur20(){
    for (int i = 0; i < currentIndex - 1; i++)
    {
        for (int j = i + 1; j < currentIndex; j++)
        {
            if (etudiants[j].departement.noteGenerale > etudiants[i].departement.noteGenerale)
            {
                Etudiants swap = etudiants[i];
                etudiants[i] = etudiants[j];
                etudiants[j] = swap;
            }
        }
    }

    for (int i = 0; i < currentIndex; i++)
    {
        if (etudiants[i].departement.noteGenerale >= 10)
        {
        printf("Etudiant numero : %d", i + 1);
        printf("\nPrenom : %s", etudiants[i].prenom);
        printf("\nNom : %s", etudiants[i].nom);
        printf("\nDate de naissance : %d/%d/%d", etudiants[i].date.jour, etudiants[i].date.mois, etudiants[i].date.annee);
        printf("\nDepartement : %s", etudiants[i].departement.dpart);
        printf("\nNote generale : %.2f", etudiants[i].departement.noteGenerale);
        printf("\nNumero unique : %d", etudiants[i].numeroUnique);
        printf("\n----------------------------------------------------------------");
        }
        
    }
}



int main()
{
    int choix = 20;
    while (choix != 0)
    {
        printf("\n_________________________________________________");
        printf("\n1. Ajouter un etudiant");
        printf("\n2. Afficher tous les etudiants");
        printf("\n3. Modifier etudiant");
        printf("\n4. Afficher un etudiant");
        printf("\n5. Afficher le moyenne generale de chaque departement");
        printf("\n6. Supprimer un etudiant");
        printf("\n7. Afficher le nombre totale d'tudiants inscrits");
        printf("\n8. Afficher le nombre d'étudiants dans chaque departement");
        printf("\n9. Afficher les etudiants ayant une moyenne generale supérieure a un certain seuil");
        printf("\n10. Afficher les 3 etudiants ayant les meilleures notes");
        printf("\n11. Afficher les etudiants ayant 10 dans chaque departement");
        printf("\n12. Rechercher un etudiant par son nom: ");
        printf("\n13. Afficher la liste des etudiants inscrits dans un departement: ");
        printf("\n13. Afficher la liste des etudiants inscrits dans un departement: ");
        printf("\n13. Afficher la liste des etudiants inscrits dans un departement: ");
        printf("\n14. Tri des etudiants en fonctions de leur nom de A a Z: ");
        printf("\n15. tries par moyenne generale: ");
        printf("\n16. tries selone moyenne superieur ou egale a 10/20 : ");
        printf("\n0. Quitter");
        printf("\nEntrez votre choix : ");
        scanf("%d", &choix);

        system("@cls||clear");

        switch (choix)
        {
        case 1:
            ajouterEtudiant();
            break;
        case 2:
            afficher();
            break;
        case 3:
            modifier();
            break;
        case 4:
            afficherUnEtudiant();
            break;
        case 5:
            moyenneGeneraleDeChaqueDepartement();
            break;
        case 6:
            supprimer();
            break;
        case 7:
            afficherLeNombreTotalDetudiantsInscrits();
            break;
        case 8:
            afficherLeNombreDetudiantsDansChaqueDepartement();
            break;
        case 9:
            EtudiantsAyantMoyenneSeuil();
            break;
        case 10:
            les3EtudiantsAyantLesMeilleuresNotes();
            break;
        case 11:
            etudiantSuperieureA10DansChaqueDepartement();
            break;
        case 12:
            recherUnEtudiantParSonNom();
            break;
        case 13:
            afficherEtudiantParDepartement();
            break;
        case 14:
            trierParNom();
            break;
        case 15:
            trierParMoyenneGenerale();
            break;
        case 16:
            triEtudiantsSelonMoyenn10Sur20();
            break;
        case 0:
            printf("Quitter\n");
            break;
        default:
            printf("choix est invalide.\n");
            break;
        }
    }
    return 0;
}
