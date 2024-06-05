#include <stdio.h>
#include<stdlib.h>

// la definition des constantes
#define codeEnter 1234 // Définir le code PIN par défaut


// Declaration des prototype des fonctions

   int codeVerifier(int code);
   void votresold();

// Déclaration de la structure infoclient
  struct infoclient{
    char nom[50]; 
    char prenom[50];
    char numero[50]; 
    char AccountNumero[50];
    char RIB[50];
    char Nature[50];
    char agence[50];
    float solde;
};


  struct infobeneficiaire {
    char nom[50];
    char prenom[50];
    char numCarte[10];
    char numCompte[50];
    char RIB[50];
    float solde;
};

// La fonction pour vérifier le code ajouté par l'utilisateur
  int codeVerifier(int code) {
    return code == codeEnter;
}

// La fonction pour voir le solde 
 void votresold( struct infoclient client ){
     
 printf("\t\t\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("\t\t\t+\t\t\t\t\t\t\t\t+\n");
    printf("\t\t\t+\t\t Votre solde : %.2f DH\t\t\t+\n", client.solde);
    printf("\t\t\t+\t\t\t\t\t\t\t\t+\n");
    printf("\t\t\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n\n");
 }
 
// Fonction pour retirer de l'argent
void retraitArgent(struct infoclient *client, float montant) {
    if (montant > 0 && montant <= client->solde) {
        client->solde -= montant;
        printf("\t\t\t++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("\t\t\t\tRetrait de %.2f DH effectue avec succes.\n\n\t\t\t\tNouveau solde : %.2f DH\n", montant, client->solde );
        printf("\t\t\t++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    } else {
        printf("Montant invalide ou solde insuffisant.\n");
    }
}

// La fonction pour achete Rocharge 
void acheteRocharge(struct infoclient *client, float rocharge){
     if(rocharge >0 && rocharge<=client->solde){
         client->solde-=rocharge;
              printf("\t\t\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("\t\t\t\tRetrait de %.2f DH effectue avec succes.\n\n\t\t\t\tNouveau solde : %.2f DH\n\n", rocharge, client->solde );
           printf("\t\t\t\tVotre recharge a ete effectuee avec succes.\n");
        printf("\t\t\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    } else {
        printf("Montant invalide ou solde insuffisant.\n");
    }
    
}

// La fonction pour 
  void numeroTelephone(){
    char telephone[10];
    printf("\tDonner votre numero de telephone :\n");
    printf("\t----------------------------------\n");
    scanf("%s",telephone);
     printf("\tLe numéro de telephone que vous avez saisi est : %s",telephone);
     printf("\n");
     printf("\t------------------------------------------------\n");
}

// La fonction pour donner a l'emeteur saisir les informations de recepteur 

   void saisirInfosBeneficiaire(struct infobeneficiaire *beneficiaire) {
    printf("\n");
    printf("\tEntrez le nom du beneficiaire : ");
    scanf("%s", beneficiaire->nom);
    printf("\tEntrez le prenom du beneficiaire :");
    scanf("%s", beneficiaire->prenom);
    printf("\tEntrez le numero de carte nationale du beneficiaire : ");
    scanf("%s", beneficiaire->numCarte);
    printf("\tEntrez le numero de compte du beneficiaire : ");
    scanf("%s", beneficiaire->numCompte);
    printf("\tEntrez le RIB du beneficiaire : ");
    scanf("%s", beneficiaire->RIB);
}

// La fonction pour envoyer l'argent a une auter compte

   void envoyerArgent(struct infoclient *envoyer, struct infobeneficiaire *beneficiaire, float montant) {
    if (montant > 0 && montant <= envoyer->solde) {
        envoyer->solde -= montant;
        beneficiaire->solde += montant;
        printf("\t================================================================================\n");
        
        printf("\tTransfert de %.2f DH effectue avec succes au beneficiaire %s %s.\n", montant, beneficiaire->nom, beneficiaire->prenom);
        printf("\tNouveau solde de l'expediteur : %.2f DH\n\n", envoyer->solde);
        
    } else {
        printf("\tMontant invalide ou solde insuffisant.\n");
    }
 printf("\t================================================================================\n\n");
        
}


// Fonction principale main 

int main() {

// Declaration des variables 
    int code;
    int choix;
    float montant;
    float NouveauSolde;
    float solde;
    float rocharge;
    int telephone;
    
    
    // Déclaration et initialisation de la structure infoclient
    struct infoclient client = {"Nbark", "Kazdabi", "069838882894","094746352442431314747","345682892390938948848","Compte cheque","Beni mellal wawa",10000};
    struct infobeneficiaire beneficiaire;
    
    // L'affiche principale et les informations d'utilisateur 
    printf("\t\t\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("\t\t\t+\t\t\t\t\t\t\t\t+\n");
    printf("\t\t\t+\t\t Bonjour dans Barid bank\t\t\t+\n");
    printf("\t\t\t+\t\t\t\t\t\t\t\t+\n");
    printf("\t\t\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n\n");
    do {
        printf("Entrez votre code PIN : ");
        scanf("%d", &code);
        printf("\n\n");
        if (codeVerifier(code)) {
            printf("\t\t\t+++++++++++++++++++++++ Votre informations ++++++++++++++++++++++\n");
            
            // Affichage des informations du client 
            printf("\t\t\t\t------------------------------------------------------\n");
            printf("\t\t\t+\tNom: %s\t\t\t\t\t\t+\n", client.nom);
            printf("\t\t\t\t------------------------------------------------------\n");
            printf("\t\t\t+\tPrenom: %s\t\t\t\t\t\t+\n", client.prenom);
            printf("\t\t\t\t------------------------------------------------------\n");
            printf("\t\t\t+\tNumero de téléphone: %s\t\t\t+\n", client.numero);
            printf("\t\t\t\t------------------------------------------------------\n");
            printf("\t\t\t+\tNumero de Compte: %s\t\t\t+\n", client.AccountNumero);
            printf("\t\t\t\t------------------------------------------------------\n");
            printf("\t\t\t+\tNumero RIB : %s\t\t\t+\n", client.RIB);
            printf("\t\t\t\t------------------------------------------------------\n");
            printf("\t\t\t+\tNature de compte: %s\t\t\t\t+\n", client.Nature);
            printf("\t\t\t\t------------------------------------------------------\n");
            printf("\t\t\t+\tNOM d'agence : %s\t\t\t\t+\n", client.agence);
            printf("\t\t\t\t------------------------------------------------------\n");
            printf("\t\t\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n\n");
            break; // Sortir de la boucle une fois le code PIN vérifié
        } else {
            printf("Code PIN incorrect. Veuillez réessayer.\n");
        }
    } while (1); 
    
    
    
    // Demnade des choix pour utilisateur
    do{
        printf("\tMenu : \n");
        printf("\t-------\n");
        printf("\t1.  Demande de solde\n");
        printf("\t2.  Retrait d'argent\n ");
        printf("\t3.  Services Telecom\n");
        printf("\t4.  Envoyer L'argent\n");
        printf("\t5.  Annuler\n\n");
        printf("Entrez votre choix : ");
         scanf("%d",&choix);
      
 // Menu d'argent pour Retrait 
       switch(choix){
            case 1 :
             votresold(client);break;
             case 2 :
               printf("\tMenu d'argent : \n");
               printf("\t-------\n");
               printf("\t1.  100 DH\n");
               printf("\t2.  200 DH\n");
               printf("\t3.  300 DH\n");
               printf("\t4.  400 DH\n");
               printf("\t5.  500 DH\n");
               printf("\t6.  600 DH\n");
               printf("\t7.  800 DH\n");
               printf("\t8.  1000 DH\n");
               printf("\t9.  2000 DH\n");
               printf("\t10. Autre montant\n\n\n");
               printf("Votre choix : ");
               scanf("%d", &choix);
               
               switch(choix){
                   case 1 :
                     montant=100.0 ;break;
                   case 2 :
                     montant=200.0;break;
                     case 3 :
                     montant=300.0 ;break;
                   case 4 :
                     montant=400.0;break;
                     case 5 :
                     montant=500.0 ;break;
                   case 6 :
                     montant=600.0;break;
                     case 7 :
                     montant=800.0 ;break;
                   case 8 :
                     montant=1000.0;break;
                     case 9 :
                     montant=2000.0 ;break;
                  case 10:
                        printf("Entrez le montant : ");
                        scanf("%f", &montant);
                        break;
                    default:
                        printf("Choix invalide.\n");
               }
                retraitArgent(&client, montant);
                break;
                
                // Les services de telecommunication 
                
                case 3 : 
                      
                      printf("\t choisir votre choix : \n");
                      printf("\t\t----------------------\n");
                      printf("\t 1. Maroc Telecom IAM \n");
                      printf("\t 2. Orange \n :");
                      printf("\t 3. Inwi \n");
                      printf("\t 4. Autoroites du Maroc \n\n");
                      printf("\t votre choix : ");
                      scanf("%d",&choix);
                      numeroTelephone();
                    
                      printf("\t choisir votre rocharge  : \n");
                      printf("\t\t----------------------\n");
                      printf("\t 1. 5 DH \n");
                      printf("\t 2. 10 DH \n :");
                      printf("\t 3. 20 DH \n");
                      printf("\t 4. 30 DH \n");
                      printf("\t 5. 50 DH \n");
                      printf("\t 6. 100 DH \n");
                      printf("\t 7. 200 DH \n");
                      printf("\t 8. 300 DH \n");
                      printf("\t votre choix : ");
                      scanf("%d",&choix);
                    
                    
                    // Les services de recharge 
                    
                      switch(choix){
                          case 1 : 
                            rocharge=5 ;break;
                          case 2 : 
                            rocharge=10 ;break;
                          case 3 :
                            rocharge=20 ;break;
                          case 4 : 
                            rocharge=30 ;break;
                          case 5 :
                            rocharge=50 ;break;
                          case 6 : 
                            rocharge=100 ;break;
                          case 7 :
                            rocharge=200 ;break;
                          case 8 :
                            rocharge=300 ;break;
                          case 9 : 
                            printf("choisir votre choix :");
                            scanf("%f",&rocharge);
                          default :
                             printf("Choix invalide.\n");
                             
                          
                          
                          
                          
                      }
                      acheteRocharge(&client,rocharge);
                      
              // envoyer l'argent a une autre personne                      
                
                case 4:
                printf("\n");
                       printf("\t\t\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
                       printf("\t\t\t+\t\t\t\t\t\t\t\t+\n");
                       printf("\t\t\t+\t\t Envoi d'argent à un beneficiaire \t\t+\n");
                       printf("\t\t\t+\t\t\t\t\t\t\t\t+\n");
                       printf("\t\t\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n\n");;
                       saisirInfosBeneficiaire(&beneficiaire);
                       printf("\n");
                       printf("\tEntrez le montant a envoyer : ");
                       scanf("\n\n%f", &montant);
                       envoyerArgent(&client, &beneficiaire, montant);
                break;
            default:
                printf("\nChoix invalide. Veuillez choisir une option valide.\n");
                break;
                
        // Le message d'annullation 
            case 5:
                     printf("\t\t\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
                     printf("\t\t\t+\t\t\t\t\t\t\t\t+\n");
                     printf("\t\t\t+\t Merci d'avoir utilise notre service. Au revoir \t+\t\t\t+\n");
                     printf("\t\t\t+\t\t\t\t\t\t\t\t+\n");
                     printf("\t\t\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n\n");;
                exit(0);
 }
        
}while(1);
return 0;

    
}

