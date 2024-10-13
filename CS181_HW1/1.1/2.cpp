//Xiaoming Huang
//CS181 homework 1 Question 2



#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;


//read info from a txt file and output string variable
string readFile(const string& filename) {
    // open the file for reading
    ifstream inputFile(filename);

    // check if the file was successfully opened
    if (!inputFile.is_open()) {
        throw runtime_error("Error: could not open input file");
    }

    // read the file into a string
    stringstream buffer;
    buffer << inputFile.rdbuf();
    string contents = buffer.str();

    // close the file
    inputFile.close();

    return contents;
}

//encryption function
//input: plaintext m and keywork key
//output: return a string c which is the ciphertext
string encrypt(string m, string key){
    //k to store length of the key, to avoid calling length() multiple times
    int k = key.length();

    //create a string c to store the cipher text
    string c = m;

    //create a index array to store count for each letter in key word
    int index[k];
    for(int i=0; i<k; i++){
        index[i] = key[i] - 97;
    }
    cout << endl<< endl;

    //int temo to store temporary index from 0 to 25 to indicate the letter m[i]
    int temp;
    for(int i=0; i<m.length(); i++){
        temp = m[i]-97;
        temp = (temp+index[i%k])%26;
        c[i] = temp+97;
    }
    return c;
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
    cout << endl<< endl;

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

    //tested with class example, where section is the keyword

    //read data from the file "vigenere-cipher.txt"
    string exampleCipherText = "wzggqbuawqpvhveirrbvnysttaknkenxosavvwfwfrvxqumhuwwqgwtgziihlocgpnhjmnnmtzqboavvabcuawohbvrjtampovklgpigfsmfmwvnniyhzyrvqkkiqywwehvjrjwgwewgzhcxucakepwpsnjhvamahkmehnhuwwvtzguwaclzstsvfxlplzmuywzygagkaofkioblwiargtvrgzitxeofswcrqbtllcmiabfkttbwbfenvzsnlytxahuwvgtzstghutvrzwrcglprariltwxwtampotgvwlqhvkhkynwpmpvmwgbjxqnbtnuxhkwasagvbwbntswmpwfdmhxncezinbdsqarvaihojmneqoalfwmpomqdqgmkuwvgfghusrfaqgggvavwzyahggwbrgjjbakeaxkgovnkwwkdwiwhdnboaumggbgbmvexaoogypwewgzvgymfrfgglbcuaq";
    cout << "Sample ciphertext we use:\n"
         << exampleCipherText << endl << endl;

    string key = "section";

    string sampleDecryption = decrypt(exampleCipherText, key);
    cout << "Sample decryption using sample ciphertext:\n"
         << sampleDecryption << endl << endl;

    string sampleEncryption = encrypt(sampleDecryption, key);
    cout << "Sample encryption using the plaintext from above:\n"
         << sampleEncryption << endl << endl;



    return 0;
}
