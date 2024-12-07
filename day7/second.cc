#include <iostream>
#include <sstream>
#include <vector>
#include <string>

#include "TriTree.hh"

using namespace std;

enum OP {
    SUM,
    MUL,
    CONC
};

int size_num(int num) {
    if (num == 0) {
        return 0;
    }
    return 1 + size_num(num/10);
}

bool fill_tritree(TriTree<long long int> &bt, const vector<long long int> &nums, int index, OP op, long long int res) {
    if (index == nums.size()) {
        return bt.data == res;
    }

    if (op == SUM) {
        bt.data += nums[index];
    } else if (op == MUL) {
        bt.data *= nums[index];
    } else if (op == CONC) {
        for (int i = 0; i < size_num(nums[index]); ++i) {
            bt.data *= 10;
        }
        bt.data +=  nums[index];
    }

    TriTree<long long int> left(bt.data);
    TriTree<long long int> center(bt.data);
    TriTree<long long int> right(bt.data);

    bt.left = &left;
    bt.center = &center;
    bt.right = &right;

    return fill_tritree(*(bt.left), nums, index+1, SUM, res) | fill_tritree(*(bt.center), nums, index+1, MUL, res) | fill_tritree(*(bt.right), nums, index+1, CONC, res);
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

        TriTree<long long int> bt(0);

        if (fill_tritree(bt, nums, 0, SUM, res)) {
            acumulator += res;
        }
    }

    cout << acumulator << endl;
}