#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm> // Pour utiliser std::count et std::find_if

#include "Bibliotheque.hpp"  
#include "Ressource.hpp"

#define CHIFFRE "0123456789"
#define BLUE "\033[1;36m"
#define YELLOW "\033[1;33m"
#define PURPLE "\033[1;95m"
#define END_COLOR "\033[0m"

Bibliotheque::Bibliotheque(std::string _Nom) {
    Nom = _Nom;
    std::cout << YELLOW << "Création de la " << Nom << END_COLOR << std::endl;
    // On vide tous les livres car ils ne sont pas vide par défaut...
    Livres.clear();
    Revues.clear();
    CDs.clear();
    VHSs.clear();
    DVDs.clear();
    Ressources_nums.clear();
}

Bibliotheque::~Bibliotheque() {
    Clear();
    Reset();
    std::cout << YELLOW << "Vous partez de la bibliothèque.\nMerci de votre visite." << END_COLOR << std::endl;
}

void Bibliotheque::AddType(std::string res) {
    // Lance la procédure d'ajout dans la base de donnée
    std::string tmp;
    bool est_un_nombre = false;
    if (Choix_ressource(res)){
        if (Type_res == livre){
            // Il s'agit d'un livre
            Livre *c_livre = new Livre();
            std::cout << "Quel est le titre du Livre ? ";
            getline(std::cin >> std::ws, tmp);
            c_livre->Titre = tmp;

            std::cout << "Quel est le nom de l'auteur ? ";
            getline(std::cin >> std::ws, tmp);
            c_livre->Auteur = tmp;

            while (!est_un_nombre) {
                std::cout << "Quelle est l'année de publication du Livre ? ";
                getline(std::cin >> std::ws, tmp);
                if (tmp.find_first_not_of(CHIFFRE) == std::string::npos) {
                    est_un_nombre = true;
                }
            }
            est_un_nombre = false;
            c_livre->Annee = stoi(tmp);
            
            while (!est_un_nombre) {
                std::cout << "Quelle est le nombre de pages du Livre ? ";
                getline(std::cin >> std::ws, tmp);
                if (tmp.find_first_not_of(CHIFFRE) == std::string::npos) {
                    est_un_nombre = true;
                }
            }
            est_un_nombre = true;
            c_livre->Nb_page = stoi(tmp);

            std::cout << "Quelle est la collection du Livre ? ";
            getline(std::cin >> std::ws, tmp);
            c_livre->Collection = tmp;

            std::cout << "Donnez-moi le résumé du Livre ! ";
            getline(std::cin >> std::ws, tmp);
            c_livre->Resume = tmp;

            // Ajout d'un ID 
            int IDmax=-10;
            for (unsigned i=0; i<Livres.size();i++){
                IDmax = std::max(IDmax,Livres[i].ID);
            }
            c_livre->ID = IDmax+10;

            // On ajoute le livre dans la réserve de livres
            Livres.push_back(*c_livre); 

        } else if (Type_res == revue) {
            // Il s'agit d'une revue
        	Revue *c_revue = new Revue();
            std::cout << "Quel est le titre de la revue ? ";
            getline(std::cin >> std::ws, tmp);
            c_revue->Titre = tmp;

            std::cout << "Quel est le nom de l'auteur ? ";
            getline(std::cin >> std::ws, tmp);
            c_revue->Auteur = tmp;

            while (!est_un_nombre) {
                std::cout << "Quelle est l'année de publication de la revue ? ";
                getline(std::cin >> std::ws, tmp);
                if (tmp.find_first_not_of(CHIFFRE) == std::string::npos) {
                    est_un_nombre = true;
                }
            }
            est_un_nombre = false;
            c_revue->Annee = stoi(tmp);
            
            while (!est_un_nombre) {
                std::cout << "Quelle est le nombre de pages de la revue ? ";
                getline(std::cin >> std::ws, tmp);
                if (tmp.find_first_not_of(CHIFFRE) == std::string::npos) {
                    est_un_nombre = true;
                }
            }
            est_un_nombre = false;
            c_revue->Nb_page = stoi(tmp);

            std::cout << "Quelle est la collection de la revue ? ";
            getline(std::cin >> std::ws, tmp);
            c_revue->Collection = tmp;

            std::cout << "Donnez-moi le résumé de la revue ! ";
            getline(std::cin >> std::ws, tmp);
            c_revue->Resume = tmp;

            std::cout << "Quel est le nom de l'éditeur ? ";
            getline(std::cin >> std::ws, tmp);
            c_revue->Editeur = tmp;

            while (!est_un_nombre) {
                std::cout << "Combien d'articles contient la revue ? ";
                getline(std::cin >> std::ws, tmp);
                if (tmp.find_first_not_of(CHIFFRE) == std::string::npos) {
                    est_un_nombre = true;
                }
            }
            est_un_nombre = false;
            int n=stoi(tmp);
            c_revue->N_articles = stoi(tmp);
            
            for (int k = 0; k < n; k++){
                std::cout << "Titre de l'article " << k << " : ";
                getline(std::cin >> std::ws, tmp);
                c_revue->Nom_articles.push_back(tmp); // à modifier  
            }
           
            int IDmax=-9;
            for (unsigned i=0; i<Revues.size();i++){
                IDmax = std::max(IDmax,Revues[i].ID);
            }
            c_revue->ID = IDmax+10;
            
            Revues.push_back(*c_revue); 
        } else if (Type_res == cd) {
        // Il s'agit d'un CD
            CD *c_CD = new CD();
            std::cout << "Quel est le nom du CD ? ";
            getline(std::cin >> std::ws, tmp);
            c_CD->Titre = tmp;

            std::cout << "Quel est le nom de l'artiste ? ";
            getline(std::cin >> std::ws, tmp);
            c_CD->Auteur = tmp;

            std::cout << "Quel est la maison de production ? ";
            getline(std::cin >> std::ws, tmp);
            c_CD->Maison_production = tmp;

            while (!est_un_nombre) {
                std::cout << "Quand est sorti le CD ? ";
                getline(std::cin >> std::ws, tmp);
                if (tmp.find_first_not_of(CHIFFRE) == std::string::npos) {
                    est_un_nombre = true;
                }
            }
            est_un_nombre = false;
            c_CD->Annee = stoi(tmp);

            while (!est_un_nombre) {
                std::cout << "Quelle est la durée du CD ? ";
                getline(std::cin >> std::ws, tmp);
                if (tmp.find_first_not_of(CHIFFRE) == std::string::npos) {
                    est_un_nombre = true;
                }
            }
            est_un_nombre = false;
            c_CD->Duree = stoi(tmp);

            while (!est_un_nombre) {
                std::cout << "Quelle est le nombre de pistes ? ";
                getline(std::cin >> std::ws, tmp);
                if (tmp.find_first_not_of(CHIFFRE) == std::string::npos) {
                    est_un_nombre = true;
                }
            }
            est_un_nombre = false;
            c_CD->Nb_pistes = stoi(tmp);
            
            int IDmax=-8;
            for (unsigned i=0; i<CDs.size();i++){
                IDmax = std::max(IDmax,CDs[i].ID);
            }
            c_CD->ID = IDmax+10;
            // On ajoute le CD dans la réserve de CDs
            CDs.push_back(*c_CD); 
        } else if (Type_res == vhs) { 
            // Il s'agit d'un VHS
            VHS *c_VHS = new VHS;
            std::cout << "Quel est le nom du VHS ? ";
            getline(std::cin >> std::ws, tmp);
            c_VHS->Titre = tmp;

            std::cout << "Quel est le nom de l'auteur ? ";
            getline(std::cin >> std::ws, tmp);
            c_VHS->Auteur = tmp;

            std::cout << "Quel est la maison de production ? ";
            getline(std::cin >> std::ws, tmp);
            c_VHS->Maison_production = tmp;

            while (!est_un_nombre) {
                std::cout << "Quelle est la durée du VHS ? ";
                getline(std::cin >> std::ws, tmp);
                if (tmp.find_first_not_of(CHIFFRE) == std::string::npos) {
                    est_un_nombre = true;
                }
            }
            est_un_nombre = false;
            c_VHS->Duree = stoi(tmp);

            int IDmax=-7;
            for (unsigned i=0; i<VHSs.size();i++){
                IDmax = std::max(IDmax,VHSs[i].ID);
            }
            c_VHS->ID = IDmax+10;
            // On ajoute le VHS dans la réserve de VHSs
            VHSs.push_back(*c_VHS); 
        } else if (Type_res == dvd) { 
            // Il s'agit d'un DVD
            DVD *c_DVD = new DVD();
            std::cout << "Quel est le nom du DVD ? ";
            getline(std::cin >> std::ws, tmp);
            c_DVD->Titre = tmp;

            std::cout << "Quel est le nom de l'auteur ? ";
            getline(std::cin >> std::ws, tmp);
            c_DVD->Auteur = tmp;

            std::cout << "Quel est la maison de production ? ";
            getline(std::cin >> std::ws, tmp);
            c_DVD->Maison_production = tmp;

            while (!est_un_nombre) {
                std::cout << "Quelle est la durée du DVD ? ";
                getline(std::cin >> std::ws, tmp);
                if (tmp.find_first_not_of(CHIFFRE) == std::string::npos) {
                    est_un_nombre = true;
                }
            }
            est_un_nombre = false;
            c_DVD->Duree = stoi(tmp);

            while (!est_un_nombre) {
                std::cout << "Quelle est le nombre de chapitres ? ";
                getline(std::cin >> std::ws, tmp);
                if (tmp.find_first_not_of(CHIFFRE) == std::string::npos) {
                    est_un_nombre = true;
                }
            }
            est_un_nombre = false;
            c_DVD->Chapitres = stoi(tmp);

            int IDmax=-6;
            for (unsigned i=0; i<DVDs.size();i++){
                IDmax = std::max(IDmax,DVDs[i].ID);
            }
            c_DVD->ID = IDmax+10;
            // On ajoute le DVD dans la réserve de DVDs
            DVDs.push_back(*c_DVD);  
        } else if (Type_res == ressource_num) { 
            // Il s'agit d'une ressource numérique
            RessourceNum *c_RessourceNum = new RessourceNum();
            std::cout << "Quel est le titre de la ressource numérique ? ";
            getline(std::cin >> std::ws, tmp);
            c_RessourceNum->Titre = tmp;

            std::cout << "Quel est le nom de l'auteur ? ";
            getline(std::cin >> std::ws, tmp);
            c_RessourceNum->Auteur = tmp;

            std::cout << "Quel est le type de la ressource numérique ? ";
            getline(std::cin >> std::ws, tmp);
            c_RessourceNum->Type = tmp;

            std::cout << "Quel est la taille de la ressource ?";
            getline(std::cin >> std::ws, tmp);
            c_RessourceNum->Taille = tmp;
            
            std::cout << "Chemin vers la ressource : ";
            getline(std::cin >> std::ws, tmp);
            c_RessourceNum->Chemin = tmp;

            int IDmax=-5;
            for (unsigned i=0; i<Ressources_nums.size();i++){
                IDmax = std::max(IDmax,Ressources_nums[i].ID);
            }
            c_RessourceNum->ID = IDmax+10;
            // On ajoute la RessourceNum dans la réserve de RessourcesNums
            Ressources_nums.push_back(*c_RessourceNum); 
        } 
    }    
    Clear(); // Mise à jour de la base de donnée
}

