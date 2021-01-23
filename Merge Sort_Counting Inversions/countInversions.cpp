#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

long merge(vector<int> &v, vector<int> &v1, vector<int> &v2) {
    long count{0};
    auto it = v.begin();
    auto it1 = v1.begin();
    auto it2 = v2.begin();
    for (; it1 != v1.end() && it2 != v2.end(); ++it) {
        if (*it1 > *it2) {
            *it = *it2;
            count += v1.end() - it1;
            ++it2;
        } else {
            *it = *it1;
            ++it1;
        }
    }
    for (; it1 != v1.end(); ++it1, ++it) {
        *it = *it1;
    }
    for (; it2 != v2.end(); ++it2, ++it) {
        *it = *it2;
    }
    return count;
}

long countInversions(vector<int> &v) {
    if (v.size() > 1) {
        long count{0};
        size_t middle = v.size() / 2;
        vector<int> v1(v.begin(), v.begin() + middle);
        vector<int> v2(v.begin() + middle, v.end());
        count += countInversions(v1);
        count += countInversions(v2);
        return count + merge(v, v1, v2);
    } else {
        return 0;
    }
}

/*
long countInversions(vector<int> &v) {
    // O(n^2) solution
    long count{0};
    for(size_t i = 0; i < v.size(); ++i){
        for(long long j = i + 1; j < v.size(); ++j){
            if(v[i] > v[j]){
                ++count;
            }
        }
    }
    return count;
}

*/

int main() {

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split_string(arr_temp_temp);

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            int arr_item = stoi(arr_temp[i]);

            arr[i] = arr_item;
        }

        long result = countInversions(arr);

        cout << result << "\n";
    }


    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
