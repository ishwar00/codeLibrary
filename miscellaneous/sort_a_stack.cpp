/*
 *
 * problem link: https://practice.geeksforgeeks.org/problems/sort-a-stack/1#
 *
 * */



void insert(stack<int>& stk, int element){
    if(stk.empty() or element >= stk.top()){
        stk.push(element);
    } else {
        int store = stk.top();
        stk.pop();
        insert(stk, element);
        stk.push(store);
    }
}

void SortedStack :: sort()
{
   stack<int> buffer;
   while(not SortedStack::s.empty()){
       buffer.push(SortedStack::s.top());
       SortedStack::s.pop();
   }
   
   while(not buffer.empty()){
       insert(SortedStack::s, buffer.top());
       buffer.pop();
   }
}