void Bibliotheque::Delete(int ID_to_suppress) {
    for (std::vector<Livre>::iterator it = Livres.begin(); it != Livres.end(); ++it) 
    {   
        if (ID_to_suppress == it->ID) {
            Livres.erase(it);
            return;
        }
    }
    for (std::vector<Revue>::iterator it = Revues.begin(); it != Revues.end(); ++it ) {
        if (ID_to_suppress == it->ID) {
            Revues.erase(it);
            return;
        }
    }
    for (std::vector<CD>::iterator it = CDs.begin(); it != CDs.end(); ++it ) {
        if (ID_to_suppress == it->ID) {
            CDs.erase(it);
            return;
        }
    }
    for (std::vector<VHS>::iterator it = VHSs.begin(); it != VHSs.end(); ++it ) {
        if (ID_to_suppress == it->ID) {
            VHSs.erase(it);
            return;
        }
    }
    for (std::vector<DVD>::iterator it = DVDs.begin(); it != DVDs.end(); ++it ) {
        if (ID_to_suppress == it->ID) {
            DVDs.erase(it);
            return;
        }
    }
    for (std::vector<RessourceNum>::iterator it = Ressources_nums.begin(); it != Ressources_nums.end(); ++it ) {
        if (ID_to_suppress == it->ID) {
            Ressources_nums.erase(it);
            return;
        }
    }
    std::cout << YELLOW << "L'ID n'a pas été trouvée dans nos instances de médias." << YELLOW << std::endl;
}

