#include<iostream>
#include <bits/stdc++.h>
#include<stack>
#include<iterator>
#include <list>
#include<fstream>
using namespace std;
stack<int>remov;
list<int>letter;
string one,two,three,four;
int scoreone=0,scoretwo=0,scorethree=0,scorefour=0;

char alphabet[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g',
						'h', 'i', 'j', 'k', 'l', 'm', 'n',
						'o', 'p', 'q', 'r', 's', 't', 'u',
						'v', 'w', 'x', 'y', 'z' };
string b[100]={"1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19","20",
					"21","22","23","24","25","26","27","28","29","30","31","32","33","34","35","36","37",
					"38","39","40","41","42","43","44","45","46","47","48","49","50","51","52","53","54",
					"55","56","57","58","59","60","61","62","63","64","65","66","67","68","69","70","71",
					"72","73","74","75","76","77","78","79","80","81","82","83","84","85","86","87","88",
					"89","90","91","92","93","94","95","96","97","98","99","100"};
int main1();
void instructions()
{
	char m;
	cout<<"Below are the point values for each letter that is used in a Scrabble game\n0 Points - Blank tile"<<endl;
	cout<<"1 Point - A, E, I, L, N, O, R, S, T and U\n";
	cout<<"2 Points - D and G\n";
	cout<<"3 Points - B, C, M and P\n";
	cout<<"4 Points - F, H, V, W and Y\n";			
	cout<<"5 Points - K\n";
	cout<<"8 Points - J and X\n";
	cout<<"10 Points - Q and Z\n";			
	cout<<"Press 0 to Pass\n";
	cout<<"Press G to end the game\n";
	cout<<"Press H to go to Home E to End The Program:";
	cin>>m;
	if(m=='H')
	main1();
}
typedef struct trie
{
	trie *child[26];
	bool isEndOfWord;
}trie;

trie *getNode()
{
	trie *temp=new trie;
	for(int i=0;i<26;i++)
		temp->child[i]=NULL;
	temp->isEndOfWord=false;
	return temp;
}
void insert(trie *root,string key)
{
	trie *node=root;
	for(int i=0;i<key.length();i++)
	{
		int n=key[i]-'a';
		if(!node->child[n])
		{
			node->child[n]=getNode();
		}
		node=node->child[n];
	}
	node->isEndOfWord=true;
}
bool change(trie *root,string key)
{
	trie *node=root;
	for(int i=0;i<key.length();i++)
	{
		int k=key[i]-'a';
		if(!node->child[k])
			return false;
		
		node=node->child[k];
	}
	node->isEndOfWord=false;
}
bool search(string key,trie *root)
{
	trie *node=root;
	for(int i=0;i<key.length();i++)
	{
		int k=key[i]-'a';
		if(!node->child[k])
			return false;
		
		node=node->child[k];
	}
	return(node!=NULL && node->isEndOfWord);
}

