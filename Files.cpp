#include <iostream>
#include <fstream>
using namespace std;
int main () {
    string name_of_file ;
    cout << "Please enter the name of the file : " ;
    cin >> name_of_file;
    ofstream file ;
    file.open(name_of_file);
    file << "ahmed moha" ;
    file.close();

}