void Bibliotheque::Load(std::string filename) {
    /*  
        Ouvre le fichier qui détient la ressource
        Chaque ligne du fichier correspond à une instance de classe de la ressource correspondante
    */
    std::ifstream fichier (filename);

    std::string line;
    int ID;

    // Nous commençons par parcourrir le fichier pour connaitre le nombre de médias par type
    int c_l = 0;        // Compteur de livres
    int c_r = 0;        // Compteur de revues
    int c_cd = 0;       // Compteur de CDs
    int c_vhs = 0;      // Compteur de VHSs
    int c_dvd = 0;      // Compteur de DVDs
    int c_res_num = 0;  // Compteur de ressources numériques
    while (std::getline(fichier, line)) 
    {
        // On récupère l'ID
        ID = stoi(line.substr(0, line.find(";;;", 0)));
        switch (ID % 10)
        {
        case 0:
            c_l++;
            break;
        case 1:
            c_r++;
            break;
        case 2:
            c_cd++;
            break;
        case 3:
            c_vhs++;
            break;
        case 4:
            c_dvd++;
            break;
        case 5:
            c_res_num++;
            break;
        
        default:
            break;
        }
    }
    fichier.close();

    // Création des futures ressources utiles
    Livre *un_livre = new Livre[c_l];
    Revue *une_revue = new Revue[c_r];
    CD *un_cd = new CD[c_cd];
    VHS *un_vhs = new VHS[c_vhs];
    DVD *un_dvd = new DVD[c_dvd];
    RessourceNum *une_ressource_num = new RessourceNum[c_res_num];

    std::ifstream fichier_reopen (filename);
    while (std::getline(fichier_reopen, line)) 
    {
        int k = 0; // Un compteur permettant de parcourrir la ligne
        int p = k + 3; // Un deuxième compteur pour simplifier l'écriture

        // On récupère l'ID
        ID = stoi(line.substr(k, line.find(";;;", k) - k));
        if (ID % 10 == 0) {
            un_livre[--c_l].ID = ID;
            k = line.find(";;;") + 1;
            p = k + 3;
            
            // On récupère le titre du livre
            un_livre[c_l].Titre = line.substr(p, line.find(";;;", k) - p);
            k = line.find(";;;", p) + 1;
            p = k + 3;

            // On récupère le nom de l'auteur du livre
            un_livre[c_l].Auteur = line.substr(p, line.find(";;;", k) - p);
            k = line.find(";;;", p) + 1;     
            p = k + 3;

            // On récupère la date de parution du livre
            un_livre[c_l].Annee = stoi(line.substr(p, line.find(";;;", k) - p));
            k = line.find(";;;", p) + 1;
            p = k + 3;

            // On récupère le nombre de pages du livre
            un_livre[c_l].Nb_page = stoi(line.substr(p, line.find(";;;", k) - p));
            k = line.find(";;;", p) + 1;
            p = k + 3;

            // On récupère la collection
            un_livre[c_l].Collection = line.substr(p, line.find(";;;", k) - p);
            k = line.find(";;;", p) + 1;
            p = k + 3;

            // On récupère le résumé
            un_livre[c_l].Resume = line.substr(p, line.find(";;;", k) - p);
            k = line.find(";;;", p) + 1;
            p = k + 3;

            // On ajoute le livre dans la réserve de livres
            Livres.push_back(un_livre[c_l]); 
            std::cout << BLUE << un_livre[c_l].Titre << END_COLOR << " est chargé en mémoire." << std::endl;
        } else if (ID % 10 == 1) {
            une_revue[--c_r].ID = ID;
            k = line.find(";;;") + 1;
            p = k + 3;
            
            // On récupère le titre
            une_revue[c_r].Titre = line.substr(p, line.find(";;;", k) - p);
            k = line.find(";;;", p) + 1;
            p = k + 3;

            // On récupère le nom de l'auteur
            une_revue[c_r].Auteur = line.substr(p, line.find(";;;", k) - p);
            k = line.find(";;;", p) + 1;     
            p = k + 3;

            // On récupère la date de parution
            une_revue[c_r].Annee = stoi(line.substr(p, line.find(";;;", k) - p));
            k = line.find(";;;", p) + 1;
            p = k + 3;

            // On récupère le nombre de pages
            une_revue[c_r].Nb_page = stoi(line.substr(p, line.find(";;;", k) - p));
            k = line.find(";;;", p) + 1;
            p = k + 3;

            // On récupère la collection
            une_revue[c_r].Collection = line.substr(p, line.find(";;;", k) - p);
            k = line.find(";;;", p) + 1;
            p = k + 3;

            // On récupère le résumé
            une_revue[c_r].Resume = line.substr(p, line.find(";;;", k) - p);
            k = line.find(";;;", p) + 1;
            p = k + 3;

            // On récupère le nom de l'éditeur
            une_revue[c_r].Editeur = line.substr(p, line.find(";;;", k) - p);
            k = line.find(";;;", p) + 1;
            p = k + 3;

            // On récupère le nombre d'article
            une_revue[c_r].N_articles = stoi(line.substr(p, line.find(";;;", k) - p));
            k = line.find(";;;", p) + 1;
            p = k + 3;

            // On récupère le nom des articles
            for (int i = 0; i < une_revue[c_r].N_articles; i++) {
                une_revue[c_r].Nom_articles[i] = line.substr(p, line.find(";;;", k) - p);
                k = line.find(";;;", p) + 1;
                p = k + 3;
            }
            // On ajoute la revue dans la réserve de revues
            Revues.push_back(une_revue[c_r]); 
            std::cout << BLUE << une_revue[c_r].Titre << END_COLOR << " est chargé en mémoire." << std::endl;
        } else if (ID % 10 == 2) {
            un_cd[--c_cd].ID = ID;
            k = line.find(";;;") + 1;
            p = k + 3;
            
            // On récupère le titre
            un_cd[c_cd].Titre = line.substr(p, line.find(";;;", k) - p);
            k = line.find(";;;", p) + 1;
            p = k + 3;

            // On récupère le nom du groupe ou de l'artiste
            un_cd[c_cd].Auteur = line.substr(p, line.find(";;;", k) - p);
            k = line.find(";;;", p) + 1;     
            p = k + 3;

            // On récupère la date de sortie du CD
            un_cd[c_cd].Annee = stoi(line.substr(p, line.find(";;;", k) - p));
            k = line.find(";;;", p) + 1;
            p = k + 3;

            // On récupère la duree
            un_cd[c_cd].Duree = line.substr(p, line.find(";;;", k) - p);
            k = line.find(";;;", p) + 1;
            p = k + 3;

            // On récupère le producteur
            un_cd[c_cd].Maison_production = line.substr(p, line.find(";;;", k) - p);
            k = line.find(";;;", p) + 1;
            p = k + 3;

            // On récupère le nombre de pistes
            un_cd[c_cd].Nb_pistes = stoi(line.substr(p, line.find(";;;", k) - p));

            CDs.push_back(un_cd[c_cd]); 
            std::cout << BLUE << un_cd[c_cd].Titre << END_COLOR << " est chargé en mémoire." << std::endl;
        } else if (ID % 10 == 3) {
            un_vhs[--c_vhs].ID = ID;
            k = line.find(";;;") + 1;
            p = k + 3;
            
            // On récupère le titre
            un_vhs[c_vhs].Titre = line.substr(p, line.find(";;;", k) - p);
            k = line.find(";;;", p) + 1;
            p = k + 3;

            // On récupère le nom de l'auteur
            un_vhs[c_vhs].Auteur = line.substr(p, line.find(";;;", k) - p);
            k = line.find(";;;", p) + 1;     
            p = k + 3;

            // On récupère la date de parution
            un_vhs[c_vhs].Annee = stoi(line.substr(p, line.find(";;;", k) - p));
            k = line.find(";;;", p) + 1;
            p = k + 3;

            // On récupère la maison de production
            un_vhs[c_vhs].Maison_production = line.substr(p, line.find(";;;", k) - p);
            k = line.find(";;;", p) + 1;
            p = k + 3;

            // On récupère la durée
            un_vhs[c_vhs].Duree = line.substr(p, line.find(";;;", k) - p);

            VHSs.push_back(un_vhs[c_vhs]); 
            std::cout << BLUE << un_vhs[c_vhs].Titre << END_COLOR << " est chargé en mémoire." << std::endl;
        } else if (ID % 10 == 4) {
            un_dvd[--c_dvd].ID = ID;
            k = line.find(";;;") + 1;
            p = k + 3;
            
            // On récupère le titre
            un_dvd[c_dvd].Titre = line.substr(p, line.find(";;;", k) - p);
            k = line.find(";;;", p) + 1;
            p = k + 3;

            // On récupère le nom de l'auteur
            un_dvd[c_dvd].Auteur = line.substr(p, line.find(";;;", k) - p);
            k = line.find(";;;", p) + 1;     
            p = k + 3;

            // On récupère la date de parution
            un_dvd[c_dvd].Annee = stoi(line.substr(p, line.find(";;;", k) - p));
            k = line.find(";;;", p) + 1;
            p = k + 3;

            // On récupère la maison de production
            un_dvd[c_dvd].Maison_production = line.substr(p, line.find(";;;", k) - p);
            k = line.find(";;;", p) + 1;
            p = k + 3;

            // On récupère la Duree
            un_dvd[c_dvd].Duree = line.substr(p, line.find(";;;", k) - p);
            k = line.find(";;;", p) + 1;
            p = k + 3;

            // On récupère le nombre de chapitres
            un_dvd[c_dvd].Chapitres = stoi(line.substr(p, line.find(";;;", k) - p));

            DVDs.push_back(un_dvd[c_dvd]); 
            std::cout << BLUE << un_dvd[c_dvd].Titre << END_COLOR << " est chargé en mémoire." << std::endl;
        } else if (ID % 10 == 5) {
            une_ressource_num[--c_res_num].ID = ID;
            k = line.find(";;;") + 1;
            p = k + 3;
            
            // On récupère le titre
            une_ressource_num[c_res_num].Titre = line.substr(p, line.find(";;;", k) - p);
            k = line.find(";;;", p) + 1;
            p = k + 3;

            // On récupère le nom de l'auteur
            une_ressource_num[c_res_num].Auteur = line.substr(p, line.find(";;;", k) - p);
            k = line.find(";;;", p) + 1;     
            p = k + 3;

            // On récupère la date de parution
            une_ressource_num[c_res_num].Annee = stoi(line.substr(p, line.find(";;;", k) - p));
            k = line.find(";;;", p) + 1;
            p = k + 3;

            // On récupère le type de la ressource
            une_ressource_num[c_res_num].Type = line.substr(p, line.find(";;;", k) - p);
            k = line.find(";;;", p) + 1;
            p = k + 3;

            // On récupère la taille
            une_ressource_num[c_res_num].Taille = line.substr(p, line.find(";;;", k) - p);
            k = line.find(";;;", p) + 1;
            p = k + 3;

            // On récupère le chemin vers la ressource numérique
            une_ressource_num[c_res_num].Chemin = line.substr(p, line.find(";;;", k) - p);

            Ressources_nums.push_back(une_ressource_num[c_res_num]); 
            std::cout << BLUE << une_ressource_num[c_res_num].Titre << END_COLOR << " est chargé en mémoire." << std::endl;
        }
    }
    fichier_reopen.close();
    Clear(); // Mise à jour de la base de donnée
}

