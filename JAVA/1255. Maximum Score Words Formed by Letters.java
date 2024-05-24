class Solution {
public int maxScoreWords(String[] words, char[] letters, int[] score) {    
    int[] letter = new int[26];
    for(char ch: letters){        
        letter[ch-'a']++;
    }
    return maxScore(words, letter, score, 0);
}
int maxScore(String[] words, int[] letters, int[] score, int i){    
    if(i == words.length) return 0;    
    int include = 0;  
    int[] left = letters.clone();      
    for(char ch: words[i].toCharArray()){        
        left[ch-'a']--;
        if(left[ch-'a'] == -1){            
            include = -1;
            break;
        }
        include += score[ch-'a'];
    }    
    if(include == -1) return maxScore(words, letters, score, i+1);    
    return Math.max(include + maxScore(words, left, score, i+1), maxScore(words, letters, score, i+1));
}
}
