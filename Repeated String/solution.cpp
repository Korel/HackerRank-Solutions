#include <bits/stdc++.h>

using namespace std;

// Complete the repeatedString function below.
long repeatedString(string s, long n) {
    if(n <= 0){
        return 0;
    }

    if(n < s.size()){
        return count(s.begin(), s.begin() + n, 'a');
    }

    long aCount = count(s.begin(), s.end(), 'a');
    long lastRepeat = n % s.size();
    long lastRepeatCount = count(s.begin(), s.begin() + lastRepeat, 'a');
    return aCount * (n / s.size()) + lastRepeatCount;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}
