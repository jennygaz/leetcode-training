#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_map>

using namespace std;

// O(n^2) time, O(1) space
pair<int, int> two_sum_quadratic( vector<int>& nums, int target ){
  for( int i = 0; i < (int)nums.size(); ++ i ){
    for( int j = i + 1; j < (int)nums.size(); ++ j )
      if( nums[i] + nums[j] == target )
        return {i, j};
  }
  return {-1, -1};
}

// O(nlgn) time, O(n) space
pair<int, int> two_sum_polylogarithmic( vector<int>& nums, int target ){
  vector<pair<int, int>> vals( nums.size() );
  for( int i = 0; i < (int)nums.size(); ++ i )
    vals[i] = {nums[i], i};
  sort( vals.begin(), vals.end() );
  for( int i = 0; i < (int)nums.size(); ++ i )
    nums[i] = vals[i].first;
  for( int i = 0; i < (int)nums.size(); ++ i ){
    auto it = lower_bound( nums.begin() + i + 1, nums.end(), target - nums[i] );
    if( it != nums.end() )
      return {i, it - nums.begin() };
  }
  return {-1, -1};
}

// O(n) time, O(n) space
pair<int, int> two_sum( vector<int>& nums, int target ){
  unordered_map<int, vector<int>> keys;
  for( int i = 0; i < (int)nums.size(); ++ i ){
    if( keys.find( nums[i] ) == keys.end() )
      keys[nums[i]] = vector<int>();
    keys[nums[i]].emplace_back( i );
  }
  for( auto val : nums ){
    if( val * 2 == target ){
      if( keys[val].size() >= 2 )
        return {keys[val][0], keys[val][1] };
    }
    else{
      auto it = keys.find( target - val );
      if( it != keys.end() )
        return {keys[val][0], it->second[0] };
    }
  }
  return {-1, -1};
}

int main(){
  int n {}, target {};
  cin >> n >> target;
  vector<int> nums( n );
  for( int i = 0; i < n; ++ i )
    cin >> nums[i];
  auto ans = two_sum( nums, target );
  cout << ans.first << " " << ans.second << '\n';
  return 0;
}