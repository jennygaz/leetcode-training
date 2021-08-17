#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

// O(n) time, O(n) space
int longest_substring_quad( string s ){
  int len {}, n = s.length();
  unordered_map<char, int> seen {};
  for( int i = 0; i < n; ++ i ){
    if( seen.find( s[i]) != seen.end() )
      seen[s[j]] = true;
  }
}

int main(){
  return 0;
}