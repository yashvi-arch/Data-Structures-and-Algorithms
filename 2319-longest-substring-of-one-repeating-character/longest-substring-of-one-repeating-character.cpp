class Solution {
    struct Node {
        char lc,rc;
        int pre,suf,best,len;

        Node() {
            lc=rc=0;
            pre=suf=best=len=0;
        }

        Node(char c) {
            lc=rc=c;
            pre=suf=best=len=1;
        }
    };

    vector<Node> tree;
    string s;

    Node merge(Node a,Node b) {
        if(a.len==0) return b;
        if(b.len==0) return a;

        Node res;
        res.len=a.len+b.len;
        res.lc=a.lc;
        res.rc=b.rc;

        res.pre=a.pre;
        res.suf=b.suf;
        res.best=max(a.best,b.best);

        if(a.rc==b.lc) {
            res.best=max(res.best,a.suf+b.pre);

            if(a.pre==a.len)
                res.pre=a.len+b.pre;

            if(b.suf==b.len)
                res.suf=b.len+a.suf;
        }

        return res;
    }

    void build(int node,int l,int r) {
        if(l==r) {
            tree[node]=Node(s[l]);
            return;
        }

        int mid=(l+r)/2;

        build(2*node,l,mid);
        build(2*node+1,mid+1,r);

        tree[node]=merge(tree[2*node],tree[2*node+1]);
    }

    void update(int node,int l,int r,int idx,char c) {
        if(l==r) {
            tree[node]=Node(c);
            return;
        }

        int mid=(l+r)/2;

        if(idx<=mid)
            update(2*node,l,mid,idx,c);
        else
            update(2*node+1,mid+1,r,idx,c);

        tree[node]=merge(tree[2*node],tree[2*node+1]);
    }

public:
    vector<int> longestRepeating(string str,string queryCharacters,vector<int>& queryIndices) {
        s=str;
        int n=s.size();

        tree.resize(4*n);

        build(1,0,n-1);

        vector<int> ans;

        for(int i=0;i<queryCharacters.size();i++) {
            int idx=queryIndices[i];
            char c=queryCharacters[i];

            s[idx]=c;

            update(1,0,n-1,idx,c);

            ans.push_back(tree[1].best);
        }

        return ans;
    }
};