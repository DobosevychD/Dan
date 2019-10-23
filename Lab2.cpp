#include <iostream>

using namespace std;

const int size = 100;
//функція яка перевіряє чи немає одинакових елементів множини
bool good_mass(int *A, int n) {
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j=0; j<n; j++ ){
            if (A[j]==A[i]){
                count++;
            }
        }
        if (count != 1 ) {
            return false;
        }
    }
    return true;
}
//функція яка створює множини
void creat(int *A, int n) {
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    if (good_mass(A, n) == false)
        cout<<"wrong mass"<<endl;
}
//функція яка виводить множини
void print(int *A, int n) {
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}
//функція яка шукає одинакові елементи множин
bool good_elem(int *A, int n, int el) {
    for (int i = 0; i < n; i++) {
        if (A[i] == el) {
            return false;
        }
    }
    return true;

}
//функція яка шукає об'єднання множин
void Association(int* mas1, int mas1_size, int* mas2, int mas2_size, int* mas_ob, int&  mas_od_size)
{
    for (int i = 0; i < mas1_size; i++) {
        if (good_elem(mas_ob, mas_od_size, mas1[i])) {
            mas_ob[mas_od_size] = mas1[i];
            mas_od_size++;
        }

    }
    for (int i = 0; i < mas2_size; i++) {
        if (good_elem(mas_ob, mas_od_size, mas2[i])) {
            mas_ob[mas_od_size] = mas2[i];
            mas_od_size++;
        }

    }
}
//функція яка шукає перетин множин
void Intersection(int* mas1, int mas1_size, int* mas2, int mas2_size, int* mas_per, int & mas_per_size)
{
    for(int i=0;i<mas1_size;i++)
    {
        if(!good_elem(mas2,mas2_size,mas1[i]))
        {
            mas_per[mas_per_size] = mas1[i];
            mas_per_size++;
        }
    }
}

int main()
{
    const int size = 100;
    int mas1[size];
    int mas2[size];
    int mas_ob[size];//множина об'єднання
    int mas_per[size];//множина перетину
    int mas1_size, mas2_size;
    int mas_od_size=0;
    int mas_per_size = 0;
    cout << "mas1_size:= ";
    cin >> mas1_size;
    cout << "mas1:= ";
    creat(mas1, mas1_size);
    cout << "mas2_size:= ";
    cin >> mas2_size;
    cout << "mas2:= ";
    creat(mas2, mas2_size);
//вивід потужності кожної з множин
    int pot_mas1 = mas1_size;
    cout << "capacity mas1: " << pot_mas1<<endl;
    int pot_mas2 = mas2_size;
    cout << "capacity mas2:  " << pot_mas2<<endl;

    Association(mas1, mas1_size, mas2, mas2_size, mas_ob, mas_od_size);
    Intersection(mas1, mas1_size, mas2, mas2_size, mas_per, mas_per_size);

    cout << "association: ";
    print(mas_ob, mas_od_size);
    cout << "intersection: ";
    print(mas_per, mas_per_size);


//створюємо додвтковий масив
    int mas_dod[size];
    int mas_dod_size = 0;//довжина mas_dod
    Association(mas1, mas1_size, mas2, mas2_size, mas_dod, mas_dod_size);

    int mas_rez[size];
    int mas_rez_size = 0;
    Intersection(mas_dod, mas_dod_size, mas2, mas2_size, mas_rez, mas_rez_size);
// перевірка закону поглинання
    bool flag = true;
    if(mas2_size==mas_rez_size)
    {
        for(int i=0;i<mas_rez_size;i++)
        {
            if(mas2[i]!=mas_rez[i])
            {
                flag = false;
                break;
            }
        }
    }
    else
    {
        flag = false;
    }

    if(flag)
    {
        cout << "zakon pogl" << endl;
    }
    else
    {
        cout << "not zakon  pogl" << endl;
    }

    return 0;

}