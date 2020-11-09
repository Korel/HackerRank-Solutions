#include<cmath>
#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

struct Player {
    int score;
    string name;
};

class Checker{
public:
  	// complete this method
    static int comparator(const Player &a, const Player &b)  {
        if (a.score > b.score) {
            return 1;
        } else if (a.score < b.score) {
            return -1;
        } else {
            const size_t size = min(a.name.size(), b.name.size());
            for(size_t i = 0; i < size; ++i){
                if(a.name[i] < b.name[i]){
                    return 1;
                } else if(a.name[i] > b.name[i]){
                    return -1;
                }
            }
            // If reached here, strings are equal or one is substring, 
            if(a.name.size() == b.name.size()){
                return 0;
            } else {
                return a.name.size() < b.name.size() ? 1 : -1;
            }
        }
    }
};




bool compare(Player a, Player b) {
    if(Checker::comparator(a,b) == -1)
        return false;
    return true;
}
int main()
{
    int n;
    cin >> n;
    vector< Player > players;
    string name;
    int score;
    for(int i = 0; i < n; i++){
        cin >> name >> score;
        Player player;
        player.name = name, player.score = score;
        players.push_back(player);
    }
    sort(players.begin(), players.end(), compare);
    for(int i = 0; i < players.size(); i++) {
        cout << players[i].name << " " << players[i].score << endl;
    }
    return 0;
}