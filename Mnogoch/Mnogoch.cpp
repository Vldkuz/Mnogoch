#include <iostream>
using namespace std;

class MyVec
{
public:
    MyVec()
    {
        this->size = 10;
        this->arr = new double[size];
    }

    MyVec(int n)
    {
        size = n;
        this->arr = new double[size];
    }

    MyVec(int n, double intiaziler)
    {
        size = n;
        this->arr= new double[size] {intiaziler};
        this->default_init = intiaziler;
    }

    ~MyVec()
    {
        delete[] this->arr;
        size = 0;
    }

    void push_by_index(double value,int index)
    {
        if (index >= size-1)
        {
            double* temp = new double[(size + index) * 2]{this->default_init};
            memcpy(temp, this->arr, size - 1);
            this->arr = temp;
            size = (size + index) * 2;
        }
        else
        {
            this->arr[index] += value;
        }
    }

    int get_size() {
        return size;
    }

    double get_value(int index)
    {
        return this->arr[index];
    }

private:
    double* arr;
    int size;
    double default_init;
};


int main()
{
    setlocale(LC_ALL, "Rus");
    int size_1, size_2;
    cin >> size_1 >> size_2;
    double* arr_1 = new double[size_1];
    double* arr_2 = new double[size_2];
    double* res = new double[size_1 + size_2];
    double* pro = new double[size_1 * size_2]{0};
    int maxindex = 0;


    for (int i = 0; i < size_1; ++i)
        cin >> arr_1[i];
    for (int i = 0; i < size_2; ++i)
        cin >> arr_2[i];
    int i = 0;
    
    //cумма
    while (i < max(size_1,size_2))
    {
        if (i >= size_1 && i < size_2)
            res[i] = 0 + arr_2[i];
        if (i >= size_2 && i < size_1)
            res[i] = 0 + arr_1[i];
        if (i<size_1 && i<size_2)
            res[i] = arr_1[i] + arr_2[i];
        ++i;
    }

    cout << "Cумма: ";
    for (int k = 0; k < i; ++k)
    {
        cout << "x^" << k << ":" << res[k] << "\t";
    }
    cout << endl;
    i = 0;

    if (size_1 <= size_2)
    {
        while (i < size_1)
        {
            for (int j = 0; j < size_2; ++j)
            {
                maxindex = max(maxindex, i + j);
                pro[i + j]+= arr_1[i] * arr_2[j];
            }
            i++;
        }
    }
    else
    {
        while (i < size_2)
        {
            for (int j = 0; j < size_1; ++j)
            {
                maxindex = max(maxindex, i + j);
                pro[i + j] += arr_2[i] * arr_1[j];
            }
            i++;
        }
    }

    cout << "Произведение: ";
    for (int i = 0; i <= maxindex; ++i)
    {
        cout << "x^" << i << ":" << pro[i] << "\t";
    }

    return 0;
}
