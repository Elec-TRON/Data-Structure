// C Programs multiplies two  linked lists l1 and l2 and returns their product


#define MOD 1000000007 ;
long long convert_in_number(node *) ;
long long  multiplyTwoLists (node* l1, node* l2)
{
    if(l1==NULL&&l2==NULL)
        return 0 ;
       
    long long no1,no2 ;
   
    no1=convert_in_number(l1) ;
    no2=convert_in_number(l2) ;
   
    return (no1*no2)%MOD ;
}

long long convert_in_number(node *head)
{
    long long num ;
    num=0 ;
   
    while(head!=NULL)
    {
        num=num*10+head->data ;
        num=num%MOD ;
        head=head->next ;
    }
    return num ;
}