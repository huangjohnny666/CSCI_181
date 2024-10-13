//Xiaoming Huang
//CS181 homework 3 Question 1b)
#include <iostream>
#include <cmath>
#include <vector>
#include <array>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;


  //print the array
void print(int arr[], int n){
    for (int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

  //print the vector
void print(vector<int> v){
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl << endl;
}

  //change int number to an array of size n, which is the binary representation of number
vector<int> DecimalToBinary(int number, int n){
    int temp = number;
    vector<int> binary(n, 0);
    int base = pow(2, n-1);
    for(int i=0; i<n; i++){
        if(temp >= base){
            binary[i] = 1;
            temp = temp-base;
        } else {
            binary[i] = 0;
        }
        base = base/2;
    }
    return binary;
}

  //ConvertBitArraytoInt()
vector<int> ConvertBitArraytoInt(vector<int> k, int n){
    //n is bit length, Ksize is # of output K
    int KSize = k.size()/n;
    vector<int> K(KSize, 0);

    //create array base[] to store each bit's value
    int base[n];
    for(int b=0; b<n; b++){
        base[b] = pow(2, n-b-1);
    }

    int sum = 0;
    for(int i=0; i<KSize; i++){
        for(int j=0; j<n; j++){
            if(k[ (i*n)+j ] == 1){
                sum = sum + base[j];
                //cout << base[j] << " ";
            }
        }
        //cout << endl;
        K[i] = sum;
        sum = 0;
    }
    return K;
}

  //convert int number's vector to their binary representation in array
vector<int> ConvertIntArraytoBit(vector<int> intK, int n){
    int size = intK.size();
    vector<int> bitK(size*n, 0);
    vector<int> K(n, 0);
    for(int i=0; i<size; i++){
        K = DecimalToBinary(intK[i], n);
        for(int j=0; j<n; j++){
            bitK[i*n+j] = K[j];
        }
    }
    return bitK;
}

  //initialization of S[0,...,2^n -1]
vector<int> S_initialization(int n){
    int size = pow(2, n);
    vector<int> S(size, 0);
    for(int i=0; i<S.size(); i++){
        S[i] = i;
    }
    return S;
}

  //T initialization, assign k to T repeatedly
vector<int> T_initialization(int n, vector<int> k){
    int size = pow(2, n);
    int key_length = k.size();
    vector<int> T(size, 0);
    for(int i=0; i<size; i++){
        T[i] = k[i%key_length];
    }
    return T;
}

  //permutation
void permutation(vector<int>& S, vector<int> T, int n){
    int j=0;
    int size = pow(2, n);
    for(int i=0; i<size; i++){
        j = (j + S[i] + T[i]) % size;
        swap(S[i], S[j]);
        //print(S);
    }
}

  //stream generation using ksNUM as total key needed
  //ksNUM = length of plaintext in decimal
vector<int> streamGeneration(vector<int> S, int n, int ksNUM){
    int generate = 1;
    int i = 0;
    int j = 0;
    int t = 0;
    int size = pow(2, n);
    vector<int> ks;
    for(int x=0; x<ksNUM; x++){
    //while(generate == 1){
        i = (i+1) % size;
        j = (j + S[i]) % size;
        swap(S[i], S[j]);
        t = (S[i] + S[j]) % size;
        ks.push_back(S[t]);
        //print(ks);
        //cout << "Type 1 go, other than 1 to stop: ";
        //cin >> generate;
    }
    return ks;
}

  //the XOR function of plaintext and keystream
void RC4_XOR(vector<int>& m, vector<int> ks){
    //if assumming m1 and m2 are same M_length
    int n = m.size();
    for(int i=0; i<n; i++){
        m[i] ^= ks[i];
    }
}


int main(){
    int n = 3;
    vector<int> k;
    k.push_back(1);
    k.push_back(2);
    k.push_back(3);
    k.push_back(6);

    vector<int> M_int;
    M_int.push_back(1);
    M_int.push_back(0);
    M_int.push_back(2);
    M_int.push_back(3);
    M_int.push_back(3);
    M_int.push_back(0);
    M_int.push_back(7);
    int M_length = M_int.size();
    vector<int> M_bit = ConvertIntArraytoBit(M_int, n);

    //0 0 1 0 0 0 0 1 0 0 1 1 0 1 1 0 0 0 1 1 1

    cout << "key in decimal: ";
    print(k);
    vector<int> bi_key = ConvertIntArraytoBit(k, n);
    cout << "key in binary: ";
    print(bi_key);


    vector<int> S_test = S_initialization(n);
    cout << "S Initialization: ";
    print(S_test);

    vector<int> T_test = T_initialization(n, k);
    cout << "T Initialization: ";
    print(T_test);

    permutation(S_test, T_test, n);
    cout << "permutation result: ";
    print(S_test);

    vector<int> keystream = streamGeneration(S_test, n, M_length);
    cout << "keystream: ";
    print(keystream);

    vector<int> ks_bit = ConvertIntArraytoBit(keystream, n);
    cout << " Keystream in binary: ";
    print(ks_bit);

    cout << " plaintext in binary: ";
    print(M_bit);

    RC4_XOR(M_bit, ks_bit);
    cout << "ciphertext in binary: ";
    print(M_bit);

    //cout << "ciphertext in decimal: ";
    //print(ConvertBitArraytoInt(M_bit, n));

    return 0;
}
