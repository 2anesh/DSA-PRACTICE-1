class Solution {
    public List<String> removeSubfolders(String[] folder) {
        List<String> list = new ArrayList<>();
        Arrays.sort(folder);
        for(int i=0;i<folder.length;i++)
        {
            if(folder[i].equals(""))
            continue;
            String t1 = folder[i];
            for(int j=i+1;j<folder.length;j++)
            {
                if(!folder[j].equals("") && folder[j].startsWith(t1+"/"))
                folder[j]="";
                else if(!folder[j].startsWith(t1))
                break;
            }
        }
        for(int i=0;i<folder.length;i++)
        {
            if(folder[i].equals(""))
            continue;
            else
            list.add(folder[i]);
        }
        return list;
    }
}
