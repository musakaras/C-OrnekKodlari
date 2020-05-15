//security.h
////This is the header file for the Security class.
//  It validates a username and password.
#ifndef _SECURITY_H
#define __SECURITY_H_
#include <iostream>
#include <string>
using namespace std;
class Security{  
	public:     
		static int validate(string username, string password);
	};
#endif// *********************
  







//security.cpp//
//  This class validates a username and password.
//  It is only an example; it is not very secure.  For better
//  security, passwords would be encrypted and stored in a database
//  rather than hard-coded into the program.
// ***********************
#include <iostream>
#include <string>

using namespace std;
#include "security.h"


// **********
// Security::validate
// This subroutine hard-codes valid users and is not
// considered a secure practice.// It returns 0 if the credentials are invalid,
 //  1 if valid user, and
 //  2 if valid administrator
// ***********
	int Security::validate(string username, string password){ 
		 if ((username=="abbott") && (password=="monday"))
		 	 return 1;  
		 if ((username=="costello") && (password=="tuesday")) 
		 	return 2;  
		 return 0;
	}
	// **********************//  
	
	
	
	
	
	
	//administrator.h
	//  This is the header file for the Administrator class.
	//  If fully fleshed out it would have more method, but for
	//  purposes of this example there is a single method, Login,
	//  which returns true if a given username and password has
	//  admin clearance.// **********************// --------------------------------// ----- ENTER YOUR CODE HERE -----// -------------------------------- 
#ifndef ADMINSTRATOR_H
#define ADMINSTRATOR_H
#include <string>
#include <iostream>
using namespace std;
	
class Administrator{  
	public:      
	  Administrator();    
	  Administrator(string name, string password);      
	  bool login(string username, string password);  
	  
	private:      
	  string name;      
	  string password;
	};
 #endif
 
 
#include <string>
#include <iostream>
using namespace std;

include "Administrator.h" 
include "Security.h"

bool  Administrator::login(string username, string password){
	int valid=Security:: validate(username,password);
	if(valid==2)
		return true;
	return false;
}




//user.h

#ifndef USER_H
#define USER_H
#include <string>
#include <iostream>

include "Security.h"
using namespace std;

class User{  
	public:      
	  bool login(string username, string password);  
	};
#endif

 
 
 
 
 
 
 
 
 
 

