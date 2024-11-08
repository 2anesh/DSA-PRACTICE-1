class Solution {
private:
    struct Node {
        int maxLen, prefixLen, suffixLen;
        Node(int val = 0) : maxLen(val), prefixLen(val), suffixLen(val) {}
    };
    vector<Node> segTree;
    string s;

    void build(int node, int start, int end) {
        if (start == end) {
            segTree[node] = Node(1);
            return;
        }
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        combine(node, start, end);
    }

    void combine(int node, int start, int end) {
        int mid = (start + end) / 2;
        int left = 2 * node, right = 2 * node + 1;
        
        Node& parent = segTree[node];
        Node& leftChild = segTree[left];
        Node& rightChild = segTree[right];

        parent.maxLen = max(leftChild.maxLen, rightChild.maxLen);
        parent.prefixLen = leftChild.prefixLen;
        parent.suffixLen = rightChild.suffixLen;

        if (s[mid] == s[mid + 1]) {
            int borderLen = leftChild.suffixLen + rightChild.prefixLen;
            parent.maxLen = max(parent.maxLen, borderLen);
            
            if (leftChild.prefixLen == mid - start + 1)
                parent.prefixLen += rightChild.prefixLen;
            if (rightChild.suffixLen == end - mid)
                parent.suffixLen += leftChild.suffixLen;
        }
    }

    void update(int node, int start, int end, int idx, char newChar) {
        if (start == end) {
            s[idx] = newChar;
            segTree[node] = Node(1);
            return;
        }

        int mid = (start + end) / 2;
        if (idx <= mid)
            update(2 * node, start, mid, idx, newChar);
        else
            update(2 * node + 1, mid + 1, end, idx, newChar);

        combine(node, start, end);
    }
public:
    vector<int> longestRepeating(string str, string queryCharacters, vector<int>& queryIndices) {
        s = str;
        int n = s.length();
        segTree.resize(4 * n);
        build(1, 0, n - 1);

        vector<int> results;
        for (int i = 0; i < queryCharacters.size(); ++i) {
            update(1, 0, n - 1, queryIndices[i], queryCharacters[i]);
            results.push_back(segTree[1].maxLen);
        }
        return results;
    }
};
