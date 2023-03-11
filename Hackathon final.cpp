#include<iostream>
#include<conio.h>
#include<iomanip>
#include<string>
#include<stdlib.h>
#include<fstream>
#include<time.h>
#include<vector>
#include<typeinfo>
using namespace std;
char store;
char correctanswer;
void question();
void playgame();
void display();
//int answer(char);
int main()
{
	display();
	return 0;
}
void playgame()
{
	int score=0;
	char name[20];
	char option;
	question();
}
void question()
{
	newgame:
	char playagain;
	int count=0;
	int score=0;
	char ans;
	char checkans;
	char checkingnum;
	string line;
	string lineAns;
    vector<string> lines;
    vector <string> linesAns;
    srand(time(0));
    //input file stream
    ifstream file("Questions.txt");
    //count number of total lines in the file and store the lines in the string vector
    int total_lines=0;
    while(getline(file,line))
    {
       	total_lines++; 
    	lines.push_back(line);  
  	}
   
    //generate a random number between 0 and count of total lines
    
    int firstletter;
    //cout<<num<<endl;
    while(count!=10)
    {
    	
    	checkfirstletter:
    	int check;
    	string forcheckingans;
	    int num=rand();
	    int random_number=num%total_lines;
	    //cout<<random_number;
	    //fetch the line where line index (starting from 0) matches with the random number
	    
	    string extractedline=lines[random_number];
	    
	    store=extractedline[0];
	    //cout<<store[0]<<endl;
	    
	    if(store=='1'|| store=='2'||store=='3'||store=='4'||store=='5'||store=='6'||store=='7'||store=='8'||store=='9')
	    {
	    	//cout<<store<<endl;
	    	checkingnum=store;
	    	//cout<<checkingnum<<endl;
	    	//forcheckingans=store;
	    	//checkingnum=forcheckingans[0];
	    	cout<<lines[random_number]<<endl;
	    	random_number++;
			cout<<lines[random_number++]<<endl;
			cout<<lines[random_number++]<<endl;
			cout<<lines[random_number++]<<endl;
			cout<<lines[random_number++]<<endl;    
	  	}
	  	else{
	  		//int random_number=num%total_lines;
	  		goto checkfirstletter;
		  }
	    //cout<<lines[0]<<endl;
	    cin>>ans;
	    system("cls");
	    count++;
	ifstream file;
	//int line_number;
	//cout<<"line number:"<<endl;
	//cin>>line_number;
	file.open("answers.txt");
	int current_line=0;
	string lineans;
	while(!file.eof())
	{
		current_line++;
		getline(file,lineans);
		//cout<<"Current line: "<< current_line<<" "<<int(store) - 48<<endl;
		
		if(int(store)-48==current_line)
		{
			//cout<<lineans<<endl;
			correctanswer = lineans[0];
			//cout<<correctanswer<<endl;
			break;
			
		}
	}
	if(ans==correctanswer)
			{
				score=score+1;
				//cout<<"Score is:"<<score<<endl;
				
			}
		
		
	
		
		//cout<<lineans[0]<<endl;
	//}
		
	}
	cout<<"Your score is:"<<score<<endl;
    if(score>5)
    {
    	cout<<"Passed the quiz"<<endl;
    	
	}
	else{
		cout<<"Oops! You failed!"<<endl;
	}
	cout<<"Do you want to play again?(Y/N)"<<endl;
	cin>>playagain;
	system("cls");
	if(playagain=='Y'|| playagain=='y')
	{
		goto newgame;
	}
	else{
		cout<<"Thankyou for playing"<<endl;
	}
}

void display()
{
	char start;
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	cout<<setw(68)<<"------------------------"<<endl;
	cout<<setw(60)<<"|  \t\tQuiz\t    |  "<<endl;
	cout<<setw(68)<<"-------------------------"<<endl;
	cout<<setw(65)<<"Press A to start"<<endl;
	getch();
	system("cls");
	cout<<setw(55)<<"Rules for the game"<<endl;
	cout<<endl;
	cout<<"Step 1: quiz contains total 10 questions"<<endl;
	cout<<"Step 2: You will be given 1 pt for each right answer"<<endl;
	cout<<"Step 3: There will be no negative marking"<<endl;
	cout<<"Step 4: Press A to start the quiz"<<endl;
	cout<<"Step 5: Please select option A,B,C,D"<<endl;
	cout<<"Step 6:If you score more than 6 than you pass the quiz"<<endl;
	cout<<"Step 7:Enter your answer only in uppercase"<<endl;

	startgame:
	cin>>start;
	system("cls");
	if(start=='A'|| start=='a')
	{
		playgame();//function to start the game
	}
	else{
		cout<<"Please enter a valid response. ENTER S TO PLAY"<<endl;
		goto startgame;
	}
}
