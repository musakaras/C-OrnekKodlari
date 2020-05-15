//file: f.hnamespace A{  void f();}
//file g.hnamespace B{  void g();}
//file f.cpp
#include <iostream>
namespace A{  
	void f(){ 
		std::cout << "A::f() called\n"; }
}

//file g.cpp
#include <iostream>
namespace B{  
	void g(){ std::cout << "B::g() called\n";
	}
}

//To create a namespace or to add to an already created namespace, use a namespace grouping. You can split the definition across files. The declaration and definition of the function void f() follows.

//file: f.hnamespace A{  void f();}One can place the definition of void f() in a namespace grouping, in a separate file if need be. (We are directed by the problem statement to do so here.)

//file f.cpp
#include <iostream>
namespace A{  
	void f(){ std::cout << "A::f() called\n"; 
	}
}

//To be able to call a function defined in your own namespace, you must provide for declarations of the functions prior to the call. This is done with the lines of code, #include "f.h" and #include "g.h". You then separately compile the .cpp  files that contain the function definitions, then link, as the compile command in the file listed here.



//File: main.cpp
//Compile command: bcc32 main.cpp f.cpp g.cpp
#include "f.h"
#include "g.h"
int main(){  
	A::f();  
	B::g(); 
	return 0;
}
