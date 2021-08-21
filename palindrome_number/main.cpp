// Given an integer x, return true if x is palindrome integer.

// An integer is a palindrome when it reads the same backward as forward. For example, 121 is palindrome while 123 is not.

#include <iostream>
#include <vector>

using namespace std;

// Solution
// If the value is negative, it can't be a palindrome
// Otherwise, iterate the digits until the middle
// and compare them. Isolate them by using modulus + division
bool is_palindrome( int x ){
  if( x < 0 ) return false;
  int left {1}, right {1};
  while( x / left >= 10 ) left *= 10;
  bool ans = true;
  while( ans and right <= left ){
    ans = ((x / left % 10) == (x / right % 10));
    left /= 10;
    right *= 10;
  }
  return ans;
}

int main(){
  vector<int> values(4, 0);
  values[0] = 121;
  values[1] = -121;
  values[2] = 10;
  values[3] = -101;
  for( auto x : values )
    cout << "is " << x << " a palindrome number? " << (is_palindrome( x ) ? "yes!" : "no!") << endl;
  return 0;
}
