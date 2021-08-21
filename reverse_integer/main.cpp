// Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
// Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

#include <iostream>
#include <vector>

using namespace std;

// SOLUTION
// We just need to iterate the digits and construct another integer from it
// We need to be careful if the value would overflow
// so we just set LIMIT as (2^31 - 1) / 10

int reverse( int x ){
  // this makes the cases [-2147483647, 2147483647], way easier to handle!
  if( x == -2147483648 ) return 0;
  int LIMIT = (((1 << 30) - 1) << 1) + 1; // assuming int is 32-bits or more, this is 2^31 - 1
  int ans {}, sign {};
  // Get the sign and drop it, since we know modulus CAN be negative
  if( x >= 0 )
    sign = 1;
  else{
    sign = -1;
    x *= -1;
  }
  while( x ){ // while the value isn't 0, no "== 0" required
    // Whenever the answer is greater than the limit OR
    // the case when it is inside [2147483640, 2147483649]
    // since LIMIT / 10 gets truncated
    // -- We could also do 1.0 * ans / LIMIT / 10
    // but that would give floating point issues
    if( ans > LIMIT / 10 or (ans == 214748364 and x % 10 > 8 ) return 0;
    ans *= 10;
    ans += x % 10;
    x /= 10;
  }
  // return the original sign
  return ans * sign;
}

int main(){
  // Some tests
  vector<int> values( 5, 0 );
  values[0] = 123;
  values[1] = -123;
  values[2] = 120;
  values[3] = 0;
  values[4] = -2147483648;
  for( auto x : values )
    cout << x << " reversed is " << reverse( x ) << endl;
  return 0;
}
