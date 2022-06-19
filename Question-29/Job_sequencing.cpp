#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(const pair<string,pair<int, int> > a, const pair<string,pair<int, int> > b)
{
    return a.second.second>b.second.second;
}

int main()
{
    vector<string> Jobs={"J1", "J2", "J3", "J4", "J5"};
    vector<int> Profit={20, 15, 10, 5, 1};
    vector<int> Deadline={2, 2, 1, 3, 5};

    int n=Jobs.size();
    int ind=0;

    vector<string> slot(*max_element(Deadline.begin(), Deadline.end()) + 1, "-1");
    slot[0]="occupied";

    vector<pair<string,pair<int, int> > > vp;

    for (int i = 0; i < n; ++i)
    {
        vp.push_back({Jobs[i],{Deadline[i],Profit[i]}});
    }
    sort(vp.begin(),vp.end(),compare);
    for (int i=0;i<n;i++)
    {
        if (slot[Deadline[vp[i].second.first]] == "-1")
        {
            slot[Deadline[vp[i].second.first]] = Jobs[vp[i].second.first];
            ind += vp[i].second.second;
            continue;
        }
        int index = Deadline[vp[i].second.first];
        for (int j = index - 1; j > 0; --j)
        {
            if (slot[j]=="-1")
            {
                slot[j] = Jobs[vp[i].second.first];
                ind += vp[i].second.second;
                break;
            }
        }
    }

    cout << "Maximum Profit Sequence of Jobs \n";
    for (int i = 1; i < slot.size(); ++i)
        cout<<slot[i]<<" ";
    cout << endl;

    cout << "Maximum Profit " << ind << endl;
}