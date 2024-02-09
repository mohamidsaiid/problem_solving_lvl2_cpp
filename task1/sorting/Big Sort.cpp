// https://www.hackerrank.com/challenges/big-sorting/problem
void merge(vector<string> &s, int low, int mid, int high)
{
    int i = low, j = mid+1, k = high;
    vector<string> n;
    while(i <= mid && j <= high)
    {
        string t = s[i], r = s[j];
        if(r.size() > t.size())
        {
            n.push_back(t);
            ++i;
        }
        else if(r.size() < t.size())
        {
            n.push_back(r);
            ++j;
        }
        else
        {
            if(r < t) 
            {
                n.push_back(r);
                ++j;
            }
            else
            {
                n.push_back(t);
                ++i;
            }
        }
    }
    while(i <= mid)
            n.push_back(s[i++]);
    while(j <= high) 
        n.push_back(s[j++]);
    auto itt = n.begin();
    for(int it = low ; it <= high && itt != n.end(); it++, ++itt) s[it] = *itt;
}

void mergeSort(vector<string> &x, int l, int r)
{
    if(l < r)
    {
        int m = (l + r) / 2;
        mergeSort(x, l, m);
        mergeSort(x,  m+1 , r);
        merge(x, l, m, r);
    }
}
vector<string> bigSorting(vector<string> unsorted) {
    mergeSort(unsorted, 0, unsorted.size() - 1);
    return unsorted;
}
