#include <string>
#include <vector>
using namespace std;


const short bLimit = 32;
const short hLimit = 127; 

namespace ariel{
    string mat(int columns, int rows , char c , char d);
    vector<vector<char>> fillingCarpet(int columns , int rows , char a , char b);
    // void initMat (char** matrix , int rows , int columns);
    }