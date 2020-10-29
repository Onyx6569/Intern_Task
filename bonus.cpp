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
	int freq[26]={0};
	for (int i = 0; i < first.length(); i++)
	{  
		if (first[i] == '?') 
			wildcard_count++;
		else
		{
		    freq[first[i]-'a']++;
		}
	}
	for (int j = 0;j < second.length(); j++ )
	{
	    if(freq[second[j]-'a']!=0)
	    {
	        freq[second[j]-'a']--;
	        count++;
	    }
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
int main(int argc, char* argv[])
{
    wordmagic obj;
    if(strcmp(argv[1],"magic")==0)
    {
            if(obj.magic(argv[2],argv[3]))
	{
                 cout<<" => Yes, "<<argv[3]<<" can be created.";
	}
           else
                 {
                  cout<<" => No, "<<argv[3]<<" cannot be created.";
	 }
    }
    else if(strcmp(argv[1],"longest")==0)
    {
	{
                  cout<<" => Longest word formed is "<<obj.longest(argv[2]);
	}
     }
    return 0;
}