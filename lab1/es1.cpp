#include <iostream>
using namespace std;

int calls = 0;
int global_initialized = 5;
int global_uninitialized;

void fibonacci(int x, int y, vector<int> &v, int n){
    v.clear();
    v.push_back(x);
    v.push_back(y); 

    for (int i = 2; i < n; i++)
        v.push_back(v[i-1] + v[i-2]);
}

void print(string &out, vector<int> &v){
    cout << out;
    for (int i: v)
        cout << i << " ";
    cout << endl;
}

void call_counter(){
    cout << calls++ << " ";
}

int main(int argc, char *argv[])
{
    int local_automatic;
    static int local_static_initialized = 10;
    static int local_static_uninitialized;
    string str("v1 = ");
  
    vector<int> v1;
    fibonacci(0, 1, v1, 20); // fibonacci(x, y, v, n)
    print(str, v1);

    while(true)
        call_counter();
    return 0;
}