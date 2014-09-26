#ifndef MINOR_H
#define MINOR_H


class Minor
{
    public:
        Minor();
        Minor(int, int);
        ~Minor();
        Minor (const Minor &original);
        Minor & operator = (const Minor &rhs);
        void delM(int**, int);
        void menu();
        void inputM();
        void randM();
        void outputM();
        int** createLI(int);
        Minor createNM(int, int**);
        const Minor operator+(Minor &ob);
        const Minor operator-(Minor &ob);
        const Minor operator*(Minor &ob);

    private:
        int n, m;
        int **A;
        int mDim;
};

#endif // MINOR_H
