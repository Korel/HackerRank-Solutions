#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the timeConversion function below.
 */
string timeConversion(string s) {
    /*
     * Write your code here.
     */
    string s1(s.end() - 2, s.end());
    string s2(s.begin(), s.begin() + 2);
    int time = atoi(s2.c_str());
    cerr << s1 << endl;

    if(s1 == "AM" || s1 == "am"){
        if(time != 12){
            return string(s.begin(), s.end() - 2);
        } else {
            return string("00") + string(s.begin()+ 2, s.end() - 2);
        }
    } else {
        if(time == 12){
            return string(s.begin(), s.end() - 2);
        } else {
            return to_string(time + 12) + string(s.begin() + 2, s.end() - 2);
        }       
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