string printRandomString(int n) 
{

	string res = ""; 
	for (int i = 0; i < n; i++)
	{
		res = res + alphabet[rand() % 26] + " "; 
	}
	return res; 
} 
int winner(string val)
{
		int score=0;
	for( int i=0;i<val.length();i++)
	{
		if(val[i]=='a'||val[i]=='e'||val[i]=='i'||val[i]=='o'||val[i]=='u'||val[i]=='l'||val[i]=='n'||val[i]=='s'||val[i]=='t'||val[i]=='r')
		{
			score+=1;
		}
		else if(val[i]=='d'||val[i]=='g')
		{
			score+=2;
		}
		else if(val[i]=='b'||val[i]=='c'||val[i]=='m'||val[i]=='p')
		{
			score+=3;
		}
		else if(val[i]=='f'||val[i]=='h'||val[i]=='v'||val[i]=='w'||val[i]=='y')
		{
			score+=4;
		}
		else if(val[i]=='k')
		{
			score+=5;
		}
		else if(val[i]=='j'||val[i]=='x')
		{
			score+=8;
		}
		else if(val[i]=='q'||val[i]=='z')
		{
			score+=10;
		}
	}
	return score;
}
void game_over()
{
	system("CLS");
	int a,b,c,data;  char m; string p;
	a=max(scoreone,scoretwo);
	b=max(scorethree,scorefour);
	c=max(a,b);
	cout<<"\n\n\n\t\t\t\t\t\t\t\t\t\tGAME OVER";
//	cout<<"\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tBEST SCORE:"<<c<<endl;
	if(c==scoreone)
	p="FIRST PLAYER";
	else if(c==scoretwo)
	p="SECOND PLAYER";
	else if(c==scorethree)
	p="THIRD PLAYER";
	else
	p="FOURTH PLAYER";
	cout<<"\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t"<<p<<" WINS\n";
	cout<<"\t\t\t\t\t\t\t\t\t\tBEST SCORE:"<<c<<endl;
	/*ofstream myfile;	
	myfile.open("high_score.txt");
	myfile>>c;
	ifstream newfile;
	newfile.open("ht.txt");
	myfile>>data;
	while(!myfile.eof())
		if(data<c)
			newfile<<data;
	myfile<<c;

	//else
	//myfile<<c;
	newfile.close();
	myfile.close();*/
	cout<<"Press H to go to Home E to End The Game";
	cin>>m;
	if(m=='H')
	main1();
	else if(m=='E')
	exit(1);

}

bool check(int f,string val,char w)
{
	if(letter.empty())
	{
		for(int i=0;i<val.length();i++)
		{	
			//b[f-1]=val[i];
			letter.push_back(f-1);									
			if(w=='r')
			{f++;}
			if(w=='b')
			{f=f+10;}	
		}
		return true;
	}
	else
	{
		list<int>::iterator it;
		for(int i=0;i<val.length();i++)
		{
			it = find(letter.begin(), letter.end(), f-1);
			if(it != letter.end()&&b[f-1]!=string(1,val[i]))
			return false;
			else if(it != letter.end()&&b[f-1]==string(1,val[i]))
			{
				if(w=='r')
				{f++;}
				if(w=='b')
				{f=f+10;}
				continue;
			}
			else 
			{
				if(w=='r')
				{f++;}
				if(w=='b')
				{f=f+10;}	
			}
		}
			if(it == letter.end())
			{
				for(int i=0;i<val.length();i++)
				{	
				//b[f-1]=val[i];
				letter.push_back(f-1);										
				if(w=='r')
				{f++;}
				if(w=='b')
				{f=f+10;}	
				}
				return true;
			}
			
		}	
			
	}

void wrdremove(int player)
{
	while(!remov.empty()){
    if(player!=1){
    one[remov.top()]=alphabet[rand() % 26];
    }
     if(player!=2){
    two[remov.top()]=alphabet[rand() % 26];
    }
     if(player!=3){
    three[remov.top()]=alphabet[rand() % 26];
    }
     if(player!=4){
    four[remov.top()]=alphabet[rand() % 26];
    }
    remov.pop();


    }
}
bool wrdcond(string val,int player)
{
	int c=0;
	string str;
	if(player==1)
	    str=one;
	else if(player==2)
	    str=two;
	else if(player==3)
	    str=three;
	else
	    str=four;

	for(int i=0;i<val.length();i++)
	{
		for(int j=0;j<str.length();j++)
		{
			if(val[i]==str[j]){
			remov.push(j);
			str[j]='1';
            c++;
            break;
			}

		}
	}
	if(c==val.length())
		{
			return true;
		}
	else
		return false;
}
int chk_bord_b(int f,char *w,string val);

int chk_bord_r(int f,char *w,string val){
    char a;
    int chk=(f+10)-(f%10);
	if (f%10==0)
    chk=chk-10;
    if((val.length())>((chk-f)+1)){
    cout<<"Wrong place entered:\n";
        cout<<"Enter first place to enter:";
        cin>>f;
        cout<<"\nState where to go :\nb for bottom:\nr for right:";
        cin>>w;
        if(*w=='r')
	chk_bord_r(f,w,val);
	if(*w=='b')
	chk_bord_b(f,w,val);
    }
return f;

}

