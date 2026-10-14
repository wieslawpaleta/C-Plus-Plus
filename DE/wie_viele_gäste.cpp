#include <iostream>
#include <string>
using namespace std;


int main() {
    int dieGästezahl;
    cout << "Wie viele Gäste? ";
    cin >> dieGästezahl;

    if (dieGästezahl <= 0) {
        cout << "Die Gästezahl muss mindestens 1 betragen.\n";
        return 0;
    }

    string* dieGäste = new string[dieGästezahl];

    cin.ignore();

    for (int i = 0; i < dieGästezahl; i++) {
        cout << "Gib den Namen für den Gast ein" << (i + 1) << ": ";
        getline(cin, dieGäste[i]);
    }


}