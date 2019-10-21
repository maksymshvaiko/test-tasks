#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>

using namespace std;

void sale(vector<int> prices) {
  std::unordered_map<int, int> m;
  long int n = prices.size();
  int mi = n - 1;
  m[prices[n - 1]] = n - 1;
  long res = 1;
  res += prices[n - 1];
  std::vector<int> res_vec;
  res_vec.push_back(n - 1);
  for (int i = n - 2; i >= 0; --i) {
    if (m.find(prices[i]) != m.end()) {
      if (m[prices[i]] > mi) {
        if (prices[i] >= prices[mi]) {
          res += (prices[i] - prices[mi]);
        } else {
          mi = i;
          res_vec.push_back(i);
        }
      }
    } else {
      if (prices[i] >= prices[mi]) {
        res += (prices[i] - prices[mi]);
      } else {
        mi = i;
        res_vec.push_back(i);
      }
    }
    m[prices[i]] = i;
  }
  std::cout << res << std::endl;
  std::sort(res_vec.begin(), res_vec.end());
  for (const auto& it : res_vec) {
    std::cout << it << ' ';
  }
}

int main() {
  // your code goes here

  std::vector<int> vec = {2, 3, 1, 2, 4, 2};
  sale(vec);

  return 0;
}
