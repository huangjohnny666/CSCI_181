//Xiaoming Huang
//CS181 homework 1 Question 3


#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;


//print element in a vector v one by one.
void print(vector<int> v){
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl << endl;
}

//count # of letters used in each column of string str,
//also print the counts
//input: ciphertext, column number, key length
//output: a vector of int, representing count of characters form a to z
vector<int> countChar(string str, int column, int k){
    vector<int> counts(26, 0);
    for (int i=column; i<str.length(); i=i+k){
        if (str[i]!=32){
            counts[str[i] - 97]++;
        }
    }
    cout << column << "th column count:\n";
    print(counts);
    cout << endl;
    return counts;
}

void amount(vector<int> v){
    int n=0;
    for(int i=0; i<v.size(); i++){
        n = n+v[i];
    }
    cout << n << " ";
}


//decryption function
//input: ciphertext c and keywork key
//output: return a string m which is the plaintext
string decrypt(string c, string key){
    //k to store length of the key, to avoid calling length() multiple times
    int k = key.length();

    //create a string c to store the cipher text
    string m = c;

    //create a index array to store count for each letter in keyword
    int index[k];
    for(int i=0; i<k; i++){
        index[i] = key[i] - 97;
    }

    //int temo to store temporary index from 0 to 25 to indicate the letter c[i]
    int temp;
    for(int i=0; i<c.length(); i++){
        temp = c[i]-97;
        temp = (temp-index[i%k])%26;
        if(temp < 0){
           temp = temp+26;
        }
        m[i] = temp+97;
    }
    return m;
}




int main(){
    string ciphertext = "lpiusnwkwcyiezwwcqelxdeizabhvthgwbkjrcfshevgiwxetnxfesgasgxeibgwmldzrewkfrrtbkmirhngveirorwvhqqsaxslzdvnlavixpqmgpbhvrbluyqxvglayxrqxjzlragalayqxbhcmbhsgawkuvnhlltmievksgxkeibfzjhvuthlnkioxlmyugytafvhgnnkxcwanlykuvwltfwqdrgxvpydvgagnakefygknkegmzxjdwfbfznkiexztxzseglaypvrtdesdfbnlmbhwnfwthgfbmzmbdxzhjgcqkrjmtfocytqbhoinowlhrwgxhaugxehvwyqfytudikmxxhmnkisbjlnisetfhnkiewsrshxxggpcqkuhopubprtvliqxbpsrcgshulxxljvlzhoohrowkwrqrusvelwutdevhxredbhjxubkpcwlnlazbvszxoayuinzwluqhnzwlbhrpxlpiusnwkwcyiezwwcqejhgwuqhvmghewlrhfxfhwfmjtphprwtruqhgasmbdwztvxuopgawwcijrkwgwhve";
    int k=7;
    vector<int> column0 = countChar(ciphertext, 0, k);
    vector<int> column1 = countChar(ciphertext, 1, k);
    vector<int> column2 = countChar(ciphertext, 2, k);
    vector<int> column3 = countChar(ciphertext, 3, k);
    vector<int> column4 = countChar(ciphertext, 4, k);
    vector<int> column5 = countChar(ciphertext, 5, k);
    vector<int> column6 = countChar(ciphertext, 6, k);

    cout << endl << endl << "Plaintex:\n";
    cout << decrypt(ciphertext, "student");

    return 0;
}
