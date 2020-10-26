    #include<iostream>
    using namespace std;

    void Sort(int *p,int n){
        for(int pass=0;pass<n;pass++){
            int min_index = pass;
            int i;
            for(i=pass+1;i<n;i++){
                if(p[i]<p[min_index])
                    min_index = i;
            }
            if(min_index!=i){
                int t = p[min_index];
                p[min_index] = p[pass];
                p[pass] = t;
            }
        }
    }

    int kthSmallest(int *p, int n, int k)
    {
        Sort(p,n);
        return p[k-1];
    }

    int kthLargest(int *p,int n,int k)
    {
        Sort(p,n);
        return p[n-k];
    }

    int main(){
        int n;
        cout<<"Enter Array Size : ";cin>>n;
        int *p = new int[n];
        cout<<"\nEnter Elements : \n";
        for(int i=0;i<n;i++){
            cin>>p[i];
        }
        cout<<"\nEnter k: "; int k; cin>>k;
        cout << "\nK'th smallest element is " << kthSmallest(p, n, k);
        cout << "\nK'th largest element is " << kthLargest(p, n, k);
        return 0;
    }
