#include "Minor.h"
#include <iostream>
#include <cassert>
#include <time.h>
#include <stdlib.h>
#include <conio.h>

using namespace std;

Minor::menu(n1,m1)
{
    int enter;
    while (true)
    {
        cout<<"Main menu"<<endl;

    cout<<"For find the sum press 1."<<endl;
    cout<<"For find the minus press 2."<<endl;
    cout<<"For find the multiplication press 3."<<endl;
    cout<<"For create the new array of objects press 4."<<endl;
    cin>>enter;
    if(enter=='1')
    {
    Minor sum;
    sum=minor1+minor2;
    cout<<"Minor1 + Minor2 = "<<endl;
    sum.outputM();}

    if(enter=='2'){
    Minor minus;
    minus=minor1-minor2;
    cout<<"Minor1 - Minor2 = "<<endl;
    minus.outputM();}

    if(enter=='3'){
    Minor product;
    product=minor1*minor2;
    cout<<"Minor1 * Minor2 = "<<endl;
    product.outputM();}

    if(enter=='4'){
    const int N=5;
    Minor masMatr[N];
    int n2, m2;
    cout<<"Enter n = ";
    cin>>n2;
    cout<<"Enter m = ";
    cin>>m2;
    Minor matr(n2, m2);
    for (int i=0; i<N; i++)
    {
        cout<<endl<<"Array"<<i<<endl;
        masMatr[i]=matr;
        masMatr[i].randM();
        masMatr[i].outputM();
    }


}} else {return 0;}
}

Minor::Minor():
    n(0),
    m(0),
    A(nullptr) {}


Minor::Minor(int n, int m):
    n(n),
    m(m),
    A(nullptr)
{
    srand(time(NULL));
    A=new int*[this->n];
    for (int i=0; i<n; i++)
        A[i]=new int[this->m];
}

Minor::Minor (const Minor &original):
    n(original.n),
    m(original.m),
    A(nullptr)
{
    A=new int*[n];
    for (int i=0; i<n; i++)
        A[i]=new int[m];

        for (int j=0; j<m; j++)
            A[i][j]=original.A[i][j];
}


Minor &Minor::operator=(const Minor &rhs)
{
    if(this!=&rhs)
    {
        n=rhs.n;
        m=rhs.m;

        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
                A[i][j]=rhs.A[i][j];
    }
    return *this;
}


Minor::~Minor()
{
    delM (A, n);
    m=0;
    n=0;
}


void Minor::delM (int** matr, int k)
{
    for (int i=0; i<k; i++)
        delete[] matr[i];
    delete[] matr;
    matr=nullptr;
}


void Minor::randM()
{
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            A[i][j]=rand() % 10;
}


void Minor::outputM()
{
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
        {
            cout.width(5);
            cout<<A[i][j];
        }
}

int** Minor::createLI(int mDim)
{
    cout<<"Enter indexes of rows and columns for minor (Up: 0,1,3, etc.): \n";
    int **listI=nullptr;
    listI=new int*[2];
    int k=n;
    for (int i=0; i<2; i++)
    {
        listI[i]=new int[mDim];
        for (int j=0; j<mDim; j++)
        {
            cin>>listI[i][j];
            if(listI[i][j]>0&&listI[i][j]<=k);
                k=m;
            else
                cout<<"Error"<<endl;
        }
        cout<<endl;
    }
    return listI;
}


Minor Minor::createNM(int mDim, int** listI)
{
    Minor newM(mDim, mDim);
    int iA=listI[0][i]-1, jA=listI[1][j]-1;
    for (int i=0; i<mDim; i++)
        for (int j=0; j<mDim; j++)
            newM.A[i][j]=A[iA][jA];

    delM (listI, 2);
    return newM;
}


const Minor Minor::operator+(Minor &ob)
{
    Minor temp(ob.n, ob.m);
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            temp.A[i][j]=A[i][j]+ob.A[i][j];
    return temp;
}


const Minor Minor::operator-(Minor &ob)
{
    Minor temp(ob.n, ob.m);
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            temp.A[i][j]=A[i][j]-ob.A[i][j];
    return temp;
}


const Minor Minor::operator*(Minor &ob)
{
   int res;
    Minor temp(ob.n, ob.m);
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
        {
            res=0;
            for(int k=0; k<n; k++)
            res+=A[i][k]*ob.A[k][j];
            temp.A[i][j]=res;
        }
    return temp;
}




