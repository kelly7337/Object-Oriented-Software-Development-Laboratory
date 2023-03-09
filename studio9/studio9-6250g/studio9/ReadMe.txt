1. vector: push_back()
   forward_list: insert_after()
   list: push_back()
   deque: push_back(), push_front()


   output: 1 2 3 4 5 6 7 8 9 10 11

2. std::vector<int> can use it.
   std::forward_list<int>, std::list<int> cannot use it.
   XXX.sort() can sort them.
   std::deque<int> can use it.

3. std::vector<int> can use it.
   std::forward_list<int>, std::list<int> cannot use it.
   XXX.reverse() can reverse them.
   std::deque<int> cannot use it.
   reverse(XXX.begin(), XXX.end()) can reverse it.
