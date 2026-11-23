class ProductOfNumbers {
public:
    vector<long long> products;
    vector<int> zeroCnt;
    ProductOfNumbers() {
        products.push_back(1);
        zeroCnt.push_back(0);
    }
    
    void add(int num) {
        if (products.back() == 0){
            products.push_back(num);
        }
        else {
            products.push_back(products.back() * num); 
        }  

        zeroCnt.push_back(zeroCnt.back() + (num == 0 ? 1 : 0));
    }
    
    int getProduct(int k) {
        int len = products.size();
        int xIdx = (len - k) - 1;

        // cout << k << " " << xIdx << endl;
        // for (int i = 0; i < len; i++){
        //     cout << products[i] << " ";
        // }
        // cout << endl;

        if (zeroCnt.back() - zeroCnt[xIdx] > 0) {
            return 0;
        }
        if (products[xIdx] == 0){
            return products.back();
        }

        return products.back() / products[xIdx];

    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */