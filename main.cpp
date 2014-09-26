#include <iostream>
#include "Minor.h"

using namespace std;

int main()
{
    cout<<"Enter the matrix and the number of rows and columns of minor:"<<endl;
    int n1, m1, mDim1;
    cout<<"Enter number of rows in matrix: ";
    cin>>n1;
    cout<<"Enter number of columns in matrix: ";
    cin>>m1;
    Minor matr1(n1, m1);
    cout<<endl<<"Main matrix: "<<endl;
    matr1.randM();
    matr1.outputM();

    cout<<"Enter the first minor dimension =  ";
    cin>>mDim1;
    Minor minor1=matr1.createNM(mDim1, matr1.createLI(mDim1));
    minor1.outputM();

    Minor matr2=matr1;
    cout<<"The second minor dimension = "<<mDim1<<endl;
    Minor minor2=matr2.createNM(mDim1, matr2.createLI(mDim1));
    minor2.outputM();

    Minor main();
}






