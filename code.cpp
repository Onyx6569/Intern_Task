#include <bits/stdc++.h>
using namespace std;
class wordmagic
{
    public:
    string letters;
    string word;
    string engletters;
    bool magic(string letters, string word);
    string longest(string engletters);
};
bool wordmagic::magic(string letters, string word)
{  
	string first = letters;  
	string second = word;  
	int count = 0;  
	int wildcard_count = 0;  

	for (int i = 0; i < second.length(); i++) {  
		for (int y = 0; y < first.length(); y++) {  
			if (first[y] == second[i])   
				first[y] = '0';  
			}  
		}  
	for (int z = 0; z < first.length(); z++) {  
		if (first[z] == '0')  
			count++;  
		if (first[z] == '?')  
			wildcard_count++;  
	}  
	if (wildcard_count + count >= second.length())  
		return true;  
	else  
		return false;  

}  
string wordmagic::longest(string engletters)
{
    string dict,winner;
    int numlongestword=0;
    ifstream inFile ("enable1.txt");
    while (!inFile.eof())
    {
        inFile>>dict;
        
        if ((magic(engletters, dict)==true)&&(dict.length()>numlongestword))
        {
            winner=dict;
            numlongestword=winner.length();
        }
    }
    return winner;
}
int main()
{
    int n;
    char rep = 'Y';
    while(rep=='Y')
    {
        wordmagic obj;
        cout<<"Enter 1 for Word Formation"<<endl<<"Enter 2 for Longest Word Determination"<<endl;
        cin>>n;
        if(n==1)
        {
            cout<<"Enter the Letters and the Word in the same order"<<endl;
            cin>>obj.letters>>obj.word;
            if(obj.magic(obj.letters,obj.word))
                cout<<"magic("<<obj.letters<<", "<<obj.word<<") -> true"<<endl;
            else
                cout<<"magic("<<obj.letters<<", "<<obj.word<<") -> false"<<endl;
        }
        else if(n==2)
        {
            cout<<"Enter the Letters to determine the Longest word  :";
            cin>>obj.engletters;
            cout<<"longest("<<obj.engletters<<") -> "<<obj.longest(obj.engletters)<<endl;
        }
        else
            cout<<"Error,Check your Input"<<endl;
        cout<<"Repeat? Input 'Y' :";
        cin>>rep;
    }
    return 0;
}




















