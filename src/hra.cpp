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
struct Monstrum {
    std:: string jmeno;
    int zivoty;
    int utok;
    bool miniboss;
    bool hlavniboss;

};
void statistiky(Postava hrac){
    std:: cout << "Charakter: " << hrac.jmeno << std:: endl;
    std:: cout << "Zivoty: " << hrac.zivoty << "/" << hrac.MaxZivoty << std:: endl;
    std:: cout << "Mana: " << hrac.energie << "/" << hrac.MaxEnergie << std:: endl;
    std:: cout << "Utok: " << hrac.silautoku << std:: endl;
    std:: cout << "Level: " << hrac.uroven << " Zkusenosti: " << hrac.zkusenosti << " Zlato: " << hrac.zlato << std:: endl;
    std:: cout << "Schopnosti:" << std::  endl;
    for (int i = 0; i < 2; i++) {
        std:: cout << " " << hrac.schopnosti[i].nazev << " utok: " << hrac.schopnosti[i].utok << ", Mana: " << hrac.schopnosti[i].ubranienergie << ")" << std:: endl;
    }
}


void vylepsenipostava(Postava hrac){
    
}

void vesnice(Postava hrac){
    int rozhodnuti;
    std:: cout << "Vytejte ve vesnici co by ste si chtel koupit" << std:: endl;
    std:: cout << "1 - Doplnit ztivoty (cena 5 zlata)" << std:: endl;
    std:: cout << "2 - Doplnit energii(cena 5 zalta)" << std:: endl;
    std:: cout << "3 - zvisit maximalni zivoty (cena 10 zlata)" << std:: endl;
    std:: cout << "4 - zvisit maximalni energii (cena 10 zalta)" << std:: endl;
    std:: cout << "5 - projit pres vesnici bez zastavky " << std:: endl;
    std:: cin >> rozhodnuti;

    switch (rozhodnuti){
    case 1:
        if (hrac.zlato >= 5){
        hrac.zlato -= 5;
        hrac.zivoty = hrac.MaxZivoty;
        std:: cout << "Doplnil sis zivoty " << std:: endl;
        }else{
        std:: cout << "Nemate dostatek zlata " << std:: endl;
        }
        break;
    case 2:
        if (hrac.zlato >= 5){
        hrac.zlato -= 5;
        hrac.energie = hrac.MaxEnergie;
        std:: cout << "Doplnil sis energii " << std:: endl;
        }else{
        std:: cout << "Nemate dostatek zlata " << std:: endl;
        }
        break;
    case 3:
        if (hrac.zlato >= 10){
            hrac.zlato -= 10;
            hrac.MaxZivoty++;
            std:: cout << "Zvisil sis maximalni Zivoty " << std:: endl;
        }else{
            std:: cout << "Nemate dostatek zlata " << std:: endl;
        }
        break;
    case 4:
        if (hrac.zlato >= 10){
        hrac.zlato -= 10;
        hrac.MaxEnergie++;
        std:: cout << "Zvisil sis maximalni Energii " << std:: endl;
        }else{
        std:: cout << "Nemate dostatek zlata " << std:: endl;
        }
        break;
    case 5:
        std:: cout << "Pokracujete v ceste " << std:: endl;
        break;
    }
}

    void les(Postava &hrac) {
        std::string dej[15];
    }
