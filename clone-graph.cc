                                   
class Solution {
    public:
    Node* dfs(Node* cur,unordered_map<Node*,Node*>& mp)
    {
        vector<Node*> neighbour;
        Node* clone=new Node(cur->val); //creates a new node if current node points to a new val
        mp[cur]=clone; //this is the map at current and itll make it equal to clone
            for(auto it:cur->neighbors) // for everytime cur points to neighbors it wil run the block of code 
            {
                if(mp.find(it)!=mp.end())   //if map is not equal to the end then
                {
                    neighbour.push_back(mp[it]);    // push back the clone node from map to neighbour
                }
                else
                    neighbour.push_back(dfs(it,mp)); // else if it will push back function with the it and map input
            }
            clone->neighbors=neighbour; //then sets clone pointing at neighbor equal to neighbor
            return clone; // then returns the clone
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*> mp; // declares unordered map
        if(node==NULL) // if the node is NUll
            return NULL; // return null
        if(node->neighbors.size()==0)   //if there is only one node present and there is no neighbors
        {
            Node* clone= new Node(node->val); // set node equal to the new node with node pointing a the value
            return clone; // then return the clone 
        }
        return dfs(node,mp); // then return the DFX fcuntion with node and map as input
    }
};