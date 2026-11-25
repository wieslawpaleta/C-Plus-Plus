#include <iostream>     // Einbinden der Standard-I/O-Bibliothek (Dołączenie standardowej biblioteki I/O)
#include <string>       // Einbinden der String-Bibliothek (Dołączenie biblioteki stringów)
#include <vector>       // Einbinden der Vector-Bibliothek für dynamische Arrays (Dołączenie biblioteki wektorów)
#include <random>       // Einbinden der Zufallszahlen-Bibliothek (Dołączenie biblioteki liczb losowych)
#include <algorithm>    // Einbinden von Algorithmen wie remove_if (Dołączenie algorytmów takich jak remove_if)
#include <cmath>        // Einbinden von mathematischen Funktionen wie std::abs (Dołączenie funkcji matematycznych jak std::abs)
#include <fstream>      // Einbinden der Datei-Stream-Bibliothek für CSV-Export (Dołączenie biblioteki strumieni plikowych do eksportu CSV)

// Struktur zur Speicherung der Statistik  eines Simulationsschritts (Struktura do przechowywania statystyk jednego kroku symulacji)
struct StatistikEintrag {
    int schritt; // Nummer des Simulationsschritts (Numer kroku symulacji)
}
// Klasse zur Darstellung der DNA eines Organismus (Klasa reprezentująca DNA organizmu)
class DNA {
private:
    std::string genSequenz;         // Speichert die Gen-Sequenz als String (Przechowuje sekwencję genów jako string)
    std::string basen = "ATCG";     // Verfügbare Basen für die DNA (Dostępne zasady dla DNA)

public:
    // Konstruktor 1: Generiert eine zufällige DNA-Sequenz (Konstruktor 1: Generuje losową sekwencję DNA)
    DNA(size_t laenge) {
        std::random_device rd;                     // Initialisiert den Hardware-Zufallsgenerator (Inicjalizuje sprzętowy generator losowy)
        std::mt19937 gen(rd());                    // Startet den Mersenne-Twister Zufallsgenerator (Uruchamia generator Mersenne-Twister)
        std::uniform_int_distribution<> dis(0, 3); // Definiert einen Bereich von 0 bis 3 für die Basen (Definiuje zakres od 0 do 3 dla zasad)

        for (size_t i = 0; i < laenge; ++i) {      // Schleife läuft für jede Position der gewünschten Länge (Pętla wykonuje się dla każdej pozycji żądanej długości)
            genSequenz += basen[dis(gen)];         // Fügt zufällig eine Basis (A, T, C oder G) hinzu (Losowo dodaje zasadę A, T, C lub G)
        }
    }

    // Konstruktor 2 für Nachkommen: Kopiert und mutiert Eltern-DNA (Konstruktor 2 dla potomka: Kopiuje i mutuje DNA rodzica)
    DNA(const DNA& elternDna, double mutationsRate) {
        genSequenz = elternDna.genSequenz;         // Übernimmt die exakte Sequenz des Elternteils (Przejmuje dokładną sekwencję rodzica)
        std::random_device rd;                     // Zufallsquelle initialisieren (Inicjalizacja źródła losowości)
        std::mt19937 gen(rd());                    // Zufallsgenerator starten (Uruchomienie generatora losowego)
        std::uniform_real_distribution<> wahrscheinlichkeit(0.0, 1.0); // Wahrscheinlichkeit von 0 bis 1 (Prawdopodobieństwo od 0 do 1)
        std::uniform_int_distribution<> basenAuswahl(0, 3);          // Auswahlindex für neue Basis (Indeks wyboru nowej zasady)

        for (size_t i = 0; i < genSequenz.length(); ++i) {           // Geht jedes Zeichen der DNA durch (Przechodzi przez każdy znak DNA)
            if (wahrscheinlichkeit(gen) < mutationsRate) {           // Prüft, ob Zufallswert kleiner als Mutationsrate ist (Sprawdza, czy wartość losowa jest mniejsza od współczynnika mutacji)
                genSequenz[i] = basen[basenAuswahl(gen)];            // Mutiert das Gen zu einer neuen Basis (Mutuje gen do nowej zasady)
            }
        }
    }

