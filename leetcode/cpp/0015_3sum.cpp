class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > S;
        int a, b, c;

        sort(num.begin(), num.end());
        /*        
        vector<int> num;
        num.reserve(num2.size());

        for (a=0; a < num.size(); ++a) {
            if (a == 0 || num2[a] != num2[a-1]) {
                num.push_back(num2[a]);
            }
        }
        */
        
        for (a = 0; a < num.size(); ++a) {
            if (a > 0 && num[a] == num[a-1])
                continue;
                
            int x = - num[a];
            int p1 = a+1, p2 = num.size() - 1;
            
            while (p1 < p2) {
                int suma = num[p1] + num[p2];
                if (suma == x) {
                    vector<int> V;
                    V.push_back(num[a]);
                    V.push_back(num[p1]);
                    V.push_back(num[p2]);
                    //S.insert(V);
                    if (S.size() == 0 || V != S[S.size() - 1])
                        S.push_back(V);
                    int q = num[p1];
                    while (p1 < p2 && num[p1] == q)
                        p1++;
                    p2--;
                } else if (suma < x) {
                    p1++;
                } else {
                    p2--;
                }
            }
        }
        //return vector<vector<int> >(S.begin(), S.end());
        return S;
    }
};