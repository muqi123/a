/*
901. Online Stock Span
https://leetcode.com/problems/online-stock-span/description/
Write a class StockSpanner which collects daily price quotes for some stock, and returns the span of that stock's price for the current day.

The span of the stock's price today is defined as the maximum number of consecutive days (starting from today and going backwards) for which the price of the stock was less than or equal to today's price.

For example, if the price of a stock over the next 7 days were [100, 80, 60, 70, 60, 75, 85], then the stock spans would be [1, 1, 1, 2, 1, 4, 6].
*/

class StockSpanner {
public:
    StockSpanner() {
        rec_ = vector<pair<int,int>>();
    }
    
    int next(int price) {
        int idx = rec_.size() - 1;
        int curCnt = 1;
        while( idx >= 0 )
        {
            int preVal = rec_.back().first;
            int preCnt = rec_.back().second;
            if( price >= preVal )
            {
                rec_.pop_back();
                curCnt += preCnt;
                idx--;
            }
            else
                break;
        }
        rec_.push_back( price, curCnt );
        return curCnt;
    }

private:
    vector<pair<int,int>> rec_;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner obj = new StockSpanner();
 * int param_1 = obj.next(price);
 */