    // Berechnet die Wahrnehmungsreichweite aus Anzahl der 'A'- und 'G'-Basen (Oblicza zasięg wykrywania na podstawie liczby zasad 'A' i 'G')
    int berechneSichtweite() const {
        int reichweite = 2;                        // Basis-Sichtweite von 2 Feldern (Bazowy zasięg widzenia równy 2 polom)
        for (char base : genSequenz) {             // Geht durch jede Base in der DNA-Sequenz (Przechodzi przez każdą zasadę w sekwencji DNA)
            if (base == 'A' || base == 'G') {      // 'A' und 'G' erhöhen die Wahrnehmung (Zasady 'A' i 'G' zwiększają zmysł wykrywania)
                reichweite += 1;                   // Erhöht Reichweite um 1 Feld (Zwiększa zasięg o 1 pole)
            }
        }
        return reichweite;                         // Gibt berechnete Sichtweite zurück (Zwraca obliczony zasięg widzenia)
    }

    // Getter für die Gen-Sequenz (Getter zwracający sekwencję genów)
    std::string getSequenz() const {
        return genSequenz;                         // Gibt den Sequenz-String zurück (Zwraca łańcuch sekwencji)
    }
};

// Klasse zur Darstellung von Nahrung im Oekosystem (Klasa reprezentująca jedzenie w ekosystemie)
class Nahrung {
public:
    int xPosition;   // X-Koordinate der Nahrung (Współrzędna X jedzenia)
    int yPosition;   // Y-Koordinate der Nahrung (Współrzędna Y jedzenia)
    int energieWert; // Menge an Energie, die die Nahrung bringt (Ilość energii, jaką daje jedzenie)

    // Konstruktor der Nahrungs-Klasse (Konstruktor klasy jedzenia)
    Nahrung(int x, int y, int energie) 
        : xPosition(x), yPosition(y), energieWert(energie) {} // Initialisierungsliste für Nahrung (Lista inicjalizacyjna dla jedzenia)
};

// Klasse zur Darstellung eines Organismus im Oekosystem (Klasa reprezentująca organizm w ekosystemie)
class Organismus {
private:
    DNA dna;         // Das DNA-Objekt des Organismus (Obiekt DNA organizmu)
    int energie;     // Verbleibende Energiepunkte (Pozostałe punkty energii)
    int xPosition;   // Aktuelle X-Position im Raster (Aktualna pozycja X na siatce)
    int yPosition;   // Aktuelle Y-Position im Raster (Aktualna pozycja Y na siatce)

public:
    // Konstruktor für die Erstanstellung (Konstruktor dla pierwszej generacji)
    Organismus(size_t dnaLaenge, int startEnergie, int startX, int startY) 
        : dna(dnaLaenge), energie(startEnergie), xPosition(startX), yPosition(startY) {} // Initialisierungsliste (Lista inicjalizacyjna)

    // Konstruktor für Nachkommen (Konstruktor dla potomków)
    Organismus(const DNA& elternDna, int startX, int startY, int startEnergie)
        : dna(elternDna, 0.20), energie(startEnergie), xPosition(startX), yPosition(startY) {} // 20% Mutationsrate für stärkere Evolution (20% mutacji dla wyraźniejszej ewolucji)

    // Methode zur Anzeige des Status (Metoda wyświetlająca stan)
    void statusAnzeigen() const {
        std::cout << "Pos: (" << xPosition << ", " << yPosition 
                  << ") | Energie: " << energie 
                  << " | Sicht: " << dna.berechneSichtweite()
                  << " | DNA: " << dna.getSequenz() << std::endl; // Gibt Infos inkl. Sichtweite aus (Wyświetla info wraz z zasięgiem widzenia)
    }

    // Hilfsmethode für zufällige Bewegung (Metoda pomocnicza do losowego ruchu)
    void zufaelligBewegen(int maxGrenze) {
        std::random_device rd;                     // Zufallsquelle (Źródło losowości)
        std::mt19937 gen(rd());                    // Generator (Generator)
        std::uniform_int_distribution<> schritt(-1, 1); // Schrittweite -1, 0 oder 1 (Krok -1, 0 lub 1)

        xPosition += schritt(gen);                 // Verändert X-Position zufällig (Zmienia pozycję X losowo)
        yPosition += schritt(gen);                 // Verändert Y-Position zufällig (Zmienia pozycję Y losowo)
        begrenzenUndEnergieVerbrauchen(maxGrenze); // Grenzen prüfen und Energie abziehen (Sprawdź granice i odejmij energię)
    }

