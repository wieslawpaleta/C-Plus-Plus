#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>

// Klasse zur Darstellung der DNA eines Organismus (Klasa reprezentująca DNA organizmu)
class DNA {
private:
    std::string genSequenz;         // Speichert die Gen-Sequenz als String (Przechowuje sekwencję genów jako string)
    std::string basen = "ATCG";     // Verfügbare Basen für die DNA (Dostępne zasady dla DNA)

public:
    // 1. Konstruktor: Generiert eine zufällige DNA-Sequenz (Konstruktor: Generuje losową sekwencję DNA)
    DNA(size_t laenge) {
        std::random_device rd;                     // Initialisiert den Hardware-Zufallsgenerator (Inicjalizuje sprzętowy generator losowy)
        std::mt19937 gen(rd());                    // Startet den Mersenne-Twister Zufallsgenerator (Uruchamia generator Mersenne-Twister)
        std::uniform_int_distribution<> dis(0, 3); // Definiert einen Bereich von 0 bis 3 für die Basen (Definiuje zakres od 0 do 3 dla zasad)

        for (size_t i = 0; i < laenge; ++i) {      // Schleife läuft für jede Position der gewünschten Länge (Pętla wykonuje się dla każdej pozycji żądanej długości)
            genSequenz += basen[dis(gen)];         // Fügt zufällig eine Basis (A, T, C oder G) hinzu (Losowo dodaje zasadę A, T, C lub G)
        }
    }

    // 2. Konstruktor für Nachkommen: Kopiert und mutiert Eltern-DNA (Konstruktor dla potomka: Kopiuje i mutuje DNA rodzica)
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
        return genSequenz; // Gibt den Sequenz-String zurück (Zwraca łańcuch sekwencji)
    }
};

// Klasse zur Darstellung von Nahrung im Oekosystem (Klasa reprezentująca jedzenie w ekosystemie)
class Nahrung {
public:
    int xPosition;   // X-Koordinate der Nahrung (Współrzędna X jedzenia)
    int yPosition;   // Y-Koordinate der Nahrung (Współrzędna Y jedzenia)
    int energieWert; // Menge an Energie, die die Nahrung bringt (Ilość energii, jaką daje jedzenie)

    // Konstruktor der Nahrungs-Klasse (Konstruktor klasy jedzenia)
    Nahrung(int x, int y, int energie) : xPosition(x), yPosition(y), energieWert(energie) {}
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
        : dna(dnaLaenge), energie(startEnergie), xPosition(startX), yPosition(startY) {}

    // Konstruktor für Nachkommen (Erbt DNA und bekommt Position/Energie) (Konstruktor dla potomków - dziedziczy DNA i otrzymuje pozycję/energię)
    Organismus(const DNA& elternDna, int startX, int startY, int startEnergie)
        : dna(elternDna, 0.15), energie(startEnergie), xPosition(startX), yPosition(startY) {} // 15% Mutationsrate (15% współczynnik mutacji)

    // Methode zur Anzeige des Status (Metoda wyświetlająca stan)
    void statusAnzeigen() const {
        std::cout << "Pos: (" << xPosition << ", " << yPosition 
                  << ") | Energie: " << energie 
                  << " | DNA: " << dna.getSequenz() << std::endl;
    }

    // Methode zum Bewegen des Organismus (Metoda poruszająca organizmem)
    void bewegen(int maxGrenze) {
        std::random_device rd;                     // Zufallsquelle (Źródło losowości)
        std::mt19937 gen(rd());                    // Generator (Generator)
        std::uniform_int_distribution<> schritt(-1, 1); // Schrittweite -1, 0 oder 1 (Krok -1, 0 lub 1)

        xPosition += schritt(gen);                 // Verändert X-Position zufällig (Zmienia pozycję X losowo)
        yPosition += schritt(gen);                 // Verändert Y-Position zufällig (Zmienia pozycję Y losowo)

        // Begrenzung innerhalb der Welt (Ograniczenie w granicach świata)
        if (xPosition < 0) xPosition = 0;          // Links nicht herausfallen (Nie wypada z lewej)
        if (xPosition > maxGrenze) xPosition = maxGrenze; // Rechts nicht herausfallen (Nie wypada z prawej)
        if (yPosition < 0) yPosition = 0;          // Unten nie herausfallen (Nie wypada na dole)
        if (yPosition > maxGrenze) yPosition = maxGrenze; // Oben nicht herausfallen (Nie wypada na górze)

        if (energie > 0) {
            energie--;                             // Bewegung kostet 1 Energiepunkt (Ruch kosztuje 1 punkt energii)
        }
    }

