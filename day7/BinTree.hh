
template <typename T>
class BinTree {
    public:
        T data;
        BinTree *left;
        BinTree *right;

        BinTree (T value) {
            data = value;
            left = nullptr;
            right = nullptr;
        }
};