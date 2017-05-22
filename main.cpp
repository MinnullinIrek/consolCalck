
#include <iostream>
#include <string>
#include "parser.h"
using namespace std;


int main(int argc, char *argv[])
{
    Parser p;
    cout << "enter:"<< endl;
    string s = "(4-6)*2";




    while(true){
        getline(cin, s );

        string error;
        if(p.getResult(s, error))
            cout << "RESULT: " << s << endl;
        else
            cout << error << endl;
    }

    std::cout << "Hqello, world!\n";
    return 0;
}
