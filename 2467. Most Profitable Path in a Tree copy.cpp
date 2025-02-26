#include <bits/stdc++.h>
using namespace std;
typedef struct stack_val
{
    short int row;
    short int col;
    short int time;
    unordered_map<int, int> visited;
    unordered_map<int, int> alice_time_node;
} sv;
class Solution
{
public:
    void traverse_bob(vector<vector<int>> &edges, int bob, vector<unordered_map<int, int>> &bob_time_set, vector<int> &bob_time_node)
    {
        unordered_map<int, int> mp;
        mp[0] = bob;
        pair<int, int> p;
        p.first = bob;
        p.second = 1;
        bob_time_set.push_back(mp);
        while (bob != 0)
        {
            for (int i = 0; i < bob; i++)
            {
                if (i < bob && edges[bob][i] == 1)
                {
                    mp[i] = 1;
                    bob_time_set.push_back(mp);
                    bob_time_node.push_back(i);
                    bob = i;
                    break;
                }
            }
        }
    }
    void traverse_alice(vector<vector<int>> &edges, unordered_map<int, int> bob_visited, unordered_map<int, int> alice_visited, vector<int> &bob_time_node, int alice_profit, int node_alice, int time, int &max_profit, vector<sv> &stk, vector<int> &amount)
    {
        int i;
        pair<int, int> pr;
        sv time_vals;
        int time = 0;
        int count_nodes = 1;
        while (!stk.empty())
        {
            node_alice = (stk.back()).row;
            time = (stk.back()).time;
            for (i = node_alice; i < edges[0].size(); i++)
            {
                if (edges[node_alice][i] == 1)
                {
                    count_nodes++;
                    if (alice_visited[i] == 0 && bob_visited[i] == 0)
                    {
                        time_vals.col = i;
                        time_vals.row = node_alice;
                        time_vals.time = time++;
                        stk.push_back(time_vals);
                        if (bob_time_node[time + 1] == i)
                        {
                            alice_profit = amount[i] / 2 + alice_profit;
                            alice_visited[i] = 1;
                            bob_visited[i] = 1;
                        }
                        else
                        {
                            alice_profit = amount[i] + alice_profit;
                            alice_visited[i] = 1;
                        }
                    }
                }
                bob_visited[bob_time_node[time]] = 1;
            }
            if (count_nodes == 1)
            {
                max_profit = max(alice_profit, max_profit);
            }
            stk.pop_back();
        }
    }
    int mostProfitablePath(vector<vector<int>> &edges, int bob, vector<int> &amount)
    {
        unordered_map<int, int> visited;
        vector<int> bob_time_node;
        traverse_bob(edges, bob, bob_time_node);
        int alice_profit = amount[0];
        int time = 0;
        // traverse_alice();
    }
};

class Solution
{
public:
    int numOfSubarrays(vector<int> &arr)
    {
        int sum = 0;
        long count = 0;
        vector<int> arr2 = arr;
        int n = arr2.size();
        for (int i = 0; i < arr2.size(); i++)
        {
            sum = sum + arr2[i];
            arr2[i] = sum;
        }
        for (int i = -1; i < arr2.size(); i++)
        {
            for (int j = n - 1; j >= i; j--)
            {
                sum = arr2[j] - arr2[i];

                if (sum % 2 != 0)
                {
                    count++;
                    cout << sum << endl;
                }
            }
        }
        return count;
    }
};