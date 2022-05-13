#include <iostream>
#include <bits/stdc++.h>
#include <conio.h>
using namespace std;

bool valid_email();
bool valid_phone_number();
bool valid_password();
bool confirm_password();

void register_user();
void enter_password();
void login();
void change_password();
void forgot_password();
void exit();
string email , password , username , phone_number ,conf_password;
fstream login_file;

int main () {
    login_file.open("login_file.txt",ios::app);
    cout << "Ahlan ya user ya habibi :)\n";
    cout << "Welcome to Facebook v2.0 \n";
    cout << "Please choose one of the following :\n";
    string option ;
    while (true)
    {
    cout << "1-Register new user." << endl <<
    "2-Login." << endl <<
    "3-Change Password." << endl <<
    "4-Forgot password." << endl <<
    "5-Exit." << endl ;
    cin >> option ;
    if (option == "1") register_user();
    else if (option == "2") login();
    else if (option == "3") change_password();
    else if (option == "4") forgot_password();
    else if (option == "5") exit();
    else cout << "Please choose an option from (1-5) ! \n";
    }
}
// __________________________________
bool valid_email (string email) {
    regex valid ("[\\w]+[.]?[\\w]+@[\\w]+.com");
    return regex_match(email, valid);
}
// __________________________________
bool valid_phone_number(string phone_number){
    regex valid ("01+[0-1]{1}+[0-9]{8}");
    return regex_match(phone_number, valid);
}
// __________________________________
bool valid_password (string password){
    bool valid = true;
    int up = 0 , lo = 0 , num = 0 , pun = 0 ;
    for (int i = 0; i < password.size(); i++)
    {
        if (password[i] >= 65 && password[i] <= 90) up +=1;
        else if (password[i] >=97 && password[i] <=122 ) lo +=1;
        else if (isdigit(password[i])) num+=1;
        else if (ispunct(password[i])) pun+=1;
    }
    if (lo != 0 && up != 0 && num != 0 && pun !=0 && password.length() >= 12) return valid;
}
// __________________________________
void enter_password(){
    cout << "Note that Your password must contain " << endl ;
    cout <<"-At least 12 characters long but 14 or more is better.\n"<<
           "-At combination of uppercase letters, lowercase letters, numbers, and symbols.\n";
    cout << "Enter your password : " ;
    int ch ;
    ch = getch();
    while (ch != 13){
        if (ch == 8) {
            if (!password.empty()){
                password.pop_back();
                cout << "\b \b";
                }
        }
        else {
            cout << "*";
            password += ch;
            }
        ch = getch();
    }
}
// __________________________________
bool confirm_password(){
    int ch ;
    ch = getch();
    while (ch != 13){
        if (ch == 8) {
            if (!conf_password.empty()){
                conf_password.pop_back();
                cout << "\b \b";
                }
        }
        else {
            cout << "*";
            conf_password += ch;
            }
        ch = getch();
    }
    cout << endl ;
    for (int i = 0; i < conf_password.length(); i++) conf_password[i] +=1;
    return conf_password == password;
}
// __________________________________
void register_user() {
    string check;
    cin.clear();
    cin.sync();
    cout << "Enter your username : ";
    getline(cin,username);
    cout << "Enter your email : ";
    cin >> email;
    while(!valid_email(email)) {
        cout << "Please enter a valid email !\n";
        cin >> email;
    }
    cout << "Enter your phone number : " ;
    cin >> phone_number;
    while(!valid_phone_number(phone_number)){
        cout << "Please enter a valid phone number !\n";
        cin >> phone_number;
    }
    enter_password();
    if (valid_password(password)) {
        cout << "\nYour password is strong :) \n";
        for (int i = 0; i < password.length(); i++) password[i] +=1;
        }
    else {
        while(!valid_password(password)){
            cout <<"\n" <<"Your password is WEAK \n ";
            enter_password();
            }
            cout << "\nYour password is strong :) \n";
        }
    cout << "Please confirm your password : ";
    while (!confirm_password()) {
        cout << "Please re-enter the password \n" ;
        conf_password.clear();
    }
    check += username;
    check += '-' ;
    check += password;
    cout << check << endl;
    login_file << check << "\n";
}
// __________________________________
void login() {

}
// __________________________________
void change_password() {

}
// __________________________________
void forgot_password() {

}
// __________________________________
void exit(){
    login_file.close();
    cout << "See you soon ;) " << endl;
    exit(1);
}