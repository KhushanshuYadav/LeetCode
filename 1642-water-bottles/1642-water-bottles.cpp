class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        //unitary methid based solution;

        return (
            numBottles+(numBottles-1)/(numExchange-1)
        );
    }
};