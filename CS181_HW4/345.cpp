//Xiaoming Huang
//CS181 homework 4 Question 3, 4, 5
#include <iostream>
#include <cmath>
#include <vector>
#include <array>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

//I just copy the code from the txt file so it's simplier to run the file
const string text = "0011000100110010001100110011010000110101001101100011011100111000001110010011000000110001001100100011001100110100001101010011011000110111001110000011100100110000001100010011001000110011001101000011010100110110001101110011100000111001001100000011000100110010001100110011010000110101001101100011011100111000001110010011000000110001001100100011001100110100001101010011011000110111001110000011100100110000001100010011001000110011001101000011010100110110001101110011100000111001001100000011000100110010001100110011010000110101001101100011011100111000001110010011000000110001001100100011001100110100001101010011011000110111001110000011100100110000001100010011001000110011001101000011010100110110001101110011100000111001001100000011000100110010001100110011010000110101001101100011011100111000001110010011000000110001001100100011001100110100001101010011011000110111001110000011100100110000001100010011001000110011001101000011010100110110001101110011100000111001001100000011000100110010001100110011010000110101001101100011011100111000001110010011000000110001001100100011001100110100001101010011011000110111001110000011100100110000001100010011001000110011001101000011010100110110001101110011100000111001001100000011000100110010001100110011010000110101001101100011011100111000001110010011000000110001001100100011001100110100001101010011011000110111001110000011100100110000001100010011001000110011001101000011010100110110001101110011100000111001001100000011000100110010001100110011010000110101001101100011011100111000001110010011000000110001001100100011001100110100001101010011011000110111001110000011100100110000";

//if needed to read data from the file, use this function
//where we can take readFile("sha3in.txt");
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

//print the 1-D vector
void print(vector<int> v){
    int n = v.size();
    for(int i=0; i<n; i++){
        cout << v[i];
    }
}

//convert a binary string to binary vector
vector<int> strToVec(string str){
    int n = str.length();
    vector<int> v(n, 0);
    for(int i=0; i<n; i++){
         v[i] = str[i] - '0';
    }
    return v;
}

//inputSHA3 function if input is 1-D array/vector
//will copy the value one by one
vector<vector<vector<int> > > inputSHA3(vector<int> v) {
    vector<vector<vector<int> > > a(5, vector<vector<int> >(5, vector<int>(64, 0)));
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 64; k++) {
                a[i][j][k] = v[64*( 5*j + i) + k];
            }
        }
    }
    return a;
}

//outputSHA3 function with input of 3-D vector
vector<int> outputSHA3( vector<vector<vector<int> > > a ){
    vector<int> v(1600, 0);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 64; k++) {
                v[64*( 5*j + i) + k] = a[i][j][k];
            }
        }
    }
    return v;
}

vector<vector<vector<int> > > theta(vector<vector<vector<int> > > a_in){
    vector<vector<vector<int> > > a_out(5, vector<vector<int> >(5, vector<int>(64, 0)));
    int sum1=0, sum2=0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 64; k++) {
                for(int jp=0; jp<5; jp++){
                    sum1 = sum1 ^ a_in[(i-1+5)%5][jp][k];
                    sum2 = sum2 ^ a_in[(i+1)%5][jp][(k-1+64)%64];
                }
                a_out[i][j][k] = a_in[i][j][k] ^ sum1 ^ sum2;
                sum1 = 0;
                sum2 = 0;
            }
        }
    }

    return a_out;
}



int main(){
//Question 3&4 checking
    cout << "Question 3 and 4:\n" << "the text:\n" << text << endl<< endl;

    //implement of inputSHA3, store in vector three
    vector<int> vec = strToVec(text);
    vector<vector<vector<int> > > three(5, vector<vector<int> >(5, vector<int>(64, 0)));
    three = inputSHA3(vec);

    //implement of outputSHA3, store in vector four, and printed
    cout << endl << endl << "output of outputSHA3:\n";
    vector<int> four = outputSHA3(three);
    print(four);
    cout << endl << endl << endl;


//Question 5:
cout << "Question 5:\n";

    vector<vector<vector<int> > > five = theta(three);
    cout << "\ncalculated value for a_out[4][3][9....18]: ";
    for(int s=9; s<=18; s++){
        cout << five[4][3][s];
    }

    cout << "\ncalculated value for a_out[3][1][15...24]: ";
    for(int s=15; s<=24; s++){
        cout << five[3][1][s];
    }
    cout << endl;

    return 0;
}
