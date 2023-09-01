#include <bits/stdc++.h>
using namespace std;

int add(int *a, int *b, int *c)
{
    *c = *a + *b;
    return *c;
}


    int timeRequiredToBuy(vector<int> & tickets, int k)
    {
        int time = 0;
        while (!tickets[k] == 0)
        {
            for (int i = 0; i < tickets.size(); i++)
            {
                if (tickets[i] > 0)
                {
                    tickets[i] = tickets[i] - 1;
                    time++;
                }
            }
        }
        return time;
    }
int main()
{



    vector<int> tickets = {84, 49, 5, 24, 70, 77, 87, 8};
    cout<<timeRequiredToBuy(tickets,3);

    
}