#include <iostream>
using namespace std;

class Matrix
{
public:
    virtual double getElem(int a, int b) = 0;
    virtual double setElem(int i, int j, double value) = 0;
    virtual Matrix2DArray add(Matrix2DArray &obj);
    virtual Matrix2DArray mul(Matrix2DArray &obj);
    virtual void inmatrix() = 0;
};

class Matrix2DArray : public Matrix
{
private:
    int rows;
    int cols;
    double **indata;
    double **data;
    double **data3;
    double **temp;

public:
    Matrix2DArray() {}

    Matrix2DArray(int height, int width)
    {
        this->cols = height;
        this->rows = width;
        indata = new double *[cols];
        for (int i = 0; i < cols; i++)
        {
            indata[i] = new double[rows];
        }

        data = new double *[cols];
        for (int i = 0; i < cols; i++)
        {
            data[i] = new double[rows];
        }
    }

    // input elements matrix function  area is below..

    void inmatrix()
    {
        double r;
        for (int i = 0; i < cols; i++)
        {
            for (int j = 0; j < rows; j++)
            {
                cout << "Enter elements in matrix: " << endl;
                cin >> r;
                indata[i][j] = r;
            }
        }
        // printing matrix is below
        for (int i = 0; i < cols; i++)
        {
            for (int j = 0; j < rows; j++)
            {
                cout << " " << indata[i][j] << " ";
            }
            cout << endl;
            cout << endl;
        }
    }

    double getElem(int i, int j)
    {
        return indata[i - 1][j - 1];
    }

    double setElem(int i, int j, double value)
    {
        indata[i - 1][j - 1] = value;
        return indata[i - 1][j - 1];
    }

    Matrix2DArray add(Matrix2DArray &obj)
    { // Matrix m1;
        Matrix2DArray m;
        for (int i = 0; i < cols; i++)
        {
            for (int j = 0; j < rows; j++)
            {
                data[i][j] = indata[i][j] + obj.indata[i][j];
            }
        }
        cout << endl;
        cout << endl;
        for (int i = 0; i < cols; i++)
        {
            for (int j = 0; j < rows; j++)
            {
                cout << " " << data[i][j] << " ";
            }
            cout << endl;
            cout << endl;
        }
        return m;
    }

    Matrix2DArray mul(Matrix2DArray &obj)
    {
        Matrix2DArray m;
        if (this->rows == obj.cols)
        {
            double **data2;
            data2 = new double *[this->cols];
            for (int i = 0; i < this->cols; i++)
            {
                data2[i] = new double[obj.rows];
            }
            for (int i = 0; i < cols; i++)
            {
                for (int j = 0; j < rows; j++)
                {
                    for (int k = 0; k < cols; k++)
                    {
                        data2[i][j] += indata[i][k] * obj.indata[k][j];
                    }
                }
            }
            cout << endl;
            cout << endl;
            for (int i = 0; i < cols; i++)
            {
                for (int j = 0; j < rows; j++)
                {
                    cout << " " << data2[i][j] << " ";
                }
                cout << endl;
                cout << endl;
            }
        }
        else
        {
            cout << " MULTIPLICATION NOT POSSIBLE ";
        }
        return m;
    }

    double min(Matrix2DArray &obj)
    {
        data3 = new double *[cols];
        for (int i = 0; i < cols; i++)
        {
            data3[i] = new double[rows];
        }

        for (int i = 0; i < cols; i++)
        {
            for (int j = 0; j < rows; j++)
            {
                if (indata[i][j] < obj.indata[i][j])
                {
                    data3[i][j] = indata[i][j];
                }
                else if (indata[i][j] > obj.indata[i][j])
                {
                    data3[i][j] = obj.indata[i][j];
                }
                else if (indata[i][j] == obj.indata[i][j])
                {
                    data3[i][j] = obj.indata[i][j];
                }
            }
        }
        cout << "THE MINIMUM VALUES COMPARE FROM BOTH MATRIX IS: " << endl;
        cout << endl;
        for (int i = 0; i < cols; i++)
        {
            for (int j = 0; j < rows; j++)
            {
                cout << " " << data3[i][j] << " ";
            }
            cout << endl;
            cout << endl;
        }
        return 0;
    }
    void transpose()
    {
        temp = new double *[cols];
        for (int i = 0; i < cols; i++)
        {
            temp[i] = new double[rows];
        }
        int a = 0;
        int b = 0;
        for (int i = 0; i < cols; i++)
        {
            for (int j = 0; j < rows; j++)
            {
                temp[b][a] = indata[i][j];
                b++;
            }
            b = 0;
            a++;
        }
        for (int i = 0; i < cols; i++)
        {
            for (int j = 0; j < rows; j++)
            {
                cout << " " << temp[i][j] << " ";
            }
            cout << endl;
            cout << endl;
        }
    }
};

class matrixlin
{
protected:
    double **data5;
    double *data3;
    double **data4;
    int rows;
    int cols;
    int elements;

public:
    matrixlin(){};

    void inmatrix(int elements)
    {
        this->elements = elements;
        double a;
        data3 = new double[elements];
        for (int i = 0; i < elements; i++)
        {
            cout << "Enter matrix elements: ";
            cin >> a;
            data3[i] = a;
        }
    }

    void set_heightwidht(int height, int width)
    {
        this->cols = height;
        this->rows = width;
        data4 = new double *[rows];
        for (int i = 0; i < rows; i++)
        {
            data4[i] = new double[cols];
        }
    }

    void delinearize()
    {
        int k = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                data4[i][j] = data3[k];
                k++;
            }
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << " " << data4[i][j] << " ";
            }
            cout << endl;
            cout << endl;
        }
    }
};

int main()
{

    // matrix addition and multipliction and  minimum fuction ...

    /*  Matrix2DArray M1(3, 3);
     M1.inmatrix();
     Matrix2DArray M2(3, 3);
     M2.inmatrix();
     M1.mul(M2);
     M1.add(M2);
     M1.min(M2);
    */

    // making matrix linearize...

    matrixlin li;
    // li.inmatrix(16);

    //  li.set_heightwidht(8,2);
    // li.delinearize();

    //  li.set_heightwidht(2,8);
    // li.delinearize();

    // li.set_heightwidht(4,4);
    // li.delinearize();

    li.inmatrix(8);

    // li.set_heightwidht(4, 2);
    li.delinearize();

    // li.set_heightwidht(8, 1);
    li.delinearize();
}
