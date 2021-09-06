// Header-Datei von User
#ifndef USER_H
#define USER_H

#include <string>
#include <fstream>

class User {
    private:  // Liste der benötigten Variablen
    std::string _userName;
    std::string _userPass;

// Funktion überprüft, ob User in Datei 'users.txt' vorhanden ist
    int checkUser(std::string choice){
        std::ifstream f;
	    std::string userInfo;
	    f.open("users.txt", std::ios::in);
	    while(std::getline(f, userInfo)){
            std::size_t strPosition = userInfo.find_first_of(";"); // Position von ; wird ermittelt, um den String an der richtigen Stelle teilen zu können
            std::size_t strLength = userInfo.length(); 
            std::string fileUserName = userInfo.substr(0, (strPosition));
            std::string fileUserPass = userInfo.substr(strPosition + 1, strLength);
                if((((fileUserName == this->_userName) && (fileUserPass == this->_userPass)) && choice == "login") // login -> Benutzername und Passwort müssen übereinstimmen
                || ((fileUserName == this->_userName) && choice == "registration")){  // registration -> überprüft, ob der Benutzername bereits vergeben ist
                    return true;
                }
		}
        return false;
    }

    public:  // Liste der benutzbaren Funktionen
    User();  // Initialisierung von User
    void setName(std::string userName);  // Funktion, die den aktuellen Benutzernamen überschreibt
    void setPass(std::string userPass);  // Funktion, die das aktuelle Passwort überschreibt
    std::string getName();  // Funktion, die den zwischengespeicherten Benutzernamen zurückgibt
    int registration();  // Funktion mit der neue Benutzer registriert werden können
    int login();  // Funktion, die die angegebenen Daten überprüft
};
#endif