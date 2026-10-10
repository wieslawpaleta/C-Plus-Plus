//C++ w3schools
//Introduction, Get Started with C++, Syntax, Statements, Syntax Code Challenge, Output (Print Text), Print Numbers, New Lines, Output Code Challenge, Comments
/*Ja, ich weiß, wie man mehrzeilige Kommentare verwendet.*/
//VariablesDeclare, Multiple Variables, Identifiers, Constants, Variables Examples, Variables Code Challenge, User Input, Data Types, Numeric Data Types, Boolean Data Types
//Character Data Types, String Data Types, auto, Data Types Examples, Enums/Enumerartion
//
//
//
//
//
//


#include <iostream>
#include <string>
#include <typeinfo>
#include <cmath>
#include <vector>
using namespace std;

struct dasAuto {
    string dieMarke;
    string dasModel;
    int dasJahr;
};

// enum dieStufe {
//     NIEDRIG,
//     MITTEL,
//     HOCH
// };

// enum dieStufe {
//     NIEDRIG = 25,
//     MITTEL = 50,
//     HOCH = 75
// };

enum dieStufe {
    NIEDRIG = 5,
    MITTEL,
    HOCH
};

// int main() {
//     std::cout << "Wer seid ihr?" << std::endl;
//     return 0;
// }


