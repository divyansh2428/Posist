
#include<bits/stdc++.h>
using namespace std;

/*class node{


};*/

const int MAX = 26;
char alphabet[MAX] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g',
                          'h', 'i', 'j', 'k', 'l', 'm', 'n',
                          'o', 'p', 'q', 'r', 's', 't', 'u',
                          'v', 'w', 'x', 'y', 'z' };



struct Node{


    float value;
    string timestamp,ownername,data;
    int nodeNumber,ownerid;
    string nodeId;
    Node *referenceNodeId;
    Node *genesisReferenceNodeId;
    string hashValue;



    /*void getdata(int a,string b,string c,string d,string e,string f)
    {
        nodeNumber=a;
        nodeId="asdasdadasdadsasd";

    }
    void showdata()
    {

    }
    void makeHash()
    {
        hashValue=1;
    }*/

    vector<Node*>child;
};

Node *newnode(int data)
{
    int i;
    Node *root=new Node();
    root->nodeNumber=data;
    root->ownerid=data;

    string res = "";
    for (i = 0; i<=31; i++)
        res = res + alphabet[rand() % MAX];

    root->nodeId=res;

    res="";
    for (i = 0; i<=2; i++)
        res = res + alphabet[rand() % MAX];

    root->ownername=res;

    time_t tt;

    // Declaring variable to store return value of
    // localtime()
    struct tm * ti;

    // Applying time()
    time (&tt);

    // Using localtime()
    ti = localtime(&tt);

     string date=asctime(ti);
    root->timestamp=date;

    string en="";
    en=root->ownername+char(root->value)+char(root->ownerid);
    long long int sum=0;

    for(i=0;i<en.length();i++)
        sum=sum+int(en[i]);
    int temp=sum;
    string x="";
    while(temp>0)
    {
        x=x+"a";
        temp=temp/10;
    }
    en=en+x;

    reverse(en.begin(),en.end());
    root->data=en;

    return root;
}
bool verifyowner(int ownerid,float value,string name,Node *root)
{
    int i;
    string check1=root->data;
    string en="";
    en=name+char(value)+char(ownerid);
    long long int sum=0;

    for(i=0;i<en.length();i++)
        sum=sum+int(en[i]);

    int temp=sum;
    string x="";
    while(temp>0)
    {
        x=x+"a";
        temp=temp/10;
    }
    en=en+x;

    reverse(en.begin(),en.end());
    if(en==check1)
        return true;
    else
        return false;

}

void edit(Node *root,int data)
{

    root->nodeNumber=data;
}
int height(Node *root)
{

    if(root==NULL)
        return 0;
    int ans=0,i;
    for(i=0;i<root->child.size();i++)
        return 1+max(ans,height(root->child[i]));
}
bool sum(Node *root)
{

    if(root==NULL)
        return 0;
    int sums=0,i;
    for(i=0;i<root->child.size();i++)
        sums=sums+sum(root->child[i]);

    return sum;
}
int main()
{
    int c=30;
     Node *root=newnode(c++);
     //Adding new node with value 43;
     int newvalue=10;
     //sum of child nodes value of a node
     if(root->value-sum(root)>newvalue)
        cout<<"Yes you can insert node as root child";
    else
        cout<<"No you can't insert node as root child";

    (root->child).push_back(newnode(c++));
    (root->child).push_back(newnode(c++));
    root->referenceNodeId=NULL;
    root->genesisReferenceNodeId=root;
    //parent address
    root->child[0]->referenceNodeId=root;
    root->child[1]->referenceNodeId=root;
    //genesis address
    root->child[0]->genesisReferenceNodeId=root;
    root->child[1]->genesisReferenceNodeId=root;


    // check if owner with owner id 1 is owner of root
    bool p=verifyowner(1,1,"div",root);
    if(p)
        cout<<"True owner";
    else
        cout<<"False Owner";

    //editing a node's properties example-nodeNumber
    edit(root->child[0],5);

    //finding longest chain from genesis/root
    int chain=height(root);
    cout<<chain<<endl;
    // finding longest chain from root
    int chains=height(root->child[0]);
    cout<<chains<<endl;

    //sum of child nodes value of a node
    cout<<sum(root);
    //merge two nodes

}
