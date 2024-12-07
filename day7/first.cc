#include <iostream>
#include <sstream>
#include <vector>
#include <string>

#include "BinTree.hh"

using namespace std;

bool fill_bintree(BinTree<long long int> &bt, const vector<long long int> &nums, int index, bool sum, long long int res) {
    if (index == nums.size()) {
        return bt.data == res;
    }

    if (sum) {
        bt.data += nums[index];
    } else {
        bt.data *= nums[index];
    }

    BinTree<long long int> left(bt.data);
    BinTree<long long int> right(bt.data);

    bt.left = &left;
    bt.right = &right;

    return fill_bintree(*(bt.left), nums, index+1, true, res) | fill_bintree(*(bt.right), nums, index+1, false, res);
}



int main() {
    string line;
    long long int acumulator = 0;

    while (getline(cin, line)) {
        stringstream ss(line);

        long long int res;
        vector<long long int> nums;

        char a;

        ss >> res >> a;

        long long int num;

        while (ss >> num) {
            nums.push_back(num);
        }

        BinTree<long long int> bt(0);

        if (fill_bintree(bt, nums, 0, true, res)) {
            acumulator += res;
        }
    }

    cout << acumulator << endl;
}