//C++ w3schools
//Introduction, Get Started with C++, Syntax, Statements, Syntax Code Challenge, Output (Print Text), Print Numbers, New Lines, Output Code Challenge, Comments
/*Ja, ich weiß, wie man mehrzeilige Kommentare verwendet.*/
//VariablesDeclare, Multiple Variables, Identifiers, Constants, Variables Examples, Variables Code Challenge, User Input, Data Types, Numeric Data Types, Boolean Data Types
//Character Data Types, String Data Types, auto, Data Types Examples,
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
using namespace std;


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
// If...Else/Nested If Praxisbeispiel
    int Alter = 20;
    bool istBürger = true;

    if (Alter >= 18) {
        cout << "Du kannst wählen.\n";

        if (istBürger) {
            cout << "Du bist Bürger, also darfst du wählen!";
        } else {
            cout << " Du kannst nicht wählen.\n";
        }
    }
// If..Else/Logical Operators in Conditions
}

