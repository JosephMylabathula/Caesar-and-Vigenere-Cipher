// Name        : Assignment 1
// Author      : Joseph Mylabathula
// Class       : Cryptography


#include <iostream>
#include <iomanip>
#include <cctype>

using namespace std;

int main() {
    
    int a, b, c;
    int key;
    string plain, str, cipher, temp, temp1, keys;
    
    cout << "Would you like to \n 1. Encrypt  \n 2. Decrypt? \n Please enter a number" << endl;
    cin >> a;
    
    if(a== 1)
    {
        cout << "What type of Cipher would you like to Encrypt?" << endl;
        cout << " 1. Caesar \n 2. Vigenère" << endl;
        cin >> b;
        
        if(b==1)
        {
            cin.ignore();
            cout << "Enter the Sentence you would like to Encrypt: " << endl;
            getline(cin, plain);
            
            for(char s: plain)
            {
                temp += toupper(s);
            }
            
            plain = temp;
            
            cout << "Enter the Key: " << endl;
            cin >> key;
            
            if(key > 26)
            {
                key = key%26;
            }
            
            for(char x: plain)
            {
                if((x + key) > 'Z')
                    cipher += '@' + (key - ('Z' - x));
                
                else
                    cipher += x + key;
            }
            
            cout << "Cipher Text is: " << cipher << endl;
            
        }
        
        if(b==2)
        {
            cin.ignore();
            cout << "What is the Sentence you want to Encrypt?: " << endl;
            getline(cin, plain);
            cout << "Enter the Key: " << endl;
            getline(cin, keys);
            
            for(char s: keys)
            {
                temp += toupper(s);                 // Convert Keys to Capital letters
            }
            for(char f: plain)
            {
                temp1 += toupper(f);                // Convert Plain Text to Capital Letters
            }
            
            keys = temp;
            plain = temp1;
            
            int z = 0;
            int v = 0;
            for(char x: plain)                      // X will go through every letter in Plain Text
            {
                v = keys[z];                        // V go through every letter of the Keys
                
                if('A' <= v && v <= 'Z')
                    v = v - 'A';                    // Keep keys in range
                
                if( x + v > 'Z')                    // Keep Plain text plus Key in Range
                    cipher += (x + v) - 26 ;
                
                else if(x + v < 'A')
                    cipher += (x +v) + 26;
                
                else
                    cipher += x + v;
                
                z++;
                
                if (z > keys.length())
                    z = 0;
            }
            
            cout << "The Cipher text is: " << cipher << endl;
            exit(1);
        }
        
    }
    
    else if (a==2)
    {
        cout << "What type of Cipher would you like to Decrypt?" << endl;
        cout << " 1. Caesar \n 2. Vigenère" << endl;
        cin >> b;
        
        if(b==1)
        {
            cin.ignore();
            cout << "Enter the Sentence you would like to Decrypt: " << endl;
            getline(cin, cipher);
            
            for(char s: cipher)
            {
                temp += toupper(s);
            }
            
            cipher = temp;
            
            cout << "Enter the Key: " << endl;
            cin >> key;
            
            if(key > 26)
            {
                key = key%26;
            }
            
            for(char x: cipher)
            {
                if((x - key) < 'A')
                    plain += '[' + (key - ('A' - x));
                
                else
                    plain += x - key;
            }
            
            cout << "Plain Text is: " << plain << endl;
        }
    }
    
    if(b == 2)
    {
        cin.ignore();
        cout << "What is the Sentence you want to Decrypt?: " << endl;
        getline(cin, cipher);
        cout << "Enter the Key: " << endl;
        getline(cin, keys);
        
        for(char s: keys)
        {
            temp += toupper(s);                 // Convert Keys to Capital letters
        }
        for(char f: cipher)
        {
            temp1 += toupper(f);                // Convert Cipher Text to Capital Letters
        }
        
        keys = temp;
        cipher = temp1;
        
        int z = 0;
        int v = 0;
        for(char x: cipher)                      // X will go through every letter in Cipher Text
        {
            v = keys[z];                        // V go through every letter of the Keys
            
            if('A' <= v && v <= 'Z')
                v = v - 'A';                    // Keep keys in range
            
            if( x - v > 'Z')
                plain += (x - v) - 26 ;
            
            if(x -v < 'A')
                plain += (x - v) + 26;
            
            else
                plain += (x - v);
            
            z++;
            
            if (z > keys.length())
                z = 0;
        }
        
        cout << "The Plain text is: " << plain << endl;
        
    }
    
    return 0;
}

/*
 Test Runs 1:
 Would you like to
 1. Encrypt
 2. Decrypt?
 Please enter a number
 1
 What type of Cipher would you like to Encrypt?
 1. Caesar
 2. Vigenère
 1
 Enter the Sentence you would like to Encrypt:
 MY NAME IS YEFF
 Enter the Key:
 1
 Cipher Text is: NZ!OBNF!JT!ZFGG
 Program ended with exit code: 0
 
 Test Run #2:
 Would you like to
 1. Encrypt
 2. Decrypt?
 Please enter a number
 1
 What type of Cipher would you like to Encrypt?
 1. Caesar
 2. Vigenère
 1
 Enter the Sentence you would like to Encrypt:
 DDDDCCBBS
 Enter the Key:
 2
 Cipher Text is: FFFFEEDDU
 Program ended with exit code: 0
 
 Test Run #3:
 
 Would you like to
 1. Encrypt
 2. Decrypt?
 Please enter a number
 2
 What type of Cipher would you like to Decrypt?
 1. Caesar
 2. Vigenère
 2
 What is the Sentence you want to Decrypt?:
 JJKLJDLKF
 Enter the Key:
 apple
 The Plain text is: JUVAFDLVQ
 Program ended with exit code: 0
 
 Test Run #4:
 Would you like to
 1. Encrypt
 2. Decrypt?
 Please enter a number
 1
 What type of Cipher would you like to Encrypt?
 1. Caesar
 2. Vigenère
 2
 What is the Sentence you want to Encrypt?:
 MY NAME IS YEFF
 Enter the Key:
 zzz
 The Cipher text is: LXSNZLD:HRSYDEE
 Program ended with exit code: 1
 

 */