    // Erhöht die Energie (Zwiększa energię)
    void energieErhoehen(int menge) {
        energie += menge;                          // Addiert die Nahrungsenergie (Dodaje energię z jedzenia)
    }

    // Getter für Positionen (Gettery dla pozycji)
    int getX() const { return xPosition; }
    int getY() const { return yPosition; }

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
        return Organismus(dna, xPosition, yPosition, energie); // Erzeugt neuen Organismus mit der Eltern-DNA (Tworzy nowy organizm z DNA rodzica)
    }
};

// Klasse zur Verwaltung des Oekosystems (Klasa zarządzająca ekosystemem)
class Welt {
private:
    int groesse;                                   // Weltgröße (Rozmiar świata)
    std::vector<Organismus> organismen;            // Liste aller Organismen (Lista wszystkich organizmów)
    std::vector<Nahrung> nahrungen;                // Liste aller Nahrungsquellen (Lista wszystkich źródeł jedzenia)

public:
    Welt(int weltGroesse) : groesse(weltGroesse) {}

    void organismusHinzufuegen(const Organismus& org) {
        organismen.push_back(org);                 // Fügt Organismus hinzu (Dodaje organizm)
    }

    // Methode zum automatischen Generieren von Nahrung (Metoda do automatycznego generowania jedzenia)
    void nahrungSpawnen(int anzahl) {
        std::random_device rd;                     // Zufallsquelle für Positionen (Źródło losowości dla pozycji)
        std::mt19937 gen(rd());                    // Generator starten (Uruchomienie generatora)
        std::uniform_int_distribution<> dis(0, groesse); // Bereich von 0 bis Weltgröße (Zakres od 0 do rozmiaru świata)

        for (int i = 0; i < anzahl; ++i) {
            int zufallX = dis(gen);                // Zufällige X-Koordinate (Losowa współrzędna X)
            int zufallY = dis(gen);                // Zufällige Y-Koordinate (Losowa współrzędna Y)
            nahrungen.push_back(Nahrung(zufallX, zufallY, 25)); // Nahrung mit 25 Energie hinzufügen (Dodaj jedzenie z 25 energią)
        }
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
-- tu skończyłem
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
        std::cout << "Anzahl Organismen (Liczba organizmów): " << organismen.size() 
                  << " | Anzahl Nahrungsquellen (Liczba źródeł jedzenia): " << nahrungen.size() << std::endl;
        for (size_t i = 0; i < organismen.size(); ++i) {
            std::cout << "  - Organismus " << i << " -> ";
            organismen[i].statusAnzeigen();          // Status jedes Organismus ausgeben (Wyświetl stan każdego organizmu)
        }
    }
};

int main() {
    std::cout << "--- Oekosystem Simulator: Schritt 4 (Nahrung) ---" << std::endl;

    // Erstelle eine Welt mit der Groesse 10x10 (Stwórz świat o wielkości 10x10)
    Welt meineWelt(10);

    // Füge einen Organismus bei Position (5, 5) mit wenig Energie hinzu (Dodaj organizm na pozycji (5, 5) z małą ilością energii)
    meineWelt.organismusHinzufuegen(Organismus(8, 3, 5, 5));

    // Füge Nahrung genau dorthin hinzu, wo sich der Organismus bewegen könnte (Dodaj jedzenie dokładnie tam, dokąd może się ruszyć organizm)
    meineWelt.nahrungHinzufuegen(Nahrung(5, 4, 10)); // 10 Energiepunkte (10 punktów energii)

    std::cout << "\nInitialer Zustand der Welt (Początkowy stan świata):" << std::endl;
    meineWelt.weltStatusAnzeigen();

    // Simuliere 3 Schritte (Symuluj 3 kroki)
    for (int i = 0; i < 3; ++i) {
        meineWelt.simulieren();
        meineWelt.weltStatusAnzeigen();
    }

    return 0;
}