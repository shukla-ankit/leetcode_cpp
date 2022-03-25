#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

string fun(string s){
	string ret;
	char prev = -1;
	int count = 0;
	for(auto cur : s){
		if(cur == prev)
			count++;
		else{
			if(prev == -1)
				count++;
			else{
				ret.push_back('0' + count);
				ret.push_back(prev);
				count = 1;
			}
			prev = cur;
		}
	}
	ret.push_back('0' + count);
	ret.push_back(prev);
	return ret;
}


string decode(string e){
    string ret;
    int count = 0;
    char last_char = -1;
    for(auto c : e){
        if('1' <= c && c <= '9')
            count = count * 10 + (c - '0');
        else{
            ret += string(count, c);
            last_char = c;
            count = 0;
        }
    }
    return ret;
}

struct visit{
	string user;
	int timestamp;
	string url;
};


 template <typename T>
 string print_array(vector<T> array){
 	string ret = "[" ;
    for(auto n: array){
        if (std::is_same<T, char>::value)
            ret += string(1, n) +",";
        else
            ret += to_string(n) + ",";
    }
    if(array.size() > 0)
        ret = ret.substr(0, ret.length()-1);
    return ret + "]" ;
}

struct SiteVisit{
	string userId;
    long timestamp;
	string url;
};

string find3Sequence(vector<SiteVisit> visits) 
{
    //sort(visits.begin(), visits.end(), visits.timestamp); //compare on timestamp
    sort(visits.begin(), visits.end(), [](SiteVisit &x, SiteVisit&y){return x.timestamp < y.timestamp;}); // mistake 1: compare on timestamp
    
	map<string, vector<string>> mapUserToURL;
    map<string, int> map3SeqToCounter;
    for(auto visit : visits)	//  mistake 2: visit not visits
    {
        if(mapUserToURL.find(visit.userId) == mapUserToURL.end())
            mapUserToURL[visit.userId] = {visit.url};
        else
            mapUserToURL[visit.userId].push_back(visit.url);
    }
    
    // u1 -> a, b, c, a, b, c, a, b, c
    for(auto userVisits : mapUserToURL){
        //vector<string> sequence = mapUserToURL[userVisits.first]; // I could have used userVisits.second
        vector<string> sequence = userVisits.second; // I could have used userVisits.second
		if(sequence.size() < 3)
            continue;
        set<string> t_seq;
        for(int i = 0; i < sequence.size() - 2; i++){
            string s = sequence[i] + "->" + sequence[i+1] + "->" + sequence[i+2];
            if(t_seq.find(s) == t_seq.end()){
                map3SeqToCounter[s]++;
            }
        }     
    }
    
    int most_visits = 0;
    string most_visited_3_seq;
    for(auto three_seq : map3SeqToCounter){
        // if(map3SeqToCounter[three_seq.first] > most_visits){
        //     most_visits = map3SeqToCounter[three_seq.first];
        //     most_visited_3_seq = three_seq.first;
        // }
		cout << three_seq.first << "    " << three_seq.second << endl;
		if(three_seq.second > most_visits){
            most_visits = three_seq.second;
            most_visited_3_seq = three_seq.first;
        }
    }
	cout << endl;
	cout << endl;
    return most_visited_3_seq; 
}

int main(){
	vector<SiteVisit> l = {
		{"user1",1,"http://google.com" },
		{"user1",3,"http://facebook.com" },
		{"user1",2,"http://netflix.com" },
		{"user2",1,"http://google.com" },
		{"user1",4,"http://yahoo.com" },
		{"user2",2,"http://netflix.com" },
		{"user2",3,"http://facebook.com" }
	};

	cout << find3Sequence(l) << endl;
    /*
	vector<visit> l = {
		{"ankit", 7, "netflix"},
		{"akanksha", -19, "netflix"},
		{"mohit", 27, "netflix"},
		{"luv", 17, "netflix"},
		{"Jignesh", 0, "netflix"},
		{"Kevin", -2, "netflix"},
	};

	std::sort(l.begin(), l.end(), [](visit &x, visit&y){ return x.timestamp < y.timestamp;});
	for(auto a : l)
		cout << "{" << a.user << ", " << a.timestamp << ", " << a.url << "}" << endl;
	
	return 0;
	*/
	//string str = "aabcc";
    //string encoded = fun(str);
    //string decoded = decode(encoded);
    //cout <<  str << " compressed becomes " << encoded << " and on decoding becomes " << decoded << endl;
	
	// map<string, int> m;
	// m["Ankit"]++;
	// m["Anshika"] = 0;
	// m["Ankita"]--;
	// for(auto e : m){
	// 	cout << e.first << " " << e.second << endl;
	// }
}