int chk_bord_b(int f,char *w,string val){
int chk=(9-(f/10))+1;
if(f/10==9)
chk=9;
if(f%10==0)
chk=(10-(f/10))+1;

if(val.length()>chk){
    cout<<"Wrong place entered:\n";
    cout<<"Enter first place to enter:";
 	cin>>f;
 	cout<<"\nState where to go :\nb for bottom:\nr for right:";
	cin>>w;
   if(*w=='r')
	chk_bord_r(f,w,val);
	if(*w=='b')
	chk_bord_b(f,w,val);

}
return f;
}



void board(trie *root)
{
	string val,y,p;    int f,score;  char w;
	static int player=1;
	wrdremove(player);
	system("CLS");
	cout<<"\n\n\t\tFIRST PLAYER\t\t\t\t\t\t\t\t\t\t\t\t\t              SECOND PLAYER";
	cout<<"\n\t\t"<<one<<"\t\t\t\t\t\t\t\t\t\t\t\t\t              "<<two<<endl;
	cout<<"\n\tSCORE:"<<scoreone<<"\t\t\t\t\t\t\t\t\t\t\t\t\t              SCORE:"<<scoretwo<<endl;

    cout <<"\n\n\t\t\t\t\t\t\t"<<"     |     |     |     |     |     |     |     |     |" << endl;
    cout <<"\t\t\t\t\t\t\t"<< "  " << b[0] << "  |  " << b[1] << "  |  " << b[2]<< "  |  " << b[3]<< "  |  " << b[4]<< "  |  " << b[5]<< "  |  " << b[6]<< "  |  " << b[7]<< "  |  " << b[8]<< "  |  " << b[9]<<endl;

    cout <<"\t\t\t\t\t\t\t"<< "_____|_____|_____|_____|_____|_____|_____|_____|_____|_____" << endl;
    cout <<"\t\t\t\t\t\t\t"<< "     |     |     |     |     |     |     |     |     |     " << endl;

    cout <<"\t\t\t\t\t\t\t"<< "  " << b[10] << " |  " << b[11] << " |  " << b[12]<< " |  " << b[13]<< " |  " << b[14]<< " |  " << b[15]<< " |  " << b[16]<< " |  " << b[17]<< " |  " << b[18]<< " |  " << b[19]<<endl;

    cout <<"\t\t\t\t\t\t\t"<< "_____|_____|_____|_____|_____|_____|_____|_____|_____|_____" << endl;
    cout <<"\t\t\t\t\t\t\t"<< "     |     |     |     |     |     |     |     |     |     " << endl;
    
    cout <<"\t\t\t\t\t\t\t"<< "  " << b[20] << " |  " << b[21] << " |  " << b[22]<< " |  " << b[23]<< " |  " << b[24]<< " |  " << b[25]<< " |  " << b[26]<< " |  " << b[27]<< " |  " << b[28]<< " |  " << b[29]<<endl;

    cout <<"\t\t\t\t\t\t\t"<< "_____|_____|_____|_____|_____|_____|_____|_____|_____|_____" << endl;
    cout <<"\t\t\t\t\t\t\t"<< "     |     |     |     |     |     |     |     |     |     " << endl;
    
    cout <<"\t\t\t\t\t\t\t"<< "  " << b[30] << " |  " << b[31] << " |  " << b[32]<< " |  " << b[33]<< " |  " << b[34]<< " |  " << b[35]<< " |  " << b[36]<< " |  " << b[37]<< " |  " << b[38]<< " |  " << b[39]<<endl;

    cout <<"\t\t\t\t\t\t\t"<< "_____|_____|_____|_____|_____|_____|_____|_____|_____|_____" << endl;
    cout <<"\t\t\t\t\t\t\t"<< "     |     |     |     |     |     |     |     |     |     " << endl;
    
    cout <<"\t\t\t\t\t\t\t"<< "  " << b[40] << " |  " << b[41] << " |  " << b[42]<< " |  " << b[43]<< " |  " << b[44]<< " |  " << b[45]<< " |  " << b[46]<< " |  " << b[47]<< " |  " << b[48]<< " |  " << b[49]<<endl;

    cout <<"\t\t\t\t\t\t\t"<< "_____|_____|_____|_____|_____|_____|_____|_____|_____|_____" << endl;
    cout <<"\t\t\t\t\t\t\t"<< "     |     |     |     |     |     |     |     |     |     " << endl;
    
    cout <<"\t\t\t\t\t\t\t"<< "  " << b[50] << " |  " << b[51] << " |  " << b[52]<< " |  " << b[53]<< " |  " << b[54]<< " |  " << b[55]<< " |  " << b[56]<< " |  " << b[57]<< " |  " << b[58]<< " |  " << b[59]<<endl;

    cout <<"\t\t\t\t\t\t\t"<< "_____|_____|_____|_____|_____|_____|_____|_____|_____|_____" << endl;
    cout <<"\t\t\t\t\t\t\t"<< "     |     |     |     |     |     |     |     |     |     " << endl;

    cout <<"\t\t\t\t\t\t\t"<< "  " << b[60] << " |  " << b[61] << " |  " << b[62]<< " |  " << b[63]<< " |  " << b[64]<< " |  " << b[65]<< " |  " << b[66]<< " |  " << b[67]<< " |  " << b[68]<< " |  " << b[69]<<endl;

    cout <<"\t\t\t\t\t\t\t"<< "_____|_____|_____|_____|_____|_____|_____|_____|_____|_____" << endl;
    cout <<"\t\t\t\t\t\t\t"<< "     |     |     |     |     |     |     |     |     |     " << endl;
    
    cout <<"\t\t\t\t\t\t\t"<< "  " << b[70] << " |  " << b[71] << " |  " << b[72]<< " |  " << b[73]<< " |  " << b[74]<< " |  " << b[75]<< " |  " << b[76]<< " |  " << b[77]<< " |  " << b[78]<< " |  " << b[79]<<endl;

    cout <<"\t\t\t\t\t\t\t"<< "_____|_____|_____|_____|_____|_____|_____|_____|_____|_____" << endl;
    cout <<"\t\t\t\t\t\t\t"<< "     |     |     |     |     |     |     |     |     |     " << endl;
    
    cout <<"\t\t\t\t\t\t\t"<< "  " << b[80] << " |  " << b[81] << " |  " << b[82]<< " |  " << b[83]<< " |  " << b[84]<< " |  " << b[85]<< " |  " << b[86]<< " |  " << b[87]<< " |  " << b[88]<< " |  " << b[89]<<endl;

    cout <<"\t\t\t\t\t\t\t"<< "_____|_____|_____|_____|_____|_____|_____|_____|_____|_____" << endl;
    cout <<"\t\t\t\t\t\t\t"<< "     |     |     |     |     |     |     |     |     |     " << endl;
    
    cout <<"\t\t\t\t\t\t\t"<< "  " << b[90] << " |  " << b[91] << " |  " << b[92]<< " |  " << b[93]<< " |  " << b[94]<< " |  " << b[95]<< " |  " << b[96]<< " |  " << b[97]<< " |  " << b[98]<< " |  " << b[99]<<endl;

    cout <<"\t\t\t\t\t\t\t"<< "     |     |     |     |     |     |     |     |     |" << endl;
    
    if(!four.empty())
	{
	cout<<"\n\n\t\tTHIRD PLAYER\t\t\t\t\t\t\t\t\t\t\t\t\t              FOURTH PLAYER";
	cout<<"\n\t\t"<<three<<"\t\t\t\t\t\t\t\t\t\t\t\t\t              "<<four<<endl;
	cout<<"\n\tSCORE:"<<scorethree<<"\t\t\t\t\t\t\t\t\t\t\t\t\t              SCORE:"<<scorefour<<endl;}
	if(!three.empty()&&four.empty())
	{
	cout<<"\n\n\t\tTHIRD PLAYER";
	cout<<"\n\t\t"<<three<<endl;
	cout<<"\n\tSCORE:"<<scorethree<<endl;}
	while(1)
	{
		player=player%4;
	    if(player==1)
	    	y="FIRST PLAYER";
	    else if(player==2)
	    	y="SECOND PLAYER";	
	    else if(player==3)
	    	y="THIRD PLAYER"; 
	    else
	    	y="FOURTH PLAYER"; 
	    	
		cout<<"\t\t\t\n"<<y<<" ENTER THE STRING:";
	    cin>>val;
	    if(val!="0"||val!="G"){
		
	    while(1)
	    {
		    if(wrdcond(val,player))
		    { //cout<<"string me h\n";
				if(search(val,root))
					{  // cout<<"tries me bhi h";
						change(root,val);
						cout<<"Go Ahead\n";
						score=winner(val);
						
						if(player==1)
	     					scoreone+=score;
						else if(player==2)
	    					scoretwo+=score;	
						else if(player==3)
							scorethree+=score;
						else
	    					scorefour+=score;
		
						cout<<"\nscore:"<<score;
					
						break;
					}
				else
				{
					//merge_cond(val,f);
		    		cout<<"Wrong Not Present In Dictionary OR Word Already Entered\n Enter Again:";
					cin>>val;	
						if(val=="0"){
					while(!remov.empty())
					remov.pop();
					break;}
					else if(val=="G")
					{
						game_over();
					}
				}	
			}
		    else
		    {
					if(val=="0"){
					while(!remov.empty())
					remov.pop();
					break;}
					else if(val=="G")
					{
						game_over();break;
					}
					cout<<"wrong word entered\n Enter Again:";
					cin>>val;
			}}
	if(val!="0")	{
		cout<<"Enter first place to enter:";
	 	cin>>f;	 
		cout<<"\nState where to go :\nb for bottom\nr for right";
		cin>>w;
			if(w=='r')
	f=chk_bord_r(f,&w,val);
	if(w=='b')
	f=chk_bord_b(f,&w,val);

	while(1)
	{
		if(check(f,val,w))
		{
			break;
		}
		else
		{
			cout<<"Wrong Place Entered\nEnter Again";
			cout<<"\nEnter first place to enter:";
		 	cin>>f;	 
			cout<<"\nState where to go :\nb for bottom\nr for right";
			cin>>w;		
		}
	}

	  
		int i;
	    for(i=0;i<val.length();i++)
		{	
			//index=f-1;
			b[f-1]=val[i];
			//letter.insert(pair<string,char>(index,val[i]));											//insert values on board
			if(w=='r')
			{f++;}
			if(w=='b')
			{f=f+10;}	
		} }}
		if(val=="0"){
			if(player==1)
			one=printRandomString(7);
			if(player==2)
			two=printRandomString(7);
			if(player==3)
			three=printRandomString(7);
			if(player==4)
			four=printRandomString(7);
			
			
		}
		player++;
	   
	    if(!two.empty()&&player==3&&three.empty()&&four.empty())
	    player=1;
	    if(!three.empty()&&player==4&&four.empty())
	    player=1;
	     board(root);

}
  
}
void two_pl(trie *root)
{
 char c;
srand(time(NULL)); 
int n = 7; 
one=printRandomString(n); 
cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tFirst player alphabets:"<<one<<endl;
two=printRandomString(n);
cout<<"\n\t\t\t\t\t\t\t\t\tSecond player alphabets:"<<two<<endl;
cout<<"\n\n\t\t\t\t\t\t\t\t\tPRESS Y TO START THE GAME:";
cin>>c;
if(c=='y' || c=='Y')
	board(root);
}