void Bibliotheque::Save(std::string filename) {
    std::ofstream fichier (filename, std::ios::app);
    std::string tmp;

    for (std::vector<Livre>::iterator it = Livres.begin(); it != Livres.end(); ++it) {
        tmp = "";
        tmp.append(std::to_string(it->ID));
        tmp.append(";;; ");
        tmp.append(it->Titre);
        tmp.append(";;; ");
        tmp.append(it->Auteur);
        tmp.append(";;; ");
        tmp.append(std::to_string(it->Annee));
        tmp.append(";;; ");
        tmp.append(std::to_string(it->Nb_page));
        tmp.append(";;; ");
        tmp.append(it->Collection);
        tmp.append(";;; ");
        tmp.append(it->Resume);
        tmp.append(";;;\n");
        fichier << tmp;
    }
    std::cout << YELLOW << "Les livres sont sauvegardés." << END_COLOR << std::endl;
    for (std::vector<Revue>::iterator it = Revues.begin(); it != Revues.end(); ++it) {
        tmp = "";
        tmp.append(std::to_string(it->ID));
        tmp.append(";;; ");
        tmp.append(it->Titre);
        tmp.append(";;; ");
        tmp.append(it->Auteur);
        tmp.append(";;; ");
        tmp.append(std::to_string(it->Annee));
        tmp.append(";;; ");
        tmp.append(std::to_string(it->Nb_page));
        tmp.append(";;; ");
        tmp.append(it->Collection);
        tmp.append(";;; ");
        tmp.append(it->Resume);
        tmp.append(";;; ");
        tmp.append(it->Editeur);
        tmp.append(";;; ");
        tmp.append(std::to_string(it->N_articles));
        for (int k = 0; k < it->N_articles; ++k){
            tmp.append(";;; ");    
            tmp.append(it->Nom_articles[k]);
        }        
        tmp.append(";;;\n");
        fichier << tmp;
    }
    std::cout << YELLOW << "Les revues sont sauvegardées." << END_COLOR << std::endl;
    for (std::vector<CD>::iterator it = CDs.begin(); it != CDs.end(); ++it) {
        tmp = "";
        tmp.append(std::to_string(it->ID));
        tmp.append(";;; ");
        tmp.append(it->Titre);
        tmp.append(";;; ");
        tmp.append(it->Auteur);
        tmp.append(";;; ");
        tmp.append(std::to_string(it->Annee));
        tmp.append(";;; ");
        tmp.append(it->Duree);
        tmp.append(";;; ");
        tmp.append(it->Maison_production);
        tmp.append(";;; ");
        tmp.append(std::to_string(it->Nb_pistes));
        tmp.append(";;;\n");
        fichier << tmp;
    }
    std::cout << YELLOW << "Les CDs sont sauvegardés." << END_COLOR << std::endl;
    for (std::vector<VHS>::iterator it = VHSs.begin(); it != VHSs.end(); ++it) {
        tmp = "";
        tmp.append(std::to_string(it->ID));
        tmp.append(";;; ");
        tmp.append(it->Titre);
        tmp.append(";;; ");
        tmp.append(it->Auteur);
        tmp.append(";;; ");
        tmp.append(std::to_string(it->Annee));
        tmp.append(";;; ");
        tmp.append(it->Maison_production);
        tmp.append(";;; ");
        tmp.append(it->Duree);
        tmp.append(";;;\n");
        fichier << tmp;
    }
    std::cout << YELLOW << "Les VHSs sont sauvegardés." << END_COLOR << std::endl;
    for (std::vector<DVD>::iterator it = DVDs.begin(); it != DVDs.end(); ++it) {
        tmp = "";
        tmp.append(std::to_string(it->ID));
        tmp.append(";;; ");
        tmp.append(it->Titre);
        tmp.append(";;; ");
        tmp.append(it->Auteur);
        tmp.append(";;; ");
        tmp.append(std::to_string(it->Annee));
        tmp.append(";;; ");
        tmp.append(it->Maison_production);
        tmp.append(";;; ");
        tmp.append(it->Duree);
        tmp.append(";;; ");
        tmp.append(std::to_string(it->Chapitres));
        tmp.append(";;;\n");
        fichier << tmp;
    }
    std::cout << YELLOW << "Les DVDs sont sauvegardés." << END_COLOR << std::endl;
    for (std::vector<RessourceNum>::iterator it = Ressources_nums.begin(); it != Ressources_nums.end(); ++it) {
        tmp = "";
        tmp.append(std::to_string(it->ID));
        tmp.append(";;; ");
        tmp.append(it->Titre);
        tmp.append(";;; ");
        tmp.append(it->Auteur);
        tmp.append(";;; ");
        tmp.append(std::to_string(it->Annee));
        tmp.append(";;; ");
        tmp.append(it->Type);
        tmp.append(";;; ");
        tmp.append(it->Taille);
        tmp.append(";;; ");
        tmp.append(it->Chemin);
        tmp.append(";;;\n");
        fichier << tmp;
    }
    std::cout << YELLOW << "Les ressources numériques sont sauvegardées." << END_COLOR << std::endl;
    fichier.close();
}

