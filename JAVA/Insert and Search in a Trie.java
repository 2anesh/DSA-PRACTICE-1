static void insert(TrieNode root, String key) 
{
    for(char ch: key.toCharArray()){
        if(root.children[ch-'a'] == null){
            root.children[ch-'a'] = new TrieNode();
        }
        root = root.children[ch-'a'];
    }
    root.isEndOfWord = true;
}
static boolean search(TrieNode root, String key)
{
    for(char ch: key.toCharArray()){
        if(root.children[ch-'a'] == null){
            return false;
        }
        root = root.children[ch-'a'];
    }
    return root.isEndOfWord;
}
