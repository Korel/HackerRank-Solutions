#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &v, vector<int> &v1, vector<int> &v2){
    auto it = v.begin();
    auto it1 = v1.begin();
    auto it2 = v2.begin();
    for(; it1 != v1.end() && it2 != v2.end(); ++it){
        if(*it1 < *it2){
            *it = *it1;
            ++it1;
        } else {
            *it = *it2;
            ++it2;
        }
    }
    for(; it1 != v1.end(); ++it1, ++it){
        *it = *it1;
    }
    for(; it2 != v2.end(); ++it2, ++it){
        *it = *it2;
    }
}

void mergeSort(vector<int> &v) {
    if(v.size() > 1) {
        size_t size1 = v.size() / 2;
        vector<int> v1(v.begin(), v.begin() + size1);
        vector<int> v2(v.begin() + size1, v.end());
        mergeSort(v1);
        mergeSort(v2);
        merge(v, v1, v2);
    }
}

int main() {

//    cout << 5/2 << endl;
//    return 0;

    std::vector<int> v{5, 3, 9, 13, 1, 18, 98, 56, 34, 6};
    mergeSort(v);
    cout << "[";
    auto it = v.begin();
    while (it != v.end() - 1)
        cout << *it++ << ' ';
    cout << *it << "]\n";
    return 0;
}
