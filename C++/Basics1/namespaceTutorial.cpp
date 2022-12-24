#include<iostream>
// instead of use the namespace std we can just use cout and cin also
// using namespace std;
// or
using std::cout;
using std::endl;
using std::cin;

namespace first_space {
   void func() {
      cout << "Inside first_space" << endl;
   }
}

// second name space
namespace second_space {
   void func() {
      cout << "Inside second_space" << endl;
   }
}

int main () {
   // Calls function from first name space.
   first_space::func();
   
   // Calls function from second name space.
   second_space::func(); 

   return 0;
}
