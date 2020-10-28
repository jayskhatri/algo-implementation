#include<iostream>
using namespace std;
void permutation_fun(string a, int l, int r);
int counter = 1;

int main() {
    string s1;
    cout << "Enter a string : ";
    cin >> s1;
    int sz = s1.size();
    cout << "\nAll possible permutations : \n";
    fun(s1, 0, sz - 1);
    return 0;

}

void fun(string a, int l, int r) {
    if (l == r) {
        cout << counter << "..." << a << endl;
        counter++;
    } else {
        for (int i = l; i <= r; i++) {
            swap(a[l], a[i]);
            fun(a, l + 1, r);
            swap(a[l], a[i]);
        }
    }
}
