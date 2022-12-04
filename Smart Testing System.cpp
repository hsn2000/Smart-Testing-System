#include <iostream>
#include<fstream>
#include<string>
#include<windows.h>
#include<conio.h>
// #include <bits/stdc++.h> 
using namespace std;
void setcolor(unsigned short color)
{
	HANDLE hndl= GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hndl,color);
}
int numOfQuestions;
class node
{
	public:
    string question;
    string a;
    string b;
    string c;
    string d;
    char ans;
    int precedence;
	int Correct;
	int Attempts;
    node *next;
};
class student
{
	public:
		string name;
		string id,mode;
		int score;
		student* next;
		student(){
			score=0;
			name=" ";
		}
};
class student_list
{
	public:
		student* head;
		student_list()
		{
			head= NULL;
		}
		void add_record(string n,string i,string mode, int sc)
		{
			student *tmp = new student;;
        	tmp->name=n;
        	tmp->id=i;
        	tmp->score=sc;
        	tmp->mode=mode;
        	tmp->next = NULL;
        	student *tmp2 = head;
        if(tmp2 == NULL)
        {
            head = tmp;
        }
        else
        {
        	while(tmp2->next)
        	{
        		tmp2=tmp2->next;
			}
			tmp2->next = tmp;
        }
		}
		
		void selection_sort()
		{
			student *temp=head;
			while(temp->next!=NULL)
			{
				student *min=temp;
				student *temp1=temp;
				while(temp1 != NULL)
				{
					if(min->score < temp1->score)
					{
						min = temp1;
					}
					temp1=temp1->next;
				}
				swap(min->score,temp->score);
				swap(min->name,temp->name);
				swap(min->id,temp->id);
				swap(min->mode,temp->mode);
				temp=temp->next;
				
			}
		}
		void traverse1()
		{
			student *temp=head;
			while(temp!=NULL)
			{
				cout <<"\n "<<temp->name<<"\t"<<temp->score;
				temp=temp->next;
			}
		}
		void count(string s)
		{
			student *temp =head;
			int cnt=0;
			while(temp!=NULL)
			{
				if(temp->mode==s)
				{
					cnt++;
				}
				temp=temp->next;
			}
			cout <<cnt;
		}
		void Number_of_attempts()
		{
			student *temp =head;
			int cnt=-1;
			while(temp!=NULL)
			{
				cnt++;
				temp=temp->next;
			}
			cout <<cnt;
		}
		void top_three(string s)
		{
			student* temp = head;
			int j=1;
			while(temp!=NULL && j<4)
			{
				if(temp->mode==s)
				{
					cout <<"\n"<<j<<") "<< temp->name<<"  "<<temp->id<<"   "<<temp->score;
					j++;
				}
				temp=temp->next;
			}
		}
};
class bstnode
{
	public:
	bstnode* left;
	bstnode* right;
	string name;
	string id;
	int marks;
	string level;
	bstnode(int m,string l,string nm,string i){
		left=NULL;
		right=NULL;
		marks=m;
		level=l; 
		name=nm; 
		id=i;
	}
};
class BST
{
	public:
	bstnode* insert(bstnode* root,int sc,string lvl,string nm,string i)
	{
		if(root==NULL){
		bstnode* temp=new bstnode(sc,lvl,nm,i);
		root=temp;	
		return root;
		}
		if(root->marks>sc){
			root->left=insert(root->left,sc,lvl,nm,i);			
		}else{
			root->right=insert(root->right,sc,lvl,nm,i);
		}
		return root;
	}
	void inorder(bstnode* root,string str)
	{
		if(root!=NULL){
			inorder(root->left,str);
			if(str==root->level){
			cout<<endl<<"Name:"<<root->name<<endl<<"ID:"<<root->id<<endl<<"Score:"<<root->marks<<endl<<"level:"<<root->level<<endl;
			}
			inorder(root->right,str);
		}
	}
};


