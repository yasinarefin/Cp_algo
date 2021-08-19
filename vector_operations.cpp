// elements less than or equal to k in sorted vector
#define lessOrEqual(v,k) distance(v.begin(),upper_bound(v.begin(),v.end(),k))
//elemetns greater than or equal to k in sorted vector
#define greaterOrEqual(v,k) distance(lower_bound(v.begin(),v.end(),k),v.end())
//elements in range l to r in sorted vector
#define inRange(v,l,r) distance(lower_bound(v.begin(),v.end(),l),upper_bound(v.begin(),v.end(),r))
// leftmost index of  the element greater than or equal to k
#define leftmostIdx(v, k) distance(v.begin(), lower_bound(v.begin(), v.end(), k));
// rightmost index of  the element less than or equal to k
#define rightMostIdx(v, k) distance(v.begin(), upper_bound(v.begin(), v.end(), k))-1 /// returns -1 in case of no such positions