void three_pl(trie *root)
{
 char c;
srand(time(NULL)); 
int n = 7; 
one=printRandomString(n); 
cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tFirst player alphabets:"<<one<<endl;
two=printRandomString(n);
cout<<"\n\t\t\t\t\t\t\t\t\tSecond player alphabets:"<<two<<endl;
three=printRandomString(n);
cout<<"\n\t\t\t\t\t\t\t\t\tThird player alphabets:"<<three<<endl;
cout<<"\n\n\t\t\t\t\t\t\t\t\tPRESS Y TO START THE GAME:";
cin>>c;
if(c=='y' || c=='Y')
	board(root);
}

void four_pl(trie *root)
{
 char c;
srand(time(NULL)); 
int n = 7; 
one=printRandomString(n); 
cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tFirst player alphabets:"<<one<<endl;
two=printRandomString(n);
cout<<"\n\t\t\t\t\t\t\t\t\tSecond player alphabets:"<<two<<endl;
three=printRandomString(n);
cout<<"\n\t\t\t\t\t\t\t\t\tThird player alphabets:"<<three<<endl;
four=printRandomString(n);
cout<<"\n\t\t\t\t\t\t\t\t\tFourth player alphabets:"<<four<<endl;
cout<<"\n\n\t\t\t\t\t\t\t\t\tPRESS Y TO START THE GAME:";
cin>>c;
if(c=='y' || c=='Y')
	board(root);
}