    // Bewegung mit genetischer Sichtweite (Ruch z uwzględnieniem genetycznego zasięgu widzenia)
    void bewegenZurNahrung(const std::vector<Nahrung>& nahrungen, int maxGrenze) {
        int sichtweite = dna.berechneSichtweite();   // Holt genetische Sichtweite des Organismus (Pobiera genetyczny zasięg widzenia organizmu)
        const Nahrung* naechsteNahrung = nullptr;  // Zeiger auf das nächste sichtbare Nahrungsstück (Wskaźnik na najbliższy widoczny kawałek jedzenia)
        int kleinsteDistanz = sichtweite + 1;      // Nur Nahrung innerhalb der Sichtweite zählt (Liczy się tylko jedzenie w zasięgu wzroku)

        for (const auto& n : nahrungen) {          // Gehe durch alle verfügbaren Nahrungsquellen (Przejdź przez wszystkie dostępne źródła jedzenia)
            int distanz = std::abs(n.xPosition - xPosition) + std::abs(n.yPosition - yPosition); // Manhattan-Distanz berechnen (Oblicz odległość Manhattan)
            if (distanz <= sichtweite && distanz < kleinsteDistanz) { // Prüft Reichweite und Nähe (Sprawdza zasięg i bliskość)
                kleinsteDistanz = distanz;         // Aktualisiert kleinste Distanz (Zaktualizuj najmniejszy dystans)
                naechsteNahrung = &n;              // Speichert Adresse der nächsten Nahrung (Zapisz adres najbliższego jedzenia)
            }
        }

        if (naechsteNahrung == nullptr) {           // Keine Nahrung in Sichtweite gefunden (Nie znaleziono jedzenia w zasięgu wzroku)
            zufaelligBewegen(maxGrenze);           // Bewegt sich zufällig (Porusza się losowo)
            return;                                // Methode beenden (Zakończ metodę)
        }

        if (xPosition < naechsteNahrung->xPosition) { // Ziel liegt rechts (Cel jest po prawej)
            xPosition += 1;                        // Gehe einen Schritt nach rechts (Zrób krok w prawo)
        } else if (xPosition > naechsteNahrung->xPosition) { // Ziel liegt links (Cel jest po lewej)
            xPosition -= 1;                        // Gehe einen Schritt nach links (Zrób krok w lewo)
        }

        if (yPosition < naechsteNahrung->yPosition) { // Ziel liegt unten (Cel jest na dole)
            yPosition += 1;                        // Gehe einen Schritt nach unten (Zrób krok w dół)
        } else if (yPosition > naechsteNahrung->yPosition) { // Ziel liegt oben (Cel jest na górze)
            yPosition -= 1;                        // Gehe einen Schritt nach oben (Zrób krok w górę)
        }

        begrenzenUndEnergieVerbrauchen(maxGrenze); // Grenzen prüfen und Energie abziehen (Sprawdź granice i odejmij energię)
    }

    // Begrenzt Position auf Welt und verbraucht Bewegungsenergie (Ogranicza pozycję do świata i zużywa energię ruchu)
    void begrenzenUndEnergieVerbrauchen(int maxGrenze) {
        if (xPosition < 0) xPosition = 0;          // Links nicht herausfallen (Nie wypada z lewej)
        if (xPosition > maxGrenze) xPosition = maxGrenze; // Rechts nicht herausfallen (Nie wypada z prawej)
        if (yPosition < 0) yPosition = 0;          // Unten nicht herausfallen (Nie wypada na dole)
        if (yPosition > maxGrenze) yPosition = maxGrenze; // Oben nicht herausfallen (Nie wypada na górze)

        if (energie > 0) {                         // Nur abziehen, wenn Energie vorhanden (Odejmuj tylko, gdy jest energia)
            energie--;                             // Bewegung kostet 1 Energiepunkt (Ruch kosztuje 1 punkt energii)
        }
    }

    // Erhöht die Energie (Zwiększa energię)
    void energieErhoehen(int menge) {
        energie += menge;                          // Addiert die Nahrungsenergie (Dodaje energię z jedzenia)
    }

