// solution 1
// #include <iostream>
// #include <vector>
// #include <unordered_map>
// #include <iterator>
// #include <utility>
//
// namespace std {
//   std::ostream & operator<<(std::ostream & os, const std::pair<int,int> & pr) {
//     os << pr.first << ": " << pr.second;
//     return os;
//   }
// }

// class solution {
// public:
//   int longestConsecutive(const std::vector<int> & nums) {
//     int len = 0;
//     std::unordered_map<int,int> map;
//     int count = 1;
//     for (auto n : nums) {
//       if (map.find(n) == map.end()) {
// 	int left = (map.find(n-1) != map.end())?map[n-1]:0;
// 	int right = (map.find(n+1) != map.end())?map[n+1]:0;
	
// 	int sum = left+right+1;
// 	len = std::max(len, sum);
	
// 	map[n] = sum;

// 	if (left != 0)
// 	  map[n-1] = sum;
// 	if (right != 0)
// 	  map[n+1] = sum;

// 	  std::cout << "(" << count++ << ")--" << n << std::endl;
// 	std::copy(map.begin(), map.end(), std::ostream_iterator<std::pair<int,int>>(std::cout, "\n"));
// 	std::cout << std::endl;
//       }
//     }
//     return len;
//   }
// };


// solution 2
#include <iostream>
#include <vector>
#include <unordered_set>

class solution {
public:
  int longestConsecutive(const std::vector<int> & nums) {
    std::unordered_set<int> num(nums.begin(), nums.end());
    int len = 0;
    for (auto n : nums) {
      int curNum = n;
      int curlen = 0;
      while (num.find(curNum) != num.end()) {
	num.erase(curNum);
	curlen++;
	curNum++;
      }

      curNum = n-1;
      while (num.find(curNum) != num.end()) {
	num.erase(curNum);
	curlen++;
	curNum--;
      }

      len = std::max(len, curlen);
    }
    return len;
  }
};

int main() {
  std::vector<int> nums{100, 4, 200, 1, 3, 2, 6, 8, 10, 9, 7};

  solution soln;
  int len = soln.longestConsecutive(nums);
  std::cout << "The length of the longest consecutive sequence is:\n"
	    << len << std::endl;
}
