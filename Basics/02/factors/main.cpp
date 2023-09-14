#include <iostream>
using namespace std;
#include <cmath>

int main() {
    int tulo;

    cout << "Enter a positive number: ";
    cin >> tulo;

    if (tulo <= 0) {
        cout << "Only positive numbers accepted" << endl;
    } else {
        int tekija1 = 1;
        int tekija2 = tulo;


        for (int i = 2; i <= sqrt(tulo); ++i) {
            if (tulo % i == 0) {
                int j = tulo / i;
                if (abs(j - i) < abs(tekija2 - tekija1)) {
                    tekija1 = i;
                    tekija2 = j;
                }
            }
        }

        cout << tulo << " = " << tekija1 << " * " << tekija2 << endl;
    }

    return 0;
}