    // Getter für X-Position (Getter dla pozycji X)
    int getX() const { return xPosition; }         // Gibt X zurück (Zwraca X)
    
    // Getter für Y-Position (Getter dla pozycji Y)
    int getY() const { return yPosition; }         // Gibt Y zurück (Zwraca Y)

    // Getter für Energie (Getter dla energii)
    int getEnergie() const { return energie; }     // Gibt Energie zurück (Zwraca energię)

    // Getter für Sichtweite (Getter dla zasięgu widzenia)
    int getSichtweite() const { return dna.berechneSichtweite(); } // Gibt Sichtweite zurück (Zwraca zasięg widzenia)

    // Prüft, ob der Organismus lebt (Sprawdza, czy organizm żyje)
    bool lebt() const {
        return energie > 0;                        // Wahr, wenn Energie über 0 liegt (Prawda, gdy energia jest powyżej 0)
    }

    // Prüft, ob genug Energie für Fortpflanzung da ist (Sprawdza, czy jest dość energii na rozmnażanie)
    bool kannReproduzieren() const {
        return energie >= 60;                      // Ab 60 Energiepunkten fortpflanzungsfähig (Zdolny do rozmnażania od 60 punktów energii)
    }

    // Methode zur Fortpflanzung (Metoda rozmnażania)
    Organismus reproduzieren() {
        energie /= 2;                              // Elternteil gibt die Hälfte seiner Energie ab (Rodzic oddaje połowę swojej energii)
        return Organismus(dna, xPosition, yPosition, energie); // Erzeugt Nachkomme (Tworzy potomka)
    }
};

// Klasse zur Verwaltung des Oekosystems und Statistiken (Klasa zarządzająca ekosystemem i statystykami)
class Welt {
private:
    int groesse;                                   // Weltgröße (Rozmiar świata)
    std::vector<Organismus> organismen;            // Liste aller Organismen (Lista wszystkich organizmów)
    std::vector<Nahrung> nahrungen;                // Liste aller Nahrungsquellen (Lista wszystkich źródeł jedzenia)

    int gesamtGeburten = 0;                        // Zählt Gesamtzahl der Geburten (Liczy łączną liczbę narodzin)
    int gesamtTode = 0;                            // Zählt Gesamtzahl der Tode (Liczy łączną liczbę zgonów)
    int gesamtGegessen = 0;                        // Zählt verzehrte Nahrungseinheiten (Liczy spożyte jednostki jedzenia)

public:
    // Konstruktor der Welt (Konstruktor świata)
    Welt(int weltGroesse) : groesse(weltGroesse) {} // Initialisiert Weltgröße (Inicjalizuje rozmiar świata)

    // Fügt Organismus hinzu (Dodaje organizm)
    void organismusHinzufuegen(const Organismus& org) {
        organismen.push_back(org);                 // Hinzufügen zum Vektor (Dodanie do wektora)
    }

    // Methode zum automatischen Generieren von Nahrung (Metoda do automatycznego generowania jedzenia)
    void nahrungSpawnen(int anzahl) {
        std::random_device rd;                     // Zufallsquelle für Positionen (Źródło losowości dla pozycji)
        std::mt19937 gen(rd());                    // Generator starten (Uruchomienie generatora)
        std::uniform_int_distribution<> dis(0, groesse); // Bereich von 0 bis Weltgröße (Zakres od 0 do rozmiaru świata)

        for (int i = 0; i < anzahl; ++i) {         // Schleife für Anzahl der Nahrung (Pętla dla liczby jedzenia)
            int zufallX = dis(gen);                // Zufällige X-Koordinate (Losowa współrzędna X)
            int zufallY = dis(gen);                // Zufällige Y-Koordinate (Losowa współrzędna Y)
            nahrungen.push_back(Nahrung(zufallX, zufallY, 25)); // Nahrung hinzufügen (Dodanie jedzenia)
        }
    }

