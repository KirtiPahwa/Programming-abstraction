#include <iostream>
using namespace std;
int *func()
{
    int a = 2;
    return &a; // warning: address of local variable 'a' returned [-Wreturn-local-addr] . Compiler will give us the warning as we are return the address of the local var created in function. Bcz when func will return , memory allocated for the function will also be realesed and varaible's memory also.
}
void func2()
{
}
int main()
{
    int num = 9;
    int *p = func();
    cout << &num << endl;
    cout << &p << endl;
    func2();
    cout << *p << endl; // will give 0 or segemnt fault that depends on compiler behaviour  // as returning a's address will have nothing bcz this fun is over. So memory has beem released and local vairables has been destroyed. So it now poining to any value.

    return 0;
}

/* Memory stack:
main stack will have higher address in the memory
func() stack willl have lower address in the memory and will destroy after func willl be finished.(Once function memories has been realease, the same mermory can be used for some other functions also.)

Memory stack:
higher 0x61ff0c (higher address) ----there is main() stack
   |
   |
lower 0x61ff08 (lower address)  ----there is func() stack


*/
