#include <iostream>
#include <string>
// using namespace std;

struct schopnost{
    std::string nazev;
    int utok;
    int zivoty;
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

int main(){
    int vstup;
    std::cout << "Vytejte ve hre plne dobrodruzstvi" << std::endl;
    std::cout << "Tvim cilem bude projit lesem kde potkas mnoho bytosti, pres ktere se musis dostat do kralovstvi." << endl;
    cout << "Pokud si chcete hru zahrat tak stisknete 1 pokud ne tak stisknete cokoliv jineho" << endl;
    cin >> vstup;

    if(start != 1) {
        cout << "Srabe namas odvahu projit strasidlelnym lesem :) tak se snad brzy uvidime.";
    }
    }
    cout << "Vyber si za koho chces hrat " <<endl;
    cout << "Ale pozor kazda postava ma jiny pocet energi a zivotu" << endl;
    cout << "Postavy jsou serazeny od nejlehci po nejtezsi" << endl;

    Postava Charakter[4];

    Charakter[0].jmeno = "Cajda";
    Charakter[0].MaxZivoty = 7;
    Charakter[0].zivoty= 7;
    Charakter[0].MaxEmergie = 5;
    Charakter[0].energie = 5;
    Charakter[0].sila utoku = 4;
    Charakter[0].zlato = 0;
    Charakter[0].uroven = 1;
    Charakter[0].schopnosti[0] = {"podpasovka", 3, 1};
    Charakter[0].schopnosti[1] = {"loketni vrazda", 4, 2};

    Charakter[1].jmeno = "Cajda";
    Charakter[1].MaxZivoty = 6;
    Charakter[1].zivoty= 6;
    Charakter[1].MaxEmergie = 6;
    Charakter[1].energie = 6;
    Charakter[1].sila utoku = 3;
    Charakter[1].zlato = 0;
    Charakter[1].uroven = 1;
    Charakter[1].schopnosti[0] = {"Pohlavek", 2, 1};
    Charakter[1].schopnosti[1] = {"past", 4, 2};

    Charakter[2].jmeno = "Dratenka";
    Charakter[2].MaxZivoty = 5;
    Charakter[2].zivoty= 5;
    Charakter[2].MaxEmergie = 5;
    Charakter[2].energie = 5;
    Charakter[2].sila utoku = 3;
    Charakter[2].zlato = 0;
    Charakter[2].uroven = 1;
    Charakter[2].schopnosti[0] = {"Kledba", 2, 1};
    Charakter[2].schopnosti[1] = {"elektricky sok", 3, 1};

    Charakter[3].jmeno = "Mazak";
    Charakter[3].MaxZivoty = 5;
    Charakter[3].zivoty= 5;
    Charakter[3].MaxEmergie = 3;
    Charakter[3].energie = 3;
    Charakter[3].sila utoku = 3;
    Charakter[3].zlato = 0;
    Charakter[3].uroven = 1;
    Charakter[3].schopnosti[0] = {"rana ze zadu", 3, 2};
    Charakter[3].schopnosti[1] = {"vypaleni svetlem", 2, 1};

}

