
#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;


//   Creating a NODE Structure
struct node
{
    string data;
    struct node *next;
};


class stack
{
    struct node *top;
    public:
    stack() 
    {
        top=NULL;
    }
    void push(string value); 
    void pop();  
    void show(); 
};

void stack::push(string value)
{
    
    struct node *ptr;
    ptr=new node;
    ptr->data=value;
    ptr->next=NULL;
    if(top!=NULL)
        ptr->next=top;
    top=ptr;
    

}


void stack::pop()
{
    struct node *temp;
    if(top==NULL)
    {
        cout<<"nThe stack is empty!!!"<<endl;
    }
    temp=top;
    top=top->next;
    delete temp;
}

void stack::show()
{
    struct node *ptr1=top;
    while(ptr1!=NULL)
    {
        cout<<ptr1->data<<"->";
        ptr1=ptr1->next;
    }
    cout<<"NULL"<<endl;
}

int main()
{
    stack s;
    ifstream file;
    file.open("input.txt");
    string word;
    string pushDelimiter="@";
    string popDelimiter="*";
    string stopDelimiter1=",";
    string stopDelimiter2=".";
    while(file>>word)
	{
		if(pushDelimiter.compare(word)==0)
		{	
			file>>word;
			while(stopDelimiter1.compare(word)!=0 && stopDelimiter2.compare(word)!=0 )
			{
			  cout<<"Pushing elements in stack as it encountered a @ :"<<endl;
			  s.push(word);
			  file>>word;
			  s.show();
			}
		}
		if(popDelimiter.compare(word)==0)
		{
			cout<<"Poping element from the stack as it encountered a * :"<<endl;
			file>>word;
			s.pop();
			s.show();
		}
			
	}
		
    
    return 0;
}
