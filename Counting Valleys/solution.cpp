#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'countingValleys' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER steps
 *  2. STRING path
 */

int countingValleys(int steps, const string &path) {
    int hill = 0;
    int valley = 0;
    int valleyCount = 0;
    bool sealevel = true;
    for(auto c : path){
        switch(c){
            case 'U':{
                if(sealevel){
                    sealevel = false;
                    hill++;
                } else if(hill){
                    hill++;
                } else {
                    valley--;
                    if(valley == 0){
                        valleyCount++;
                        sealevel = true;
                    }
                }
            break;
            }
            case 'D': {
                if(sealevel){
                    sealevel = false;
                    valley++;
                } else if(hill){
                    hill--;
                    if(hill == 0){
                        sealevel = true;
                    }
                } else {
                    valley++;
                }
            break;
            }
        }
    }
    return valleyCount;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string steps_temp;
    getline(cin, steps_temp);

    int steps = stoi(ltrim(rtrim(steps_temp)));

    string path;
    getline(cin, path);

    int result = countingValleys(steps, path);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
