#include <string>
#include <fstream>

#include "User.h"

// Initialisierung von User
User::User(){
    _userName = "";
    _userPass = "";
}

// Funktion, die den aktuellen Benutzernamen überschreibt
void User::setName(std::string userName){
    _userName = userName;
}

// Funktion, die das aktuelle Passwort überschreibt
void User::setPass(std::string userPass){
    _userPass = userPass;
}

// Funktion, die den zwischengespeicherten Benutzernamen zurückgibt
std::string User::getName(){
    return this->_userName;
}

// Funktion mit der neue Benutzer registriert werden können
int User::registration(){
    int result = checkUser("registration");  // Funktion, die überprüft, ob Benutzername schon vergeben ist
    if(result == false){  // Falls nein, wird ein neuer Benutzer angelegt
        std::fstream f;
	    f.open("users.txt", std::ios::app);
	    f << this->_userName << ";" << this->_userPass << "\n";
	    f.close();
        return true;
    }
    else{
        return false;
    }
}

// Funktion, die die angegebenen Daten überprüft
int User::login(){
    int result = checkUser("login");  // Funktion, die überptft, ob Benutzername und Passwort abgespeichert sind
    if(result == true){
        return true;
    }
    else{
        return false;
    }
}