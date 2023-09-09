#include <iostream>
using namespace std;

int main()
{
    std::cout << "How many numbers would you like to have? ";
    int i;
    cin >> i;

    for(int luku = 1; luku <= i; ++luku){
        if(luku % 3 == 0){
            cout << "zip" << endl;
        }
        else if(luku % 7 == 0){
            cout << "boing" << endl;
        }
        else{
        cout << luku << endl;
        }

    }

    return 0;
}
