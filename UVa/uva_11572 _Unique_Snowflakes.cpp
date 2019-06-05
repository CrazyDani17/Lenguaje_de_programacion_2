#include <iostream>
#include <set>
using namespace std;

int main()
{
    int n;
    int n_snowflakes;
    int code_snowflakes;
    set <int> set_snowflakes;
    cin>>n;
    while(n>0){
        cin>>n_snowflakes;
        while(n_snowflakes>0){
            cin>>code_snowflakes;
            if(code_snowflakes<=109 && code_snowflakes>=0){
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
