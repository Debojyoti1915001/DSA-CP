long long colosseum(int n,vector<int> a) {
        multiset<int>aa1;
        multiset<int,greater<int>>aa2;
        long long maxvalue=0,minvalue=0;
        
        vector<pair<long long,long long>>vector1;
        vector<pair<long long,long long>>vector2;
        
        for(int i=0;i<2*n;i++)
        {
            if(aa1.size()<n)
            {
                maxvalue+=a[i];
                minvalue+=a[i];
                aa1.insert(a[i]);
                aa2.insert(a[i]);
            }
            else{
                if(a[i]>(*aa1.begin()))
                {
                    maxvalue+=a[i]-(*aa1.begin());
                    aa1.erase(aa1.begin());
                    aa1.insert(a[i]);
                }
                if(a[i]<(*aa2.begin())){
                    minvalue+=+a[i]-(*aa2.begin());
                    aa2.erase(aa2.begin());
                    aa2.insert(a[i]);
                }
            }
            
            if(aa1.size()==n)
            vector1.push_back({maxvalue,minvalue});
        }
        aa1.clear();
        aa2.clear();
        maxvalue=0,minvalue=0;
        reverse(a.begin(),a.end());
        for(int i=0;i<2*n;i++)
        {
            if(aa1.size()<n)
            {
                maxvalue+=a[i];
                minvalue+=a[i];
                aa1.insert(a[i]);
                aa2.insert(a[i]);
            }
            else{
                if(a[i]>(*aa1.begin()))
                {
                    maxvalue+=a[i]-(*aa1.begin());
                    aa1.erase(aa1.begin());
                    aa1.insert(a[i]);
                }
                if(a[i]<(*aa2.begin())){
                    minvalue+=a[i]-(*aa2.begin());
                    aa2.erase(aa2.begin());
                    aa2.insert(a[i]);
                }
                
            }
            if(aa1.size()==n)
            vector2.push_back({maxvalue,minvalue});
        }
        reverse(vector2.begin(),vector2.end());
        long long ans=-1*1e16;
        
        for(int i=0;i<vector1.size();i++)
        {
            ans=max(ans,(vector1[i].first-vector2[i].second));
        }
        
        return ans;
   }