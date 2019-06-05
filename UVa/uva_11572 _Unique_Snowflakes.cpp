#include <iostream>
#include <set>
using namespace std;

int main()
{
    long long n;
    long long n_snowflakes;
    long long code_snowflakes;
    set <long long> set_snowflakes;
    cin>>n;
    while(n>0){
        cin>>n_snowflakes;
        while(n_snowflakes>0){
            cin>>code_snowflakes;
            if(code_snowflakes<=1000000000 && code_snowflakes>=0){
                set_snowflakes.insert(code_snowflakes);
            }
            n_snowflakes--;
        }
        cout<<set_snowflakes.size()<<endl;
        set_snowflakes.clear();
        n--;
    }
    return 0;
}
