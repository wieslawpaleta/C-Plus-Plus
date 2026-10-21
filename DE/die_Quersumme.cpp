#include <iostream>
using namespace std;

int main()
{
        int num, sum = 0;
        cout << "Bitte geben Sie eine Zahl ein: ";
        cin >> num;
        while (num > 0)
        {
            sum += num % 10;
            num /= 10;
        }
        cout << "Die Quersumme der Zahl ist: " << sum << endl;
        return 0;
}