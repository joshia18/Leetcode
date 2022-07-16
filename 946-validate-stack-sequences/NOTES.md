```
stack<int> stk;
int n = pushed.size();
​
int i = 0, j = 0;
​
while(i < n){
stk.push(pushed[i]);
i++;
while(!stk.empty() && stk.top() == popped[j] &&  j < n){
stk.pop();
j++;
}
}
​
return stk.empty() ? true : false;
```