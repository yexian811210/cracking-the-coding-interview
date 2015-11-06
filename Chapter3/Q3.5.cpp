//
//  main.cpp
//  crack_stack
//
//  Created by 王力涵 on 15/11/5.
//  Copyright © 2015年 王力涵. All rights reserved.
//

#include <iostream>
#include <stack>

class Test{
  public:
    std::stack<int> sortstack(std::stack<int> s) {
        std::stack<int> new_n;
        new_n.push(s.top());
        s.pop();
        int temp;
        while(!s.empty()) {
            temp = s.top();
            s.pop();
            if(temp<new_n.top()) {
                new_n.push(temp);
            }
            else {
                while(!new_n.empty()) {
                    s.push(new_n.top());
                    new_n.pop();
                }
                new_n.push(temp);
            }
        }
        return new_n;
    }
};

int main(int argc, const char * argv[]) {
    Test test;
    std::stack<int> n;
    n.push(8);
    n.push(10);
    n.push(7);
    n.push(15);
    n.push(6);
    n.push(9);
    n.push(2);
    n.push(5);
    std::stack<int> reals = test.sortstack(n);
    while(!reals.empty()) {
        std::cout<<reals.top()<<std::endl;
        reals.pop();
    }
    // insert code here...
    //std::cout << test.sortstack(n).top()<<std::endl;
    return 0;
}