class Queue
{
	node* head;
	node* last;
	public:
	Queue() 
	{
		last=NULL;
	}
    void EnQueue(string question,string a,string b,string c,string d,char ans)
	{ 
        if (last == NULL) 
        {
			node *tmp = new node;
			tmp->question = question;
			tmp->a = a;
			tmp->b = b;
			tmp->c = c;
			tmp->d = d;
			tmp->ans = ans;
            last = tmp; 
            last -> next = last; 
	    } 
	    else
        {
			node *tmp = new node;
			tmp->question = question;
			tmp->a = a;
			tmp->b = b;
			tmp->c = c;
			tmp->d = d;
			tmp->ans = ans;
            tmp -> next = last -> next; 
            last -> next = tmp; 
            last = tmp; 
        }
	} 
	void traverse() 
	{ 
        node *temp=new node();
        if (last == NULL) 
        { 
            cout << "List is empty." << endl; 
            return; 
        } 
        temp = last -> next;
        do{
            cout<<"Q-> ";
            cout<<temp->question;
            cout<<endl;
            cout<<temp->a<<"     "<<temp->b<<"     \n"<<temp->c<<"     "<<temp->d;
            cout<<endl;
			cout<<"Correct Answer: "<<temp->ans;
            temp=temp->next;
            cout<<endl;
	    }
        while(temp != last->next);
    }
};
class linked_list
{
	private:
    node *head;
	student stdnt;
	public:
    node* ReturnHead()
    {
        return head;
    }
    linked_list()
    {
        head = NULL;
    } 
    void get_head()
    {
    	node* temp=head;
    	cout<<"Q"<<"-> ";
        cout<<temp->question;
        cout<<endl;
        cout<<temp->a<<"     "<<temp->b<<"     \n"<<temp->c<<"     "<<temp->d;
		cout<<"\n\n Correct Attempts: "<<temp->Correct;
        cout<<"\n\n Total Attempts: "<<temp->Attempts;
        cout<<endl;
	}
	void get_tail()
	{
		node* temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		cout<<"Q"<<"-> ";
        cout<<temp->question;
        cout<<endl;
        cout<<temp->a<<"     "<<temp->b<<"     \n"<<temp->c<<"     "<<temp->d;
        cout<<"\n\n Precedence: "<<temp->precedence;
		cout<<"\n\n Correct Attempts: "<<temp->Correct;
        cout<<"\n\n Total Attempts: "<<temp->Attempts;
        cout<<endl;		
	}
    void add_node_at_front(string question,string a,string b,string c,string d,char ans,int precedence,int Correct,int Attempts)
    {
        node *tmp = new node;
        tmp->question = question;
        tmp->a = a;
        tmp->b = b;
        tmp->c = c;
        tmp->d = d;
        tmp->ans = ans;
        tmp->precedence = precedence;
		tmp->Correct = Correct;
		tmp->Attempts = Attempts;
        tmp->next = head;
        head= tmp;
    }
    void add_node_at_last(string question,string a,string b,string c,string d,char ans,int precedence,int Correct,int Attempts)
    {
    	node *tmp = new node;
        tmp->question = question;
        tmp->a = a;
        tmp->b = b;
        tmp->c = c;
        tmp->d = d;
        tmp->ans = ans;
        tmp->precedence = precedence;
		tmp->Correct = Correct;
		tmp->Attempts = Attempts;
        tmp->next = NULL;
        node *tmp2 = head;
        if(tmp2 == NULL)
        {
            head = tmp;
        }
        else
        {
        	while(tmp2->next)
        	{
        		tmp2=tmp2->next;
			}
			tmp2->next = tmp;
        }
	}
    void CheckPrecedence()
    {
        node *temp=new node();
        temp=head;
        while(temp!=NULL)
        {
            temp=temp->next;
        } 
    }
    void Sort()
    {
        node* temp1=new node();
        node* temp2=new node();
        node* min=new node();
        for(temp1=head;temp1!=NULL;temp1=temp1->next)
        {
            min=temp1;
            for(temp2=temp1;temp2!=NULL;temp2=temp2->next)
            {
                if(temp2->precedence>min->precedence)
                min=temp2;
            }
            string t1=temp1->question;
            temp1->question=min->question;
            min->question=t1;
            string t2=temp1->a;
            temp1->a=min->a;
            min->a=t2;
            string t3=temp1->b;
            temp1->b=min->b;
            min->b=t3;
            string t4=temp1->c;
            temp1->c=min->c;
            min->c=t4;
            string t5=temp1->d;
            temp1->d=min->d;
            min->d=t5;
            char t7=temp1->ans;
            temp1->ans=min->ans;
            min->ans=t7;
            int t6=temp1->precedence;
            temp1->precedence=min->precedence;
            min->precedence=t6;
            int t8=temp1->Correct;
            temp1->Correct=min->Correct;
            min->Correct=t8;
            int t9=temp1->Attempts;
            temp1->Attempts=min->Attempts;
            min->Attempts=t9;
        }
    }
    void PutToFile()
    {
        ofstream outfile;          
        outfile.open("questions.txt");
        if(!outfile)
        cout << "FILE NOT OPENED";
		outfile<<numOfQuestions;
		outfile<<endl;
        node *temp=new node();
        temp=head;
        while(temp!=NULL)
        {
            outfile<<temp->question;
            outfile<<endl;
            outfile<<temp->a<<" "<<temp->b<<" "<<temp->c<<" "<<temp->d<<" "<<temp->ans<<" "<<temp->precedence<<" "<<temp->Correct<<" "<<temp->Attempts;
            outfile<<endl;
            temp=temp->next;
        }
        outfile.close();
if(stdnt.name!=" "){
        ofstream fout;
        fout.open("studentrecord.txt",ios::app);
        if(!fout){
        	cout<<endl<<"ERROR in opening file";
		}
			fout<<stdnt.name<<" "<<stdnt.id<<" "<<stdnt.score<<" "<<stdnt.mode;
			fout<<endl;
		fout.close();
		}
    }
void level()
{
	int op,size=0; 
	Queue correct;
	Queue incorrect;
	system("cls");
	string lvl[]={"DIFFICULT","MEDIUM","EASY"};
	cout<<endl<<"Enter your Name:"; cin>>stdnt.name;
	cout<<endl<<"Enter your ID:";cin>>stdnt.id;
	cout<<endl;
	setcolor(12);
	cout<<"1."<<lvl[0];
	setcolor(11);
	cout<<"\n2."<<lvl[1];
	setcolor(10);
	cout<<"\n3."<<lvl[2];
	setcolor(15); cout<<"\nSELECT ONE:";
	cin>>op;
	stdnt.mode=lvl[op-1];
	size=numOfQuestions;
	int start,end;
	int loops=size/3;
	start=op-1;
	start=start*10;
	end=op*10;
	if(size%3!=0)
	{
		if(op==3)
		{
			start=op-1;
			start=start*10;
			end=size;
			loops=size%3+loops;
		}
	}
	int i=0;
	node* tmp=new node(); tmp=head;
	while(i!=start)
	{
		tmp=tmp->next;
		i++;
	}
	int j=0;
	setcolor(op+3);
	while(i!=end)
	{
		tmp->Attempts=tmp->Attempts+1;
		repeat:
		system("cls");
		cout<<"Q"<<j+1<<"-> ";
            cout<<tmp->question;
            cout<<endl;
            cout<<tmp->a<<"     "<<tmp->b<<"     \n"<<tmp->c<<"     "<<tmp->d;
            cout<<endl;
            char answer=toupper(getch());
			if(answer==tmp->ans){
                stdnt.score+=10;
				tmp->Correct++;
				correct.EnQueue(tmp->question,tmp->a,tmp->b,tmp->c,tmp->d,tmp->ans);
				}
            else{
				if(answer=='A'||answer=='B'||answer=='C'||answer=='D')
				{
					tmp->precedence++;
					incorrect.EnQueue(tmp->question,tmp->a,tmp->b,tmp->c,tmp->d,tmp->ans);
				}
				else
				goto repeat;
				}
            cout<<endl;
			i++;
			j++;
			tmp=tmp->next;
}
	system("cls");
	cout<<"\n\n\n\t\t\t\t\tYour Test Report";
	cout<<"\n\n\t\t\tYour Correct Questions were:\n\n";
	correct.traverse();
	cout<<"\n\n\t\t\tYour Incorrect Questions were:\n\n";
	incorrect.traverse();
	cout<<"\n\n\n\t\t\t\t\tStudent Result\n";
	cout<<stdnt.name<<" you have scored "<<stdnt.score<<" in "<<stdnt.mode<<" mode";
	if(stdnt.score<50)
	{
		cout<<"\nYou have scored below average marks";
		cout<<"\nYou better start preparing for the Fast admission Test as it is not an easy one :)";
		cout<<"\nYou can again prefer us with different difficully modes for better preperation for the test anytime :)";
	}
	else
	{
		cout<<"\nCongratulations!! You have scored above average marks";
		cout<<"\nHow about solving our test again with difficulty level more high? :)";
		cout<<"\nYou can again prefer us with different difficully modes for better preperation for the test anytime :)";
	}
	cout<<"\t\t\nThank You For Using Our Test Preperation Program!\n\n\n";
}
    void Display()
    {
		int i=1;
        node *temp=new node();
        temp=head;
        while(temp!=NULL)
        {
            cout<<"Q"<<i<<"-> ";
            cout<<temp->question;
            cout<<endl;
            cout<<temp->a<<"     "<<temp->b<<"     \n"<<temp->c<<"     "<<temp->d;
            temp=temp->next;
            cout<<endl;
			i++;
        }   
	}
		void DeleteQuestion()
		{
			int num;
			Display();
			cout<<"\n\n Which question do you want to delete?\nEnter question number: ";
			cin>>num;
			node *temp=new node();
       		temp=head;
			int count=1;
			if(num==1)
			{
				head=head->next;
			}
			else
			{
				while(count!=(num-1))
				{
					count++;
					temp=temp->next;
				}
				temp->next=temp->next->next;
			}
			numOfQuestions--;
			PutToFile();
			cout<<"The question was succesfully deleted! ";
		}
};
class hashing
{
	public:
	student *array;
	int hash;
	hashing()
	{
		array=new student[100];
		for(int i=0;i<100;i++)
		array[i].id=" ";
		hash=31;
	}
	
