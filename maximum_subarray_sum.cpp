// given an array of "n" numbers, calculate the largest possible sum  of a sequence of consecutive values
// in the array(without altering the sequence).

# include<bits/stdc++.h>
using namespace std;

int main(){
int best = 0, sum = 0, n = 8;
int array[] = {-1, 2, 4, -3, 5, 2, -5, 2};
for(int i = 0; i < n; i++){
  sum = max(array[i], sum+array[i]);
  best = max(sum, best);
}
cout << best << "\n";
}
