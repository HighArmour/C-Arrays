#include<conio.h>
#include<iostream>
#include<math.h>
/* Sourabh Mishra */
using namespace std;
double d = 0;
double det(int n, double mat[10][10]);
double det(int n, double mat[10][10])
{
    double submat[10][10];
    if (n == 2)
        return ((mat[0][0] * mat[1][1]) - (mat[1][0] * mat[0][1]));
    else
        {
            for (int c = 0; c < n; c++)
                {
                    int subi = 0; //submatrix's i value
                    for (int i = 1; i < n; i++)
                        {
                            int subj = 0;
                            for (int j = 0; j < n; j++)
                                {
                                    if (j == c)
                                        continue;
                                    submat[subi][subj] = mat[i][j];
                                    subj++;
                                }
                            subi++;
                        }
                    d = d + (pow(-1, c) * mat[0][c] * det(n - 1, submat));
                }
        }
    return d;
}
int main(int argc, char **argv)
{
    cout << "Enter dimension of the matrix:\n";
    int n;
    cin >> n;
    double mat[10][10];
    cout << "Enter elements of the matrix:\n";
    for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                {
                    cin >> mat[j][i];
                }
        }
    cout << "Determinant of the given matrix is: " << det(n, mat);
    return 0;
}

/*
Enter the dimension of the matrix:
3
Enter the elements of the matrix:
3 5 2
8 4 8
2 4 7
The determinant of the given matrix is: -164

Enter the dimension of the matrix:
4
Enter the elements of the matrix:
9 5 2 5
9 5 3 7
6 5 4 8
1 5 3 7
The determinant of the given matrix is: 0
