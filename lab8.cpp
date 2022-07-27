#include <iostream> //Three CPP libraries will be used
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;
using std::getline;

#include <fstream>
using std::ifstream;
using std::ofstream;

struct Diagnostic //Struct will hold our data
{
  string sayThis;
  Diagnostic* yes;
  Diagnostic* no;
};

void serializeDown(ofstream&, Diagnostic*);
void deallocate(Diagnostic*);
char validateInput();
void identificationOutputBlock()

int main()
{ 
  void identificationOutputBlock()
  Diagnostic a = {" You must live near Washington, huh!"};
  Diagnostic b = {" You must live near New York state, huh!"};
  Diagnostic c = {" You must live near California, huh!"};
  Diagnostic d = {" You must live near Florida, huh!"};
  Diagnostic e = {" North of the USA?\nYou must live in Canada, huh!"};
  Diagnostic f = {" South of the USA?\nYou must live in Mexico, huh!"};
  Diagnostic g = {" Well, those are a whole lot of countries! I wouldn't be able to make an educated guess without more branches!"};
  Diagnostic h = {" So neither of those? You must be living in India, Australia, Africa....or even Antarctica, if you are crazy!"};
  
  Diagnostic i = {" Is it in the NORTH-WEST?", &a, &b};
  Diagnostic j = {" Is it in the SOUTH-WEST?", &c, &d};
  Diagnostic k = {" Do you live south of the USA?", &e, &f};
  Diagnostic l = {" Do you live in a Europe/Asia/Russia?", &g, &h};
  Diagnostic m = {" Do you live in the northern part of the USA?", &i, &j};
  Diagnostic n = {" Do you live on this continent?", &k, &l};
  Diagnostic o = {" Do you live in the USA?", &m, &n};
  
  cout << "\n\n I will try to find out what region of the world you live in!\n\n";
  
  Diagnostic* top = &o;
  char userInputYN;
  Diagnostic* p = top;
  while(true)
  {
    cout << p->sayThis;
	if(p->yes == 0 && p->no == 0) break;
	cout << "\n Yes or No [Y/N]: ";
	cin >> userInputYN; userInputYN = toupper(userInputYN);
	cin.ignore(1000,10);
	
	if(userInputYN != 'Y' && userInputYN != 'N')
	  userInputYN = validateInput(); toupper(userInputYN);
	  
	if(userInputYN == 'Y') p = p->yes;
	else if(userInputYN == 'N') p = p->no;
	
	cout << endl;
  }
  
  ofstream fout;
  fout.open("ai.txt");
  serializeDown(fout, top);
  fout.close();
   

  
  deallocate(top);
  
  cout << "\n\n Done with the program!";
}
/********************************************************************
*Purpose: Validates input for valid type
*Parameters:None
*Return:None
********************************************************************/ 
char validateInput()
{
  char input;
 
  do
  {
  cout << " Please enter Y for yes, N for no: ";
  cin >> input; input = toupper(input);
  cin.ignore(1000,10);
  
  }while(input != 'Y' && input != 'N');
  
  return input;
}
/********************************************************************
*Purpose: To serializedown
*Parameters: fout will write to file *p will traverse the list
*Return:None
********************************************************************/ 
void serializeDown(ofstream& fout, Diagnostic* p)
{
  if(p == NULL)
    fout << "EOF\n";
  else
  {
	fout << p->sayThis << "\n";
    serializeDown(fout, p->yes);
	serializeDown(fout, p->no);
  }
}
/********************************************************************
*Purpose: Deallocates all nodes to prevent memory leak
*Parameters: Diagnostic* p will traverse through the node
*Return:None
********************************************************************/ 
void deallocate(Diagnostic* p)
{
	if(p == 0) return;
	deallocate(p->yes);
	deallocate(p->no);
	delete p;
}
/**************************************************
*Purpose: ID of student
*Parameters: None
*Return: None
**************************************************/
void identificationOutputBlock()
{
  // identification comments code block
  cout << "Sabas Segovia\n";
  cout << "Lab 8, Binary Tree\n";
  cout << "Editor(s) used: Code::Blocks, Notepad, Notepad++\n";
  cout << "Compiler(s) used: MinGW GNU\n";
  cout << "Apologies for my late two previous assigments\n\n\n\n";
}