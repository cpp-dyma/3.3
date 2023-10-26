#include <iostream>
#include "redirecter.h"

int main(){

    //Pour le support des accents sur Windows
    std::setlocale(LC_ALL, ".utf8");

    //Ecriture dans la console
    std::cout<<"Ceci est un message d'information"<<std::endl;
    std::cerr<<"Ceci est un message d'erreur"<<std::endl;
    std::clog<<"Ceci est un message de log"<<std::endl;

    int age = 33;

    std::cout<<"Je m'appelle"<<"John Doe"<<" et j'ai "<<age<<"ans"<<std::endl;
    std::cout<<"Voici une \t tabulation"<<std::endl;
    std::cout<<"Plusieurs \nmoyens de revenir"<<std::endl<<"a la ligne"<<std::endl;

    //*******************************************************************************//

    //Lecture
    int annee_naissance;
    std::string nom;

    std::cout<<"Quel est votre nom : "<<std::endl;
    std::getline(std::cin, nom);

    std::cout<<"Quel est votre âge : ";
    std::cin>>age;

    std::cout<<"Quel est année de naissance : ";
    std::cin>>annee_naissance;

    std::cout<<"Vous vous appelez "<<nom<<", vous avez "<<age<<"ans et êtes nés en "<<annee_naissance<<std::endl;

    //*******************************************************************************//

    //Redirection d'un flux
    std::clog<<"Avant la redirection"<<std::endl;

    std::ofstream log("logs");
    redirecter redirect(log, std::clog);

    std::clog<<"Après la redirection"<<std::endl;

    std::cout<<"Message final";

    return 0;
}