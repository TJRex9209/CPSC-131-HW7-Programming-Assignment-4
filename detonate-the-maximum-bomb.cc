class Solution {
public:
    
    // function to find if bomb 'b' is in range of bomb 'a'
    int insideRange(vector<int> a, vector<int> b)
    {
        long long x = abs((a[0]-b[0])); // set x long equal to aboslute value of vector a(0) - vector b(0)
        long long y = abs((a[1]-b[1])); // set y long equal to aboslute value of vector a(1) - vector b(1)
        long long r = a[2]; //long r is equal to vector a(2)
        long long dis = x*x + y*y; // distance is equal to x^2+y^2
        return  r*r >= dis ; // this will either return a 1 or a 0 depending if the statement is true or false
    }
    
    int bfs(int bid, int len, vector<vector<int>> adj) // bfs fucntion
    {
        int val = 1;
        vector<int> blasted(len, 0);//creates vector with blasted function with len and 0 as parmaeters
        queue<int> q; // int queue
        q.push(bid); //push the queue q push bid to the back of the queue
        blasted[bid]=1; // vector blaster at [bid] equal to 1
        int blastedTillNow = 1;
        while(!q.empty()) // while 1 is not empty run the block of code
        {
            int f = q.front(); // set f = to the front of queue q 
            q.pop(); // pop queue q
            for(auto k : adj[f])
            {
                if(!blasted[k]) // if blasted[k] is false then run the block of code
                {
                    q.push(k); // push k into queue q 
                    blasted[k]=1; // set blastedp[k] equal to 1
                    blastedTillNow++; // then add 1 the blasted till now
                    val = max(val, blastedTillNow); // set val equal to the higher value between val and blasted til now
                    
                    
                }
            }
        }
        return val; // bfs returns val
    }
        
    int maximumDetonation(vector<vector<int>>& bombs) {
        
        //create adjacency list for all bombs
        vector<vector<int>> adj(bombs.size());
        for(int i=0; i<bombs.size(); i++) //for loop for bomb size
        {
            for(int j=0; j<bombs.size(); j++)// for loop for bomb size
            {
                if(i!=j)// if i doesnt equal to j run code below
                {
                    if(insideRange(bombs[i], bombs[j])) // ifinside range of bomb[i] and bomb[j]
                    {
                        adj[i].push_back(j);//adj[i] and pushback j into adj[i]
                    }
                }
            }
        }
        
        
        int ans = 0;
        // perform bfs considering every bomb as source , find the max ans
        for(int i=0; i<bombs.size(); i++)
        {
            int x = bfs(i, bombs.size(), adj); // x equal to bfs with paramters of i, bomb.size, and adj
            ans = max(ans, x);// sets answer to the higher value between answer and x
        }
        
        return ans; //return ans
        
      
    }
};