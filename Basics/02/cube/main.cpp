#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int numero;
    cout << "Enter a number: ";
    cin >> numero;

    int result = pow(numero, 3);
    if(result > numeric_limits<int>::max() || result < numeric_limits<int>::min()){
        cout << "Error! The cube of " << numero << " is not " << result << endl;
    }
    else{
        cout << "The cube of " << numero << " is " << result << "." << endl;
    }
    return 0;
}
