/*====================================================
    Draw the possible positions of n queens on the chessboard 
    so that they do not attack each other.
 =====================================================*/

#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

/*  Check the N queens on the chessboard, whether they can attack each other or not*/
bool queenNQueen(vector<int> a, vector<int> b, int n) {

    for (int i=0; i < n-1; i++) {
        int x = a[i], y = b[i];
        //cout << x << y << "\n";

        for (int j=i+1; j < n; j++) {
            int _x = a[j], _y = b[j];

            if (x == _x) {
                // cout << "false1";
                return false;
            }

            if (y == _y) {
                // cout << "false2";
                return false;
            }

            if (abs(x- _x) == abs(y - _y)) {
                // cout << "false3";
                return false;
            }
        }
    }
    // cout << "true";
    return true;
}



bool checkQueen(vector<int> a, vector<int> b, int x, int y) 
{
    /* Check if the queen has x, y coordinates are reasonable or not */

    if (a.size() == 0) {
        return true;
    }

    for (int i=0; i < a.size(); i++) {
        int _x = a[i], _y = b[i];

        if (x == _x) {
            //cout << "false1";
            return false;
        }

        if (y == _y) {
            //cout << "false2";
            return false;
        }

        if (abs(x- _x) == abs(y - _y)) {
            //cout << "false3";
            return false;
        }
    }
    //cout << "true";
    return true;
}

void drawNQueensChess (vector<int> a, vector<int> b, int n) {
    /* draw a chessboard n queens */
    
    char arr[n][n];

    for (int i=0; i < n; i++) {
        for (int j=0; j < n; j++) {
            arr[i][j] = '-';
        }
    }

    for (int i=0; i < n; i++) {
        arr[a[i]][b[i]] = '*';
    }

    for (int i=0; i < n; i++) {
        for (int j=0; j < n; j++) {
            cout << arr[i][j];
        }
        cout << endl;
    }
    cout <<  "==========\n";
}

void queensChess (vector<int> a, vector<int> b, int n) {

    int len  = a.size();
    int row = len;

    if (len == n) {
        drawNQueensChess(a, b, n);
    } 
    else {
        for (int i=0; i < n; i++) {
            
            if (checkQueen(a, b, row, i)) {

                // check the queen in the row_th, position i_th
                // if reasonable call recursively for next row
                a.push_back(row);
                b.push_back(i);
                
                queensChess(a, b, n);


                // delete to check next i_th positions in row_th
                a.pop_back();
                b.pop_back();
            }
        }
    }

}

int main() {
    int n;
    cin >> n;

    // vector a, b stores the x, y (row, col) positions of the queens on the chessboard, respectively
    vector<int> a, b;
    
    queensChess(a, b, n);
}