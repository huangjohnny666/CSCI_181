//Xiaoming Huang
//CS181 homework 5 Question 3, 4, 5
#include <iostream>
#include <cmath>
#include <vector>
#include <array>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iomanip>
using namespace std;

int rhomatrix[25] = {0,36,3,41,18,
                    1,44,10,45,2,
                    62,6,43,15,61,
                    28,55,25,21,56,
                    27,20,39,8,14};



//vector<vector<vector<int> > > a(5, vector<vector<int> >(5, vector<int>(64, 0)));

const string text = "0011000100110010001100110011010000110101001101100011011100111000001110010011000000110001001100100011001100110100001101010011011000110111001110000011100100110000001100010011001000110011001101000011010100110110001101110011100000111001001100000011000100110010001100110011010000110101001101100011011100111000001110010011000000110001001100100011001100110100001101010011011000110111001110000011100100110000001100010011001000110011001101000011010100110110001101110011100000111001001100000011000100110010001100110011010000110101001101100011011100111000001110010011000000110001001100100011001100110100001101010011011000110111001110000011100100110000001100010011001000110011001101000011010100110110001101110011100000111001001100000011000100110010001100110011010000110101001101100011011100111000001110010011000000110001001100100011001100110100001101010011011000110111001110000011100100110000001100010011001000110011001101000011010100110110001101110011100000111001001100000011000100110010001100110011010000110101001101100011011100111000001110010011000000110001001100100011001100110100001101010011011000110111001110000011100100110000001100010011001000110011001101000011010100110110001101110011100000111001001100000011000100110010001100110011010000110101001101100011011100111000001110010011000000110001001100100011001100110100001101010011011000110111001110000011100100110000001100010011001000110011001101000011010100110110001101110011100000111001001100000011000100110010001100110011010000110101001101100011011100111000001110010011000000110001001100100011001100110100001101010011011000110111001110000011100100110000";


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


//Rho function, input a_in, out up a_out after Rho step,
//a_in unchanged
vector<vector<vector<int> > > rho(vector<vector<vector<int> > > a){
    vector<vector<vector<int> > > rhoA(5, vector<vector<int> >(5, vector<int>(64, 0)));
    int shift = 0;
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            shift = rhomatrix[i*5+j];
            for(int k=0; k<64; k++){
                rhoA[i][j][k] = a[i][j][k-shift];
            }
        }
    }
    return rhoA;
}


//Pi function, input a_in, out up a_out after Pi step,
//a_in unchanged
vector<vector<vector<int> > > pi(const vector<vector<vector<int> > >& a){
    vector<vector<vector<int> > > piA(5, vector<vector<int> >(5, vector<int>(64, 0)));
    for(int k=0; k<64; k++){
        for(int ip=0; ip<5; ip++){
            for(int jp=0; jp<5; jp++){
                piA[jp][(2*ip+3*jp)%5][k] = a[ip][jp][k];
            }
        }
    }
    return piA;
}


//Chi function, input a_in, out up a_out after Chi step,
//a_in unchanged
vector<vector<vector<int> > > chi(const vector<vector<vector<int> > >& a){
    vector<vector<vector<int> > > chiA(5, vector<vector<int> >(5, vector<int>(64, 0)));
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 64; k++) {
                chiA[i][j][k] = a[i][j][k] ^ ( (1^a[(i+1)%5][j][k]) * a[(i+2)%5][j][k]);
            }
        }
    }


    return chiA;
}




int main(){

//create the a_in 3d vector as input
//a is the 3d vector
    vector<int> v = strToVec(text);
    vector<vector<vector<int> > > a = inputSHA3(v);


//Question 3
    vector<vector<vector<int> > > a3 = rho(a);

    //checking
    cout << "--Question 3--\nchecking for a_out[4][3][9....18]: ";
    for(int i=9; i<=18; i++){
        cout << a3[4][3][i];
    }
    cout << endl;
    //result
    cout << "   value for a_out[3][1][15...24]: ";
    for(int i=15; i<=24; i++){
        cout << a3[3][1][i];
    }
    cout << endl << endl << endl;



//Question 4
    //create vector after pi function
    vector<vector<vector<int> > > a4 = pi(a);

    //checking
    cout << "--Question 4--\nchecking for a_out[4][3][9....18]: ";
    for(int i=9; i<=18; i++){
        cout << a4[4][3][i];
    }

    //result
    cout << endl << "   value for a_out[3][1][15...24]: ";
    for(int i=15; i<=24; i++){
        cout << a4[3][1][i];
    }
    cout << endl << endl << endl;




//Question 5
    //create vector after pi function
    vector<vector<vector<int> > > a5 = chi(a);

    //checking
    cout << "--Question 5--\nchecking for a_out[4][3][9....18]: ";
    for(int i=9; i<=18; i++){
        cout << a5[4][3][i];
    }

    //result
    cout << endl << "   value for a_out[3][1][15...24]: ";
    for(int i=15; i<=24; i++){
        cout << a5[3][1][i];
    }

    return 0;
}
