class Solution {
  static void merge(ArrayList<HashSet> a,ArrayList<HashSet> res,
                      List<List<String>> accounts,int j){
      if(a.size()==1){
          fill(accounts,a.get(0),j);
      }
      else{
          HashSet<String> uwu=new HashSet<>();
          for(HashSet<String> u:a){
              for(String gg:u){
                  uwu.add(gg);
              }
              res.remove(u);
          }
          fill(accounts,uwu,j);
          res.add(uwu);   
      }
  }     
  static void fill(List<List<String>> accounts,HashSet<String> y,int j){
      for(int i=1;i<accounts.get(j).size();i++){
          if(!y.contains(accounts.get(j).get(i))){
              y.add(accounts.get(j).get(i));
          }
      }
      
  }
  static List<List<String>> accountsMerge(List<List<String>> accounts){
      List<List<String>> res=new ArrayList<List<String>>();
      HashMap<String,ArrayList<HashSet>> mp=new HashMap<>();
      for(int i=0;i<accounts.size();i++){
          boolean flag = false;
          String name=accounts.get(i).get(0);
          if(mp.containsKey(name)){
              ArrayList<HashSet> x=mp.get(name);
              ArrayList<HashSet> merged=new ArrayList<>();
              
              for(int j=0;j<x.size();j++){
                  HashSet<String> y=x.get(j);
                  for(int k=1;k<accounts.get(i).size();k++){
                      if(y.contains(accounts.get(i).get(k))){
                          merged.add(y);
                          flag=true;
                      }
                  }
              }
              if(flag==false){
                  HashSet<String> z=new HashSet<>();
                  for(int k=1;k<accounts.get(i).size();k++){
                      z.add(accounts.get(i).get(k));
                  }
                  x.add(z);
              }
              else{
                  merge(merged,x,accounts,i);
              }
          }
          else{
              ArrayList<HashSet> temp=new ArrayList<HashSet>();
              HashSet<String> s=new HashSet<>();
              for(int u=1;u<accounts.get(i).size();u++){
                  s.add(accounts.get(i).get(u));
              }
              temp.add(s);
              mp.put(name,temp);
          }
      }
      for(String name : mp.keySet()){
          ArrayList<HashSet> curr=mp.get(name);
          for(int i=0;i<curr.size();i++){
              List<String> hm=new ArrayList<String>();
              hm.add(name);
              HashSet<String> set=curr.get(i);
              for(String s : set){
                  hm.add(s);
              }
              Collections.sort(hm);
              res.add(hm);
          }
      }
      return res;
      
  }
}
