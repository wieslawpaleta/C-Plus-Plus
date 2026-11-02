#include <iostream>
#include <string>
#include <vector>
#include <random>

// Klasse zur Darstellung der DNA eines Organismus (Klasa reprezentująca DNA organizmu)
class DNA {
private:
    std::string genSequenz;
    const std::string basen = "ATCG";

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
        std::cout << "Position: (" << xPosition << ", " << yPosition 
                  << ") | Energie: " << energie 
                  << " | DNA: " << dna.getSequenz() << std::endl;
    }

    // Methode zum Bewegen des Organismus innerhalb der Weltgranzen (Metoda poruszająca organizmem w granicach świata)
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

public:
    // Konstruktor für die Welt mit einer bestimten Groesse (Konstruktor świata o określonym rozmiarze)
    Welt(int weltGroesse) : groesse(weltGroesse) {}

    // Fügt einen Organismus zur Welt hinzu (Dodaje organizm do świata)
    void organismusHinzufuegen(const Organismus& org) {
        organismen.push_back(org);
    }

    // Führt einen Simulationsschritt für alle Organismen aus (Wykonuje krok symulacji dla wszystkich organizmów)
    void simulieren() {
        std::cout << "\n--- Simulationsschritt wird gestartet (Rozpoczyna się krok symulacji) ---" << std::endl;
    }
}

int main() {
    std::cout << "--- Oekosystem Simulator: Schritt 2 ---" << std::endl;

    // Erstelle einen Organismus mit DNA-Laenge 10, 50 Energie und Startposition (0, 0)
    // (Stwórz organizm o długości DNA 10, 50 energii i pozycji początkowej (0, 0))
    Organismus org(10, 50, 0, 0);

    // Zeige den initialen Status an (Wyświetl stan początkowy)
    org.statusAnzeigen();

    // Bewege den Organismus (Przesuń organizm)
    org.bewegen(3, 4);
    std::cout << "Nach der Bewegung (Po ruchu):" << std::endl;
    org.statusAnzeigen();

    return 0;
}