// Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

// Given a roman numeral, convert it to an integer.

/*
 * I can be placed before V (5) and X (10) to make 4 and 9. 
 * X can be placed before L (50) and C (100) to make 40 and 90. 
 * C can be placed before D (500) and M (1000) to make 400 and 900.
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int roman_to_int( string s ){
  // grab the keys
  unordered_map<char, int> roman{ {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000} };
  int ans {};
  // iterate from right to left
  for( int i = (int)s.length() - 1; i >= 0; -- i ){
    ans += roman[s[i]];
    if( i > 0 and roman[s[i]] > roman[s[i - 1]] ){ // we need to substract
      if( s[i - 1] == 'I' ) ans -= roman['I'];
      else if( s[i - 1] == 'X' ) ans -= roman['X'];
      else if( s[i - 1] == 'C' ) ans -= roman['C'];
      // but also to advance the pointer
      -- i;
    }
  }
  return ans;
}

int main(){
  vector<string> tests( 5 );
  tests[0] = "III";
  tests[1] = "IV";
  tests[2] = "IX";
  tests[3] = "LVIII";
  tests[4] = "MCMXCIV";
  for( auto s : tests ){
    cout << s << " to integer is " << roman_to_int( s ) << endl;
  }
  return 0;
}
