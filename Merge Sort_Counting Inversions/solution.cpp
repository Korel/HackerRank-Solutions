#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Uses the code from countInversions_iterator.cpp

long merge(vector<int>::iterator begin1, vector<int>::iterator end1, vector<int>::iterator end2){
    long count{0};
    vector<int> temp;
    temp.reserve(end2 - begin1);
    auto it1 = begin1;
    auto it2 = end1;
    while(it1 != end1 && it2 != end2){
        if(*it1 > *it2){
            temp.emplace_back(*it2++);
            count += end1 - it1;
        } else {
            temp.emplace_back(*it1++);
        }
    }

    while(it1 != end1){
        temp.emplace_back(*it1++);
    }
    while(it2 != end2){
        temp.emplace_back(*it2++);
    }

    for(auto &t : temp){
        *begin1++ = t;
    }
    return count;
}


long mergeSort(vector<int>::iterator begin, vector<int>::iterator end){
    size_t size = end - begin;
    if(size > 1){
        long count{0};
        size_t middle = size / 2;
        count += mergeSort(begin, begin + middle);
        count += mergeSort(begin + middle, end);
        return count + merge(begin, begin + middle, end);
    } else {
        return 0;
    }
}

long countInversions(vector<int> &v) {
    return mergeSort(v.begin(), v.end());
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

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

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
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