	int hashfunc(string s)
	{
		int sum=0;
		for(int i=0;i<s.length();i++)
		{
			sum+=s[i];
		}
		sum=sum%hash;
		return sum;
	}
	void insert()
	{
		string nm,i,lvl;
		int sc,pos;
		ifstream file;
		file.open("studentrecord.txt");
		while(file>>nm>>i>>sc>>lvl)
		{
			pos=hashfunc(i);
			int k=0,j=pos;
			while(array[pos].id!=" ")
			{
				pos=(pos+k)%hash;
				k++;j++;
				if(j==100)
				break;
			}
			if(j==100)
			{
				cout<<endl<<"full";
			}
			else
			{
				array[pos].id=i;
				array[pos].mode=lvl;
				array[pos].name=nm;
				array[pos].score=sc;
			}		
		}
		file.close();
	}
	void display()
	{
		for(int i=0;i<100;i++)
		{
			if(array[i].id!=" ")
			{
				cout<<"Name: "<<array[i].name<<" ID:"<<array[i].id<<"score: "<<array[i].score<<"mode: "<<array[i].mode;
				cout<<endl;
			}
			
		}
	}
	void search(string val)
	{
		int pos=hashfunc(val);
		int i=0,j=0;
		while(array[pos].id!=val){
			pos=(pos+i)%hash;
			i++;
			j++;
			if(j==100)
			break;
		}
		if(j==100){
			cout<<endl<<"not found";
		}else{
			cout<<"Name: "<<array[pos].name<<" ID: "<<array[pos].id<<" score: "<<array[pos].score<<" mode: "<<array[pos].mode<<endl;
		}

	}
};
class admin
{
	public:
		int d;
		string Password;
		linked_list A;
		student_list B;
		
