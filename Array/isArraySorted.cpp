#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> v(n);
    for (int &x : v) {
        cin >> x;
    }

    bool isSorted = true;
    for (int i = 1; i < n; ++i) {
        if (v[i] < v[i - 1]) {
            isSorted = false;
            break;
        }
    }

    cout << (isSorted ? "YES" : "NO") << '\n';
    
    return 0;
}