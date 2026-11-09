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
        std::mt19937 gen(rd());                    // Startet den Mersenne-Twister Zufallsgenerator (Uruchomiler generator Mersenne-Twister)
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

// Klasse zur Darstellung von Nahrung im Oekosystem (Klasa przedstawiająca jedzenie w ekosystemie)
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
        
    // Methode zur Anzeige des aktuellen Status (Metoda wyświetlająca aktualny stan)
    void statusAnzeigen() const {
        std::cout << "Pos: (" << xPosition << ", " << yPosition 
                  << ") | Energie: " << energie 
                  << " | DNA: " << dna.getSequenz() << std::endl;
    }

    // Methode zum Bewegen des Organismus innerhalb der Weltgrenzen (Metoda poruszająca organizmem w granicach świata)
    void bewegen(int maxGrenze) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> schritt(-1, 1);

        xPosition += schritt(gen);
        yPosition += schritt(gen);

        // Begrenzung der Welt, damit niemand herausfaellt (Ograniczenie świata, aby nikt nie wypadł poza planszę)
        if (xPosition < 0) xPosition = 0;
        if (xPosition > maxGrenze) xPosition = maxGrenze;
        if (yPosition < 0) yPosition = 0;
        if (yPosition > maxGrenze) yPosition = maxGrenze;

        // Energieverlust bei Bewegung (Utrata energii podczas ruchu)
        if (energie > 0) {
            energie--;
        }
    }

    // Energie hinzufügen, wenn Nahrung konsumiert wird (Dodawanie energii po skonsumowaniu jedzenia)
    void energieErhoehen(int menge) {
        energie += menge;
    }

    // Getter für X-Position (Getter dla pozycji X)
    int getX() const { return xPosition; }

    // Getter für Y-Position (Getter dla pozycji Y)
    int getY() const { return yPosition; }

    // Prüft, ob der Organismus noch am Leben ist (Sprawdza, czy organizm nadal żyje)
    bool lebt() const {
        return energie > 0;
    }
};

// Klasse zur Verwaltung des Oekosystems und aller Organismen (Klasa do zarządzania ekosystemem i wszystkimi organizmami)
class Welt {
private:
    int groesse;
    std::vector<Organismus> organismen;
    std::vector<Nahrung> nahrungen;

public:
    // Konstruktor für die Welt mit einer bestimmten Groesse (Konstruktor świata o określonym rozmiarze)
    Welt(int weltGroesse) : groesse(weltGroesse) {}

    // Fügt einen Organismus zur Welt hinzu (Dodaje organizm do świata)
    void organismusHinzufuegen(const Organismus& org) {
        organismen.push_back(org);
    }

    // Fügt Nahrung zur Welt hinzu (Dodaje jedzenie do świata)
    void nahrungHinzufügen(const Nahrung& n) {
        nahrungen.push_back(n);
    }

    // Führt einen Simulationsschritt für alle Organismen aus (Wykonuje krok symulacji dla wszystkich organizmów)
    void simulieren() {
        std::cout << "\n--- Simulationsschritt wird gestartet (Rozpoczyna się krok symulacji) ---" << std::endl;
        
        // Lasse alle Organismen bewegen (Pozwól wszystkim organizmom się poruszyć)
        for (auto& org : organismen) {
            org.bewegen(groesse);
        }

        // Interaktion: Prüfen, ob Organismen Nahrung finden (Interakcja: czy organizmy znajdują jedzenie)
        for (auto orgIt = organismen.begin(); orgIt != organismen.end(); ++orgIt) {
            for (auto nahIt = nahrungen.begin(); nahIt != nahrungen.end(); ) {
                if (orgIt->getX() == nahIt->xPosition && orgIt->getY() == nahIt->yPosition) {
                    // Organismus frisst die Nahrung (Organizm zjada jedzenie)
                    orgIt->energieErhoehen(nahIt->energieWert);
                    orgIt->energieErhoehen(nahIt->energieWert);
                    std::cout << "Ein Organismus hat Nahrung gefunden und Energie erhalten! (Organizm znalazł jedzenie i zyskał energię!)" << std::endl;

                    // Entferne die konsumierte Nahrung aus dem Vektor (Usuń skonsumowane jedzenie z wektora)
                    nahIt = nahrungen.erase(nahIt);
                } else {
                    ++nahIt;
                }
            }
        }

        // Entferne tote Organismen aus dem Vector (Usuń martwe organizmy z wektora)
        organismen.erase(
            std::remove_if(organismen.begin(), organismen.end(), [](const Organismus& o) {
                return !o.lebt();
            }),
            organismen.end()
        );
    }

    // Zeigt den Status der gesamten Welt an (Wyświetla stan całego świata)
    void weltStatusAnzeigen() const {
        std::cout << "Anzahl Organismen (Liczba organizmów): " << organismen.size() 
                  << " | Anzahl Nahrungsquellen (Liczba źródeł jedzenia): " << nahrungen.size() << std::endl;
        for (size_t i = 0; i < organismen.size(); ++i) {
            std::cout << "Organismus " << i << " -> ";
            organismen[i].statusAnzeigen();
        }
    }
};

int main() {
    std::cout << "--- Oekosystem Simulator: Schritt 3 (Welt) ---" << std::endl;

    // Erstelle eine Welt mit der Groesse 10x10 (Stwórz świat o wielkości 10x10)
    Welt meineWelt(10);

    // Füge einen Organismus bei Position (5, 5) mit wenig Energie hinzu (Dodaj organizm na pozycji (5, 5) z małą ilością energii)
    meineWelt.organismusHinzufuegen(Organismus(8, 3, 5, 5));
    
    //Füge Nahrung genau dorthin hinzu, wo sich der Organismus bewegen könnte (Dodaj jedzenie dokładnie tam, dokąd może się ruszyć organizm)
    meineWelt.nahrungHinzufügen(Nahrung(5, 4, 10)); // 10 Energiepunkte (10 punktów energii)

    std::cout << "\nInitialer Zustand der Welt (Początkowy stan świata):" << std::endl;
    meineWelt.weltStatusAnzeigen();

    // Simuliere 3 Schritte (Symuluj 3 kroki)
    for (int i = 0; i < 3; ++i) {
        meineWelt.simulieren();
        meineWelt.weltStatusAnzeigen();
    }

    return 0;
}