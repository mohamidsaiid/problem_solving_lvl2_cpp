// https://leetcode.com/problems/number-of-recent-calls/description/
class RecentCounter {
private:
    int l, h;
    queue<int> timeFrame;
public:
    RecentCounter() {
        this->l = INT_MIN;
        this->h = INT_MAX;
    }
    bool check(int c)
    {
        return (c >= this->l && c <= this->h);
    }
    int ping(int t) {
        this->l = t - 3000;
        this->h = t;
        this->timeFrame.push(t);
        while(!this->timeFrame.empty() && !check(this->timeFrame.front()))
            this->timeFrame.pop();
        return this->timeFrame.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
