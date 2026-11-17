#include <iostream>     // Einbinden der Standard-I/O-Bibliothek (Dołączenie standardowej biblioteki I/O)
#include <string>       // Einbinden der String-Bibliothek (Dołączenie biblioteki stringów)
#include <vector>       // Einbinden der Vector-Bibliothek für dynamische Arrays (Dołączenie biblioteki wektorów)
#include <random>       // Einbinden der Zufallszahlen-Bibliothek (Dołączenie biblioteki liczb losowych)
#include <algorithm>    // Einbinden von Algorithmen wie remove_if (Dołączenie algorytmów takich jak remove_if)

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
        : dna(elternDna, 0.15), energie(startEnergie), xPosition(startX), yPosition(startY) {} // Initialisierungsliste mit Mutationsrate (Lista inicjalizacyjna ze współczynnikiem mutacji)

    // Methode zur Anzeige des Status (Metoda wyświetlająca stan)
    void statusAnzeigen() const {
        std::cout << "Pos: (" << xPosition << ", " << yPosition 
                  << ") | Energie: " << energie 
                  << " | DNA: " << dna.getSequenz() << std::endl; // Gibt Infos aus (Wyświetla informacje)
    }

    // Methode zum Bewegen des Organismus (Metoda poruszająca organizmem)
    void bewegen(int maxGrenze) {
        std::random_device rd;                     // Zufallsquelle (Źródło losowości)
        std::mt19937 gen(rd());                    // Generator (Generator)
        std::uniform_int_distribution<> schritt(-1, 1); // Schrittweite -1, 0 oder 1 (Krok -1, 0 lub 1)

        xPosition += schritt(gen);                 // Verändert X-Position zufällig (Zmienia pozycję X losowo)
        yPosition += schritt(gen);                 // Verändert Y-Position zufällig (Zmienia pozycję Y losowo)

        if (xPosition < 0) xPosition = 0;          // Links nicht herausfallen (Nie wypada z lewej)
        if (xPosition > maxGrenze) xPosition = maxGrenze; // Rechts nicht herausfallen (Nie wypada z prawej)
        if (yPosition < 0) yPosition = 0;          // Unten nicht herausfallen (Nie wypada na dole)
        if (yPosition > maxGrenze) yPosition = maxGrenze; // Oben nicht herausfallen (Nie wypada na górze)

        if (energie > 0) {
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

// Klasse zur Verwaltung des Oekosystems (Klasa zarządzająca ekosystemem)
class Welt {
private:
    int groesse;                                   // Weltgröße (Rozmiar świata)
    std::vector<Organismus> organismen;            // Liste aller Organismen (Lista wszystkich organizmów)
    std::vector<Nahrung> nahrungen;                // Liste aller Nahrungsquellen (Lista wszystkich źródeł jedzenia)

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
                char symbol = '.';                 // Standardmäßig leeres Feld (Domyślně puste pole)

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

    // Hauptsimulationsschritt (Główny krok symulacji)
    void simulieren() {
        std::cout << "\n--- Simulationsschritt gestartet (Rozpoczęto krok symulacji) ---" << std::endl;
        
        // 0. Automatischia neue Nahrung in jedem Schritt spawnen (Automatyczne generowanie nowego jedzenia w każdym kroku)
        nahrungSpawnen(2);                             // Fügt in jedem Schritt 2 neue Nahrungsstücke hinzu (Dodaje 2 nowe kawałki jedzenia w każdym kroku)

        // 1. Alle Organismen bewegen sich (Wszystkie organizmy się poruszają)
        for (auto& org : organismen) {
            org.bewegen(groesse);
        }

        // 2. Nahrung einsammeln (Zbieranie jedzenia)
        for (auto orgIt = organismen.begin(); orgIt != organismen.end(); ++orgIt) {
            for (auto nahIt = nahrungen.begin(); nahIt != nahrungen.end(); ) {
                if (orgIt->getX() == nahIt->xPosition && orgIt->getY() == nahIt->yPosition) {
                    orgIt->energieErhoehen(nahIt->energieWert); // Energie aufladen (Doładowanie energii)
                    std::cout << "Ein Organismus hat Nahrung gefunden! (Organizm znalazł jedzenie!)" << std::endl;
                    nahIt = nahrungen.erase(nahIt);        // Gegessene Nahrung löschen (Usuwanie zjedzonego jedzenia)
                } else {
                    ++nahIt;
                }
            }
        }

        // 3. Fortpflanzung der Organismen (Rozmnażanie organizmów)
        std::vector<Organismus> neueOrganismen;            // Temporäre Liste für Babys (Tymczasowa lista na maluchy)
        for (auto& org : organismen) {
            if (org.lebt() && org.kannReproduzieren()) {   // Wenn lebendig und genug Energie (Jeśli żyje i ma dość energii)
                neueOrganismen.push_back(org.reproduzieren()); // Erstelle Nachkomme (Stwórz potomka)
                std::cout << "Ein Organismus hat sich fortgepflanzt! (Organizm się rozmnożył!)" << std::endl;
            }
        }
        // Füge die neuen Nachkommen zur Hauptliste hinzu (Dodaj nowych potomków do głównej listy)
        for (const auto& baby : neueOrganismen) {
            organismen.push_back(baby);
        }

        // Tote Organismen entfernen (Usuwanie martwych organizmów)
        organismen.erase(
            std::remove_if(organismen.begin(), organismen.end(), [](const Organismus& o) {
                return !o.lebt();                  // Entferne alle, die nicht mehr leben (Usuń wszystkie, które już nie żyją)
            }),
            organismen.end()
        );
    }

    // Zeigt den aktuellen Weltstatus (Wyświetla aktualny stan świata)
    void weltStatusAnzeigen() const {
        std::cout << "Organismen (Organizmy): " << organismen.size() 
                  << " | Nahrung (Jedzenie): " << nahrungen.size() << std::endl;
    }
};

// Hauptfunktion des Programms (Główna funkcja programu)
int main() {
    std::cout << "--- Oekosystem Simulator: Schritt 7 (Visualisierung) ---" << std::endl;

    // Erstelle eine Welt mit der Groesse 10x10 (Stwórz świat o wielkości 10x10)
    Welt meineWelt(9);

    // Starte mit zwei Organismen (Rozpocznij z dwoma organizmami)
    meineWelt.organismusHinzufuegen(Organismus(8, 40, 3, 3));
    meineWelt.organismusHinzufuegen(Organismus(8, 40, 6, 6));

    meineWelt.weltStatusAnzeigen();

    // Simuliere 3 Schritte (Symuluj 3 kroki)
    for (int i = 0; i < 3; ++i) {
        meineWelt.simulieren();
        meineWelt.weltStatusAnzeigen();
    }

    return 0;
}