void Bibliotheque::List() {
    std::string line;
    std::string substring = "";
    bool is_empty = true;
    int k = 0; // un compteur
    if (!Livres.empty()) {
        is_empty = false;
        ListDisplay(livre); // Le tableau d'affichage des livres
        for (auto it = Livres.begin(); it != Livres.end(); ++it) {
            if (std::count(Found_ID.begin(), Found_ID.end(), it->ID)) {
                std::string substring = "|";
                substring.append(Largeur_affichage(std::to_string(it->ID), 6)); // ID
                substring.append(Largeur_affichage(it->Titre, 21)); // Titre
                substring.append(Largeur_affichage(it->Auteur, 23)); // Auteur
                substring.append(Largeur_affichage(std::to_string(it->Annee), 9));
                std::cout << PURPLE << substring << END_COLOR <<std::endl;
            }
            k++;
        }
        std::cout << YELLOW << " --------------------------------------------------------------\n\n" << END_COLOR << std::endl; 
    }
    k = 0;
    if (!Revues.empty()) {
        is_empty = false;
        ListDisplay(revue); // Le tableau d'affichage des livres
        for (auto it = Revues.begin(); it != Revues.end(); ++it) {
            if (std::count(Found_ID.begin(), Found_ID.end(), it->ID)) {
                std::string substring = "|";
                substring.append(Largeur_affichage(std::to_string(it->ID), 6)); // ID
                substring.append(Largeur_affichage(it->Titre, 21)); // Titre
                substring.append(Largeur_affichage(it->Auteur, 23)); // Auteur
                substring.append(Largeur_affichage(std::to_string(it->Annee), 9));
                std::cout << PURPLE << substring << END_COLOR <<std::endl;
            }
            k++;
        }
    std::cout << YELLOW << " --------------------------------------------------------------\n\n" << END_COLOR << std::endl; 
    }   
    k = 0;
    if (!CDs.empty()) {
        is_empty = false;
        ListDisplay(cd); // Le tableau d'affichage des livres
        for (auto it = CDs.begin(); it != CDs.end(); ++it) {
            if (std::count(Found_ID.begin(), Found_ID.end(), it->ID)) {
                std::string substring = "|";
                substring.append(Largeur_affichage(std::to_string(it->ID), 6)); // ID
                substring.append(Largeur_affichage(it->Titre, 21)); // Titre
                substring.append(Largeur_affichage(it->Auteur, 23)); // Auteur
                substring.append(Largeur_affichage(std::to_string(it->Annee), 9));
                std::cout << PURPLE << substring << END_COLOR <<std::endl;
            }
            k++;
        }
    std::cout << YELLOW << " --------------------------------------------------------------\n\n" << END_COLOR << std::endl; 
    }
    k = 0;
    if (!VHSs.empty()) {
        is_empty = false;
        ListDisplay(vhs); // Le tableau d'affichage des livres
        for (auto it = VHSs.begin(); it != VHSs.end(); ++it) {
            if (std::count(Found_ID.begin(), Found_ID.end(), it->ID)) {
                std::string substring = "|";
                substring.append(Largeur_affichage(std::to_string(it->ID), 6)); // ID
                substring.append(Largeur_affichage(it->Titre, 21)); // Titre
                substring.append(Largeur_affichage(it->Auteur, 23)); // Auteur
                substring.append(Largeur_affichage(std::to_string(it->Annee), 9));
                std::cout << PURPLE << substring << END_COLOR <<std::endl;
            }
            k++;
        }
    std::cout << YELLOW << " --------------------------------------------------------------\n\n" << END_COLOR << std::endl; 
    }
    k = 0;
    if (!DVDs.empty()) {
        is_empty = false;
        ListDisplay(dvd); // Le tableau d'affichage des livres
        for (auto it = DVDs.begin(); it != DVDs.end(); ++it) {
            if (std::count(Found_ID.begin(), Found_ID.end(), it->ID)) {
                std::string substring = "|";
                substring.append(Largeur_affichage(std::to_string(it->ID), 6)); // ID
                substring.append(Largeur_affichage(it->Titre, 21)); // Titre
                substring.append(Largeur_affichage(it->Auteur, 23)); // Auteur
                substring.append(Largeur_affichage(std::to_string(it->Annee), 9));
                std::cout << PURPLE << substring << END_COLOR <<std::endl;
            }
            k++;
        }
        std::cout << YELLOW << " --------------------------------------------------------------\n\n" << END_COLOR << std::endl; 
    }
    k = 0;  
    if (!Ressources_nums.empty()) {
        is_empty = false;
        ListDisplay(ressource_num); // Le tableau d'affichage des livres
        for (auto it = Ressources_nums.begin(); it != Ressources_nums.end(); ++it) {
            if (std::count(Found_ID.begin(), Found_ID.end(), it->ID)) {
                std::string substring = "|";
                substring.append(Largeur_affichage(std::to_string(it->ID), 6)); // ID
                substring.append(Largeur_affichage(it->Titre, 21)); // Titre
                substring.append(Largeur_affichage(it->Auteur, 23)); // Auteur
                substring.append(Largeur_affichage(std::to_string(it->Annee), 9));
                std::cout << PURPLE << substring << END_COLOR <<std::endl;
            }
            k++;
        }
        std::cout << YELLOW << " --------------------------------------------------------------\n\n" << END_COLOR << std::endl; 
    }
    if (is_empty) {
        std::cout << YELLOW << "Nous n'avons rien à afficher car notre base de données courante est vide." << END_COLOR << std::endl;
    }
}

