#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

  
void binaryStringOfLengthN (vector<char> store ,int n) {
    // print binary numbers of length N

    if (store.size() < n) {

        store.push_back('0');
        if (store.size() == n) {
            cout << string(store.begin(), store.end()) << endl;
        }
        binaryStringOfLengthN(store, n);
        store.pop_back();
        

        store.push_back('1');
        if (store.size() == n) {
            cout << string(store.begin(), store.end()) << endl;
        }
        binaryStringOfLengthN(store, n);

    }
}



void binaryStringNM(vector<char> store, int n, int m)
{
    // print the binary numbers with n digits 0 and m digits 1

    if (store.size() < n+m) {

        if ( count(store.begin(), store.end(), '0') < n) {
            store.push_back('0');
            if (store.size() == n+m) {
                cout << string(store.begin(), store.end()) << endl;
            }
            binaryStringNM(store, n, m);
            store.pop_back();
        }


        if (count(store.begin(), store.end(), '1') < m) {
            store.push_back('1');
            if (store.size() == n+m) {
                cout << string(store.begin(), store.end()) << endl;
            }
            binaryStringNM(store, n, m);
        }

    }
}



void stringRecursion(vector<char> arr, vector<char> store, int n) {
    // print the permutations of a string s containing non-duplicate characters.

    if ( store.size() < n ) 
    {
        for (int i=0; i<n; i++) {

            if (count(store.begin(), store.end(), arr[i]) == 0) 
            {
                store.push_back(arr[i]);

                if (store.size() == n) 
                {
                    cout << string(store.begin(), store.end()) << endl;
                }


                stringRecursion(arr, store, n);

                store.pop_back();
            }
        }
    }
}




vector<string> passwordRecursion(vector<char> arr, vector<char> store, int n, vector<string> passwordStored) {
    // Generate all passwords from a set of characters

    if ( store.size() < n ) 
    {
        for (int i=0; i<n; i++) {

            store.push_back(arr[i]);
            passwordStored.push_back(string(store.begin(), store.end()));

            passwordStored = passwordRecursion(arr, store, n, passwordStored);

            store.pop_back();
        }
    }

    return passwordStored;
}


  

int main() {

    /* ################################## */
    /* print binary numbers of length N  */

    // int n;
    // cin >> n;

    // vector<char> store;

    // binaryStringOfLengthN(store, n);



    /* ################################## */
    /* print the binary numbers with n digits 0 and m digits 1 */

    // int n, m;

    // cin >> n >> m;

    // vector<char> store;

    // binaryStringNM(store, n, m);



    /* ################################## */
    /* print the permutations of a string s containing non-duplicate characters. */

    // string s;
    // cin >> s;

    // vector<char> arr(s.begin(), s.end());
    // vector<char> store;

    // int len = s.length();

    // stringRecursion(arr, store, len);


    

    /* ################################## */
    /* Generate all passwords from a set of characters */

    // string s;
    // cin >> s;

    // vector<char> arr(s.begin(), s.end());
    // vector<char> store;
    // vector<string> passwordStored;

    // int len = s.length();

    // vector<string> vec = passwordRecursion(arr, store, len, passwordStored);

    // for (int i=1; i <= len; i++) {
    //     for (auto p: vec) {
    //         if (p.size() == i) {
    //             cout << p << endl;
    //         }
    //     }
    // }




    /* ################################## */
    

}