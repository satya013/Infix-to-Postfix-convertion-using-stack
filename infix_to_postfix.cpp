#include<iostream>
#include<stack>  //for all stack implementation
#include<string>
#include<locale>  //to use   isalnum()
using namespace std;
int preced(char ch)      //to check precedence
{
	if(ch=='+'||ch=='-')
	     return 1;
	else if(ch=='*'||ch=='/')
		 return 2; 
	else if(ch=='^')     //higher precedence
		 return 3;
	else return	0; 	    
}

string inTopost(string infix)
{stack<char>stk;
stk.push('@');         //intially add any special char to point out end of stack
string postfix=" ";   //to store final postfix  expression
string::iterator it;  //to read infix expression character by character
for(it=infix.begin();it!=infix.end();it++)
{
	if(isalnum(char(*it)))  //if alphanumerical char simply add to postfix exp.
        postfix+=*it;

	else if(*it=='(')stk.push(*it);
	else if(*it==')')
		 {
		 	while(stk.top()!='@'&&stk.top()!=')')  //if ')' pop out untill encounter a '(' and add to postfix exp.
		 	  {
			    postfix+=stk.top();
		 	    stk.pop();
		      }
		       stk.pop();     //to pop out '('
		 }
		
	else 
		 {
		 	if(preced(*it)>preced(*it))   //if higher precedence than top of stck simply push it
                stk.push(*it);
            else
				{
					while(stk.top()!='@'&&preced(*it)<=preced(stk.top()))  //else pop out untill encounter an operator with lesser precedence
					{
						postfix+=stk.top();
						stk.pop();
					}
					stk.push(*it);   //then push the new operator
					}    
		 }
}
while(stk.top()!='@')  //pop out and add to postfix exp. if there is any operator left
{
	postfix+=stk.top();
	stk.pop();
}
return postfix;
}

int main()
{
	string infix;
	cout<<"Enter the infix expression : \n";
	getline(cin,infix);
	cout<<"Postfix expression : ";
	cout<<inTopost(infix);
}
