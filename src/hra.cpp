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



void vesnice(Postava &hrac){
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
void souboj1(Postava &hrac){
    Monstrum monster = {"Bomber", 8, 2, false, false};

    std::cout << "Souboj proti " << monster.jmeno << " zapocal" << std::endl;

    while (hrac.zivoty > 0 && monster.zivoty > 0) {
        monster.zivoty -= hrac.silautoku;
        std::cout << "Utokl jsi " << monster.jmeno << " a zpusobil mu " << hrac.silautoku << " zraneni. " 
                  << monster.jmeno << " ma " << monster.zivoty << " zivotu." << std::endl;
        if (monster.zivoty <= 0) {
            std::cout << "Vyhral jsi souboj!" << std::endl;
            hrac.zlato += 5;
            break;
        }

        hrac.zivoty -= monster.utok;
        std::cout << monster.jmeno << " te utocil a zpusobil ti " << monster.utok << " zraneni. Mas " 
                  << hrac.zivoty << " zivotu." << std::endl;
        if (hrac.zivoty <= 0) {
            std::cout << "Prohral jsi souboj." << std::endl;
            break;
        }
    }
}

void souboj2(Postava &hrac){
    Monstrum monster[2] = {
 {"Zmar", 13, 3, false, false},
        {"Des", 10, 5, false, false}
    };

    std::cout << "Souboj proti dvem monstrum zacina, tak se priprav." << std::endl;

    while (hrac.zivoty > 0 && (monster[0].zivoty > 0 || monster[1].zivoty > 0)) {
        for (int i = 0; i < 2; i++) {
            if (monster[i].zivoty > 0) {
                monster[i].zivoty -= hrac.silautoku;
                std::cout << "Utokl jsi " << monster[i].jmeno << " a zpusobil mu " << hrac.silautoku << " zraneni. "
                          << monster[i].jmeno << " ma " << (monster[i].zivoty > 0 ? monster[i].zivoty : 0) << " zivotu." << std::endl;
                if (monster[i].zivoty <= 0) {
                    std::cout << "Zabil jsi " << monster[i].jmeno << "!" << std::endl;
                }
                break;
            }
        }

        bool nekdoZije = false;
        for (int i = 0; i < 2; i++) {
            if (monster[i].zivoty > 0) {
                nekdoZije = true;
                break;
            }
        }
        if (!nekdoZije) {
            std::cout << "Vyhral jsi souboj proti dvem monstrum." << std::endl;
            hrac.zlato += 10;
            break;
        }

        for (int i = 0; i < 2; i++) {
            if (monster[i].zivoty > 0) {
                hrac.zivoty -= monster[i].utok;
                std::cout << monster[i].jmeno << " te utocil a zpusobil ti " << monster[i].utok << " zraneni. Mas "
                          << (hrac.zivoty > 0 ? hrac.zivoty : 0) << " zivotu." << std::endl;
                if (hrac.zivoty <= 0) {
                    std::cout << "Prohral jsi souboj." << std::endl;
                    return;
                }
            }
        }
    }
}

void souboj3(Postava &hrac) {
    Monstrum monster[3] = {
        {"Zkaza", 15, 4, false, false},
        {"Bestie", 16, 4, false, false},
        {"Horda", 15, 6, false, false}
    };

    std::cout << "Tri monstra te napadli." << std::endl;

    while (hrac.zivoty > 0 && (monster[0].zivoty > 0 || monster[1].zivoty > 0 || monster[2].zivoty > 0)) {
        for (int i = 0; i < 3; i++) {
            if (monster[i].zivoty > 0) {
                monster[i].zivoty -= hrac.silautoku;
                std::cout << "Utokl jsi " << monster[i].jmeno << " a zpusobil mu " << hrac.silautoku << " zraneni. "
                          << monster[i].jmeno << " ma " << (monster[i].zivoty > 0 ? monster[i].zivoty : 0) << " zivotu." << std::endl;
                if (monster[i].zivoty <= 0) {
                    std::cout << "Zabil jsi " << monster[i].jmeno << "!" << std::endl;
                }
                break;
            }
        }

        bool nekdoZije = false;
        for (int i = 0; i < 3; i++) {
            if (monster[i].zivoty > 0) {
                nekdoZije = true;
                break;
            }
        }
        if (!nekdoZije) {
            std::cout << "Vyhral jsi souboj proti trem monstrum." << std::endl;
            hrac.zlato += 15;
            break;
        }

        for (int i = 0; i < 3; i++) {
            if (monster[i].zivoty > 0) {
                hrac.zivoty -= monster[i].utok;
                std::cout << monster[i].jmeno << " te utocil a zpusobil ti " << monster[i].utok << " zraneni. Mas "
                          << (hrac.zivoty > 0 ? hrac.zivoty : 0) << " zivotu." << std::endl;
                if (hrac.zivoty <= 0) {
                    std::cout << "Prohral jsi souboj." << std::endl;
                    return;
                }
            }
        }
    }
}

void soubojminiboss(Postava &hrac){
    
}
void soubojhlavniboss(Postava &hrac){

}

    void les(Postava &hrac) {
        std::string dej[16] = {
            "souboj1", "souboj2", "souboj3", "souboj2",
            "vesnice", "souboj1", "souboj3", "souboj2",
            "souboj1", "soubojminiboss", "souboj2", "souboj3",
            "vesnice", "soubojhlavniboss", "souboj3", "souboj2"

        };
         for (int i = 0; i < 20; i++) {
        int pokracovat;
        std::cout << "Krok " << i + 1 << " v lese" << std::endl;
        std::cout << "Zadej 1 pro pokračování: ";
        std::cin >> pokracovat;

        if (dej[i] == "vesnice") {
            std::cout << "Dorazil jsi do vesnice" << std::endl;
            vesnice(hrac);
        } else if (dej[i] == "souboj1") {
            std::cout << "hele jedno monstrum te viziva" << std::endl;
            souboj1(hrac);
        } else if (dej[i] == "souboj2") {
            std::cout << "Narazil jsi na dvě monstra" << std::endl;
            souboj2(hrac);
        } else if (dej[i] == "souboj3") {
            std::cout << "Tři monstra jsou pred tebou" << std::endl;
            souboj3(hrac);
        } else if (dej[i] == "soubojminiboss") {
            std::cout << "Pozor objevil se pred tebou mini boss" << std::endl;
            soubojminiboss(hrac);
        } else if (dej[i] == "soubojhlavniboss") {
            std::cout << "Narazil jsi na hlavniho bosse" << std::endl;
            soubojhlavniboss(hrac);
            if (hrac.zivoty > 0) {
                std::cout << "Vyhrál jsi hru! Gratulujeme!" << std::endl;
            } else {
                std::cout << "Zemřel jsi v boji s hlavním bossem."<< std::endl;
                std::cout <<  "Konec hry.";
            }
            break;
        }

        if (hrac.zivoty <= 0) {
            std::cout << "Zemřel jsi." << std::endl;
            std::cout << " Konec hry.";
            break;
        }
    }
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
    monstra[0].zivoty = 8;
    monstra[0].utok = 2;
    monstra[0].miniboss = false;
    monstra[0].hlavniboss = false;

    monstra[1].jmeno = "Troll" ;
    monstra[1].zivoty = 7;
    monstra[1].utok = 3;
    monstra[1].miniboss = false;
    monstra[1].hlavniboss = false;

    monstra[2].jmeno = "Sok" ;
    monstra[2].zivoty = 8;
    monstra[2].utok = 3;
    monstra[2].miniboss = false;
    monstra[2].hlavniboss = false;

    monstra[3].jmeno = "Golem" ;
    monstra[3].zivoty = 8;
    monstra[3].utok = 6;
    monstra[3].miniboss = false;
    monstra[3].hlavniboss = false;

    monstra[4].jmeno = "Zurivec" ;
    monstra[4].zivoty = 9;
    monstra[4].utok = 5;
    monstra[4].miniboss = false;
    monstra[4].hlavniboss = false;

    monstra[5].jmeno = "Barbar" ;
    monstra[5].zivoty = 13;
    monstra[5].utok = 4;
    monstra[5].miniboss = false;
    monstra[5].hlavniboss = false;

    monstra[6].jmeno = "Mraz" ;
    monstra[6].zivoty = 13;
    monstra[6].utok = 2;
    monstra[6].miniboss = false;
    monstra[6].hlavniboss = false;

    monstra[7].jmeno = "Des" ;
    monstra[7].zivoty = 10;
    monstra[7].utok = 5;
    monstra[7].miniboss = false;
    monstra[7].hlavniboss = false;

    monstra[8].jmeno = "Zmar" ;
    monstra[8].zivoty = 13;
    monstra[8].utok = 3;
    monstra[8].miniboss = false;
    monstra[8].hlavniboss = false;

    monstra[9].jmeno = "Zkaza" ;
    monstra[9].zivoty = 15;
    monstra[9].utok = 4;
    monstra[9].miniboss = false;
    monstra[9].hlavniboss = false;

    monstra[10].jmeno = "Bestie" ;
    monstra[10].zivoty = 16;
    monstra[10].utok = 4;
    monstra[10].miniboss = false;
    monstra[10].hlavniboss = false;

    monstra[11].jmeno = "Horda" ;
    monstra[11].zivoty = 15;
    monstra[11].utok = 6;
    monstra[11].miniboss = false;
    monstra[11].hlavniboss = false;

    monstra[12].jmeno = "Drtic" ;
    monstra[12].zivoty = 17;
    monstra[12].utok = 5;
    monstra[12].miniboss = false;
    monstra[12].hlavniboss = false;

    monstra[13].jmeno = "Netvor" ;
    monstra[13].zivoty = 16;
    monstra[13].utok = 6;
    monstra[13].miniboss = false;
    monstra[13].hlavniboss = false;

    monstra[14].jmeno = "KAT" ;
    monstra[14].zivoty = 19;
    monstra[14].utok = 10;
    monstra[14].miniboss = true;
    monstra[14].hlavniboss = false;

    monstra[15].jmeno = "TYRAN" ;
    monstra[15].zivoty = 20;
    monstra[15].utok = 11;
    monstra[15].miniboss = true;
    monstra[15].hlavniboss = false;

bool vybervarianty;
std:: cout << "stojis pred strasidelnym lesem kde te muzou prepadnout monstra, tak doufam ze si pripravenej bojovat mas na vyber muzes navstivit vesnici s penezi co jsi nasel na zemi nebo pujdes do lesa." << std:: endl;
std:: cout << "pro to aby jsi sel do mesta zmackni 1 pr to aby si sel do vesnice tak zmackni 0";
std:: cin >> vybervarianty;

if(vybervarianty == 1){
    std:: cout <<"dorazil jsi do vesnice " << std:: endl;
    std:: cout << "co chces delat";
    vesnice(hrace);
}else if(vybervarianty == 0){
    std:: cout << "pokracujes do lesa" << std:: endl;
    les(hrace);
}else{
std:: cout << "zadal jsi chybnou hodnotu" << std:: endl;
std:: cout << "zadej znova";
}
}
