#include <iostream>
#include <string>
#include <stdlib.h>
#include "User.h"

// Funktion, die bei erfolgreicher Anmeldung eine personalisierte Wilkommensseite ausgibt
int homepage(User * ptrUser){
    system("cls");
    int choice = 0;
    while((choice != 1) || (choice != 2)){
        std::cout << "\n\n  Herzlich Willkommen " << ptrUser->getName() << ",\n  Sie haben sich erfolgreich angemeldet.\n\n" 
            << "Abmelden: 1\n Programm beenden: 2" << "\nAuswahl: ";
            std::cin >> choice;
        if(choice == 1){
            system("cls");
            std::cout << "\nABGEMELDET\n\n";
            return 0;
        }
        else if(choice == 2){
            system("cls");
            std::cout << "\nAUF WIEDERSEHEN";
            return 3;
        }
        else{
            system("cls");
            std::cout << "Bitte benutzen Sie eine der aufgefuehrten Auswahlmoeglichkeiten.\n" ;
        }
    }
    return 0;
}

// Funktion, die dem Benutzer anbietet sich anzumelden oder zu registrieren
int loginPage(){
    int choice = 0;
    while(choice !=3){
        std::cout << "  ANMELDESEITE" << std::endl << std::endl << "  Anmeldung: 1\n  Registrierung: 2\n Beenden: 3" << std::endl << "Auswahl: ";
        std::cin >> choice;
        if(choice == 1){   
            User userLogin;  // Initialisiere den User
            User * ptrUserLogin = &userLogin;
    
            // Eingaben des Benutzers
            std::string userName;
            std::cout << "Benutzername: ";
            std::cin >> userName;
            std::string userPass;
            std::cout << "Passwort: ";
            std::cin >> userPass;

            // Überschreibe die default-Angaben bei der Initialisierung von User
            ptrUserLogin->setName(userName);
            ptrUserLogin->setPass(userPass);

            // Rufe die Methode auf mit der man sich anmelden kann
            int login = ptrUserLogin->login();
            if(login == true){
                choice = homepage(ptrUserLogin);
            }
            else{
                system("cls");
                std::cout << "Anmeldung fehlgeschlagen\n\n" << std::endl;
            }
        }
        else if(choice == 2){   
            User userRegistration;  // Initialisiere den User
            User * ptrUserRegistration = &userRegistration;

            // Eingaben des Benutzers
            std::string userName;
            std::cout << "Benutzername: ";
            std::cin >> userName;
            std::string userPass;
            std::cout << "Passwort: ";
            std::cin >> userPass;

            // Überschreibe die default-Angaben bei der Initialisierung von User
            ptrUserRegistration->setName(userName);
            ptrUserRegistration->setPass(userPass);

            // Rufe die Methode auf, die einen neuen Benutzer registriert
            int registration = ptrUserRegistration->registration();
            if(registration == true){
                system("cls");
                std::cout << "\nRegistrierung erfolgreich\n\n" << std::endl;
            }
            else{
                system("cls");
                std::cout << "\nRegistrierung fehlgeschlagen, Benutzername bereits vergeben\n\n" << std::endl;
            }
        }
        else if(choice == 3){
            system("cls");
            std::cout << "\nAUF WIEDERSEHEN";
        }
        else{
            system("cls");
            std::cout << "\nBitte benutzen Sie eine der aufgefuehrten Auswahlmoeglichkeiten.\n\n" ;
        }
    }
    return true;
}

int main(){
    loginPage();
    return 0;
}