#include<vector>
#include<queue>
#include<unordered_set>
using namespace std;

class SmallestInfiniteSet {
  priority_queue<int, vector<int>, greater<>> pq;
  int cap;
  // elements that have been popped till now
  unordered_set<int> st;
public:
  SmallestInfiniteSet() {
    cap = 1;
    pq.push(1);
  }

  int popSmallest() {
    if (!pq.empty()) {
      int e = pq.top();
      pq.pop();
      st.insert(e);
      return e;
    }
    // empty pq means all element till cap have been popped
    cap++;
    st.insert(cap);
    return cap;
  }

  void addBack(int num) {
    if (num <= cap) {
      // if the element was popped before
      if(st.find(num) != st.end()) {
        st.erase(num);
        pq.push(num);
      }
    }

    // increase cap
    while(cap < num) {
      cap++;
      pq.push(cap);
    }
  }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */