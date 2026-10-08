#include <iostream>
using namespace std;

int main() {

    bool schiffe[4][4] = {
        { 0, 1, 1, 0},
        { 0, 0, 0, 0},
        { 0, 0, 1, 0},
        { 0, 0, 1, 0}
    };

int dieTreffer = 0;
int dieAnzahlDerZüge = 0;

while (dieTreffer < 4) {
    int dieZeile, dieSpalte;

    cout << "Koordinatenauswahl\n";

    cout << "Wähle eine Zeilennummer zwischen 0 und 3: ";
    cin >> dieZeile;

    cout << "Wähle eine Spaltennummer zwischen 0 und 3: ";
    cin >> dieSpalte;

    if (schiffe[dieZeile][dieSpalte]) {
        schiffe[dieZeile][dieSpalte] = 0;

        dieTreffer++;

        cout << "Treffer! " << "Noch " << (4 - dieTreffer) << "\n\n";
    } else {
       cout << "Wasser!\n\n";
    }
    dieAnzahlDerZüge++;
}
cout << "Sieg!\n";
cout << "Du hast in " << dieAnzahlDerZüge << " Runden gewonnen!";

}