void Bibliotheque::Show(int id) {
    for (auto it = Livres.begin(); it != Livres.end(); ++it) {
        if (it->ID == id) {
            std::cout << YELLOW << "Titre : " << END_COLOR << PURPLE << it->Titre << END_COLOR << std::endl;
            std::cout << YELLOW << "Auteur : " << END_COLOR << PURPLE << it->Auteur << END_COLOR << std::endl;
            std::cout << YELLOW << "Date : " << END_COLOR << PURPLE << it->Annee << END_COLOR << std::endl;
            std::cout << YELLOW << "Nombre de pages : " << END_COLOR << PURPLE << it->Nb_page << END_COLOR << std::endl;
            std::cout << YELLOW << "Collection : " << END_COLOR << PURPLE << it->Collection << END_COLOR << std::endl;
            std::cout << YELLOW << "Résumé : " << END_COLOR << PURPLE << it->Resume << END_COLOR << std::endl;
            return;

        }
    }
    for (auto it = Revues.begin(); it != Revues.end(); ++it) {
        if (it->ID == id) {
            std::cout << YELLOW << "Titre : " <<  END_COLOR << PURPLE << it->Titre << END_COLOR << std::endl;
            std::cout << YELLOW << "Auteur : "<<  END_COLOR << PURPLE << it->Auteur << END_COLOR << std::endl;
            std::cout << YELLOW << "Date : "<<  END_COLOR << PURPLE << it->Annee << END_COLOR << std::endl;
            std::cout << YELLOW << "Pages : "<<  END_COLOR << PURPLE << it->Nb_page << END_COLOR << std::endl;
            std::cout << YELLOW << "Collection : " <<  END_COLOR << PURPLE << it->Collection << END_COLOR << std::endl;
            std::cout << YELLOW << "Nombre d'articles : " << END_COLOR << PURPLE <<  it->N_articles << END_COLOR << std::endl;
            for (auto article : it->Nom_articles) {
                std::cout << YELLOW << "Article 1 : " << END_COLOR << PURPLE << article << END_COLOR;
            }
            std::cout << YELLOW << "Résumé : " << END_COLOR << PURPLE << it->Resume << END_COLOR << std::endl;
            return;
        }
    }
    for (auto it = CDs.begin(); it != CDs.end(); ++it) {
        if (it->ID == id) {
            std::cout << YELLOW << "Titre : " << END_COLOR << PURPLE << it->Titre << END_COLOR << std::endl;
            std::cout << YELLOW << "Artiste/Groupe : " << END_COLOR << PURPLE << it->Auteur << END_COLOR << std::endl;
            std::cout << YELLOW << "Date : " << END_COLOR << PURPLE << it->Annee << END_COLOR << std::endl;
            std::cout << YELLOW << "Durée : " << END_COLOR << PURPLE << it->Duree << END_COLOR << std::endl;
            std::cout << YELLOW << "Maison de production : " << END_COLOR << PURPLE << it->Maison_production << END_COLOR << std::endl;
            std::cout << YELLOW << "Nombre de pistes : " << END_COLOR << PURPLE << it->Nb_pistes << END_COLOR << std::endl;
            return;
        }
    }
    for (auto it = VHSs.begin(); it != VHSs.end(); ++it) {
        if (it->ID == id) {
            std::cout << YELLOW << "Titre : " << END_COLOR << PURPLE << it->Titre << END_COLOR << std::endl;
            std::cout << YELLOW << "Auteur : " << END_COLOR << PURPLE << it->Auteur << END_COLOR << std::endl;
            std::cout << YELLOW << "Date : " << END_COLOR << PURPLE << it->Annee << END_COLOR << std::endl;
            std::cout << YELLOW << "Durée : " << END_COLOR << PURPLE << it->Duree << END_COLOR << std::endl;
            std::cout << YELLOW << "Maison de production : " << END_COLOR << PURPLE << it->Maison_production << END_COLOR << std::endl;
            return;
        }
    }
    for (auto it = DVDs.begin(); it != DVDs.end(); ++it) {
        if (it->ID == id) {
            std::cout << YELLOW << "Titre : " << END_COLOR << PURPLE << it->Titre << END_COLOR << std::endl;
            std::cout << YELLOW << "Auteur : " << END_COLOR << PURPLE << it->Auteur << END_COLOR << std::endl;
            std::cout << YELLOW << "Date : " << END_COLOR << PURPLE << it->Annee << END_COLOR << std::endl;
            std::cout << YELLOW << "Durée : " << END_COLOR << PURPLE << it->Duree << END_COLOR << std::endl;
            std::cout << YELLOW << "Maison de production : " << END_COLOR << PURPLE << it->Maison_production << END_COLOR << std::endl;
            std::cout << YELLOW << "Nombre de chapitres : " << END_COLOR << PURPLE << it->Chapitres << END_COLOR << std::endl;
            return;

        }
    }
    for (auto it = Ressources_nums.begin(); it != Ressources_nums.end(); ++it) {
        if (it->ID == id) {
            std::cout << YELLOW << "Titre : " << END_COLOR << PURPLE << it->Titre << END_COLOR << std::endl;
            std::cout << YELLOW << "Auteur : " << END_COLOR << PURPLE << it->Auteur << END_COLOR << std::endl;
            std::cout << YELLOW << "Date : " << END_COLOR << PURPLE << it->Annee << END_COLOR << std::endl;
            std::cout << YELLOW << "Type : " << END_COLOR << PURPLE << it->Type << END_COLOR << std::endl;
            std::cout << YELLOW << "Taille : " << END_COLOR << PURPLE << it->Taille << END_COLOR << std::endl;
            std::cout << YELLOW << "Chemin : " << END_COLOR << PURPLE << it->Chemin << END_COLOR << std::endl;
            return;
        }
    }
    std::cout << YELLOW << "l'ID " << id << " ne correspond à aucun média dans notre bibliothèque." << END_COLOR << std::endl;
}

