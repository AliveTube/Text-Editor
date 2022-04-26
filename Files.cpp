#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;

void add_text();
void display_content();
void empty_file();
void encrypt_content();
void decrypt_content();
void merge_file();
void count_words();
void count_characters();
void count_lines();
void search_word();
void repeated_words();
void upper_case();
void lower_case();
void title();
void save();
void exit();

int main () {
    ifstream myfile;
    char name_of_file[100];
    cin >> name_of_file;
    strcat(name_of_file,".txt");
    myfile.open(name_of_file);
    ofstream file;
    if (myfile) {
        cout<<"This File Already Exists " << endl ;
    }
    else {
        file.open(name_of_file);
        cout << "This is a new file. I created it for you :)" ;
    }
}

// __________________________________
void add_text() {

}
// __________________________________
void display_content(){

}
// __________________________________
void empty_file(){

}
// __________________________________
void encrypt_content(){

}
// __________________________________
void decrypt_content(){

}
// __________________________________
void merge_file(){

}
// __________________________________
void count_words(){

}
// __________________________________
void count_characters(){

}
// __________________________________
void count_lines(){

}
// __________________________________
void search_word(){

}
// __________________________________
void repeated_words(){

}
// __________________________________
void upper_case(){

}
// __________________________________
void lower_case(){

}
// __________________________________
void title(){

}
// __________________________________
void save(){

}
// __________________________________
void exit(){

}
