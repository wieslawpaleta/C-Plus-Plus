#include <string>
#include <iostream>
#include <vector>

// Repräsentiert eine einzelne Aufgabe im System (Reprezentuje pojedyncze zadanie w systemie)
struct Aufgabe {
    int id;                     // Eindeutige Identifikationsnummer (Unikalny numer identyfikacyjny)
    std::string titel;          // Beschreibung der Aufgabe (Opis zadania)
    bool erledigt;              // Status: true wenn abgeschlossen, sonst false (Status: true, jeśli ukończono, w przeciwnym razie false)

    // Konstruktor zur Initialisierung einer neuen Aufgabe (Konstruktor do inicjalizacji nowego zadania)
    Aufgabe(int aufgabenId, std::string aufgabenTitel) 
        : id(aufgabenId), titel(aufgabenTitel), erledigt(false) {}

    // Methode zur formatierten Ausgabe der Aufgabe auf der Konsole (Metoda służąca do sformatowanego wypisywania zadania w konsoli)
    void anzeigen() const {
        std::cout << "[" << (erledigt ? "X" : " ") << "] "
                  << id << ": " << titel << "\n";
    }
};

class AufgabenManager {
    private:
    std::vector<Aufgabe> aufgabenListe; // Speichert alle Aufgaben (Przechowuje wszystkie zadania)
    int naechsteId; // Zählt die ID für die nächste Aufgabe hoch (Zwiększa ID dla nastepnego zadania)

    public:
        // Konstruktor initialisiert die ID mit 1 (Konstruktor inicjalizuje ID wartością 1)
        AufgabenManager() : naechsteId(1) {}

        // Fügt eine neue Aufgabe zur Liste hinzu (Dodaje nowe zadanie do listy)
        void aufgabeHinzufuegen(const std::string& titel) {
            aufgabenListe.emplace_back(naechsteId++, titel);
        }

        // Zeigt alle vorhandenen Aufgaben an (Wyświetla wszystkie istniejące zadania)
        void alleAnzeigen() const {
            if (aufgabenListe.empty()) {
                return;
            }
            for (const auto& aufgabe : aufgabenListe) {
                aufgabe.anzeigen();
            }
        }

        // Markiert eine Aufgabe anhand der ID als erledigt (Oznacza zadanie jako wykonane na podstawie ID)
        void alsErledigtMarkieren(int id) {
            for (auto& aufgabe : aufgabenListe) {
                if (aufgabe.id == id) {
                    aufgabe.erledigt = true;
                    std::cout << "Aufgabe " << id << " als erledigt markiert. (Zadanie " << id << " oznaczone jako wykonane.)\n";
                    return;
                }
            }
            std::cout << "Aufgabe mit ID " << id << " nicht gefunden. (Nie znaleziono zadania o ID " << id << ".)\n";
        }

        // (Diese Methoden kommen in die Klasse AufgabenManager / Te metody trafiąją do klasy AufgabenManager)
            // Speichert alle Aufgaben in eine Textdatei (Zapisuje wszystkie zadania do pliku tekstowego)
            void speichernInDatei(const std::string& dateiName) const {
                std::ofstream datei(dateiName); // Öffnet die Datei zum Schreiben Otwiera plik do zapisu)
                if (!datei.is.open()) {
                    
                }
            }
};

int main() {
    AufgabenManager manager; // Erstellt eine Instanz des Managers (Tworzy instancję menedżera)

    // Aufgaben hinzufügen (Dodawanie zadań)
    manager.aufgabeHinzufuegen("C++ Portfolio-Projekt starten");
    manager.aufgabeHinzufuegen("Über Klassen und Vektoren lernen");
    manager.aufgabeHinzufuegen("Dateispeicherung implementieren");

    std::cout << "--- Alle Aufgaben (Wszystkie zadania) ---\n";
    manager.alleAnzeigen();

    // Eine Aufgabe als erledigt markieren (Oznaczanie zadania jako wykonane)
    std::cout << "\n";
    manager.alsErledigtMarkieren(1);

    std::cout << "\n--- Aktualisierte Liste (Zaktualizowano lista) ---\n";
    manager.alleAnzeigen();

    return 0;
}