void Bibliotheque::Search(std::string recherche) {
    std::vector<int> new_reaserch_ID; // Vecteur contenant les ID temporaires de la recherche
    bool condition = false;
    // Parcourrir toutes les données parmi les ID trouvés lors de la recherche précédente
    for (auto it = Livres.begin(); it != Livres.end(); ++it) {
        condition = std::to_string(it->ID) == recherche;
        condition = condition || it->Titre == recherche;
        condition = condition || it->Auteur == recherche;
        condition = condition || std::to_string(it->Annee) == recherche;
        condition = condition || std::to_string(it->Nb_page) == recherche;
        condition = condition || it->Collection == recherche;
        condition = condition || it->Resume == recherche;
        condition = condition && std::count(Found_ID.begin(), Found_ID.end(), it->ID); // L'ID est-il dans la base de donnée courante ?
        if(condition) {
            new_reaserch_ID.push_back(it->ID);
        }
    }
    for (auto it = Revues.begin(); it != Revues.end(); ++it) {
        condition = condition || std::to_string(it->ID) == recherche;
        condition = condition || it->Titre == recherche;
        condition = condition || it->Auteur == recherche;
        condition = condition || std::to_string(it->Annee) == recherche;
        condition = condition || std::to_string(it->Nb_page) == recherche;
        condition = condition || it->Collection == recherche;
        condition = condition || it->Resume == recherche;
        condition = condition || it->Editeur == recherche;
        condition = condition || std::to_string(it->N_articles) == recherche;
        for (int k = 0; k < it->N_articles; ++k){
            condition = condition || it->Nom_articles[k] == recherche;
        } 
        condition = condition && std::count(Found_ID.begin(), Found_ID.end(), it->ID);
        if(condition) {
            new_reaserch_ID.push_back(it->ID);
        }
    }
    for (auto it = CDs.begin(); it != CDs.end(); ++it) {
        condition = std::to_string(it->ID) == recherche;
        condition = condition || it->Titre == recherche;
        condition = condition || it->Auteur == recherche;
        condition = condition || std::to_string(it->Annee) == recherche;
        condition = condition || it->Duree == recherche;
        condition = condition || it->Maison_production == recherche;
        condition = condition || std::to_string(it->Nb_pistes) == recherche;
        condition = condition && std::count(Found_ID.begin(), Found_ID.end(), it->ID);
        if(condition) {
            new_reaserch_ID.push_back(it->ID);
        }
    }
    for (auto it = VHSs.begin(); it != VHSs.end(); ++it) {
        condition = std::to_string(it->ID) == recherche;
        condition = condition || it->Titre == recherche;
        condition = condition || it->Auteur == recherche;
        condition = condition || std::to_string(it->Annee) == recherche;
        condition = condition || it->Maison_production == recherche;
        condition = condition || it->Duree == recherche;
        condition = condition && std::count(Found_ID.begin(), Found_ID.end(), it->ID);
        if(condition) {
            new_reaserch_ID.push_back(it->ID);
        }
    }
    for (auto it = DVDs.begin(); it != DVDs.end(); ++it) {
        condition = std::to_string(it->ID) == recherche;
        condition = condition || it->Titre == recherche;
        condition = condition || it->Auteur == recherche;
        condition = condition || std::to_string(it->Annee) == recherche;
        condition = condition || it->Maison_production == recherche;
        condition = condition || it->Duree == recherche;
        condition = condition || std::to_string(it->Chapitres) == recherche;
        condition = condition && std::count(Found_ID.begin(), Found_ID.end(), it->ID);
        if(condition) {
            new_reaserch_ID.push_back(it->ID);
        }
    }
    for (std::vector<RessourceNum>::iterator it = Ressources_nums.begin(); it != Ressources_nums.end(); ++it) {
        condition = std::to_string(it->ID) == recherche;
        condition = condition || it->Titre == recherche;
        condition = condition || it->Auteur == recherche;
        condition = condition || std::to_string(it->Annee) == recherche;
        condition = condition || it->Type == recherche;
        condition = condition || it->Taille == recherche;
        condition = condition || it->Chemin == recherche;
        condition = condition && std::count(Found_ID.begin(), Found_ID.end(), it->ID);
        if(condition) {
            new_reaserch_ID.push_back(it->ID);
        }
    }
    Found_ID = new_reaserch_ID; // Nous mettons à jours la base de donnée;
    std::cout << YELLOW << "Nous avons trouvés " << Found_ID.size() << " ressources correspondant à votre recherche. ";
    std::cout << "Écrivez \"LIST\" pour les afficher. " << END_COLOR << std::endl;
}