    // Methode zur textbasierten Visualisierung der Welt (Metoda tekstowej wizualizacji świata)
    void visualisieren() const {
        std::cout << "\n--- WELTKARTE (MAPA ŚWIATA) ---" << std::endl; // Titel ausgeben (Wypisanie tytułu)
        
        for (int y = 0; y <= groesse; ++y) {       // Schleife für Y-Achse / Zeilen (Pętla dla osi Y / wierszy)
            for (int x = 0; x <= groesse; ++x) {   // Schleife für X-Achse / Spalten (Pętla dla osi X / kolumn)
                char symbol = '.';                 // Standardmäßig leeres Feld (Domyślnie puste pole)

                for (const auto& n : nahrungen) {  // Gehe durch alle Nahrungsquellen (Przejdź przez wszystkie źródła jedzenia)
                    if (n.xPosition == x && n.yPosition == y) {
                        symbol = 'N';              // Nahrungs-Symbol (Symbol jedzenia)
                        break;                     // Schleife abbrechen (Przerwanie pętli)
                    }
                }

                for (const auto& o : organismen) { // Gehe durch alle Organismen (Przejdź przez wszystkie organizmy)
                    if (o.getX() == x && o.getY() == y) {
                        symbol = 'O';              // Organismus-Symbol (Symbol organizmu)
                        break;                     // Schleife abbrechen (Przerwanie pętli)
                    }
                }

                std::cout << symbol << " ";        // Zeichen ausgeben gefolgt von Leerzeichen (Wypisanie znaku ze spacją)
            }
            std::cout << std::endl;                // Neue Zeile nach jeder Reihe (Nowa linia po każdym wierszu)
        }
        std::cout << "-------------------------------" << std::endl; // Trennlinie (Linia oddzielająca)
    }

    // Methode zur Anzeige von Statistiken (Metoda wyświetlania statystyk)
    void statistikenAnzeigen() const {
        std::cout << "=== OEKOSYSTEM STATISTIKEN (STATYSTYKI EKOSYSTEMU) ===" << std::endl; // Titel (Tytuł)
        std::cout << "Lebende Organismen (Żyjące organizmy): " << organismen.size() << std::endl; // Anzahl (Liczba)
        std::cout << "Verfügbare Nahrung (Dostępne jedzenie): " << nahrungen.size() << std::endl; // Nahrung (Jedzenie)
        std::cout << "Gesamte Geburten (Łączne narodziny):   " << gesamtGeburten << std::endl; // Geburten (Narodziny)
        std::cout << "Gesamte Tode (Łączne zgony):         " << gesamtTode << std::endl;     // Tode (Zgony)
        std::cout << "Verzehrte Nahrung (Zjedzone jedzenie): " << gesamtGegessen << std::endl; // Gegessen (Zjedzone)

        if (!organismen.empty()) {                 // Prüfen, ob Vektor nicht leer ist (Sprawdzenie, czy wektor nie jest pusty)
            int gesamtEnergie = 0;                 // Summe aller Energien (Suma wszystkich energii)
            int gesamtSicht = 0;                   // Summe aller Sichtweiten (Suma wszystkich zasięgów widzenia)
            for (const auto& o : organismen) {     // Durchlaufe alle Organismen (Przejdź przez wszystkie organizmy)
                gesamtEnergie += o.getEnergie();   // Addiere Energiewerte (Dodaj wartości energii)
                gesamtSicht += o.getSichtweite();  // Addiere Sichtweiten (Dodaj zasięgi widzenia)
            }
            double durchschnittsEnergie = static_cast<double>(gesamtEnergie) / organismen.size(); // Durchschnitt berechnen (Oblicz średnią)
            double durchschnittsSicht = static_cast<double>(gesamtSicht) / organismen.size();     // Mittlere Sichtweite berechnen (Oblicz średni zasięg widzenia)
            std::cout << "Durchschnittsenergie (Średnia energia):   " << durchschnittsEnergie << std::endl; // Ausgabe (Wyjście)
            std::cout << "Durchschnittssicht (Średni zasięg wzroku): " << durchschnittsSicht << std::endl; // Ausgabe (Wyjście)
        } else {
            std::cout << "Durchschnittsenergie (Średnia energia): 0" << std::endl; // Fallback wenn alle tot (Wartość zapasowa, gdy wszyscy nie żyją)
        }
        std::cout << "==================================================" << std::endl; // Trennlinie (Linia oddzielająca)
    }

