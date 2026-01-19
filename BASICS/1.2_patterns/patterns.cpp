#include<bits/stdc++.h>
using namespace std;

void pattern1(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}
void pattern2(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}
void pattern3(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            cout << j+1<<" ";
        }
        cout << endl;
    }
}
void pattern4(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            cout << i+1<<" ";
        }
        cout << endl;
    }
}
void pattern5(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n-i; j++) {
            cout <<"* ";
        }
        cout << endl;
    }
}
void pattern6(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n-i; j++) {
            cout << j+1 <<" ";
        }
        cout << endl;
    }
}
void pattern7(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n-(i+1); j++) {
            cout <<" ";
        }
        for(int k = 0; k < (2*(i+1))-1; k++) {
            cout << "*";
        }
        cout << endl;
    }
}
void pattern8(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <i; j++) {
            cout <<" ";
        }
        for(int k = 0; k < (2*(n-i))-1; k++) {
            cout << "*";
        }
        cout << endl;
    }
}
void pattern9(int n)
{
    for (int i = 0; i < 2 * n; i++)
    {
        if (i < n)
        {
            for (int j = 0; j < n - (i + 1); j++)
            {
                cout << " ";
            }
            for (int k = 0; k < (2 * (i + 1)) - 1; k++)
            {
                cout << "*";
            }
            cout << endl;
        }

        else
        {
            for (int j = 0; j < i - n; j++)
            {
                cout << " ";
            }
            for (int k = 0; k < 4 * n - (2 * i + 1); k++)
            {
                cout << "*";
            }
            cout << endl;
        }
    }
}
void pattern10(int n)
{
    for (int i = 0; i < 2 * n; i++)
    {
        int stars = i < n ? i + 1 : 2 * n - (i + 1);
        for (int j = 0; j < stars; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void pattern11(int n)
{
    for (int i = 1; i <= n; i++)
    {
        int stars = i % 2 ==0 ? 0 : 1;
        for (int j = 0; j < i; j++)
        {
            cout << stars;
            stars = 1-stars;
        }
        cout << endl;
    }
}
void pattern12(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j;
        }
        for (int j = 1; j <= 2*n-2*i; j++)
        {
            cout << " ";
        }
        for (int j = i; j >= 1; j--)
        {
            cout << j;
        }
        cout << endl;
    }
}
void pattern13(int n)
{
    int numbers = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << numbers << " ";
            numbers += 1;
        }
        cout << endl;
    }       
}
void pattern14(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (char ch = 'A'; ch <= 'A'+i; ch++)
        {
            cout << ch << " ";
        }
        cout << endl;
    }       
}
void pattern15(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (char ch = 'A'; ch <= 'A'+n-(i+1); ch++)
        {
            cout << ch << " ";
        }
        cout << endl;
    }       
}
void pattern16(int n)
{
    char start = 'A';
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << start << " ";
        }
        cout << endl;
        start++;
    }       
}
void pattern17(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n-(i+1); j++) {
            cout <<" ";
        }
        char ch = 'A';
        int breakpoint = (2*i+1)/2;
        for(int k = 0; k < 2*i+1; k++) {
            cout << ch;
            if(k < breakpoint) {
                ch++;
            } else {
                ch--;
            }
        }
        cout << endl;
    }
}
void pattern18(int n) {
    for (int i = 0; i < n; i++)
    {
        char ch = 'A' + n - i - 1;
        for (int j = 0; j < i + 1; j++)
        {
            cout << ch;
            ch++;
        }
        cout << endl;
    }
}
void pattern19(int n)
{
    // int spaces = 0;
    for (int i = 0; i < 2 * n; i++)
    {
        int stars = i < n ? n-i: i-n+1;
        int spaces = i < n ? 2*i :4*n-2*i-2; ;
        //star
        for (int j = 0; j < stars; j++)
        {
            cout << "*";
        }
        //spaces
        for (int j = 0; j <spaces; j++)
        {
            cout << " ";
        }
        //star
        for (int j = 0; j < stars; j++)
        {
            cout << "*";
        }

        // if(i<n) spaces += 2;
        // else spaces -= 2;
        cout << endl;
    }
}
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        // pattern1(n);
        // pattern2(n);
        // pattern3(n);
        // pattern4(n);
        // pattern5(n);
        // pattern6(n);
        // pattern7(n);
        // pattern8(n);
        // pattern9(n);
        // pattern10(n);
        // pattern11(n);
        // pattern12(n);
        // pattern13(n);
        // pattern14(n);
        // pattern15(n);
        // pattern16(n);
        // pattern17(n);
        // pattern18(n);
        pattern19(n);
    }
    return 0;
}