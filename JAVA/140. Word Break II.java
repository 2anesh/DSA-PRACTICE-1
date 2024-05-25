class Solution {
    public List<String> wordBreak(String s, List<String> wordDict) {
        return test(s, wordDict);
    }    
    private List<String> test(String s, List<String> wordDict) {
        Trie trie = new Trie();
        for(String word : wordDict) trie.add(word);        
        var queue = new LinkedList<Sentence>();
        var result = new ArrayList<String>();
        queue.offer(new Sentence());
        char[] chArr = s.toCharArray();        
        while(!queue.isEmpty()) {
            Sentence sentence = queue.poll();          
            Node parent = trie.root;
            for(int i = sentence.index; i < s.length(); i++) {
                Node child = parent.getChild(chArr[i]);
                if(child == null) break;
                if(child.isWord) {
                    List<String> newWords = new ArrayList<String>(sentence.words);
                    String newWord = s.substring(sentence.index, i + 1);
                    newWords.add(newWord);
                    if(i == s.length() - 1) {
                        var sb = new StringBuilder();
                        for(String w : newWords) sb.append(w).append(" ");
                        result.add(sb.toString().trim());
                    } else {
                        Sentence newSentence = new Sentence();
                        newSentence.index = i + 1;
                        newSentence.words = newWords;
                        queue.offer(newSentence);
                    }
                }
                parent = child;
            }
        }
        return result;
    }   
    static class Sentence {
        List<String> words = new ArrayList<>();
        int index = 0;
    }    
    static class Trie {
        Node root = new Node('-');
        public void add(String word) {
            Node parent = root;
            for(char ch : word.toCharArray()) {
                Node child = parent.hasChild(ch) ? parent.getChild(ch) : new Node(ch);
                parent.addChild(ch, child);
                parent = child;
            }
            parent.isWord = true;
        }
    }    
    static class Node {
        char ch;
        Node[] children = new Node[26];
        boolean isWord;        
        public Node(char ch) {
            this.ch = ch;
        }        
        public boolean hasChild(char ch) {
            return children[ch - 'a'] != null;
        }       
        public Node getChild(char ch) {
            return children[ch - 'a'];
        }       
        public void addChild(char ch, Node child) {
            children[ch - 'a'] = child;
        }
    }
}
