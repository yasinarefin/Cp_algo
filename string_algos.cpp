struct KMP{
    vector<int> failure;
    KMP(string &str){
        failure.resize(str.length(), 0);
        int cur = 0, mxcur = 0;
        failure[0] = cur;

        for(int i = 1; i<(int)str.size(); i++)
        {
            while(cur != 0 && str[cur] != str[i]) cur = failure[cur-1];
            if(str[cur] == str[i]) ++cur;

            failure[i] = cur;

            mxcur = max(mxcur, cur);
        }
    }

};
