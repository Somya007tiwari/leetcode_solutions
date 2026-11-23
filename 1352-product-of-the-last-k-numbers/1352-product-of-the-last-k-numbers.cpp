
class ProductOfNumbers {
public:
    vector<int> prefix;

    ProductOfNumbers() {
        prefix.push_back(1);
    }

    void add(int num) {
        // Reset prefix if num is 0
        if (num == 0) {
            prefix.clear();
            prefix.push_back(1);
        }
        else {
            prefix.push_back(prefix.back() * num);
        }
    }

    int getProduct(int k) {
        int n = prefix.size();

        // If zero is present in last k numbers
        if (k >= n) {
            return 0;
        }

        return prefix[n - 1] / prefix[n - 1 - k];
    }
};


/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */