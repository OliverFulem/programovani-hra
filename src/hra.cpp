#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <algorithm> // Pro std::min
// Řekne překladači, aby nedefinoval makra min a max z Windows
#define NOMINMAX
// Nyní můžeme bezpečně vložit windows.h
#include <windows.h> // Potřebné pro funkce SetConsole...

// --- Datové struktury ---
struct Schopnost {
    std::string nazev;
    int utok;
    int ubraniEnergie;
};

struct Postava {
    std::string jmeno;
    int maxZivoty;
    int zivoty;
    int maxEnergie;
    int energie;
    int silaUtoku;
    int zlato;
    int uroven;
    int zkusenosti;
    std::vector<Schopnost> schopnosti;
};

struct Monstrum {
    std::string jmeno;
    int zivoty;
    int utok;
    bool jeMiniboss;
    bool jeHlavniBoss;
};


// --- Pomocné funkce ---

int ziskejValidniVstup(int min, int max) {
    int volba;
    while (true) {
        std::cin >> volba;
        if (std::cin.fail() || volba < min || volba > max) {
            std::cout << "Neplatná volba. Zadejte prosím číslo mezi " << min << " a " << max << ": ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
    }
    return volba;
}


void statistiky(const Postava& hrac) {
    std::cout << "\n--- STATISTIKY ---\n";
    std::cout << "Charakter: " << hrac.jmeno << '\n';
    std::cout << "Životy: " << hrac.zivoty << "/" << hrac.maxZivoty << '\n';
    std::cout << "Energie: " << hrac.energie << "/" << hrac.maxEnergie << '\n';
    std::cout << "Útok: " << hrac.silaUtoku << '\n';
    std::cout << "Level: " << hrac.uroven << " | Zkušenosti: " << hrac.zkusenosti << " | Zlato: " << hrac.zlato << '\n';
    std::cout << "Schopnosti:\n";
    for (const auto& s : hrac.schopnosti) {
        std::cout << " - " << s.nazev << " (Útok: " << s.utok << ", Energie: " << s.ubraniEnergie << ")\n";
    }
    std::cout << "------------------\n";
}


// --- Herní systémy ---

bool provedTransakci(Postava &hrac, int cena) {
    if (hrac.zlato >= cena) {
        hrac.zlato -= cena;
        return true;
    } else {
        std::cout << "Nemáte dostatek zlata.\n";
        return false;
    }
}

void vesnice(Postava &hrac) {
    const int CENA_DOPLNENI = 5;
    const int CENA_VYLEPSENI = 10;

    bool hotovo = false;
    while (!hotovo) {
        statistiky(hrac);
        std::cout << "\nVítejte ve vesnici! Co byste si chtěl koupit?\n";
        std::cout << "1 - Doplnit životy (cena " << CENA_DOPLNENI << " zlata)\n";
        std::cout << "2 - Doplnit energii (cena " << CENA_DOPLNENI << " zlata)\n";
        std::cout << "3 - Zvýšit maximální životy (cena " << CENA_VYLEPSENI << " zlata)\n";
        std::cout << "4 - Zvýšit maximální energii (cena " << CENA_VYLEPSENI << " zlata)\n";
        std::cout << "5 - Odejít z vesnice\n";
        std::cout << "Vaše volba: ";
        int rozhodnuti = ziskejValidniVstup(1, 5);

        switch (rozhodnuti) {
            case 1:
                if (provedTransakci(hrac, CENA_DOPLNENI)) {
                    hrac.zivoty = hrac.maxZivoty;
                    std::cout << "Doplnil sis životy.\n";
                }
                break;
            case 2:
                if (provedTransakci(hrac, CENA_DOPLNENI)) {
                    hrac.energie = hrac.maxEnergie;
                    std::cout << "Doplnil sis energii.\n";
                }
                break;
            case 3:
                if (provedTransakci(hrac, CENA_VYLEPSENI)) {
                    hrac.maxZivoty++;
                    std::cout << "Zvýšil sis maximální životy.\n";
                }
                break;
            case 4:
                if (provedTransakci(hrac, CENA_VYLEPSENI)) {
                    hrac.maxEnergie++;
                    std::cout << "Zvýšil sis maximální energii.\n";
                }
                break;
            case 5:
                std::cout << "Odcházíte z vesnice.\n";
                hotovo = true;
                break;
        }
    }
}


void souboj(Postava &hrac, std::vector<Monstrum> &monstra) {
    std::cout << "\n!!! ZAČÍNÁ SOUBOJ !!!\n";
    int zlateOdmeny = 0;

    while (hrac.zivoty > 0 && !monstra.empty()) {
        std::cout << "\n--- TVŮJ TAH ---\n";
        statistiky(hrac);
        std::cout << "Protivníci:\n";
        for (size_t i = 0; i < monstra.size(); ++i) {
            std::cout << i + 1 << ". " << monstra[i].jmeno << " (Životy: " << monstra[i].zivoty << ")\n";
        }

        size_t cilIndex = 0;
        if (monstra.size() > 1) {
            std::cout << "Vyber cíl (1-" << monstra.size() << "): ";
            cilIndex = ziskejValidniVstup(1, monstra.size()) - 1;
        }

        // Odečtení energie za základní útok
        const int ENERGIE_UTOK = 1;
        if (hrac.energie >= ENERGIE_UTOK) {
            hrac.energie -= ENERGIE_UTOK;
            Monstrum &cil = monstra[cilIndex];
            cil.zivoty -= hrac.silaUtoku;
            std::cout << "Útočíš na " << cil.jmeno << " a způsobil jsi " << hrac.silaUtoku << " zranění. (Odečtena 1 energie)\n";

            if (cil.zivoty <= 0) {
                std::cout << "Porazil jsi " << cil.jmeno << "!\n";
                zlateOdmeny += cil.jeMiniboss ? 20 : 5;
                monstra.erase(monstra.begin() + cilIndex);
            } else {
                std::cout << cil.jmeno << " má nyní " << cil.zivoty << " životů.\n";
            }
        } else {
            std::cout << "Nemáš dostatek energie na útok! Kolo přeskakuješ.\n";
        }

        if (monstra.empty()) break;

        std::cout << "\n--- TAH MONSTER ---\n";
        for (const auto& monstrum : monstra) {
            hrac.zivoty -= monstrum.utok;
            std::cout << monstrum.jmeno << " na tebe zaútočil a způsobil ti " << monstrum.utok << " zranění. Máš "
                      << std::max(0, hrac.zivoty) << " životů.\n";
            if (hrac.zivoty <= 0) break;
        }
    }

    if (hrac.zivoty > 0) {
        std::cout << "\nVyhrál jsi souboj! Získal jsi " << zlateOdmeny << " zlata.\n";
        hrac.zlato += zlateOdmeny;
    } else {
        std::cout << "\nProhrál jsi souboj...\n";
    }
}

void soubojHavniBoss(Postava &hrac) {
    Monstrum hlavniBoss = {"Geomancer", 16, 8, false, true};
    std::cout << "Souboj s bossem: " << hlavniBoss.jmeno << '\n';

    while (hrac.zivoty > 0 && hlavniBoss.zivoty > 0) {
        statistiky(hrac);
        std::cout << "\n" << hlavniBoss.jmeno << " má " << hlavniBoss.zivoty << " životů.\n";
        std::cout << "Vyber tvar, který Geomancer použije (1 - Čtverec, 2 - Obdélník, 3 - Kruh): ";
        int volba = ziskejValidniVstup(1, 3);

        int poskozeni = 0;
        switch(volba) {
            case 1: // Čtverec
                std::cout << "****\n*  *\n*  *\n****\n";
                poskozeni = hlavniBoss.utok * 4;
                std::cout << "Geomancer útočí čtvercem za " << poskozeni << " poškození!\n";
                break;
            case 2: // Obdélník
                std::cout << "******\n*    *\n******\n";
                poskozeni = hlavniBoss.utok * 2 + (hrac.uroven * 2);
                std::cout << "Geomancer útočí obdélníkem za " << poskozeni << " poškození!\n";
                break;
            case 3: { // Kruh
                std::cout << " *** \n*   *\n*   *\n *** \n";
                int nasobitel = 1 + (rand() % 3); // 1, 2, nebo 3
                if (nasobitel == 2) nasobitel = 3; // 1, 3, nebo 4
                else if (nasobitel == 3) nasobitel = 4;
                poskozeni = hlavniBoss.utok * nasobitel * 2;
                std::cout << "Geomancer útočí kruhem za " << poskozeni << " poškození! (Násobitel: " << nasobitel << ")\n";
                break;
            }
        }

        hrac.zivoty -= poskozeni;
        std::cout << "Máš " << std::max(0, hrac.zivoty) << " životů.\n";
        if (hrac.zivoty <= 0) break;


        std::cout << "\nTvůj útok na Geomancera!\n";
        hlavniBoss.zivoty -= hrac.silaUtoku;
        std::cout << "Způsobil jsi " << hrac.silaUtoku << " poškození. Geomancer má nyní " << std::max(0, hlavniBoss.zivoty) << " životů.\n";
    }

    if (hrac.zivoty > 0) {
        std::cout << "Porazil jsi bosse " << hlavniBoss.jmeno << "!\n";
    } else {
        std::cout << "Prohrál jsi proti bossovi.\n";
    }
}

enum class TypUdalosti {
    Vesnice, Souboj1, Souboj2, Souboj3, Souboj4, Souboj5, Miniboss1, Miniboss2, SoubojHavniBoss, Konec
};

void les(Postava &hrac) {
    const std::vector<TypUdalosti> dej = {
        TypUdalosti::Souboj1, TypUdalosti::Vesnice, TypUdalosti::Souboj2, TypUdalosti::Souboj3, TypUdalosti::Vesnice,
        TypUdalosti::Miniboss1, TypUdalosti::Souboj2, TypUdalosti::Souboj4, TypUdalosti::Vesnice, TypUdalosti::Souboj5,
        TypUdalosti::Miniboss2, TypUdalosti::Vesnice,  TypUdalosti::Souboj5,  TypUdalosti::Souboj2,  TypUdalosti::Souboj3,
        TypUdalosti::Vesnice, TypUdalosti::SoubojHavniBoss, TypUdalosti::Konec
    };

    for (size_t i = 0; i < dej.size(); ++i) {
        std::cout << "\n--- Krok " << i + 1 << " v lese ---\n";
        std::cout << "Stiskni 1 pro pokračování: ";
        ziskejValidniVstup(1, 1);

        TypUdalosti udalost = dej[i];
        std::vector<Monstrum> monstra;

        switch (udalost) {
            case TypUdalosti::Vesnice:
                std::cout << "Dorazil jsi do vesnice.\n";
                vesnice(hrac);
                break;
            case TypUdalosti::Souboj1:
                std::cout << "Narazil jsi na monstrum!\n";
                monstra.push_back({"Bomber", 5, 2, false, false});
                souboj(hrac, monstra);
                break;
            case TypUdalosti::Souboj2:
                std::cout << "Narazil jsi na dvě monstra!\n";
                monstra.push_back({"Zmar", 8, 3, false, false});
                monstra.push_back({"Děs", 8, 3, false, false});
                souboj(hrac, monstra);
                break;
            case TypUdalosti::Souboj3:
                std::cout << "Tři monstra jsou před tebou!\n";
                monstra.push_back({"Zkáza", 12, 1, false, false});
                monstra.push_back({"Bestie", 9, 4, false, false});
                monstra.push_back({"Horda", 9, 4, false, false});
                souboj(hrac, monstra);
                break;
            case TypUdalosti::Souboj4:
                std::cout << "Dvě monstra jsou před tebou!\n";
                monstra.push_back({"Golem", 10, 2, false, false});
                monstra.push_back({"Zuřivec", 8, 4, false, false});
                souboj(hrac, monstra);
                break;
            case TypUdalosti::Souboj5:
                std::cout << "Dvě monstra jsou před tebou!\n";
                monstra.push_back({"Barbar", 10, 4, false, false});
                monstra.push_back({"Mráz", 12, 3, false, false});
                souboj(hrac, monstra);
                break;
            case TypUdalosti::Miniboss1:
                std::cout << "Pozor! Objevil se mini boss!\n";
                monstra.push_back({"KAT", 14, 6, true, false});
                souboj(hrac, monstra);
                break;
            case TypUdalosti::Miniboss2:
                std::cout << "Pozor! Objevil se silnější mini boss!\n";
                monstra.push_back({"TYRAN", 12, 7, true, false});
                souboj(hrac, monstra);
                break;
            case TypUdalosti::SoubojHavniBoss:
                std::cout << "Narazil jsi na hlavního bosse!\n";
                soubojHavniBoss(hrac);
                if (hrac.zivoty > 0) {
                    std::cout << "\n*** Vyhrál jsi hru! Gratulujeme! ***\n";
                } else {
                    std::cout << "Zemřel jsi v boji s hlavním bossem.\n";
                }
                break;
            case TypUdalosti::Konec:
                std::cout << "Došel jsi do finální destinace.\n";
                std::cout << "Tady tvoje dobrodružná výprava končí.\n";
                std::cout << ":)\n";
                return;
        }

        if (hrac.zivoty <= 0) {
            std::cout << "\nZemřel jsi. Konec hry.\n";
            return;
        }
    }
}

std::vector<Postava> vytvorPostavy() {
    return {
        {"Cajda", 40, 40, 12, 12, 10, 30, 1, 0, {{"Podpásovka", 5, 1}, {"Loketní vražda", 7, 2}}},
        {"Tufo", 40, 40, 12, 12, 10, 30, 1, 0, {{"Pohlavek", 4, 1}, {"Past", 7, 2}}},
        {"Drátěnka", 40, 40, 12, 12, 8, 30, 1, 0, {{"Kletba", 4, 1}, {"Elektrický šok", 5, 1}}},
        {"Mazák", 40, 40, 12, 12, 10, 30, 1, 0, {{"Rána zezadu", 6, 2}, {"Vypálení světlem", 4, 1}}}
    };
}

int main() {
	// Nastaví kódovou stránku konzole pro výstup (aby se správně tisklo)
    SetConsoleOutputCP(CP_UTF8);
    // Volitelně: Nastaví kódovou stránku pro vstup (aby fungoval std::cin s diakritikou)
    SetConsoleCP(CP_UTF8);
    std::cout << "Vítejte ve hře plné dobrodružství!\n";
    std::cout << "Tvým cílem bude projít lesem a porazit vše, co ti stojí v cestě.\n";
    std::cout << "Přejete si hrát? (1 pro ano, 2 pro ne): ";
    if (ziskejValidniVstup(1, 2) != 1) {
        std::cout << "Škoda! Snad se brzy uvidíme.\n";
        return 0;
    }

    auto postavy = vytvorPostavy();
    std::cout << "\nVyber si, za koho chceš hrát:\n";
    for (size_t i = 0; i < postavy.size(); ++i) {
        std::cout << i + 1 << " - " << postavy[i].jmeno << '\n';
    }

    std::cout << "Tvoje volba: ";
    int vyberPostavy = ziskejValidniVstup(1, postavy.size());
    Postava hrac = postavy[vyberPostavy - 1];

    std::cout << "\nVybral sis postavu:\n";
    statistiky(hrac);

    std::cout << "\nStojíš před strašidelným lesem. Můžeš jít rovnou do lesa, nebo navštívit vesnici pro přípravu.\n";
    std::cout << "1 - Navštívit vesnici\n2 - Vstoupit do lesa\n";
    std::cout << "Tvoje volba: ";
    int vyberCesty = ziskejValidniVstup(1, 2);

    if (vyberCesty == 1) {
        vesnice(hrac);
    }

    std::cout << "\nVstupuješ do temného lesa... Hodně štěstí!\n";
    les(hrac);

    return 0;
}