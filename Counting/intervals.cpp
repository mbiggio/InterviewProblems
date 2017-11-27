#include <stack>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/*
Merging all intersecting intervals into their union
*/

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

 
 struct xPoint {
     int x;
     bool first;
     xPoint(): x(0), first(true) {};
     xPoint(int x, bool first): x(x), first(first) {};
     bool operator<(const xPoint &other) const {
         if (x == other.x) {
            return (first && !other.first);
         }        
         return x<other.x;
     }
 };
 
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        int n = intervals.size();
        vector<Interval> result;
        stack<int> s;
        vector<xPoint> points(2*n);
        int j=0;
        for (int i=0; i<n; i++) {
            points[j++]=xPoint(intervals[i].start,true);
            points[j++]=xPoint(intervals[i].end,false);
        }
        sort(points.begin(),points.end());
        for (int k=0; k<points.size(); k++) {
            if (points[k].first) {
                s.push(points[k].x);
            } else {
                if (s.size() == 1) {
                    result.push_back(Interval(s.top(),points[k].x));
                }
                s.pop();
            }
        }
        return result;
    }
};

void print_intervals(vector<Interval> v) {
   for (auto I:v) cout << "[" << I.start << "," << I.end << "]" << endl;
}

int main() {
   Solution sol;
   vector<Interval> v = {Interval(5,5),
                         Interval(1,3),
                         Interval(3,5),
                         Interval(4,6),
                         Interval(1,1),
                         Interval(1,3),                         
   };
   print_intervals(sol.merge(v));
}