    // Hauptsimulationsschritt (Główny krok symulacji)
    void simulieren() {
        std::cout << "\n--- Simulationsschritt gestartet (Rozpoczęto krok symulacji) ---" << std::endl;
        
        nahrungSpawnen(3);                         // 3 neue Nahrungsstücke spawnen (Generowanie 3 nowych kawałków jedzenia)

        for (auto& org : organismen) {
            org.bewegenZurNahrung(nahrungen, groesse); // Organismus bewegt sich im Rahmen seiner Sichtweite (Organizm porusza się w ramach swojego zasięgu widzenia)
        }

        for (auto orgIt = organismen.begin(); orgIt != organismen.end(); ++orgIt) {
            for (auto nahIt = nahrungen.begin(); nahIt != nahrungen.end(); ) {
                if (orgIt->getX() == nahIt->xPosition && orgIt->getY() == nahIt->yPosition) {
                    orgIt->energieErhoehen(nahIt->energieWert); // Energie aufstocken (Doładowanie energii)
                    std::cout << "Ein Organismus hat Nahrung gefunden! (Organizm znalazł jedzenie!)" << std::endl;
                    gesamtGegessen++;              // Zähler für verzehrte Nahrung erhöhen (Zwiększenie licznika zjedzonego jedzenia)
                    nahIt = nahrungen.erase(nahIt);    // Gegessenes Essen löschen (Usunięcie zjedzonego jedzenia)
                } else {
                    ++nahIt;                       // Weitergehen (Przejście dalej)
                }
            }
        }

        std::vector<Organismus> neueOrganismen;    // Liste für Babys (Lista na potomstwo)
        for (auto& org : organismen) {
            if (org.lebt() && org.kannReproduzieren()) {
                neueOrganismen.push_back(org.reproduzieren()); // Nachkomme erzeugen (Utworzenie potomka)
                gesamtGeburten++;                  // Zähler für Geburten erhöhen (Zwiększenie licznika narodzin)
                std::cout << "Ein Organismus hat sich fortgepflanzt! (Organizm się rozmnożył!)" << std::endl;
            }
        }
        for (const auto& baby : neueOrganismen) {
            organismen.push_back(baby);            // Babys zur Hauptliste hinzufügen (Dodanie maluchów do głównej listy)
        }

        size_t anzahlVorher = organismen.size();   // Größe vor dem Filtern (Rozmiar przed filtrowaniem)
        
        organismen.erase(
            std::remove_if(organismen.begin(), organismen.end(), [](const Organismus& o) {
                return !o.lebt();                  // Tote Organismen entfernen (Usunięcie martwych organizmów)
            }),
            organismen.end()
        );

        size_t anzahlNachher = organismen.size();  // Größe nach dem Filtern (Rozmiar po filtrowaniu)
        size_t gestorbenInDiesemSchritt = anzahlVorher - anzahlNachher; // Differenz ist die Zahl der Tode (Różnica to liczba zgonów)
        gesamtTode += gestorbenInDiesemSchritt;    // Zum Gesamtzähler addieren (Dodanie do całkowitego licznika)
    }
};

// Hauptfunktion des Programms (Główna funkcja programu)
int main() {
    std::cout << "--- Oekosystem Simulator: Schritt 10 (Genetik & Sichtweite) ---" << std::endl;

    Welt meineWelt(9);                             // Erstelle Welt 10x10 (0 bis 9) (Stwórz świat 10x10 od 0 do 9)
    
    meineWelt.organismusHinzufuegen(Organismus(10, 45, 2, 2)); // Organismus 1 mit 10 Basen DNA (Organizm 1 z 10 zasadami DNA)
    meineWelt.organismusHinzufuegen(Organismus(10, 45, 7, 7)); // Organismus 2 mit 10 Basen DNA (Organizm 2 z 10 zasadami DNA)

    meineWelt.visualisieren();                     // Weltkarte initial anzeigen (Wyświetl mapę świata początkową)

    for (int i = 0; i < 5; ++i) {                  // Schleife für 5 Simulationsschritte (Pętla dla 5 kroków symulacji)
        meineWelt.simulieren();                    // Schritt ausführen (Wykonaj krok)
        meineWelt.visualisieren();                 // Karte nach dem Schritt anzeigen (Wyświetl mapę po kroku)
        meineWelt.statistikenAnzeigen();           // Statistiken nach jedem Schritt anzeigen (Wyświetl statystyki po każdym kroku)
    }

    return 0;                                      // Programm erfolgreich beendet (Program zakończony pomyślnie)
}