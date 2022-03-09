#include <string>
#include <exception>
#include <stdexcept>
#include <iostream>
#include <vector>
#include "mat.hpp"


using namespace std;
using namespace ariel;

bool checkInputFunc(int columns , int rows,char a , char b){
    if(rows <= 0 || columns <= 0 ){ return false;}
    if(rows % 2 == 0 || columns % 2 == 0 ){ return false;}
    // if(a >= hLimit || a < bLimit){ return false;} // Depends on the limit(check for part b)
    // if(b >= hLimit || b < bLimit){ return false;} // Depends on the limit(check for part b)
    return true;
}

namespace ariel{

     vector<vector<char>> fillingCarpet(int columns , int rows , char a , char b){
        int columnFromEnd = columns - 1;
        int columnFromBeg = 0;
        int rowFromEnd = rows - 1;
        int rowFromBeg = 0;

       
        vector<vector<char>> matrix(rows, vector<char> (columns, 0));
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
        
    string mat(int columns , int rows , char c , char d){
        if(!(checkInputFunc(columns , rows , c, d))){
            throw invalid_argument("Mat size is always odd");
        }
        vector<vector<char>> carpetMat;
        carpetMat = fillingCarpet(columns , rows ,c,d);
        string carpet ;
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
//     // cout << mat(9,3,'@',2) << endl;
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
