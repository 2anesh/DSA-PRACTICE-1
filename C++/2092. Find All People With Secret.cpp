class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
      vector<bool> discovered(n, false);
        discovered[0] = true;
        discovered[firstPerson] = true;
        sort(meetings.begin(), meetings.end(), [](const auto& a, const auto& b) {
            return a[2] < b[2];
        });
        for (int i = 0, meetingsCount = meetings.size(); i < meetingsCount; ) {
            int endIndex = i;
            while (endIndex + 1 < meetingsCount && meetings[endIndex + 1][2] == meetings[i][2]) {
                ++endIndex;
            }
            unordered_map<int, vector<int>> graph;
            unordered_set<int> participants;
            for (int k = i; k <= endIndex; ++k) {
                int personA = meetings[k][0], personB = meetings[k][1];
                graph[personA].push_back(personB);
                graph[personB].push_back(personA);
                participants.insert(personA);
                participants.insert(personB);
            }
            queue<int> queuePeople;
            for (int person : participants) {
                if (discovered[person]) {
                    queuePeople.push(person);
                }
            }
            while (!queuePeople.empty()) {
                int currentPerson = queuePeople.front();
                queuePeople.pop();
                for (int neighbour : graph[currentPerson]) {
                    if (!discovered[neighbour]) {
                        discovered[neighbour] = true;
                        queuePeople.push(neighbour);
                    }
                }
            }
            i = endIndex + 1;
        }
        vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (discovered[i]) {
                result.push_back(i);
            }
        }
        return result;  
    }
};