int create_trie()
{
	trie *root=getNode();
	ifstream fin;
	fin.open("words.txt");
	string s;
	while(fin.eof()==0){
		fin>>s;
		insert(root,s);
	}
	fin.close();
	
	cout<<"Choose the number of players:\n1.Two Player\n2.Three Player\n3.Four Player\n";
	int p;
	cin>>p;

	switch(p)
	{
		case 1:system("CLS");two_pl(root);break;
		case 2:system("CLS");three_pl(root);break;
		case 3:system("CLS");four_pl(root);break;
	}
	//search("activity",root)?cout<<"yes\n" : cout<<"no\n";
}
int main1()
{
	
	system("CLS");
	
	cout<<"\n\n\n\n\n\n\n\t\t\t\t\t\t\t||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n";
	cout<<"\t\t\t\t\t\t\t||\t\t\t\t\t\t\t||\n\t\t\t\t\t\t\t||		READY TO PLAY SCRABBLE\t\t\t||\n";
	cout<<"\t\t\t\t\t\t\t||\t\t\t\t\t\t\t||\n";
	cout<<"\t\t\t\t\t\t\t||\t\t1.PLAY GAME\t\t\t\t||\n";
	cout<<"\t\t\t\t\t\t\t||\t\t2.INSTRUCTIONS\t\t\t\t||\n\t\t\t\t\t\t\t||\t\t\t\t\t\t\t||\n";
	cout<<"\t\t\t\t\t\t\t||\t\t\t\t\t\t\t||\n\t\t\t\t\t\t\t||\t\t\t\t\t\t\t||\n\t\t\t\t\t\t\t||\t\t\t\t\t\t\t||\n";
	cout<<"\t\t\t\t\t\t\t||\t\t\t\t\t\t\t||\n\t\t\t\t\t\t\t||\t\t\t\t\t\t\t||\n\t\t\t\t\t\t\t||\t\t\t\t\t\t\t||\n";
	cout<<"\t\t\t\t\t\t\t||\t\t\t\t\t\t\t||";
	cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n";
	cout<<"\t\t\t\t\t\t\t\t\n\nCHOOSE YOUR OPTION:";
	int m;
	cin>>m;
	switch(m)
	{
		case 1:
		create_trie();break;
		case 2:instructions();break;
		case 3:cout<<"high score\n";
	}
}
int main()
{	//fflush(stdin);
	main1();
}
