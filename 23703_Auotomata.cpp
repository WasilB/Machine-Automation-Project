#include <iostream>
#include <string>

using namespace std; 

int dfa = 0;


//function for starting state of DFA

void state1 (char c)
{
	if(c=='m')
	{
		dfa =5;
	}
	else if(c=='g')
	{
		dfa=2;
	}
	else if(c=='h')
	{
		dfa =4;
	}
	else 
	{
		dfa = -1;
	}
}


// function for state 2

void state2 (char c)
{
	if (c=='h')
	{
		dfa = 2;
	}
	else if(c =='g')
	{
		dfa = 3;
	}
	else if (c =='m')
	{
		dfa = 9;
	}
	else 
	{
		dfa = -1;
	}
	
}

// function for state 3
void state3 (char c)
{
	if ( c == 'g')
   {
	dfa =6;
   }
   
   else if ( c=='m'||c=='h')
   {
   	dfa = 9;
   }
   else
   {
   	 dfa = -1;
   } 
   

}


// function for state 4

void state4 (char c)
{
	if(  c == 'm')
	{
		dfa = 4;
	}
	
	else if (c == 'h')
	{
		dfa = 3;
	}
	
	else if ( c== 'g')
	{
		dfa = 9;
	}
	
	else 
	{
		dfa = -1;
	}
	
	
	
}


// function for state 5
void state5 (char c)
{
	if (c == 'g')
	{
		dfa = 5;
	}
	else if (c == 'h')
	{
		dfa =9;
	}
	else if ( c=='m')
	{
		dfa =3;
	}
	else
	{
		dfa = -1;
	}
}


// function for state 6
void state6 ( char c)
{
	if (c =='m')
	{
		dfa =7;
	}
	else if (c=='g'||c=='h')
	{
		dfa =9;
	}
	else
	{
		dfa = -1;
	}
	
	
}

//function for state 7

void state7 (char c)
{
	if(c=='g')
	{
		dfa =8;
	}
	else if (c=='m'||c=='h')
	{
		dfa = 9;
	}
	else 
	{
		dfa = -1;
	}
	
}

//function for state 8

void state8 (char c)
{
	if (c=='g'||c=='h'||c=='m')
	{
		dfa = 9;
	}
	else
	{
		dfa = -1;
	}
}

//function for dead state9
void state9 (char c)
{
	if (c=='g'||c=='h'||c=='m')
	{
		dfa = 9;
	}
	else
	{
		dfa = -1;
	}
	
}

int isAccepted(string str)
{
    // store length of string
    int i, len = str.length();
  
    for (i = 0; i < len; i++) {
        if (dfa == 0)
            state1(str[i]);
  
        else if (dfa == 2)
            state2(str[i]);
  
        else if (dfa == 3)
            state3(str[i]);
  
        else if (dfa == 4)
            state4(str[i]);
  
        else if (dfa == 5)
            state5(str[i]);
            
        else if (dfa == 6)
		state6(str[i]);
		
		else if (dfa ==7)
		state7(str[i]);
		
		else if (dfa == 8)
		state8(str[i]);
		
		else if(dfa == 9)
		state9(str[i]); 
            
        else
            return 0;
    }
    if (dfa == 8)
        return 1;
    else
        return 0;
}

int main()
{
	string choice = "y";
	
	while(choice == "y"||choice == "Y")
	{
		string s;
	cout<<"Enter your String: ";
	getline(cin,s);
	
	if (isAccepted(s))
        printf("Accepted!");
    else
        printf("Rejected!");
        
    dfa = 0; 
    cout<<endl<<"Press y to Enter another string: ";
    getline(cin,choice);
		
	}
	   

	return 0;
}