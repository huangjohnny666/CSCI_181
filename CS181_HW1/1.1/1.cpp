//Xiaoming Huang
//CS181 homework 1 Question 1


#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

/*
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
*/

//frequency rank of each letter in english
const char engFreq[26] = {'e', 't', 'a', 'o', 'i', 'n', 's', 'r', 'h', 'd', 'l', 'u', 'c', 'm', 'f', 'y', 'w', 'g', 'p', 'b', 'v', 'k', 'x', 'q', 'j', 'z'};

//count the # of each letter in the text, " " ignored
vector<int> countChar(string str){
    vector<int> counts(26, 0);
    for (int i=0; i<str.length(); i++){
        if (str[i]!=32){
          counts[str[i] - 65]++;
        }
    }
    return counts;
}

//replace original with replace
void replace(string& str, char ori, char replace){
    for (int i=0; i<str.length(); i++){
        if(str[i] == ori){
            str[i] = replace;
        }
    }
    cout << str << endl << endl;
}

//selection sort of a 2d vector, sorted by the 2nd value
void vecSeleSort(vector<vector<int> >& v, int n){
    int max;
    for (int i=0; i<n-1; i++){
       max = i;
       for (int j=i+1; j<n; j++){
          if(v[j][1] > v[max][1]){
              max = j;
          }
       }
       //swap;
       swap(v[i], v[max]);
    }
}

//print each entry of a vector v
void print(vector<int> v){
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
}


//sum of all entries in a vector v
int sum(vector<int> v){
    int sum=0;
    for(int i=0; i<v.size(); i++){
        sum = sum+v[i];
    }
    return sum;
}

int main() {

    //read data from the file, stored in text
    string text = "ZIW VQKD LAFLIOFW YOSZWKWR ZIKGAUI ZIW SWQCWL GY ZIW ZKWWL EQLZOFU RQHHSWR LIQRGVL GF ZIW UKGAFR TWSGV TOKRL EIOKHWR QFR LQFU OF ZIW TKQFEIWL QRROFU ZG ZIW HWQEWYAS QDTOQFEW GY ZIW YGKWLZ Q SOUIZ TKWWMW KALZSWR ZIW SWQCWL EKWQZOFU Q UWFZSW VIOLHWKOFU LGAFR ZIQZ YOSSWR ZIW QOK";

    //vector store the count of each letter from A to Z
    vector<int> count = countChar(text);
    cout << endl << endl;
    //print the count number in sequence
    cout << "count of each letter from A to Z:\n";
    print(count);

    //assign a 2d vector which also store index from 0to 25 to represent each letter
    vector<vector<int> > myVector(26, vector<int>(2));//26row, 2column
    for (int i=0; i<26; i++){
        myVector[i][0] = i;
        myVector[i][1] = count[i];
    }
    cout << endl << endl;

    //sort the myVector by the count value
    vecSeleSort(myVector, 26);

    //create an array of characters which rank from highest amount to lowest in the text
    char letters[26];
    cout << "Sort the letters in descending order:\n";
    for (int i=0; i<26; i++){
        letters[i] = myVector[i][0] + 65;
        cout << letters[i] << " ";
    }
    cout << endl << endl;

    cout << text << endl << endl;

    //note letters stores the count of letters in text in descending order
    //and  engFreq stores the frequency

    cout << "test one...\n";
    string test1 = text;
    replace(test1, 'W', 'e');
    replace(test1, 'Z', 't');
    replace(test1, 'I', 'a');
    cout << "failed as tae seems wired...\n\n";


    cout << "tae seems weird, but the is a word, so try to switch these two...\n"
         << "test two...\n";
    string test2 = text;
    replace(test2, 'W', 'e');
    replace(test2, 'Z', 't');
    replace(test2, 'I', 'h');
    replace(test2, 'Q', 'a');
    //some 2-letter word of G*, guess one of it to be "of"
    replace(test2, 'G', 'o');
    //the fifth word --> through
    replace(test2, 'K', 'r');
    replace(test2, 'A', 'u');
    replace(test2, 'U', 'g');
    //"oY the treeL" --> "of the trees"
    replace(test2, 'Y', 'f');
    replace(test2, 'L', 's');
    //"SeaCes of the trees" --> "leaves of the trees"
    replace(test2, 'S', 'l');
    replace(test2, 'C', 'v');
    //another common o* is on, so try "oF" with "on"
    replace(test2, 'F', 'n');
    //"on the grounR" --> "on the ground"
    replace(test2, 'R', 'd');
    //"sunshOne fOltered through the leaves" --> "sunshine filtered through the leaves"
    replace(test2, 'O', 'i');
    //"shadoVs on the ground" --> "shadows on the ground"
    replace(test2, 'V', 'w');
    //"Telow Tirds" --> "below birds"
    replace(test2, 'T', 'b');
    //"warD sunshine" --> "warm sunshine"
    replace(test2, 'D', 'm');
    //"sang in the branEhes" --> "sang in the branches"
    replace(test2, 'E', 'c');
    //"the Heaceful ambiance" --> "the peachful ambiance"
    replace(test2, 'H', 'p');
    //"breeMe" --> "breeze"
    replace(test2, 'M', 'z');

cout << endl << "end of testing and the plaintext is:\n"
     << test2 << endl << endl;



return 0;
}
