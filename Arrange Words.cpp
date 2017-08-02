/* Question present on: https://codepair.hackerrank.com/paper/ziubekledljkajphmyetfbzxryhuwlfq?b=eyJpbnRlcnZpZXdfaWQiOjM4MDY1NSwicm9sZSI6ImludGVydmlld2VyIiwic2hvcnRfdXJsIjoiaHR0cDovL2hyLmdzLzg1ZGU5OCJ9#
We define the variable sentence to be a string of space-separated words that starts with a capital letter followed by lowercase letters and spaces, and ends with a period (i.e., it satisfies the regular expression ^[A-Z][a-z ]*\.$). We want to rearrange the words in sentence such that the following conditions are satisfied:
Each word is ordered by ascending word length. For example, the word rank (which has 4 letters) would come before the word hacker (which has 6 letters).
The rearranged sentence must be formatted to satisfy the regular expression ^[A-Z][a-z ]*\.$ (i.e., start with a capital letter, followed by lowercase letters and spaces, and terminated by a period).
If two or more words have equal length, they must appear in the same order as in the original sentence. For example, Cats and hats. would become And cats hats.
Complete the function in the editor below. It has one parameter:
Name	Type	Description
sentence	string	A string of space-separated words satisfying the regular expression ^[A-Z][a-z ]*\.$.
Return a string denoting the rearranged sentence satisfying the criteria above.
Input Format
A single line of space-separated words denoting sentence.
Constraints
1 ≤ length of sentence < 104
It is guaranteed that sentence satisfies the regular expression ^[A-Z][a-z ]*\.$.
Output Format
Return a string denoting the sorted sentence according to length.
Sample Input 0
The lines are printed in reverse order.
Sample Output 0
In the are lines order printed reverse.
Explanation 0
We organize the strings of each respective length in sentence = The lines are printed in reverse order. as:
Length 2: {in}
Length 3: {the, are}
Length 5: {lines, order}
Length 7: {printed, reverse}
We then reassemble our sequences of words as a sentence string, ensuring that the first letter is uppercase, the intermediate letters are lowercase, and the string terminates with a period. Thus, we return In the are lines order printed reverse. as our answer.
Sample Input 1
Here i come.
Sample Output 1
I here come.
Explanation 1
We organize the strings of each respective length in sentence = Here i come. as:
Length 1: {i}
Length 4: {here, come}
We then reassemble our sequences of words as a sentence string, ensuring that the first letter is uppercase, the intermediate letters are lowercase, and the string terminates with a period. Thus, we return I here come. as our answer.
Sample Input 2
I love to code.
Sample Output 1
I to love code.
Explanation 1
We organize the strings of each respective length in sentence = I love to code. as:
Length 1: {i}
Length 2: {to}
Length 4: {love, code}
We then reassemble our sequences of words as a sentence string, ensuring that the first letter is uppercase, the intermediate letters are lowercase, and the string terminates with a period. Thus, we return I to love code. as our answer.
*/
#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

string arrange(string sentence){
    string tmp="";
    int n = sentence.length();
    vector<string> words;
    for(int i=0; i<n; i++){
        if(sentence[i]==' ' || sentence[i]=='.'){

            words.push_back(tmp);
            tmp="";
        }
        else {
            tmp+=tolower(sentence[i]);
        //cout<<tmp;
        }
    }
    int ws = words.size();
    map<int,vector<string > > mp;
    for(int i=0; i<ws; i++){
        int wl = words[i].length();
            mp[wl].push_back(words[i]);
    }
    words.clear();
    map<int,vector<string > >::iterator it;
    for(it=mp.begin(); it!=mp.end(); it++){
        //cout<< it->first<<endl;
        vector<string > v = it->second;
        for(unsigned int vi=0; vi<v.size(); vi++){
            //cout<<v[vi]<<" ";
            words.push_back(v[vi]);
        }
        //cout<<endl;
    }
    string ans="";
    words[0][0] = toupper(words[0][0]);
    for(int i=0; i<ws-1; i++){
        //cout << words[i]<<" ";
        ans+=(words[i]+" ");
    }
    //cout<<words[ws-1]<<".";
    ans+=(words[ws-1]+".");
    return ans;
}

int main()
{
    string sentt;
    getline(cin,sentt);
    cout<<arrange(sentt);

    return 0;
}
