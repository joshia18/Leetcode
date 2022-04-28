class Solution {
public:
    string decodeString(string s) {
        
        //one to keep the numbers thst we visit and another one to keep the temporary stringss that come in the middle
        //whenever we find '[', we put the temporary string into the res stack and whenever we find ']', we build it with the repetition number from counts stack
        stack<int> counts;
        stack<string> res;
        
        string result = "";
        
        int index = 0;
        
        while(index < s.size()){
            if(s[index] >= '0' && s[index] <= '9'){
                int count = 0;
                
                while(s[index] >= '0' && s[index] <= '9'){\
                    //calculating the count here, IMPORTANT here it is "count = ", not "count += ", count += gives bad wrong results as per maths expression
                    count = (10 * count + (s[index] - '0'));
                    index++;
                }
                cout << count;
                counts.push(count);
            }
            else if(s[index] == '['){
                //once added the temporary result into the stack, we modify the result string to ""
                res.push(result);
                result = "";
                index++;
            }
            else if(s[index] == ']'){
                string temp = res.top();
                res.pop();
                
                int count = counts.top(); counts.pop();
                
                for(int i = 0; i < count; i++){
                    temp += result;
                }
                
                result = temp;
                
                index++;
            }
            else{
                result += s[index];
                index++;
            }
        }
        
        return result;
    }
};