int main() {
//     cout << "Hallo, Welt! Wie geht es euch?" << endl;
//     cout << "Wer seid ihr?" << endl;
//     cout << "\nHallo, Welt! Wie geht es euch? ";
//     cout << "Wer seid ihr?\n";
//     cout << 3 << endl;
//     cout << 5 << endl;
//     cout << 3 + 5 << endl;
//     cout << 3 * 5 << endl;
//     cout << "GrundLegendes" << "\n";
//     cout << "Dieser Kurs richtet sich an Anfänger\t";
//     cout << "Du kennst die Regeln" << endl;
//     int meinNum = 15;
//     cout << meinNum << endl;
//     double meinDouble;
//     meinDouble = 6.98;
//     cout << meinDouble << endl;
//     char meinChar = 'P';
//     meinChar = 'Z';
//     cout << meinChar << endl;
//     string meinText = "der Begriff";
//     bool meinBooLean = true;
//     cout << meinText << " Nummer " << meinBooLean << endl;
//     double sum = meinNum + meinDouble;
//     cout << sum << endl;
//     int x = 9, y = 3, z = 2;
//     cout << x + y + z << endl;
//     int a, b, c;
//     a = b = c = 50;
//     cout << a + b + c << endl;
//     string pilzArt = "der Fliegenpilz";
//     cout << pilzArt << endl;
//     const int kilometerProStunde = 60;
//     cout << kilometerProStunde << endl;
//     // kilometerProStunde = 30; //error
//     // cout << kilometerProStunde << endl;


// //Der Rechteckrechner
//     int Länge = 4;
//     int Breite = 6;


//     int Fläche = Länge * Breite;


//     cout << "Die Länge beträgt: " << Länge << "\n";
//     cout << "Die Breite beträgt: " << Breite << "\n";
//     cout << "die Fläche des Rechtecks beträgt: " << Fläche << "\n";


// //User Input
//     int d;
//     cout << "Gib eine Zahl ein: ";
//     cin >> d;
//     cout << "Deine Zahl ist: " << d << endl;

// //Der Rechteckrechner mit CIN
//     int teil1, teil2;
//     int summe;
//     cout << "Gib eine Zahl ein: ";
//     cin >> teil1;
//     cout << "Gib die nächste Zahl ein: ";
//     cin >> teil2;
//     summe = teil1 + teil2;
//     cout << "Die Summe beträgt: " << summe << endl;

//     float meinFloatNum = 5.99;
//     string meinText1 = "Hallo";
//     char meinBuchstabe = 'D';

//     float f1 = 35e3;
//     double d1 = 12E4;
//     cout << f1;
//     cout << d1 << endl;


//     char p = 65; 
//     char r = 66; 
//     char q = 67;
//     cout << p << endl;
//     cout << b << endl;
//     cout << c << endl;


//     auto i = 2.99f;
//     cout << typeid(i).name() << endl;


//     int stück = 49;
//     double kosten_pro_stück  = 23.66;
//     double gesamtkosten = stück * kosten_pro_stück;
//     char währung = '$';

//     cout << "Stückzahl: " << stück << "\n";
//     cout << "Kosten pro Stück: " << kosten_pro_stück << "\n";
//     cout << "Gesamtkosten: " << gesamtkosten << währung << "\n";

    
// /* Data Types Code Challenge, Operators, Arithmetic Operators (Ich bin jetzt hier) */


//     int summe1 = 34 + 66;
//     cout << summe1 << endl;
//     int summe2 = summe1 + 50;
//     cout << summe2 << endl;
//     int summe3 = summe2 + summe1;
//     cout << summe3 << endl;


//     int hu = 100;
//     int bu = 20;

//     cout << (hu + bu) << "\n";
//     cout << (hu - bu) << "\n";
//     cout << (hu * bu) << "\n";
//     cout << (hu / bu) << "\n";
//     cout << (hu % bu) << "\n";

//     int zu = 7;
//     ++z;
//     cout << zu << "\n";
//     --z;
//     cout << zu << "\n";


//     int gu = 10;
//     int du = 3;
    
//     cout << (gu + du) << "\n";
//     cout << (gu - du) << "\n";
//     cout << (gu * du) << "\n";
//     cout << (gu / du) << "\n";
//     cout << (gu % du) << "\n";


//     int lu = 5;
//     ++lu;
//     cout << lu << "\n";
//     --lu;
//     cout << lu << "\n";


//     int au = 10;
//     int qu = 3;
//     cout << (x / y) << "\n";

//     double vu = 10.0;
//     double nu = 3.0;
//     cout << (a / b) << "\n";


//     int tu = 5;

//     ++tu;
//     cout << tu << "\n";


//     int wu = 5;

//     --wu;
//     cout << wu << "\n";


//     int uu = 5;

//     ++uu;
//     --uu;
//     cout << uu << "\n";


//     int personenImRaum = 0;

//     personenImRaum++;
//     personenImRaum++;
//     personenImRaum++;

//     cout << personenImRaum << "\n";

//     personenImRaum--;

//     cout << personenImRaum << "\n";


// /*Assignment Operators (Ich bin jetzt hier) */


//     int yu = 10;
//     yu += 5;
//     yu -= 5;
//     yu *= 5;
//     yu /= 5;
//     yu %= 5;
//     yu &= 5;
//     yu |= 5;
//     yu ^= 5;
//     yu >>= 5;
//     yu <<= 5;

//     cout << yu << endl;


// /*Praixsbeispiel*/
// /*Comparison Operators, Logical Operators, Operator Precedence*/


//     int ersparnisse = 100;
//     ersparnisse += 50;

//     cout << "Die Gesamtersparnisse: " << ersparnisse;


//     int ao = 5;
//     int bo = 3;

//     cout << (ao > bo) << endl;
//     cout << (ao < bo) << endl;
//     cout << (ao == bo) << endl;
//     cout << (ao != bo) << endl;
//     cout << (ao >= bo) << endl;
//     cout << (ao <= bo) << endl;
//     cout << (ao < bo && ao != bo) << endl;
//     cout << (ao < bo || ao > bo) << endl;
//     cout << !(ao < bo && ao == bo) << endl;


//     int co = 2 + 3 * 4;
//     int eo = (2 + 3) * 4;
    
//     cout << co << endl;
//     cout << eo << endl;


//     /* Operators Code Challenge, Strings */


//     string gruss = "Halo";

//     cout << gruss << endl;


//     /*String Concatenation*/
//     string vorname1 = "Willhelm";
//     string nachname1 = "Schmidt";
//     string vollständigerName = vorname1 + nachname1;
//     cout << vollständigerName << endl;
    
//     string vorname2 = "Willhelm";
//     string nachname2 = "Schmidt";
//     string vollständigerName1 = vorname2 + " " + nachname2;
//     cout << vollständigerName1 << endl;

//     string vorname3 = "Willhelm";
//     string nachname3 = "Schmidt";
//     string vollständigerName2 = vorname3.append(nachname3);
//     cout << vollständigerName2 << endl;
    

//     /*Numbers and Strings*/
//     int fo = 10;
//     int go = 20;
//     int ho = fo + go;
//     cout << ho << endl;

//     string io = "10";
//     string jo = "20";
//     string ko = io + jo;
//     cout << ko << endl;


//     /*String Length*/
//     string lo = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
//     cout << "Die Länge der Textzeichenkette beträgt: " << lo.length() << endl;
//     cout << "Die Länge der Textzeichenkette beträgt: " << lo.size() << endl;

//     return 0;


    /*Access Strings*/
//     string mo = "Halo";
//     cout << mo[1] << endl;
//     cout << mo[mo.length() - 1] << endl;


//     string no = "Willkommen";
//     no[0] = 'J';
//     cout << no << endl;


//     string oo = "Willkommen";
//     cout << oo << endl;

//     cout << oo.at(0) << endl;
//     cout << oo.at(1) << endl;
//     cout << oo.at(oo.length() - 1) << endl;

//     oo.at(0) = 'J';
//     cout << oo << endl;


// // Special Characters
//     string qo = "Wir sind\t die sogenannten \"Vikings\" aus dem\n Norder.\'\\";
//     cout << qo << endl;


// // User Input Strings
//     // string name5;
//     // cout << "Gib deinen vollständigen Namen ein: ";
//     // cin >> name5;
//     // cout << "Dein Name, Kumpel, ist: " << name5 << endl;


//     string fullName;
//     cout << "Gib deinen vollständigen Namen ein: ";
//     getline (cin, fullName);
//     cout << "Dein Name, Kumpel, ist: " << fullName << endl;


// String Namespace
// C-Style Strings, Strings Code Challenge
//     string grüße1 =  "Willkommen";
//     char grüße2[] = "Willkommen";

//     cout << grüße1 << endl;
//     cout << grüße2 << endl;


// // Math
//     cout << max(5, 10) << endl;
//     cout << min(5,10) << endl;
//     cout << sqrt(64) << endl;
//     cout << round(2.6) << endl;
//     cout << log(2) << endl;


// // Booleans, Boolean Expressions, Boolean Examples, Booleans Code Challenge
//     bool machtProgrammierenSpaß = true;
//     bool schmecktFischGut = false; 

//     cout << machtProgrammierenSpaß << "\n";
//     cout << schmecktFischGut << "\n";

//     cout << boolalpha << "\n";

//     cout << machtProgrammierenSpaß << "\n";
//     cout << schmecktFischGut << "\n";

//     cout << noboolalpha << "\n";

//     cout << machtProgrammierenSpaß << "\n";
//     cout << schmecktFischGut << "\n";


//     int a = 10;
//     int b = 9;
//     cout << (a > b) << endl;
//     cout << (a == b) << endl;
//     bool istGrößer = a > b;
//     cout << istGrößer << endl;


//     int meinAlter = 25;
//     int wahlAlter = 18;

//     if (meinAlter >= wahlAlter) {
//         cout << "Alt genug, um zu wählen!" << endl;
//     } else {
//         cout << "Nicht alt genug, um zu wählen." << endl;
//     }


// If ... Else/if, If ... Else/Else, If ... Else/Else if
    // int zeit = 16;
    // if (zeit < 12) {
    //     cout << "Guten Morgen!" << endl; 
    // } else if (zeit < 18) {
    //     cout << "Guten Tag!" << endl;
    // } else {
    //     cout << "Guten Abend!" << endl;
    // }

    // int zeit = 16;

    // bool istMorgen = zeit < 12;
    // bool istTag = zeit < 18;

    // if (istMorgen) {
    //     cout << "Guten Morgen!" << endl;
    // } else if (istTag) {
    //     cout << "Guten Tag!" << endl;
    // } else {
    //     cout << "Guten Abend!" << endl;
    // }


// If...Else/Short hand if...else
    // int zeit = 20;
    // if (zeit < 18) {
    //     cout << "Guten Tag." << endl;
    // } else {
    //     cout << "Guten Abend" << endl;
    // }


    // int time = 20;
    // string result = (time < 18)? "Guten Tag." : "Guten Abend.";
    // cout << result << endl;


    // int zeit = 20;
    // cout << ((zeit < 18) ? "Guten Tag." : "Guten Abend.");

    // int zeit = 22; 
    // string nachricht = (zeit < 12) ? "Guten morgen."
    //     : (zeit < 18) ? "Guten Tag."
    //     : "Guten abend.";
    // cout << nachricht;


// If...Else/Nested If 
    // int x = 15;
    // int y = 25;

    // if (x > 10) {
    //     cout << "x ist größer als 10\n";
        
    //     if (y > 20) {
    //         cout << "y ist auch größer als 20\n";
    //     }
    // }
// // If...Else/Nested If Praxisbeispiel
//     int Alter = 20;
//     bool istBürger = true;

//     if (Alter >= 18) {
//         cout << "Du kannst wählen.\n";

//         if (istBürger) {
//             cout << "Du bist Bürger, also darfst du wählen!";
//         } else {
//             cout << " Du kannst nicht wählen.\n";
//         }
//     }


// If..Else/Logical Operators in Conditions
    // int a = 200;
    // int b = 33;
    // int c = 500;

    // if (a > b && c > a) {
    //     cout << "Beide Bedingungen sind erfüllt.";
    // }

//    if (a > b || a > c) {
//         cout << "Mindestens eine Bedingung ist wahr.";
//     } 

    // if (!(a < b)) {
    //     cout << "b ist nicht größer als a.";
    // }


    // bool istEingeloggt = true;
    // bool istAdmin = false;
    // int sicherheitsNiveau = 3; // 1 = am höchsten 

    // if (istEingeloggt && (istAdmin || sicherheitsNiveau <= 2)) {
    //     cout << "Zugriff erlaubt."; 
    // } else {
    //     cout << "Zugriff verweigert.";
    // }


//If ... Else/If ... Else Examples 
    // int derTürcode = 1337;

    // if (derTürcode = 1337) {
    //     cout  << "Code korrekt. \nDie Tür ist jetzt offen.\n";
    // } else {
    //     cout << "Falscher Code. \nDie Tür bleibt geschlossen.\n";
    // }

    // int meinNummer = 10;

    // if (meinNummer > 0) {
    //     cout << "Der Wert ist eine positive Zahl.\n";
    // } else if (meinNummer < 0) {
    //     cout << "Der Wert ist eine negative Zahl.\n";
    // } else {
    //     cout << "Der Wert is 0.\n";
    // }

    // int meinAlter = 25;
    // int Wahlalter = 18;

    // if (meinAlter >= Wahlalter) {
    //     cout << "Alt genug, um zu wählen!\n";
    // } else {
    //     cout << "Nicht alt genug, um zu wählen!\n";
    // }


    // int dasAlter = 20;
    // bool istStaatsbürger = true;

    // if (dasAlter >= 18) {
    //     cout << "Alt genug, um zu wählen!\n";

    //     if (istStaatsbürger) {
    //         cout << "Und du bist Staatsbürger, deshalb kannst du wählen!\n";
    //     } else {
    //         cout << "Aber du musst Staatsbürger sein, um wählen zu dürfen.\n";
    //     }
    // } else {
    //     cout << "Nicht alt genug, um zu wählen.\n";
    // }


    // int meineZahl = 5;

    // if (meineZahl % 2 == 0) {
    //     cout << meineZahl << " ist gerade.\n";
    // } else {
    //     cout << meineZahl << " ist ungerade.\n";
    // }


//     int dieTemperatur = 30;

    //     if (dieTemperatur < 0) {
    //         cout << "Es ist eiskalt!\n";
    //     } else if (dieTemperatur < 20) {
    //         cout << "Es ist kühl.";
    //     } else {
    //         cout << "Es ist warm.\n";
    //     }
//If ... Else/Conditions Code Challenge
//Switch/Switch, Switch/Switch Code Challenge
    // int derTag = 6;
    // switch (derTag) {
    //     case 1:
    //      cout << "der Montag" << endl;
    //      break;
    //     case 2:
    //      cout << "der Dienstag" << endl;
    //      break;
    //     case 3:
    //      cout << "der Mittwoch" << endl;
    //      break;
    //     case 4:
    //      cout << "der Donnerstag" << endl;
    //      break;
    //     case 5:
    //      cout << "der Freitag" << endl;
    //      break;
    //     case 6:
    //      cout << "der Samstag" << endl;
    //      break;
    //     case 7:
    //      cout << "der Sonntag" << endl;
        

    // int derTag = 4;
    // switch (derTag) {
    //     case 6:
    //         cout << "Heute ist Samstag" << endl;
    //         break;
    //     case 7:
    //         cout << "Heute ist Sonntag" << endl;
    //         break;
    //     default:
    //         cout << "Freue mich auf das Wochenende!";
    // }
    

//While Loop/While Loop
    // int i = 0;
    // while (i < 5) {
    //     cout << i << "\n";
    //     i++;
    // }
    

    // int dasRückzählen = 3;

    // while (dasRückzählen > 0) {
    //     cout << dasRückzählen << "\n";
    //     dasRückzählen--;
    // }

    // cout << "Frohes neues Jahr!\n";


//  While/Do/While Loop
    // int i = 0;
    // do {
    //     cout << i << "\n";
    //     i++;
    // }

    // while (i < 5);


    // int i = 10;
    // do {
    //     cout << "i is " << i << "\n";
    //     i++;
    // } 

    // while(i < 5);


    // int dieZahl;
    // do {
    //     cout << "Gib eine positive Zahl ein: ";
    //     cin >> dieZahl;
    // }

    // while (dieZahl > 0);


//While Loop/While Loop Beispiele
    // int dasRückzählen = 3;

    // while (dasRückzählen > 0) {
    //     cout << dasRückzählen << "\n";
    //     dasRückzählen--;
    // }

    // cout << "Frohes neues Jahr!\n";

    // int i = 0;

    // while (i <= 10) {
    //     cout << i << "\n";
    //     i += 2;
    // }

    // return 0;

    // int dieZahlen = 12345;

    // int revZahlen = 0;

    // while (dieZahlen) {
    //     revZahlen = revZahlen * 10 + dieZahlen % 10;

    //     dieZahlen /= 10;
    // }

    // cout << "Umgedrehte Zahlen: " << revZahlen << "\n";

    // int derWürfel = 1;

    // while (derWürfel <= 6) {
    //     if (derWürfel < 6) {
    //         cout << "Kein Yatzy!\n";
    //     } else {
    //         cout << "Yatzy!\n";
    //     }
    // derWürfel = derWürfel + 1;
    // }


//While Loop/While Loop Code Challenge
//For Loop/For Loop
    // for (int i = 0; i <= 10; i = i + 2){
    //     cout << i << "\n";
    // }

    // int sum = 0;
    // for (int i = 1; i <= 5; i++) {
    //     sum = sum + i;
    // }
    // cout << "Die Summer ist " << sum; 

//     for (int i = 5; i > 0; i--) {
//         cout << i << "\n";
//     }


// //For Loop/Nested Loops
//     for (int i = 1; i <= 2; ++i) {
//         cout << "Äußerer: " << i << "\n";

//         for (int j = 1; j <= 3; ++j) {
//             cout << "Inner: " << j << "\n";
//         }
//     }


//     for (int i = 1; i <= 3; i++) {
//         for (int j = 1; j <= 3; j++) {
//             cout << i * j << " ";
//         }
//     cout << "\n";
//     }


// // For Loop/The foreach Loop
//     int meineZahlen[5] = {10, 20, 30, 40, 50};
//     for (int num : meineZahlen) {
//         cout << num << "\n";
//     }

    // string dasWort = "Halo";
    // for (char c : dasWort) {
    //     cout << c << "\n";
    // }


//For Loop/For Loop Examples, For Loop/For Loop Code Challenge
    // for (int i = 0; i <= 100; i += 10) {
    //     cout << i << "\n";
    // }

    // for (int i = 0; i <= 10; i = i + 2) {
    //     cout << i << "\n";
    // }

    // for (int i = 1; i <= 10; i = i +2) {
    //     cout << i << "\n";
    // }

    // for (int i = 2; i <= 512; i *= 2) {
    //     cout << i << "\n";
    // }

    // int dieZahl = 2;
    // int i;

    // for (i = 1; i <= 10; i++) {
    //     cout << dieZahl << " x " << i << " = " << dieZahl * i << "\n";
    // }


//Break and Continue/Break and Continue
    // for (int i = 0; i < 10; i++) {
    //     if (i == 4) {
    //         break;
    //     }
    //     cout << i << "\n";
    // }

    // for (int i = 0; i < 10; i++) {
    //     if (i == 4) {
    //         continue;
    //     }
    //     cout << i << "\n";
    // }

    // int i = 0;
    // while (i < 10) {
    //     cout << i << "\n";
    //     i++;
    //     if (i == 4) {
    //         break;
    //     }
    // }

    // int i = 0;
    // while (i < 10) {
    //     if (i == 4) {
    //         i++;
    //         continue;
    //     }
    //     cout << i << "\n";
    //     i++;
    
    // }


//Arrays/Arrays
// string dieAutos[4] = {"Volvo", "BMW", "Ford", "Mazda "};
// cout << dieAutos[0];
// }

// string dieAutos[4] = {"Volvo", "BMW", "Ford", "Mazda "};
// dieAutos[0] = "Opel";
// cout << dieAutos[0];


//Arrays/Arrays and Loops
// string dieAutos[5] = {"Volvo", "BMW", "Ford", "Mazda ", "Tesla"};

// for (int i = 0; i < 5; i++) {
//     cout << dieAutos[i] << "\n";
// }

// string dieAutos[5] = {"Volvo", "BMW", "Ford", "Mazda ", "Tesla"};

// for (int i = 0; i < 5; i++) {
//     cout << i << " = " << dieAutos[i] << "\n";
// }

// int meineZahlen[5] = {10, 20, 30, 40, 50};

// for (int i = 0; i < 5; i++) {
//     cout << meineZahlen[i] << "\n";
// }

// int meineZahlen[5] = {10, 20, 30, 40, 50};
// for (int dieZahl : meineZahlen){
//     cout << Zahl << "\n";
// }

// string dieAutos[5] = {"Volvo", "BMW", "Ford", "Mazda", "Tesla"};
// for (string dasAuto : dieAutos) {
//     cout << dasAuto << "\n";
// }


// // Arrats/Omit Array Size
// string dieAutos[5];
// dieAutos[0] = "Volvo";
// dieAutos[1] = "BMW";
// dieAutos[2] = "Mazda";
// dieAutos[3] = "Tesla";
// dieAutos[4] = "Ford";

// for(int i = 0; i < 5; i++) {
//     cout << dieAutos[i] << "\n";
// }

// return 0;


// vector<string> dieAutos = {"Volvo", "BMW", "Ford"};
// dieAutos.push_back("Tesla");

// for (string dasAuto : dieAutos) {
//     cout << dasAuto << "\n";
// }
// return 0;


// int meineZahlen[5] = {10, 20, 30, 40, 50};
// int holeArrayLaenge = sizeof(meineZahlen) / sizeof(meineZahlen[0]);
// cout << sizeof(holeArrayLaenge);


// int meineZahlen[5] = {10, 20, 30, 40, 50};
// for (int i = 0; i < 5; i++) {
//     cout << meineZahlen[i] << "\n";
// }


// int meineZahlen[5] = {10, 20, 30, 40, 50};
// for (int i = 0; i < sizeof(meineZahlen) / sizeof(meineZahlen[0]); i++) {
//     cout << meineZahlen[i] << "\n";
// }


// int meineZahlen[5] = {10, 20, 30, 40, 50};
// for (int eineZahl : meineZahlen) {
//     cout << eineZahl << "\n";
// }


//Arrays/Arrays Beispiele aus dem echten Leben
// int dieAlter[8] = {20, 22, 18, 35, 48, 26, 87, 70};

// float avg, sum = 0;
// int i;

// int dieLänge = sizeof(dieAlter) / sizeof(dieAlter[0]);

// for (int dasAlter : dieAlter) {
//     sum += dasAlter;
// }

// avg = sum / dieLänge;

// cout << "Der Mittelwert ist: " << avg << "\n";


// int dieAlter[8] = {20, 22, 18, 35, 48, 26, 87, 70};

// int i;

// int dasMindestAlter = dieAlter[0];

// for (int dasAlter : dieAlter) {
//     if (dasMindestAlter > dasAlter) {
//         dasMindestAlter = dasAlter;
//     }
// }

// cout << "Das MindestAlter ist: " << dasMindestAlter << "\n";

//Arrays/Multi-Dimensional Arrays
// string dieBuchstaben[2][4] = {
//     { "A", "B", "C", "D" },
//     { "E", "F", "G", "H" }
// };
// dieBuchstaben[0][0] = "Z";

// cout << dieBuchstaben[0][2];
// cout << dieBuchstaben[0][0];

// for (int i = 0; i < 2; i++) {
//     for (int j = 0; j < 4; j++) {
//         cout << dieBuchstaben[i][j] << "\n";
//     }
// }


// string dieBuchstaben1[2][2][2] = {
//   {
//     { "A", "B" },
//     { "C", "D" }
//   },
//   {
//     { "E", "F" },
//     { "G", "H" }
//   }
// };

// for (int i = 0; i < 2; i++) {
//   for (int j = 0; j < 2; j++) {
//     for (int k = 0; k < 2; k++) {
//       cout << dieBuchstaben1[i][j][k] << "\n";
//     }
//   }
// }


//Schiffe versenken in ""
//Arrays/Arrays Code Challenge
//Structures
// struct {
//     int meineZahl;
//     string meinString;
// } meineStruktur;

// meineStruktur.meineZahl = 1;
// meineStruktur.meinString = "Halo Welt!";

// cout << meineStruktur.meineZahl << "\n";
// cout << meineStruktur.meinString << "\n";

// struct {
//     string dieMarke;
//     string dasModel;
//     int dasJahr;
// } meinAuto1, meinAuto2;

// meinAuto1.dieMarke = "BMW";
// meinAuto1.dasModel = "X5";
// meinAuto1.dasJahr = 1999;

// meinAuto2.dieMarke = "Ford";
// meinAuto2.dasModel = "Mustang";
// meinAuto2.dasJahr = 1999;

// cout << meinAuto1.dieMarke << " " << meinAuto1.dasModel << " " << meinAuto1.dasJahr << "\n";
// cout << meinAuto2.dieMarke << " " << meinAuto2.dasModel << " " << meinAuto2.dasJahr << "\n";

// dasAuto meinAuto1;
// meinAuto1.dieMarke = "BMW";
// meinAuto1.dasModel = "X5";
// meinAuto1.dasJahr = 1999;

// dasAuto meinAuto2;
// meinAuto2.dieMarke = "Ford";
// meinAuto2.dasModel = "Mustang";
// meinAuto2.dasJahr = 1969;

// cout << meinAuto1.dieMarke << " " << meinAuto1.dasModel << " " << meinAuto1.dasJahr << "\n";
// cout << meinAuto2.dieMarke << " " << meinAuto2.dasModel << " " << meinAuto2.dasJahr << "\n";

// return 0;


//Enums
// enum dieStufe meinVar = MITTEL;
// cout << meinVar;

// return 0;


}

