#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>

// Klasse zur Darstellung der DNA eines Organismus (Klasa reprezentująca DNA organizmu)
class DNA {
private:
    std::string genSequenz;
    std::string basen = "ATCG"; // 'const' wurde entfernt, damit der Vektor verschieben kann ('const' zostało usunięte, aby wektor mógł przesuwać obiekty)

public:
    // Konstruktor: Generiert eine zufällige DNA-Sequenz (Konstruktor: Generuje losową sekwencję DNA)
    DNA(size_t laenge) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, 3);

        for (size_t i = 0; i < laenge; ++i) {
            genSequenz += basen[dis(gen)];
        }
    }

    // Methode zur Mutation der DNA basierend auf einer Mutationsrate (Metoda mutacji DNA oparta na współczynniku mutacji)
    void mutieren(double mutationsRate) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> wahrscheinlichkeit(0.0, 1.0);
        std::uniform_int_distribution<> basenAuswahl(0, 3);

        for (size_t i = 0; i < genSequenz.length(); ++i) {
            if (wahrscheinlichkeit(gen) < mutationsRate) {
                genSequenz[i] = basen[basenAuswahl(gen)];
            }
        }
    }

    // Getter für die Gen-Sequenz (Getter zwracający sekwencję genów)
    std::string getSequenz() const {
        return genSequenz;
    }
};

// Klasse zur Darstellung von Nahrung im Oekosystem (Klasa przedstawiająca jedzenie w ekosystemie)
class Nahrung {
public:
    int xPosition;
    int yPosition;
    int energieWert;

    // Konstruktor für die Nahrung (Konstruktor dla jedzenia)
    Nahrung(int x, int y, int energie) : xPosition(x), yPosition(y), energieWert(energie) {}
};

// Klasse zur Darstellung eines Organismus im Oekosystem (Klasa reprezentująca organizm w ekosystemie)
class Organismus {
private:
    DNA dna;
    int energie;
    int xPosition;
    int yPosition;

public:
    // Konstruktor mit Initialisierungsliste (Konstruktor z listą inicjalizacyjną)
    Organismus(size_t dnaLaenge, int startEnergie, int startX, int startY) 
        : dna(dnaLaenge), energie(startEnergie), xPosition(startX), yPosition(startY) {}

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
            for (auto nahIt = nahrungen.begin(); nahIt)
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
        std::cout << "Aktuelle Anzahl Organismen (Aktualna liczba organizmów): " << organismen.size() << std::endl;
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

    // Füge zwei Organismen hinzu, einer davon mit sehr wenig Energie (Dodaj dwa organizmy, jeden z nich z bardzo małą ilością energii)
    meineWelt.organismusHinzufuegen(Organismus(8, 10, 5, 5)); // Viel Energie (Dużo energii)
    meineWelt.organismusHinzufuegen(Organismus(8, 2, 2, 2));  // Weniger Energie, wird bald sterben (Mniej energii, wkrótce umrze)

    std::cout << "\nInitialer Zustand der Welt (Początkowy stan świata):" << std::endl;
    meineWelt.weltStatusAnzeigen();

    // Simuliere 3 Schritte (Symuluj 3 kroki)
    for (int i = 0; i < 3; ++i) {
        meineWelt.simulieren();
        meineWelt.weltStatusAnzeigen();
    }

    return 0;
}