void Bibliotheque::Clear() {
    /* Remet à jour la base de donnée courante */
    Found_ID.clear();
    for (std::vector<Livre>::iterator it = Livres.begin(); it != Livres.end(); ++it) {
        Found_ID.push_back(it->ID);
    }
    for (std::vector<Revue>::iterator it = Revues.begin(); it != Revues.end(); ++it) {
        Found_ID.push_back(it->ID);
    }
    for (std::vector<CD>::iterator it = CDs.begin(); it != CDs.end(); ++it) {
        Found_ID.push_back(it->ID);
    }
    for (std::vector<VHS>::iterator it = VHSs.begin(); it != VHSs.end(); ++it) {
        Found_ID.push_back(it->ID);
    }
    for (std::vector<DVD>::iterator it = DVDs.begin(); it != DVDs.end(); ++it) {
        Found_ID.push_back(it->ID);
    }
    for (std::vector<RessourceNum>::iterator it = Ressources_nums.begin(); it != Ressources_nums.end(); ++it) {
        Found_ID.push_back(it->ID);
    }
}

void Bibliotheque::Reset(){
    Livres.clear();
    Revues.clear();
    CDs.clear();
    VHSs.clear();
    DVDs.clear();
    Ressources_nums.clear();
    std::cout << YELLOW << "Tous les livres ont été brulé, les DVD cassés, les ordinateurs jetés par la fenêtre." << END_COLOR << std::endl;
}

void Bibliotheque::Reserver() {
    std::cout << "Quel est le titre de la ressource que vous souhaitez reserver ? " << std::endl;
}

void Bibliotheque::ListDisplay(int i=0) {
    /*
        Permet d'afficher les hauts des tableaux affichant les ressources
    */
    switch (i) {
        case 0: // Les livres
            std::cout << YELLOW << "Livre(s) : \n" << END_COLOR;
            std::cout << YELLOW << " -------------------------------------------------------------- " << END_COLOR << std::endl;
            std::cout << YELLOW << "|  ID  |        Titre        |       Auteur          |  Année  |" << END_COLOR << std::endl;
            std::cout << YELLOW << " -------------------------------------------------------------- " << END_COLOR << std::endl; 
            break;
        case 1: // Les Revues
            std::cout  << YELLOW << "Revue(s) : \n";
            std::cout  << YELLOW << " -------------------------------------------------------------- " << END_COLOR << std::endl;
            std::cout  << YELLOW << "|  ID  |        Titre        |       Auteur          |  Année  |" << END_COLOR << std::endl;
            std::cout  << YELLOW << " -------------------------------------------------------------- " << END_COLOR << std::endl; 
            break;
        case 2: // Les CDs
            std::cout  << YELLOW << "CD(s) : \n";
            std::cout  << YELLOW<< " --------------------------------------------------------------- " << END_COLOR << std::endl;
            std::cout  << YELLOW << "|  ID  |        Titre        |    Groupe / Artiste   |  Année  |" << END_COLOR << std::endl;
            std::cout  << YELLOW << " -------------------------------------------------------------- " << END_COLOR << std::endl; 
            break;
        case 3: // Les VHSs
            std::cout  << YELLOW << "VHS(s) : \n";
            std::cout  << YELLOW << " -------------------------------------------------------------- " << END_COLOR << std::endl;
            std::cout  << YELLOW << "|  ID  |        Titre        |      Réalisateur      |  Année  |" << END_COLOR << std::endl;
            std::cout  << YELLOW << " -------------------------------------------------------------- " << END_COLOR << std::endl; 
            break;
        case 4: // Les DVDs
            std::cout  << YELLOW << "DVD(s) : \n";
            std::cout  << YELLOW << " -------------------------------------------------------------- " << END_COLOR << std::endl;
            std::cout  << YELLOW << "|  ID  |        Titre        |      Réalisateur      |  Année  |" << END_COLOR << std::endl;
            std::cout  << YELLOW << " -------------------------------------------------------------- " << END_COLOR << std::endl; 
            break;
        case 5: // Les Ressources Numériques
            std::cout  << YELLOW << "Ressource(s) Numérique(s) : \n";
            std::cout  << YELLOW << " -------------------------------------------------------------- " << END_COLOR << std::endl;
            std::cout  << YELLOW << "|  ID  |        Titre        |        Auteur         |  Année  |" << END_COLOR << std::endl;
            std::cout  << YELLOW << " -------------------------------------------------------------- " << END_COLOR << std::endl; 
            break;
    }
}

std::string Bibliotheque::Largeur_affichage(std::string line, int i) {
    int compteur = line.size();
    if (compteur > i) { // Il faut tonquer la chaine
        return line.substr(0, i).append("|");
    }
    std::string buffer;
    while(compteur < i) {
        if (compteur % 2 == 0) {
            line.append(" ");
        } else {
            buffer = " ";
            buffer.append(line);
            line = buffer;
        }
        compteur++;
    }
    line.append("|");
    return line;
}