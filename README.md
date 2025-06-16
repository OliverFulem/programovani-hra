# Textové RPG Dobrodružství v Lese

Vítejte v jednoduché textové RPG hře napsané v C++. Vstupte do role hrdiny, probojujte se temným lesem a postavte se všemu, co vám zkříží cestu!

## O hře

Jste dobrodruh, který stojí na pokraji strašidelného lesa. Vaším úkolem je projít lesem krok za krokem, bojovat s monstry, navštěvovat vesnici pro vylepšení a nakonec porazit mocného bosse, který číhá v hlubinách lesa. Hra je plně ovládaná pomocí číselných voleb v konzoli.

## Cíl hry

Přežijte nebezpečnou cestu lesem a porazte finálního bosse, **Geomancera**.

## Jak hrát

1.  **Výběr postavy:** Na začátku si vyberete jednoho ze čtyř dostupných hrdinů. Každý má trochu jiné statistiky a schopnosti.
2.  **První rozhodnutí:** Můžete se vydat rovnou do lesa, nebo nejprve navštívit vesnici.
3.  **Vesnice:** Ve vesnici můžete utratit zlato, které získáte z bojů. Lze si zde:
    * Doplnit životy a energii.
    * Trvale zvýšit maximální životy a energii.
4.  **Boj:** Souboje jsou tahové.
    * Ve svém tahu si vyberete, na které monstrum zaútočíte.
    * Poté zaútočí všechna zbývající monstra na vás.
    * Hra končí, pokud vaše životy klesnou na 0.
5.  **Postup hrou:** Hra vás provede sérií předem daných událostí – soubojů, návštěv vesnice a střetů s mini-bossy, které vedou až k finálnímu souboji.

## Kompilace a spuštění

Ke kompilaci je potřeba C++ překladač, například **Clang++** nebo **G++**. Hra byla vyvinuta s použitím C++17.

### Metoda 1: PowerShell skript (Doporučeno)

Pokud máte v adresáři se hrou připravený skript `build.ps1`, je to nejjednodušší cesta.

1.  Otevřete terminál PowerShell ve složce s projektem.
2.  Spusťte skript zadáním příkazu:
    ```powershell
    .\build.ps1
    ```
3.  Pokud kompilace proběhne úspěšně, skript vám to oznámí.
4.  Spusťte hru příkazem:
    ```powershell
    .\hra.exe
    ```

### Metoda 2: Manuální kompilace

Hru můžete zkompilovat i ručně pomocí následujícího příkazu v terminálu:

```bash
# Pro kompilátor Clang++
clang++ -std=c++17 -Wall -o hra.exe hra.cpp

# Alternativně pro kompilátor G++
g++ -std=c++17 -Wall -o hra.exe hra.cpp
```

Po úspěšné kompilaci spusťte hru:

```bash
.\hra.exe
```

---

### Řešení problémů

**Problém se spuštěním skriptu `build.ps1` v PowerShellu**

Při pokusu o spuštění skriptu `.\build.ps1` se vám může zobrazit chyba podobná této:
```
.\build.ps1 : File C:\cesta\k_projektu\build.ps1 cannot be loaded because running scripts is disabled on this system.
```
Toto je bezpečnostní opatření PowerShellu, které standardně blokuje spouštění lokálních skriptů.

**Řešení:** Musíte dočasně povolit spouštění skriptů. Otevřete PowerShell a zadejte následující příkaz:
```powershell
Set-ExecutionPolicy RemoteSigned -Scope Process
```
-   `Set-ExecutionPolicy RemoteSigned`: Povolí spouštění lokálních skriptů, které jste vytvořili.
-   `-Scope Process`: Toto nastavení platí **pouze pro aktuální okno PowerShellu**. Po jeho zavření se vše vrátí do původního, bezpečného stavu.

Po spuštění tohoto příkazu v terminálu by měl jít skript `.\build.ps1` bez problémů spustit.

**Chyba "unresolved external symbol" při kompilaci na Windows**

Protože hra používá specifické funkce Windows pro správné zobrazení české diakritiky v konzoli (např. `SetConsoleOutputCP`), může při kompilaci dojít k chybě. Obvykle se projeví jako `unresolved external symbol` nebo `undefined reference`.

To znamená, že překladač nenašel implementaci těchto funkcí.

**Řešení:** Musíte překladači explicitně říci, aby přilinkoval systémovou knihovnu `user32`, kde se tyto funkce nacházejí. Upravte kompilační příkaz přidáním `-luser32` na konec:

**Příklad pro PowerShell skript (`build.ps1`):**

```powershell
clang++ -std=c++17 -Wall -Wextra -o hra.exe .\hra.cpp -luser32
```

**Příklad pro manuální kompilaci:**

```bash
clang++ -std=c++17 -Wall -o hra.exe hra.cpp -luser32
```

---

Hodně štěstí na vaší cestě!
README.md
Displaying hra.cpp.