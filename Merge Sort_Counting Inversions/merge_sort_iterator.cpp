#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>::iterator begin1, vector<int>::iterator end1, vector<int>::iterator end2){
    vector<int> temp;
    temp.reserve(end2 - begin1);
    auto it1 = begin1;
    auto it2 = end1;

    while(it1 != end1 && it2 != end2){
        if(*it1 > *it2){
            temp.emplace_back(*it2++);
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
}

void mergeSort(vector<int>::iterator begin, vector<int>::iterator end){
    size_t size = end - begin;
    if(size > 1){
        size_t middle = size / 2;
        mergeSort(begin, begin + middle);
        mergeSort(begin + middle, end);
        merge(begin, begin + middle, end);
    }
}

int main() {

    std::vector<int> v{5, 3, 9, 13, 1, 18, 98, 56, 34, 6, 8, 99, 16, 42, 27, 48, 554, 659};
    mergeSort(v.begin(), v.end());
    cout << "[";
    auto it = v.begin();
    while (it != v.end() - 1)
        cout << *it++ << ' ';
    cout << *it << "]\n";
    return 0;
}
