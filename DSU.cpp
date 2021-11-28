struct DSU{
    vector<int> id;
    vector<int> Size;
    int len;
    DSU(int l){
        len=l;
        id.resize(l+1);
        Size.resize(l+1);
        for(int x=0;x<len+1;x++)
            id[x]=x;
        for(int x=0;x<len+1;x++)
            Size[x]=1;
    }
    int root(int i){
        while(id[i]!=i){
            id[i] = id[id[i]];
            i = id[i];
        }
        return i;
    }
    bool ifCon(int id1,int id2){
        return root(id1)==root(id2);
    }
    void unite(int id1,int id2){
        if(ifCon(id1,id2)) return;
        int r1 = root(id1);
        int r2 = root(id2);
        if(Size[r1]>Size[r2]){
            id[r2] = r1;
            Size[r1]+=Size[r2];
        }else{
            id[r1] = r2;
            Size[r2]+=Size[r1];
        }

    }

};
