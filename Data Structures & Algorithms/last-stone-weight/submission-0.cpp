class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
       priority_queue<int> pq;
    //    
    //         if(pq.empty())
    //             pq.push(stones[i]);
    //         else if(pq.top()==stones[i]){
    //             pq.pop();
    //         }
    //         else if(pq.top()>stones[i]){
    //             int el = pq.top();
    //             pq.pop();
    //             pq.push(el-stones[i]);
    //         }

    for(int i=0;i<stones.size();i++){
      pq.push(stones[i]);
       }

    while(pq.size()>=2){
        int x = pq.top();
        pq.pop();
        int y = pq.top();
        if(x==y){
            pq.pop();
        }
        else {
            pq.pop();
            pq.push(x-y);
        }
    }
    return pq.empty()?0:pq.top(); 
    }
};
