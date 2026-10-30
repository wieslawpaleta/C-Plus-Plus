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

    // Methode zum Bewegen des Organismus (Metoda poruszająca organizmem)
    void bewegen(int deltaX, int deltaY) {
        xPosition += deltaX;
        yPosition += deltaY;
        
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