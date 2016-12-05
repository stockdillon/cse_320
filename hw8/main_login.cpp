//
//  Hw 8 Problem 2  : program that reads in username/login pairs
//  and performs authentication of usernames until EOF is encountered.
//--------------------------------------------------------------------

#include <string>
#include <iostream>
#include <fstream>
#include "HashTable.cpp"

using namespace std;
//definition of your entity.
struct Password
{
    void setKey ( string newKey ) { username = newKey; }
    string getKey () const { return username; }
    static unsigned int hash(const string& str)
    {
        int val = 0;

        for (int i=0; i<str.length(); i++)
            val += str[i];
        return val;
    }
    string username,
           password;
};

int main()
{
   //few declarations ... feel free to change any of them.
    HashTable<Password, string> passwords(8);
    Password tempPass;
    string name,      // user-supplied name
           pass;      // user-supplied password
    bool userFound;   // is user in table?

    //rest is yours...

}
