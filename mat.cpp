#include <string>
#include <exception>
#include <stdexcept>
#include <iostream>
#include <array>
#include "mat.hpp"

using namespace std;
using namespace ariel;

bool checkInputFunc(int columns , int rows,char a , char b){
    if(rows <= 0 || columns <= 0 ) return false;
    if(rows % 2 == 0 || columns % 2 == 0 ) return false;
    if(a >= 127 || a < 32) return false;
    if(b >= 127 || b < 32) return false;
    return true;
}

namespace ariel{

    char** fillingCarpet(int columns , int rows , char a , char b){
        int columnFromEnd = columns - 1;
        int columnFromBeg = 0;
        int rowFromEnd = rows - 1;
        int rowFromBeg = 0;

        char** matrix;
        matrix = new char*[rows];
        for (int i = 0; i < rows; i++)
        {
            matrix[i] = new char[columns];
        }
        // initMat(matrix , rows,columns);
        while(columnFromEnd >= columnFromBeg && rowFromEnd >= rowFromBeg){
               for(int h = columnFromBeg; h <= columnFromEnd ;h++){
                   if (columnFromEnd % 2 == 0 && columnFromBeg % 2 == 0) // Even bigger than 0.
                   {
                       matrix[rowFromEnd][h] = a;
                       matrix[rowFromBeg][h] = a;
                   }else{
                       matrix[rowFromEnd][h] = b;
                       matrix[rowFromBeg][h] = b;
                   }
              }
               for (int i = rowFromBeg; i <= rowFromEnd; i++)
               {
                   if (rowFromEnd % 2 == 0 && rowFromBeg % 2 == 0) // Even bigger than 0.
                   {
                     matrix[i][columnFromEnd] = a;
                     matrix[i][columnFromBeg] = a;
                   } else{
                       matrix[i][columnFromEnd] = b;
                       matrix[i][columnFromBeg] = b;
                   } 
               }
                columnFromEnd--;
                columnFromBeg++;
                rowFromEnd--;
                rowFromBeg++;
        }
        return matrix;
    }
    // void initMat (char** matrix , int rows , int columns){
    //     matrix = new char*[rows];
    //     for (int i = 0; i < rows; i++)
    //     {
    //         matrix[i] = new char[columns];
    //     }

    // }
        
    string mat(int columns , int rows , char a , char b){
        if(!(checkInputFunc(columns , rows , a, b))){
            throw invalid_argument("Mat size is always odd");
        }
        char** carpetMat = fillingCarpet(columns , rows ,a,b);
        string carpet = "";
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                carpet += carpetMat[i][j];
            }
            carpet += "\n"; 
        }
        return carpet;
    }

}





// int main(){
//     cout << ariel::mat(9,7,'@','-') << endl;
//     cout << mat(13,5,'@','-') << endl;
//     cout << mat(33,19,'@','-') << endl;
//     cout << mat(1,1,'%','$') << endl;
//     cout << mat(9,3,'@','@') << endl;
//     // cout << mat(9,3,'@','\n') << endl;
//     cout << mat(9,3,'@',2) << endl;
//     try
//     {
//         cout << mat(35,-3,'@','-') << endl;
//         cout << mat(0,43,'@','-') << endl;
//         cout << mat(-2,43,'@','-') << endl;
//         cout << mat(13,4,'@','-') << endl;
//     }
//     catch(exception& e)
//     {
//         cout <<"caught exp :"  << e.what() << '\n' << endl;
//     }
//     cout << mat(1,9,'%','$') << endl;
//     cout << mat(9,1,'%','$') << endl;
// }