int main () {
    int vstup;

    std::cout << "Vytejte ve hre plne dobrodruzstvi" << std::endl;
    std::cout << "Tvym cilem bude projit lesem kde potkas mnoho bytosti, pres ktere se musis dostat do kralovstvi." << std::endl;
    std::cout << "Pokud si chcete hru zahrat tak stisknete 1 pokud ne tak stisknete jakekoliv jine cislo" << std::endl;
    std::cin >> vstup;

    if(vstup != 1) {
        std::cout << "Srabe namas odvahu projit strasidlelnym lesem tak se snad brzy uvidime." << std::endl;
        return 0;
    }
    std::cout <<"Dobre pokracujem dal" << std::endl;
    std::cout << "Vyber si za koho chces hrat " << std::endl;
    std::cout << "Ale pozor kazda postava ma jiny pocet energi a zivotu" << std::endl;
    std::cout << "Postavy jsou serazeny od nejlehci po nejtezsi" << std::endl;   


    Postava Charakter[4];

    Charakter[0].jmeno = "Cajda";
    Charakter[0].MaxZivoty = 12;
    Charakter[0].zivoty= 12;
    Charakter[0].MaxEnergie = 6;
    Charakter[0].energie = 6;
    Charakter[0].silautoku = 4;
    Charakter[0].zlato = 0;
    Charakter[0].uroven = 1;
    Charakter[0].schopnosti[0] = {"podpasovka", 3, 1};
    Charakter[0].schopnosti[1] = {"loketni vrazda", 4, 2};

    Charakter[1].jmeno = "Tufo";
    Charakter[1].MaxZivoty = 11;
    Charakter[1].zivoty= 11;
    Charakter[1].MaxEnergie = 6;
    Charakter[1].energie = 6;
    Charakter[1].silautoku = 3;
    Charakter[1].zlato = 0;
    Charakter[1].uroven = 1;
    Charakter[1].schopnosti[0] = {"Pohlavek", 2, 1};
    Charakter[1].schopnosti[1] = {"past", 4, 2};

    Charakter[2].jmeno = "Dratenka";
    Charakter[2].MaxZivoty = 10;
    Charakter[2].zivoty= 10;
    Charakter[2].MaxEnergie = 5;
    Charakter[2].energie = 5;
    Charakter[2].silautoku = 3;
    Charakter[2].zlato = 0;
    Charakter[2].uroven = 1;
    Charakter[2].schopnosti[0] = {"Kledba", 2, 1};
    Charakter[2].schopnosti[1] = {"elektricky sok", 3, 1};

    Charakter[3].jmeno = "Mazak";
    Charakter[3].MaxZivoty = 10;
    Charakter[3].zivoty= 10;
    Charakter[3].MaxEnergie = 4;
    Charakter[3].energie = 4;
    Charakter[3].silautoku = 3;
    Charakter[3].zlato = 0;
    Charakter[3].uroven = 1;
    Charakter[3].schopnosti[0] = {"rana ze zadu", 3, 2};
    Charakter[3].schopnosti[1] = {"vypaleni svetlem", 2, 1};

int vyberpostavy;
do{
    std:: cout << "Vyber si za koho chces hrat";
    std:: cout << ", ale pozor jak uz jsem se zminoval, tak kazda postva umi neco jineho" << std:: endl;
    std:: cout << "Mas tedy na vyber mezi" << " : " << " 1 - Cajdou,  2 - Tufem,  3 - Dratenkou, 4 - Mazakem" << std::endl;
    std:: cin >> vyberpostavy;
    } while (vyberpostavy < 1 || vyberpostavy > 4);
    std:: cout << "Vybral sis " << Charakter[vyberpostavy - 1].jmeno << std:: endl;

    Postava hrace = Charakter[vyberpostavy - 1];
    statistiky(hrace);

    Monstrum monstra[16];
    monstra[0].jmeno = "Bomber" ;
    monstra[0].utok = 2;
    monstra[0].miniboss = false;
    monstra[0].hlavniboss = false;

    monstra[1].jmeno = "Troll" ;
    monstra[1].utok = 3;
    monstra[1].miniboss = false;
    monstra[1].hlavniboss = false;

    monstra[2].jmeno = "Sok" ;
    monstra[2].utok = 3;
    monstra[2].miniboss = false;
    monstra[2].hlavniboss = false;

    monstra[3].jmeno = "Golem" ;
    monstra[3].utok = 6;
    monstra[3].miniboss = false;
    monstra[3].hlavniboss = false;

    monstra[4].jmeno = "Zurivec" ;
    monstra[4].utok = 5;
    monstra[4].miniboss = false;
    monstra[4].hlavniboss = false;

    monstra[5].jmeno = "Barbar" ;
    monstra[5].utok = 4;
    monstra[5].miniboss = false;
    monstra[5].hlavniboss = false;

    monstra[6].jmeno = "Mraz" ;
    monstra[6].utok = 2;
    monstra[6].miniboss = false;
    monstra[6].hlavniboss = false;

    monstra[7].jmeno = "Des" ;
    monstra[7].utok = 5;
    monstra[7].miniboss = false;
    monstra[7].hlavniboss = false;

    monstra[8].jmeno = "Zmar" ;
    monstra[8].utok = 3;
    monstra[8].miniboss = false;
    monstra[8].hlavniboss = false;

    monstra[9].jmeno = "Zkaza" ;
    monstra[9].utok = 4;
    monstra[9].miniboss = false;
    monstra[9].hlavniboss = false;

    monstra[10].jmeno = "Bestie" ;
    monstra[10].utok = 4;
    monstra[10].miniboss = false;
    monstra[10].hlavniboss = false;

    monstra[11].jmeno = "¨Horda" ;
    monstra[11].utok = 6;
    monstra[11].miniboss = false;
    monstra[11].hlavniboss = false;

    monstra[12].jmeno = "Drtic" ;
    monstra[12].utok = 5;
    monstra[12].miniboss = false;
    monstra[12].hlavniboss = false;

    monstra[13].jmeno = "Netvor" ;
    monstra[13].utok = 6;
    monstra[13].miniboss = false;
    monstra[13].hlavniboss = false;

    monstra[14].jmeno = "KAT" ;
    monstra[14].utok = 10;
    monstra[14].miniboss = true;
    monstra[14].hlavniboss = false;

    monstra[15].jmeno = "TYRAN" ;
    monstra[15].utok = 11;
    monstra[15].miniboss = true;
    monstra[15].hlavniboss = false;


}
