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
fstream myfile;
char name_of_file[100];
int main () {
    cout<<"Please enter the file's name"<<endl;
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
    myfile.close();
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
    string word,temp; char letter; int count = 0;
    cout<<"Enter the word that you search\n";
    cin>> word;
    for_each(word.begin(), word.end(), [](char & c){
        c = ::tolower(c);
    });
    myfile.open(name_of_file);
    while(!myfile.eof()){
        letter = myfile.get();
        if (letter == EOF) {
            if (temp == word)
                count++;
            temp ="";
            break;
        }
        else if (!isalpha(letter) && ! isdigit(letter)){
            if (temp == word)
                count++;
            temp ="";
            continue;
        }
        temp += tolower(letter);
    }
    cout<<"THe word repeated " << count <<" of times "<<endl;
    myfile.close();
}
// __________________________________
void upper_case(){
    string text;
    char letter;
    myfile.open(name_of_file);
    while(!myfile.eof()){
        letter = myfile.get();
        if (letter == EOF)
            break;
        text += toupper(letter);
    }
    myfile.close();
    myfile.open(name_of_file, ios::out);
    myfile << text;
    myfile.close();
}
// __________________________________
void lower_case(){
    string text;
    char letter;
    myfile.open(name_of_file);
    while(!myfile.eof()){
        letter = myfile.get();
        if (letter == EOF)
            break;
        text += tolower(letter);
    }
    myfile.close();
    myfile.open(name_of_file, ios::out);
    myfile << text;
    myfile.close();
}
// __________________________________
void title(){
    string text;
    stringstream content;
    myfile.open(name_of_file,ios::in);
    content << myfile.rdbuf();
    text = content.str();
    myfile.close();
    myfile.open(name_of_file,ios::in);
    for(int i =0; i < text.length();i++){
        if(isalpha(text[i]) && !(isalpha(text[i-1])))
            text[i] = toupper(text[i]);
        else
            text[i] = tolower(text[i]);
    }
    myfile.close();
    myfile.open(name_of_file, ios::out);
    myfile << text;
    myfile.close();
}
// __________________________________
void save(){
    fstream newFile;
    char new_name[100];
    cout<<"please enter the name if the file"<<endl;
    cin>>new_name;
    string text;
    stringstream content;
    ofstream New_File;

    strcat(new_name,".txt");
    newFile.open(new_name);
    myfile.open(new_name,ios::in);
    myfile.close();
    if (newFile) {
        newFile.open(new_name);
        newFile << text;
        newFile.close();
        cout<<"over wrote on this file" << endl ;
    }
    else {
        New_File.open(new_name);
        New_File << text ;
        New_File.close();
        cout << "This is a new file. I created it for you :)" ;
    }
    newFile.close();

}
// __________________________________
void exit(){

}
