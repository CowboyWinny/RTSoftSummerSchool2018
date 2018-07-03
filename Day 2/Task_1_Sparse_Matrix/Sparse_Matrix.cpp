#include <map>
#include <iostream>
//M, N - array sizes
using namespace std;

template<typename T, int M, int N>
class SparseMatrix
{
    public:
        SparseMatrix();
        //SparseMatrix(const SparseMatrix<T, M, N>& other);

        T& operator()(int i, int j);
        //const T& operator()(int i, int j) const;
        T& set(int i, int j, T value);
        void show();
    private:
        map<int, map<int, T>> matrix;
        T zero_value = static_cast<T>(0);
};

template<typename T, int M, int N>
SparseMatrix<T, M, N>::SparseMatrix()
{
    //matrix[0][0] = 0;
    cout << "Matrix initialized" <<  endl;
}

template<typename T, int M, int N>
T& SparseMatrix<T, M, N>::operator()(int i, int j)
{
    if(i < M && j < N)
    {
        if(matrix.find(i) != matrix.end())
        {
            if(matrix[i].find(j) != matrix[i].end())
            {
                return matrix[i][j];
            }
            else return zero_value;
        }
        else return zero_value;
    }
    else cout << "Element out of range";
}

template<typename T, int M, int N>
T& SparseMatrix<T, M, N>::set(int i, int j, T value)
{
    if(i < M && j < N)
    {
        matrix[i][j] = value;
    }
    else cout << "Element out of range" << endl;
}

template<typename T, int M, int N>
void SparseMatrix<T, M, N>::show()
{
    for(int i = 0; i < M; i++)
    {
        if(matrix.find(i) != matrix.end())
        {
            for(int j = 0; j < N; j++)
            {
                if(matrix[i].find(j) != matrix[i].end())
                {
                    cout << matrix[i][j] << " ";
                }                
                else 
                {
                    cout << "0 ";
                }
            }
            cout << endl;
        }
        else
        { 
            for(int j = 0; j < N; j++)
                cout << "0 ";
            cout << endl;
        }
    }
}

int main(int argc, char const *argv[])
{
    SparseMatrix<float, 5, 4> mat;
    mat.set(2, 1, 2.7);
    cout << "\n" << "Sparse Matrix element " << mat(2, 1) <<  " just added" << endl;
    mat.set(10, 10, 34.1);
    mat.set(1, 1, 1.111);
    mat.set(2, 2, 2.222);
    mat.set(3, 3, 3.333);
    mat.show();
    
    return 0;
}
