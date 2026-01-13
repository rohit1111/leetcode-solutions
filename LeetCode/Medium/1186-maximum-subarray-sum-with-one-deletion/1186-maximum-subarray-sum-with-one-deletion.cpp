class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int i=0;
        int nodelete=arr[i];
        int onedelete=INT_MIN;
        int n = arr.size();
        int ans=arr[i];
        for(i=1;i<n;i++){
            //int preondedelete = onedelete;
            int prevnodelete = nodelete;

            nodelete=max(nodelete+arr[i],arr[i]);
            int v2;
            if(onedelete == INT_MIN){
                onedelete=prevnodelete;
            }else{
                onedelete=onedelete+arr[i];
            }
            //onedelete = max(v2+arr[i],v2);
            //onedelete = max(prevnodelete,onedelete+arr[i]);
            onedelete = max(prevnodelete,onedelete);


            ans = max(ans,max(nodelete,onedelete));
        }
        return ans;
    }
};