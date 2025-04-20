#include <iostream>
#include <string>
// using namespace std;

struct schopnost{
    std::string nazev;
    int utok;
    int ubranienergie;
};

struct Postava{
    std::string jmeno;
    int MaxZivoty;
    int zivoty;
    int MaxEnergie;
    int energie;
    int silautoku;
    int zlato;
    int uroven;
    int zkusenosti;
    schopnost schopnosti[2];
};

void statistiky(Postava hrac){
    std:: cout << "Charakter: " << hrac.jmeno << std:: endl;
    std:: cout << "Zivoty: " << hrac.zivoty << "/" << hrac.MaxZivoty << std:: endl;
    std:: cout << "Mana: " << hrac.energie << "/" << hrac.MaxEnergie << std:: endl;
    std:: cout << "Utok: " << hrac.silautoku << std:: endl;
    std:: cout << "Level: " << hrac.uroven << " Zkusenosti: " << hrac.zkusenosti << " Zlato: " << hrac.zlato << std:: endl;
    std:: cout << "Schopnosti:" << std::  endl;
    for (int i = 0; i < 3; i++) {
        std:: cout << " " << hrac.schopnosti[i].nazev << " utok: " << hrac.schopnosti[i].utok << ", Mana: " << hrac.schopnosti[i].ubranienergie << ")" << std:: endl;
    }
}


void vylepsenipostava(Postava hrac){
    
}

int main () {
    int vstup;

    std::cout << "Vytejte ve hre plne dobrodruzstvi" << std::endl;
    std::cout << "Tvim cilem bude projit lesem kde potkas mnoho bytosti, pres ktere se musis dostat do kralovstvi." << std::endl;
    std::cout << "Pokud si chcete hru zahrat tak stisknete 1 pokud ne tak stisknete cokoliv jineho" << std::endl;
    std::cin >> vstup;

    if(vstup != 1) {
        std::cout << "Srabe namas odvahu projit strasidlelnym lesem : tak se snad brzy uvidime.";
        //retur 0;
    }
    
    std::cout << "Vyber si za koho chces hrat " << std::endl;
    std::cout << "Ale pozor kazda postava ma jiny pocet energi a zivotu" << std::endl;
    std::cout << "Postavy jsou serazeny od nejlehci po nejtezsi" << std::endl;   
    Postava Charakter[4];

    Charakter[0].jmeno = "Cajda";
    Charakter[0].MaxZivoty = 7;
    Charakter[0].zivoty= 7;
    Charakter[0].MaxEnergie = 5;
    Charakter[0].energie = 5;
    Charakter[0].silautoku = 4;
    Charakter[0].zlato = 0;
    Charakter[0].uroven = 1;
    Charakter[0].schopnosti[0] = {"podpasovka", 3, 1};
    Charakter[0].schopnosti[1] = {"loketni vrazda", 4, 2};

    Charakter[1].jmeno = "Tufo";
    Charakter[1].MaxZivoty = 6;
    Charakter[1].zivoty= 6;
    Charakter[1].MaxEnergie = 6;
    Charakter[1].energie = 6;
    Charakter[1].silautoku = 3;
    Charakter[1].zlato = 0;
    Charakter[1].uroven = 1;
    Charakter[1].schopnosti[0] = {"Pohlavek", 2, 1};
    Charakter[1].schopnosti[1] = {"past", 4, 2};

    Charakter[2].jmeno = "Dratenka";
    Charakter[2].MaxZivoty = 5;
    Charakter[2].zivoty= 5;
    Charakter[2].MaxEnergie = 5;
    Charakter[2].energie = 5;
    Charakter[2].silautoku = 3;
    Charakter[2].zlato = 0;
    Charakter[2].uroven = 1;
    Charakter[2].schopnosti[0] = {"Kledba", 2, 1};
    Charakter[2].schopnosti[1] = {"elektricky sok", 3, 1};

    Charakter[3].jmeno = "Mazak";
    Charakter[3].MaxZivoty = 5;
    Charakter[3].zivoty= 5;
    Charakter[3].MaxEnergie = 3;
    Charakter[3].energie = 3;
    Charakter[3].silautoku = 3;
    Charakter[3].zlato = 0;
    Charakter[3].uroven = 1;
    Charakter[3].schopnosti[0] = {"rana ze zadu", 3, 2};
    Charakter[3].schopnosti[1] = {"vypaleni svetlem", 2, 1};

int vyberpostavy;
do{
    std:: cout << "Vyber si za koho chces hrat";
    std:: cout << ", ale pozor jak uz jsem se zminoval, tak kazda postva umi neco jineho" << std:: endl;
    std:: cout << "Mas tedy na vyber mezi" << " : " << "Cajdou, Tufem, Dratenkou a Mazakem";
    std:: cin >> vyberpostavy;
    } while (vyberpostavy < 1 || vyberpostavy > 4);
    
    Postava hrace = Charakter[vyberpostavy - 1];
    statistiky(hrace);

}
