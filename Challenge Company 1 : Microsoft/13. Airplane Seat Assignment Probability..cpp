😂 its very tricky question :
If person lost their ticket and only single person then probability of getting right seat of that person is 1.00.
Now if more then 1 person, and one person is lost his/her ticket and he/she randomly pick the seat. Now the probability for all other person is I) either 
they have take correct seat  ii) person have not take correct seat because seat is already taken by person which who can lost it’s ticket so probability of
all other person is 1/2.
Time complexity is : O(1)

class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        if(n==1) return 1.00000;
        return 1.00000/2;
    }
};
