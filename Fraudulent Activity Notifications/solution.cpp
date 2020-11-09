#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the activityNotifications function below.
int activityNotifications(const vector<int> &expenditure, int d) {
    size_t notification = 0;
    vector<int> count(200 + 1, 0);
    vector<int> countFreq(200 + 1, 0);

    for (int j = 0; j < d; ++j) {
        count[expenditure[j]]++;
    }

    int double_median;
    size_t medianIndex = d / 2;
    for (int i = d; i < expenditure.size(); ++i) {
        countFreq[0] = count[0];
        for (int j = 1; j < countFreq.size(); ++j) {
            countFreq[j] = countFreq[j - 1] + count[j];
        }

        /** This is too expensive when d is big
        for (int j = i-d; j < i; ++j) {
            sorted[countFreq[expenditure[j]] - 1] = expenditure[j];
        }
        */

        if (d % 2 == 0) {
            int j = 0;
            for (; j < countFreq.size(); ++j) {
                if (medianIndex <= countFreq[j]) {
                    double_median = j;
                    break;
                }
            }
            for (; j < countFreq.size(); ++j) {
                if (medianIndex + 1 <= countFreq[j]) {
                    double_median = double_median + j;
                    break;
                }
            }
        } else {
            for (int j = 0; j < countFreq.size(); ++j) {
                if (medianIndex + 1 <= countFreq[j]) {
                    double_median = 2 * j;
                    break;
                }
            }
        }

        if (expenditure[i] >= double_median) {
            ++notification;
        }

        count[expenditure[i - d]]--;
        count[expenditure[i]]++;

    }

    return notification;
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nd_temp;
    getline(cin, nd_temp);

    vector<string> nd = split_string(nd_temp);

    int n = stoi(nd[0]);

    int d = stoi(nd[1]);

    string expenditure_temp_temp;
    getline(cin, expenditure_temp_temp);

    vector<string> expenditure_temp = split_string(expenditure_temp_temp);

    vector<int> expenditure(n);

    for (int i = 0; i < n; i++) {
        int expenditure_item = stoi(expenditure_temp[i]);

        expenditure[i] = expenditure_item;
    }

    int result = activityNotifications(expenditure, d);

    fout << result << "\n";

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
