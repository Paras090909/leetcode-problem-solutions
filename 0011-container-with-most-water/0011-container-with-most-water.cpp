class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0, j = n-1, result = 0;

        while(i < j){
            int cp = min(height[i], height[j]);
            //cout<<"controlling point is"<<cp<<endl;
            int area = cp * (j-i);
           //cout<<"current area is "<<area<<endl;
            result = max(result, area);
            if(height[i] < height[j]){
                i++;
            }else{
                j--;
            }
        }
        return result;
    }
};