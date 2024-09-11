#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct {
    char jour[15], mois[15], annee[15];
} DateDeNaissance;

typedef struct {
    char dpart[20];
    float noteGenerale;
} Departement;

typedef struct {
    char nom[30], prenom[30];
    int numeroUnique;
    DateDeNaissance date;
    Departement departement;
} Etudiants;

Etudiants etudiants[200];
int currentIndex = 0;

void ajouterEtudiant() {
    int choix;
    
    if (currentIndex >= 200) {
        printf("La liste des étudiants est pleine.\n");
        return;
    }

    printf("Entrez le prenom : ");
    scanf("%s", etudiants[currentIndex].prenom);
    
    printf("Entrez le nom : ");
    scanf("%s", etudiants[currentIndex].nom);
    
    printf("Entrez la date de naissance.\n");
    printf("Entrez le jour : ");
    scanf("%s", etudiants[currentIndex].date.jour);
    
    printf("Entrez le mois : ");
    scanf("%s", etudiants[currentIndex].date.mois);
    
    printf("Entrez l'annee : ");
    scanf("%s", etudiants[currentIndex].date.annee);
    
    printf("Entrez le departement.\n");
    printf("1. Pour MATH\n");
    printf("2. Pour PC\n");
    printf("3. Pour SVT\n");
    printf("Entrez votre choix : ");
    scanf("%d", &choix);
    
    switch (choix) {
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
    
    printf("Entrez la note generale : ");
    scanf("%f",&etudiants[currentIndex].departement.noteGenerale);

    printf("Entrez la numero unique:");
    scanf("%d",&etudiants[currentIndex].numeroUnique);

    currentIndex++;
}

void afficher() {
    for (int i = 0; i < currentIndex; i++) {
        printf("etudiant numero : %d", i+1);
        printf("\nPrenom : %s", etudiants[i].prenom);
        printf("\nNom : %s", etudiants[i].nom);
        printf("\nDate de naissance : %s/%s/%s", etudiants[i].date.jour, etudiants[i].date.mois, etudiants[i].date.annee);
        printf("\nDepartement : %s", etudiants[i].departement.dpart);
        printf("\nNote generale : %.2f", etudiants[i].departement.noteGenerale);
        printf("\nNumero  unique : %d", etudiants[i].numeroUnique);
        printf("\n----------------------------------------------------------------");
    }
}

void modifier(){
    int uniqueNombre;
    int choix;
    printf("entrez unique nombre d'etudiant: ");
    scanf("%d",&uniqueNombre);
    for (int i = 0; i < currentIndex; i++)
    {
        if (uniqueNombre == etudiants[i].numeroUnique)
        {
     printf("Entrez le nouvelle prenom : ");
    scanf("%s", etudiants[i].prenom);
    
    printf("Entrez le nouvelle nom : ");
    scanf("%s", etudiants[i].nom);
    
    printf("Entrez la nouvelle date de naissance.\n");
    printf("Entrez le nouvelle jour : ");
    scanf("%s", etudiants[i].date.jour);
    
    printf("Entrez le nouvelle mois : ");
    scanf("%s", etudiants[i].date.mois);
    
    printf("Entrez l'annee : ");
    scanf("%s", etudiants[i].date.annee);
    
    printf("Entrez le nouvelle departement.\n");
    printf("1. Pour math\n");
    printf("2. Pour PC\n");
    printf("3. Pour SVT\n");
    printf("Entrez votre choix : ");
    scanf("%d", &choix);
    
    switch (choix) {
        case 1:
            strcpy(etudiants[i].departement.dpart, "math");
            break;
        case 2:
            strcpy(etudiants[i].departement.dpart, "PC");
            break;
        case 3:
            strcpy(etudiants[i].departement.dpart, "SVT");
            break;
        default:
            printf("Choix invalide, département non defini.\n");
            strcpy(etudiants[i].departement.dpart, "Non");
            break;
    }
    
    printf("Entrez la nouvelle note generale : ");
    scanf("%f",&etudiants[i].departement.noteGenerale);

    printf("Entrez la nouvelle numero unique:");
    scanf("%d",&etudiants[i].numeroUnique);
    }else
    {
        printf("unique numero est invalide.\n");
    }
        }
        
    
    
}

void afficherUnEtudiant(){
    int uniqueNumber;
    printf("entrez unique numero");
    scanf("%d",&uniqueNumber);
    for (int i = 0; i < currentIndex; i++) {
    if (uniqueNumber == etudiants[i].numeroUnique)
    {
        printf("\nPrenom : %s", etudiants[i].prenom);
        printf("\nNom : %s", etudiants[i].nom);
        printf("\nDate de naissance : %s/%s/%s", etudiants[i].date.jour, etudiants[i].date.mois, etudiants[i].date.annee);
        printf("\nDepartement : %s", etudiants[i].departement.dpart);
        printf("\nNote generale : %.2f\n", etudiants[i].departement.noteGenerale);
        printf("\nNumero  unique : %d\n", etudiants[i].numeroUnique);
    }
    }
}

void supprimer(){
    int uniquNumber;
    printf("entrez uniqu number: ");
    scanf("%d", &uniquNumber);

    for (int i = 0; i < currentIndex; i++)
    {
        if (uniquNumber == etudiants[i].numeroUnique)
        {
            for (int j = i; j < currentIndex - 1 ; j++)
            {
               etudiants[j] = etudiants[i + 1];
            }
            currentIndex--;
            printf("\netudiant supprimer avce success.\n");
            return;
        }
        
    }
   
    printf("etudiant untrovable!!");
    
}

void moyenneGeneraleDeChaqueDepartement(){
    
    float math = 0, svt = 0, pc = 0, moyenneGeneraleDeLuniversite = 0;
    int mathEtudiant = 0, svtEtudiant = 0, pcEtudiant = 0, nombreDeDepartement = 0;
    for (int i = 0; i < currentIndex; i++)
    {
        if (strcmp(etudiants[i].departement.dpart, "MATH") == 0 )
        {
            math += etudiants[i].departement.noteGenerale;
            mathEtudiant ++;
            
        }
        else if (strcmp(etudiants[i].departement.dpart, "PC") == 0 )
        {
            pc += etudiants[i].departement.noteGenerale;
            pcEtudiant++;
        }
        else if (strcmp(etudiants[i].departement.dpart, "SVT") == 0 )
        {
            svt += etudiants[i].departement.noteGenerale;+
            svtEtudiant++;
        }
        
    }

    if (mathEtudiant >0)
    {
        math = math / mathEtudiant;
        printf("\n le moyenne general de math est: %f",math);
        moyenneGeneraleDeLuniversite += math;
        nombreDeDepartement++;
        
    }
    if (pcEtudiant >0)
    {
        pc = pc / pcEtudiant;
        printf("\n le moyenne general de pc est: %f",pc);
        moyenneGeneraleDeLuniversite += pc;
         nombreDeDepartement++;
    }
    if (svtEtudiant >0)
    {
        svt = svt / svtEtudiant;
        printf("\n le moyenne general de svt est: %f",svt);
        moyenneGeneraleDeLuniversite += svt;
        nombreDeDepartement++;
    }
    if (moyenneGeneraleDeLuniversite > 0)
    {
        moyenneGeneraleDeLuniversite = moyenneGeneraleDeLuniversite / nombreDeDepartement;
        printf("\n le moyenne general de luniversite est: %f",moyenneGeneraleDeLuniversite);
    }
    
}

void afficherLeNombreTotalDetudiantsInscrits(){
    printf("\nle nombre total d'etudiants inscrits est: %d",currentIndex );
}

void afficherLeNombreDetudiantsDansChaqueDepartement(){
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

void EtudiantsAyantMoyenneSeuil(){
    float moyenneSeuil;
    int numbreDetudaint = 0;
    printf("\nentrez le moyenne seuil: ");
    scanf("%f",&moyenneSeuil);
for (int i = 0; i < currentIndex; i++) {
    if (moyenneSeuil <= etudiants[i].departement.noteGenerale)
    {
        printf("etudiant numero : %d", i+1);
        printf("\nPrenom : %s", etudiants[i].prenom);
        printf("\nNom : %s", etudiants[i].nom);
        printf("\nDate de naissance : %s/%s/%s", etudiants[i].date.jour, etudiants[i].date.mois, etudiants[i].date.annee);
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

void les3EtudiantsAyantLesMeilleuresNotes(){
    if (currentIndex < 3)
    {
       printf("il n'y a pas 3 etudiant pour afficher");
    }else
    {
        
    }
    
    
}

void etudiantSuperieureA10DansChaqueDepartement(){
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

void recherUnEtudiantParSonNom(){
    char nome[30];
    printf("entrez le nome d'etudiant: ");
    scanf("%s", nome);
     for (int i = 0; i < currentIndex; i++) {
    if (strcmp(etudiants[i].nom, nome)==0)
    {
        printf("etudiant numero : %d", i+1);
        printf("\nPrenom : %s", etudiants[i].prenom);
        printf("\nNom : %s", etudiants[i].nom);
        printf("\nDate de naissance : %s/%s/%s", etudiants[i].date.jour, etudiants[i].date.mois, etudiants[i].date.annee);
        printf("\nDepartement : %s", etudiants[i].departement.dpart);
        printf("\nNote generale : %.2f", etudiants[i].departement.noteGenerale);
        printf("\nNumero  unique : %d", etudiants[i].numeroUnique);
    }
    
    }

}

void afficherEtudiantParDepartement(){
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
   }else if (choix == 2)
   {
     strcpy(departement, "PC");
   }else if (choix == 3){
     strcpy(departement, "SVT");
   }

    for (int i = 0; i < currentIndex; i++) {
    if (strcmp(etudiants[i].departement.dpart, departement))
    {
        printf("\nPrenom : %s", etudiants[i].prenom);
        printf("\nNom : %s", etudiants[i].nom);
        printf("\nDate de naissance : %s/%s/%s", etudiants[i].date.jour, etudiants[i].date.mois, etudiants[i].date.annee);
        printf("\nDepartement : %s", etudiants[i].departement.dpart);
        printf("\nNote generale : %.2f\n", etudiants[i].departement.noteGenerale);
        printf("\nNumero  unique : %d\n", etudiants[i].numeroUnique);
    }
    }
   
   
}

int main() {
    int choix = 20;
    while (choix != 0) {
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
        printf("\n11. Afficher les etudiants ayant 10 dans chaque departement");
        printf("\n12. Rechercher un etudiant par son nom: ");
        printf("\n13. Afficher la liste des etudiants inscrits dans un departement: ");
        printf("\n0. Quitter");
        printf("\nEntrez votre choix : ");
        scanf("%d", &choix);

        system("@cls||clear"); 

        switch (choix) {
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
            case 11: 
                etudiantSuperieureA10DansChaqueDepartement();
                break;
            case 12: 
                recherUnEtudiantParSonNom();
                break;
            case 13: 
                afficherEtudiantParDepartement();
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
