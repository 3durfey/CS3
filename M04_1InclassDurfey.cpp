// C++ program to demonstrate the use of list containers
#include <iostream>
#include <list>
#include <map>

using namespace std;

int main()
{
	map<string, list<string> > map1;
	list<string> Bulbasaur{"vine whip", "tackle", "seed bomb", "sludge bomb"};
	list<string> Charmander{"ember", "scratch", "flamethrower", "flame charge"};
	list<string> Squirtle{"aqua jet", "frustration", "return", "scratch"};
	list<string> Ivysaur{"vine whip", "razor leaf", "power whip", "frustration"};

	map1.insert({"Bulbasaur", Bulbasaur});
	map1.insert({"Charmander", Charmander});
	map1.insert({"Squirtle", Squirtle});
	map1.insert({"Ivysaur", Ivysaur});

	map<string, list<string> >::iterator it = map1.begin();
	while (it != map1.end())
	{
		string word = it->first;
		cout << word << endl;
		list<string> temp = it->second;
		for (auto x : temp) {
        cout << x << endl;
		}
		it++;
		cout << endl;
	}


}


/*
Bulbasaur
vine whip
tackle 
seed bomb
sludge bomb

Charmander
ember
scratch
flamethrower
flame charge

Squirtle
aqua jet
frustration
return
scratch

Ivysaur
vine whip
razor leaf
power whip
frustration

*/