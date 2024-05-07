#include <iostream>
#include <string>
using namespace std;

int k = 1;
int sum_n(int n);
void tail_r(int* mas, int n, int r, int ind);
void linear_r(int* mas, int r);
void print(int* mas, int n);
int length(string s);
int length_of_progression(string s);

int main()
{
    setlocale(LC_ALL, "Ukr");
    cout << "Завдання 1: створити геометричну прогресію за допомогою рекурсії" << endl;
    int r, n, ind = 1;
    int mas[100];

    cout << "Введіть розмір масиву: ";
    cin >> n;
    cout << "Введіть перший член масиву (ціле число): ";
    cin >> mas[0];
    cout << "Введіть знаменник геометричної прогресії: ";
    cin >> r;
    tail_r(mas, n, r, ind);
    cout << "Геометрична прогресія за хвостовою рекурсією:" << endl;
    print(mas, n);

    for (int i = 1; i < n; i++)
        mas[i] = 0;
    k = n;
    linear_r(mas, r);
    cout << "Геометрична прогресія за лінійною рекурсією:" << endl;
    print(mas, n);

    string s = "";
    for (int i = 0; i < n; i++)
        s += to_string(mas[i]);

    cout << endl << "Завдання 2: обчислити довжину рядка геометричної прогресії рекурсивною функцією." << endl;
    cout << "Довжина рядка: " << length_of_progression(s) << endl;
    system("pause");
    return 0;
}

int sum_n(int n)
{
    int sum=0;
    while (n != 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

void tail_r(int* mas, int n, int r, int ind)
{
    if (ind == n)
        return;
    mas[ind] = mas[ind - 1] * r;
    tail_r(mas, n, r, ind + 1);
}

void linear_r(int* mas, int r)
{
    if (k > 1)
    {
        k--;
        linear_r(mas, r);
    }
    mas[k] = mas[k - 1] * r;
    k++;
}

void print(int* mas, int n)
{
    for (int i = 0; i < n; i++)
        cout << mas[i] << " ";
    cout << endl;
}

int length(string s)
{
    if (s.empty())
        return 0;
    return 1 + length(s.substr(1));
}

int length_of_progression(string s)
{
    if (s.empty())
        return 0;
    return 1 + length_of_progression(s.substr(1));
}
