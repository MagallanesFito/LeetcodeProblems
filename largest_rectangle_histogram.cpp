#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int maxarea = 0;
int getMin(vector<int> heights,int l,int r){
    int min_ = 100000000;
    int minindex = -1;
    for(int i=l;i<=r;i++){
        if(heights[i] < min_){
            min_= heights[i];
            minindex = i;
        }
    }
    return minindex;
}
void divideAndConquer(vector<int> heights,int l,int r){
    if(l==r) maxarea =  max(heights[l],maxarea);
    else{
        int minIndex = getMin(heights,l,r);
        //cout << minIndex << endl;
        maxarea = max(heights[minIndex]*(r-l+1),maxarea);
        if(minIndex != l){
            divideAndConquer(heights,l,minIndex-1);
        }
        if(minIndex != r){
            divideAndConquer(heights,minIndex+1,r);
        }
    }
    //int maxRight = divideAndConquer(heights,minIndex+1,r);
    //return max(heights[minIndex]*(r-l+1),max(maxLeft,maxRight));
}
int linearMaxArea(vector<int> hist){
     // Create an empty stack. The stack holds indexes
    // of hist[] array. The bars stored in stack are
    // always in increasing order of their heights.
    stack<int> s;
    int n = hist.size();

    int max_area = 0; // Initialize max area
    int tp;  // To store top of stack
    int area_with_top; // To store area with top bar
                       // as the smallest bar

    // Run through all bars of given histogram
    int i = 0;
    while (i < n)
    {
        // If this bar is higher than the bar on top
        // stack, push it to stack
        if (s.empty() || hist[s.top()] <= hist[i])
            s.push(i++);

        // If this bar is lower than top of stack,
        // then calculate area of rectangle with stack
        // top as the smallest (or minimum height) bar.
        // 'i' is 'right index' for the top and element
        // before top in stack is 'left index'
        else
        {
            tp = s.top();  // store the top index
            s.pop();  // pop the top

            // Calculate the area with hist[tp] stack
            // as smallest bar
            area_with_top = hist[tp] * (s.empty() ? i :
                                   i - s.top() - 1);

            // update max area, if needed
            if (max_area < area_with_top)
                max_area = area_with_top;
        }
    }

    // Now pop the remaining bars from stack and calculate
    // area with every popped bar as the smallest bar
    while (s.empty() == false)
    {
        tp = s.top();
        s.pop();
        area_with_top = hist[tp] * (s.empty() ? i :
                                i - s.top() - 1);

        if (max_area < area_with_top)
            max_area = area_with_top;
    }

    return max_area;


}
int largestRectangleArea(vector<int>& heights) {
    int greatestArea = linearMaxArea(heights);
    return greatestArea;
    //int largestLinear = linear(heights)
}
int main(){
    vector<int> a = {2,1,5,6,2,3};
    int ress = largestRectangleArea(a);
    cout << ress <<endl;
    return 0;
}
