#include <iostream>
using namespace std;
// 1. Qsort

int Arr[14] = {1,0,4,3,3,1,0,2,4,7,9,10,6,5};
void qsort(int left, int right) {
    //making the 2 parts:
    int i, j, etalon, swap;
    //i is left , j is right
    i = left, j = right;
    etalon = Arr[(left + right )/2 ];
 
    cout << "#�����, ������� �� ���� �� " << i << " �� " << j << endl;
    cout << "������= " << etalon << endl;
    do
    {
        while (Arr[i] < etalon){ 
            cout << "�������� ������" << endl;
            i++;
        }
        while (Arr[j] > etalon){  
            cout << "�������� �������" << endl;
            j--; 
        }
        if (i <= j)
        {
             cout << "������� �� " << Arr[i] << " � " << Arr[j] << endl;
             swap = Arr[i];
             Arr[i] = Arr[j];
             Arr[j] = swap;

             i++;
             j--;
        }
    } while (i <= j);
    cout << "���� �� ���������" << endl;

    //Uslovie za duno:
    if (left < right) {
        // -- recursion --
     
        //left part
        qsort(left, j);

        //right part
        qsort(i, right);
    }
    else {
        // -- bottom --
        cout << "- ����. -" << endl;
        cout << "���������" << endl << endl;
    }
}
void Print() {
    for (int i = 0; i < 14; i++) { cout << Arr[i] << " "; }
    cout << endl;
}
int main(){ 
    setlocale(LC_ALL, "Bulgarian");
    cout << "������� ��������� �� ������:" << endl;
    Print();
    qsort(0, 14-1);
    cout << endl << "������ ��������� �� ������ :" << endl;
    Print();
    return 0;
}

