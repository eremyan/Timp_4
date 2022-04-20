#pragma once
#include <iostream>
#include <string>
#include "RouteTableCipher.h"
#include <cctype>
using namespace std;
int main()
{
    int c;
    int key;
    string skey, text;
    do {
        cout<<"Введите 1 для зашифрования, 2 для расшифрования, 0 для выхода: ";
        cin>>c;
        if(c==1) {
            cout<<"Введите ключ:";
            cin.get();
            getline(cin,skey);
            try {
                cipher_error::getValidKey(skey);
                cout<<"Ключ установлен\n";
                cout<<"Введите текст для шифрования:";
                getline(cin,text);
                key=stoi(skey);
                cipher_error::getValidText(text);
                RouteTableCipher cipher(key);
                string ciphertext=cipher.encrypt(text,key);
                cout<<"Зашифрованный текст:"<<ciphertext<<endl;

            }
            catch(cipher_error& e) {
                cout<<e.what()<<endl;
            }

        }
        if(c==2) {
            cout<<"Введите ключ:";
            cin.get();
            getline(cin,skey);
            try {
                cipher_error::getValidKey(skey);
                cout<<"Ключ установлен\n";
                cout<<"Введите текст для расшифрования:";
                getline(cin,text);
                key=stoi(skey);
                cipher_error::getValidText(text);
                RouteTableCipher cipher(key);
                string decryptedtext=cipher.decrypt(text,key);
                cout<<"Расшифрованный текст:"<<decryptedtext<<endl;
                
            } catch(cipher_error& e) {
                cout<<e.what()<<endl;
            }
        }
        if(c==0) {
            cout<<"Завершение программы..."<<endl;
            exit(0);
        } else if((c>2) or (c<0)) {
            cout<<"Неверная команда"<<endl;

        }

    }
    while(c!=0);
    return 0;
}