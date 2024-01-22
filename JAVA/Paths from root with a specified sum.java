class Solution
{
    
    public static void helper(ArrayList<ArrayList<Integer>> list,Node root,int sum,ArrayList<Integer>temp,int target){
        if(root==null) return;
        
        sum+=root.data;
        temp.add(root.data);
        if(sum==target){
            list.add(new ArrayList<>(temp));
        }
        helper(list,root.left,sum,temp,target);
        helper(list,root.right,sum,temp,target);
        
        sum-=root.data;
        temp.remove(temp.size()-1);
        
    }
    public static ArrayList<ArrayList<Integer>> printPaths(Node root, int sum)
    {
        // code here
        ArrayList<ArrayList<Integer>> list = new ArrayList<>();
        helper(list,root,0,new ArrayList<>(),sum);

        return list;
    }
}
