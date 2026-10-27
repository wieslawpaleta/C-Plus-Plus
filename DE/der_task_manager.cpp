#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

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

        // Löscht eine Aufgabe anhand der ID (Usuwa zadanie na podstawie ID)
        void aufgabeLoeschen(int id) {
            for (auto it = aufgabenListe.begin(); it != aufgabenListe.end(); ++it) {
                if (it->id == id) {
                    aufgabenListe.erase(it); // Entfernt das Element aus dem Vector (Usuwa element z wektora)
                    std::cout << "Aufgabe " << id << " wurde geloescht. (Zadanie " << id << " zostało usunięte.)\n";
                    return;
                }
            }
                std::cout << "Aufgabe mit ID " << id << " zum Loeschen nicht gefunden. (Nie znaleziono zadania o ID " << id << " do usunięcia.)\n";
        }

        // (Diese Methoden kommen in die Klasse AufgabenManager / Te metody trafiąją do klasy AufgabenManager)
            // Speichert alle Aufgaben in eine Textdatei (Zapisuje wszystkie zadania do pliku tekstowego)
        void speichernInDatei(const std::string& dateiName) const {
            std::ofstream datei(dateiName); // Öffnet die Datei zum Schreiben (Otwiera plik do zapisu)
            if (!datei.is_open()) {
                std::cout << "Fehler beim Speichern der Datei! (Błąd podczas zapisu pliku!)\n";
                return;
            }

            for (const auto& aufgabe : aufgabenListe) {
                // Format: ID;Erledigt(1/0);Titel (Format: ID;Wykonane(1/0);Tytuł)
                    datei << aufgabe.id << ";" << (aufgabe.erledigt ? 1 : 0) << ";" << aufgabe.titel << "\n";
            }
            std::cout << "Aufgaben erfolgreich in " << dateiName << " gespeichert. (Zadania zostały pomyślnie zapisane w " << dateiName << ".)\n";
        }

            // Lädt Aufgaben aus einer Textdatei (Wczytuje zadania z pliku tekstowego)
            void ladenAusDatei(const std::string& dateiName) {
                std::ifstream datei(dateiName); // Öffnet die Datei zum Lesen (Otwiera plik do odczytu)
                if (!datei.is_open()) {
                    std::cout << "Keine bestehende Datei gefunden. Starte mit leerer Liste. (Nie znaleziono istniejącego pliku. Start z pustą listą.)\n";
                    return;
                }
            
                aufgabenListe.clear(); // Liste vor dem laden leeren (Czyszczenie listy przed wczytaniem)
                std::string zeile;
                int maxId = 0;

                while (std::getline(datei, zeile)) {
                    std::stringstream ss(zeile);
                    std::string idStr, erledigtStr, titel;

                    if (std::getline(ss, idStr, ';') && std::getline(ss, erledigtStr, ';') && std::getline(ss, titel)) {
                        int id = std::stoi(idStr);
                        bool erledigt = (std::stoi(erledigtStr) == 1);

                        Aufgabe aufgabe(id, titel);
                        aufgabe.erledigt = erledigt;
                        aufgabenListe.push_back(aufgabe);

                        if (id > maxId) {
                            maxId = id;
                        }
                    }
                }
                        naechsteId = maxId + 1; // Nächste ID basierend auf geladenen Daten anpassen (Dostosowanie następnego ID na podstawie wczytanych danych)
                        std::cout << "Aufgaben erfolgreich aus " << dateiName << " geladen. (Zadania zostały pomyślnie wczytane z " << dateiName << ".)\n";
            }
        };

int main() {
    AufgabenManager manager; // Erstellt eine Instanz des Managers (Tworzy instancję menedżera)
    manager.ladenAusDatei("aufgaben.txt"); // Lädt vorhandene Aufgaben beim Start (Wczytuje istniejące zadania przy starcie)

    int auswahl;
    do {
        std::cout << "\n=== TASK MANAGER ===\n";
        std::cout << "1. Aufgabe hinzufuegen (Dodaj zadanie)\n";
        std::cout << "2. Alle Aufgaben anzeigen (Wyświetl wszystkie zadania)\n";
        std::cout << "3. Aufgabe als erledigt markieren (Oznacz zadanie jako wykonane)\n";
        std::cout << "4. Aufgabe loeschen (Usuń zadanie)\n";
        std::cout << "5. Speichern und Beenden (Zapisz i wyjdź)\n";
        std::cout << "Waehle eine Option (Wybierz opcję): ";
        std::cin >> auswahl;

        // Witchtig: Eingabepuffer nach std::cin bereinigen (Ważne: Czyszczenie bufora wejściowego po std::cin)
        std::cin.ignore();

        switch (auswahl) {
            case 1: {
                std::string titel;
                std::cout << "Gib den Titel der Aufgabe ein (Podaj tytuł zadania): ";
                std::getline(std::cin, titel);
                manager.aufgabeHinzufuegen(titel);
                break;
            }
            case 2:
            std::cout << "\n--- Deine Aufgaben (Twoje zadania) ---\n";
            manager.alleAnzeigen();
            break;
            case 3: {
                int id;
                std::cout << "Gib die ID der erledigten Aufgabe ein (Podaj ID wykonanego zadania): ";
                std::cin >> id;
                manager.alsErledigtMarkieren(id);
                break;
            }
            case 4: {
                int id;
                std::cout << "Gib die ID der zu loeschenden Aufgabe ein (Podaj ID zadania do usunięcia): ";
                std::cin >> id;
                manager.aufgabeLoeschen(id);
                break;
            }
            case 5:
                manager.speichernInDatei("aufgaben.txt");
                std::cout << "Programm beendet. Auf Wiedersehen! (Program zakończony. Do widzenia!)\n";
                break;
            default:
                std::cout << "Ungueltige Auswahl. Versuche es erneut. (Nieprawidłowy wybór. Spróbuj ponownie.)\n";          
          }
        } while (auswahl != 5);
     return 0;
}
    
    
    
    
    
    
    
    
    // // Aufgaben hinzufügen (Dodawanie zadań)
    // manager.aufgabeHinzufuegen("C++ Portfolio-Projekt starten");
    // manager.aufgabeHinzufuegen("Über Klassen und Vektoren lernen");
    // manager.aufgabeHinzufuegen("Dateispeicherung implementieren");

    // std::cout << "--- Alle Aufgaben (Wszystkie zadania) ---\n";
    // manager.alleAnzeigen();

    // // Eine Aufgabe als erledigt markieren (Oznaczanie zadania jako wykonane)
    // std::cout << "\n";
    // manager.alsErledigtMarkieren(1);

    // std::cout << "\n--- Aktualisierte Liste (Zaktualizowana lista) ---\n";
    // manager.alleAnzeigen();

//     return 0;
// }
