#include "menu.h"
#include "comptebancaire.h"
#include "compteepargne.h"
#include "compteclient.h"
#include <iostream>


using namespace std;

int main()
{
    /**
 * ... root du fichier txt compteBancaire ...
 */
    Menu menuCB("../LaBanque/client.txt");
    //CompteBancaire leCompte;
    //CompteEpargne leCompte(3);
    CompteClient leCompte;
    int touche;
    float montant;


    do{
        touche = menuCB.Afficher();
        switch (touche){
        case 1:
            cout << "Ouvrir un compte Epargne : " << leCompte.ConsulterSolde()<<endl;
            break;
        case 2:
            cout << "Gerer le compte Bancaire : " ;
            //leCompte.Deposer(montant);
            break;
        case 3:
            cout << "Gerer le compte Epargne : " <<endl;
            break;
        default:
            break;
        }

    }while(touche != 4);
    return 0;



/**
    do{
        touche = menuCB.Afficher();
        switch (touche){
        case 1:
            cout << "valeur du solde : " << leCompte.ConsulterSolde()<<endl;
            break;
        case 2:
            cout << "montant deposer : " ;
            cin >> montant;
            leCompte.Deposer(montant);
            break;
        case 3:
            cout << "montant retirer : " ;
            cin >> montant ;
            if(leCompte.Retirer())
                cout << "Retrait Effectuer"<<endl;
            else
                cout << "Retrait Effectuer"<<endl;
            break;
        case 4:
            leCompte.CalculerInterets();
            cout << "Interets calculer: " <<endl;
            break;
                   default:
                            break;
        }

    }while(touche != 5);
        return 0;


        /**
         *     do{
        touche = menuCB.Afficher();
        switch (touche){
        case 1:
            cout << "valeur du solde : " << leCompte.ConsulterSolde()<<endl;
            break;
        case 2:
            cout << "montant deposer : " ;
            cin >> montant;
            leCompte.Deposer(montant);
            break;
        case 3:
            cout << "montant retirer : " ;
            cin >> montant ;
            if(leCompte.Retirer())
                cout << "Retrait Effectuer"<<endl;
            else
                cout << "Retrait Effectuer"<<endl;
            break;
                default:
                            break;
}
    }while(touche != 4);
        return 0;
*/

    /**
 * ... affichage du fichier txt compteBancaire ...
 */
    menuCB.Afficher();
    Menu::AttendreAppuiTouche;

    return 0 ;
}
