
template <typename T>
class TriTree {
    public:
        T data;
        TriTree *left;
        TriTree *center;
        TriTree *right;

        TriTree (T value) {
            data = value;
            left = nullptr;
            center = nullptr;
            right = nullptr;
        }
};