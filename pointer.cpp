#include <iostream>
#include<cstring>

using namespace std;

int* getPointerToTen() {
    int* pInt;
    pInt = new int;
    *pInt = 10;
    return pInt;
}

void multiply(int *n, int k) {
    *n =  (*n) * k;
    cout << *n;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int* getPointerToArray(int n) {
    int* arr;
    arr = new int[n];

    for (int i=0; i < n; i++) {
        cin >> *(arr+i);
        // cin >> arr[i];
    }

    return arr;
}

double* getSquare (double number) {
    double* sq = new double;
    *sq = number * number;
    return sq;
}

// merge 2 arrays of integers in the given order
int* merge(int* firstArr, int lenArr1, int* secondArr, int lenArr2) {
    if (lenArr1 == 0) return secondArr;
    if (lenArr2 == 0) return firstArr;

    int len = lenArr1 + lenArr2;
    int* arr = new int[len];

    int mergeIdx = 0, firstiIdx = 0, secondIdx = 0;
    
    // ascending
    if (firstArr[0] <= firstArr[lenArr1-1] || secondArr[0] <= secondArr[lenArr2-1]) {
        while (firstiIdx < lenArr1 && secondIdx < lenArr2) {
            if (firstArr[firstiIdx] <= secondArr[secondIdx]) {
                arr[mergeIdx] = firstArr[firstiIdx];
                firstiIdx++;
            }
            else {
                arr[mergeIdx] = secondArr[secondIdx];
                secondIdx++;
            }
            mergeIdx++;
        }

        while (firstiIdx < lenArr1)
        {
            arr[mergeIdx] = firstArr[firstiIdx];
            mergeIdx++;
            firstiIdx++;
        }

        while (secondIdx < lenArr2)
        {
            arr[mergeIdx] = secondArr[secondIdx];
            mergeIdx++;
            secondIdx++;
        }
    }

    // decrease
    else {
        while (firstiIdx < lenArr1 && secondIdx < lenArr2) {
            if (firstArr[firstiIdx] >= secondArr[secondIdx]) {
                arr[mergeIdx] = firstArr[firstiIdx];
                firstiIdx++;
            }
            else {
                arr[mergeIdx] = secondArr[secondIdx];
                secondIdx++;
            }
            mergeIdx++;
        }

        while (firstiIdx < lenArr1)
        {
            arr[mergeIdx] = firstArr[firstiIdx];
            mergeIdx++;
            firstiIdx++;
        }

        while (secondIdx < lenArr2)
        {
            arr[mergeIdx] = secondArr[secondIdx];
            mergeIdx++;
            secondIdx++;
        }
    }


    return arr;

}

// create 2D matrix
int** inputMatrix(int nRows, int nCols) {
    int** matrix = new int*[nRows];

    for(int i = 0; i < nRows; i++) {
        matrix[i] = new int[nCols];
    }

    for (int i=0; i < nRows; i++) {
        for (int j=0; j<nCols; j++) {
            cin >> matrix[i][j];
        }
    }

    return matrix;
}

// print 2D matrix
void printMatrix(int** matrix, int nRows, int nCols) {
    for (int i=0; i < nRows; i++) {
        for (int j=0; j<nCols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// transpose Matrix
int** transposeMat(int** matrix, int nRows, int nCols) {
    int** transposeMatrix = new int*[nCols];

    for (int i=0; i<nCols; i++) {
        transposeMatrix[i] = new int[nRows];
    }

    for (int i=0; i<nRows; i++) {
        for (int j=0; j<nCols; j++) {
            transposeMatrix[j][i] = matrix[i][j];
        }
    }

    return transposeMatrix;

}

// reverse string
void reverseSeq(char *s) {
    int len = strlen(s);

    for (int i=0; i< len/2; i++) {
        char c = s[i];
        s[i] = s[len-1-i];
        s[len-1-i] = c;
    }
}

// filter the character to the right of the string
void rFilter(char *s) {
    int len = strlen(s);
    cout << "length: " << len << "\n";
    for (int i=len-1; i>= 0; i--) {
        if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z') {
            break;
        } else {
            s[i] = '_';
        }
    }
}


int main() {
    char *s;
    s = new char[50];
    cin >> s;
    rFilter(s);
    cout << s;
}