		admin()
		{
			d=1111;
			Password="admin";
			ifstream file;          
			file.open("questions.txt");
			if(!file)
			cout << "FILE NOT OPENED";
			string temp;
			string a;
			string b;
			string c;
			string d;
			int NumOfCorrect;
			int NumOfAttempts;
			char ans;
			int precedence;
			file>>numOfQuestions;
			getline(file,temp);
			for(int i=0;i<numOfQuestions;i++) 
			{
					getline(file,temp);
					file>>a;
					file>>b;
					file>>c;
					file>>d;
					file>>ans;
					file>>precedence;
					file>>NumOfCorrect;
					file>>NumOfAttempts;
					A.add_node_at_last(temp,a,b,c,d,ans,precedence,NumOfCorrect,NumOfAttempts);
					getline(file,temp);
			}
			file.close();
			ifstream ifile;          
			ifile.open("studentrecord.txt");
			if(!ifile)
			cout << "FILE NOT OPENED";
			string na;
			string iden;
			int sc;
			string mo;
			while(!(ifile.eof())) 
			{
					ifile >> na >> iden >> sc >> mo;
					B.add_record(na,iden,mo,sc);
						
			}
			ifile.close();
			B.selection_sort();
			int ch;
			cout << "\n\n\t\t\t\t Welcome To FAST Student-Guide Testing system";
			system("color 0B");
			cout << "\n 1. Student";
			cout << "\n 2. Admin";
			cout << "\n Press any other button to exit";
			cout << "\n Your Choice: ";
			cin >> ch;
			if(ch==1)
			{
				A.level();
				A.Sort();
				A.PutToFile();
			}
			else if(ch==2)
			{
				security();
			}
			else
			{
				cout <<"\n Thank you for visiting";
			}
		}
		void security()
		{
			int i;
			string p;
			system("cls");
			cout <<"\t\t\t\tPlease Verify Yourself";
			cout <<"\nEnter ID: ";
			cin >> i;
			cout <<"Enter Password: ";
			cin >> p;
			if(i==d && p==Password)
			{
				admin_menu();
			}
			else
			{
				cout <<"\n Invalid ID or Password";
				security();
			}
		}
		void admin_menu()
		{
			int choice;
			do
			{
				setcolor(143);
				system("cls");
				
				cout <<"\n\t\t\t\tWelcome to Admin Panel";
				
				cout<<endl<<char(218)<<"-----------------------------------"<<char(191);
				cout <<"\n| 1. Add a Question                 |";
				cout<<endl<<char(195)<<"-----------------------------------"<<char(180);
				cout <<"\n| 2. Delete a Question              |";
				cout<<endl<<char(195)<<"-----------------------------------"<<char(180);
				cout <<"\n| 3. Get top 3 scorers              |";
				cout<<endl<<char(195)<<"-----------------------------------"<<char(180);
				cout <<"\n| 4. Get most difficult question    |";
				cout<<endl<<char(195)<<"-----------------------------------"<<char(180);
				cout <<"\n| 5. Get most easy question         |";
				cout<<endl<<char(195)<<"-----------------------------------"<<char(180);
				cout <<"\n| 6. Get a summary report           |";
				cout<<endl<<char(195)<<"-----------------------------------"<<char(180);
				cout <<"\n| 7. Search a student by ID         |";
				cout<<endl<<char(195)<<"-----------------------------------"<<char(180);
				cout <<"\n| 0. Exit Program                   |";
				cout<<endl<<char(192)<<"-----------------------------------"<<char(217);
				cout << "\n Your Choice: ";
				cin >> choice;

				switch(choice){
					case 1:
						{
							system("cls");
							string a="A.",b="B.",c="C.",d="D.";
							string a1,b2,c3,d4;
							char an;
							char array[100];
							cout <<"\n Enter Question:\n";
							cin.getline(array,100);
							cin.getline(array,100);
							string q=array;
							cout <<"\n Enter option a:\n";
							cin >> a1;
							cout <<"\n Enter option b:\n";
							cin >> b2;
							cout <<"\n Enter option c:\n";
							cin >> c3;
							cout <<"\n Enter option d:\n";
							cin >> d4;
							cout <<"\n Enter the correct option(a/b/c/d)\n";
							an=toupper(getch());
							a=a+a1;
							b=b+b2;
							c=c+c3;
							d=d+d4;
							A.add_node_at_last(q,a,b,c,d,an,0,0,0);
							numOfQuestions++;
							A.PutToFile();
							cout<<"\nQuestion was successfully added!";
							cout<<"\n\n\t\tPress Any key to go back.";
							getch();
						}
						break;
					case 2:
						system("cls");
						A.DeleteQuestion();
						cout<<"\n\n\t\tPress Any key to go back.";
						getch();
						break;
					case 3:
						system("cls");
						get_top_three();
						cout<<"\n\n\t\tPress Any key to go back.";
						getch();
						break;
					case 4:
						system("cls");
						A.get_head();
						cout<<"\n\n\t\tPress Any key to go back.";
						getch();
						break;
					case 5:
						system("cls");
						A.get_tail();
						cout<<"\n\n\t\tPress Any key to go back.";
						getch();
						break;
					case 6:
						system("cls");
						report();
						criteriamatch();
						cout<<"\n\n\t\tPress Any key to go back.";
						getch();
						break;
					case 7:
						system("cls");
						string val;
						hashing h;
						h.insert();
						cout<<endl<<"enter student ID:";
						cin>>val;
						h.search(val);
						cout<<"\n\n\t\tPress Any key to go back.";
						getch();
						break;				
					}
			}while(choice);
		}
		void get_top_three()
		{
			int ch;
			system("cls");
			cout <<"\n Select difficulty mode";
			cout <<"\n 1. EASY MODE";
			cout <<"\n 2. MEDIUM MODE";
			cout <<"\n 3. DIFFICULT MODE\n";
			cout << " Your Choice: ";
			cin >> ch;
			if(ch==1)
			{
				B.top_three("EASY");
			}
			else if(ch==2)
			{
				B.top_three("MEDIUM");
			}
			else if(ch==3)
			{
				B.top_three("DIFFICULT");
			}
			else
			{
				cout <<"\n Invalid option try again press any button to continue";
				getch();
				get_top_three();
			}
		}
		void report()
		{
			cout <<"\n \t\t\t REPORT";
			cout <<"\n\t\t Total Number of Tests: ";
			B.Number_of_attempts();
			cout <<"\n\n\t\tMost Difficult Question yet:\n";
			A.get_head();
			cout <<"\n\t\t Most Easiest Question yet: \n ";
			A.get_tail();
			cout <<"\n\n\t\t Number of easy attempts: ";
			B.count("EASY");
			cout <<"\n\t      Top Scoreers of easy category are: \n";
			B.top_three("EASY");
			cout <<"\n\n\t\t Number of medium attempts: ";
			B.count("MEDIUM");

			cout <<"\n\t      Top Scoreers of medium category are: \n";
			B.top_three("MEDIUM");
			cout <<"\n\n\t\t Number of hard attempts: ";
			B.count("DIFFICULT");
			cout <<"\n\t      Top Scoreers of hard category are: \n";
			B.top_three("DIFFICULT");
		}
		void criteriamatch()
		{
			int sc;
			string nm,lvl,i;
			BST tree;
			bstnode* first=NULL;
			ifstream fin("studentrecord.txt",ios::in);
			first=tree.insert(first,50," "," "," ");
			while(fin >> nm >> i >> sc >> lvl)
			{
				tree.insert(first,sc,lvl,nm,i);
			}
			fin.close();
			cout<<endl<<"\t\tIN EASY MODE:";
			cout<<endl<<"\tStudents who scored below criteria:";
			tree.inorder(first->left,"EASY");
			cout<<endl<<"\tStudents who scored above criteria:";
			tree.inorder(first->right,"EASY");
			cout<<endl<<"\n\t\tIN MEDIUM MODE:";
			cout<<endl<<"\tStudents who scored below criteria:";
			tree.inorder(first->left,"MEDIUM");
			cout<<endl<<"\tStudents who scored above criteria:";
			tree.inorder(first->right,"MEDIUM");
			cout<<endl<<"\n\t\tIN DIFFICULT MODE:";
			cout<<endl<<"\tStudents who scored below criteria:";
			tree.inorder(first->left,"DIFFICULT");
			cout<<endl<<"\tStudents who scored above criteria:";
			tree.inorder(first->right,"DIFFICULT");
		}
};

main()
{
    admin D;
}

