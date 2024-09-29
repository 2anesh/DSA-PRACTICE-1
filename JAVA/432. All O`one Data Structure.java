class AllOne {
    private class BucketNode{
        int val;
        BucketNode count;
        BucketNode pre;
        BucketNode next;
        Set<String> keySet;
        private BucketNode(int val){
            this.val = val;
            keySet = new HashSet<>();
        }
    }
    private BucketNode head;
    private BucketNode tail;
    private Map<String, Integer> keyValueMap;
    private Map<Integer, BucketNode> valueBucketMap;
    public AllOne() {
         head = new BucketNode(Integer.MIN_VALUE);
         tail = new BucketNode(Integer.MAX_VALUE);
         keyValueMap  = new HashMap<>();
         valueBucketMap = new HashMap<>();
         head.next = tail;
         tail.pre = head;
    }
    public void inc(String key) {
        if(keyValueMap.containsKey(key)){
            changeValue(key, 1);            
        }
        else{
            if(head.next.val != 1){
                addBucketAfter(new BucketNode(1),head);
            }
            head.next.keySet.add(key);
            keyValueMap.put(key, 1);
            valueBucketMap.put(1, head.next);
        }
    }
    public void dec(String key) {
        if(keyValueMap.containsKey(key)){
            if(keyValueMap.get(key) == 1){
                keyValueMap.remove(key);
                removeKeyfromBucket(valueBucketMap.get(1), key);
            }
            else{
                changeValue(key, -1);
            }
        }        
    }
    public String getMaxKey() {
        return tail.pre == head? "": (String)tail.pre.keySet.iterator().next();
    }
    public String getMinKey() {
        return head.next == tail? "": (String)head.next.keySet.iterator().next();
    }
    private void changeValue(String key, int offset){
        int curVal = keyValueMap.get(key);
        BucketNode curBucket = valueBucketMap.get(curVal);
        BucketNode newBucket;
        if(valueBucketMap.containsKey(curVal + offset)){
            newBucket = valueBucketMap.get(curVal + offset);
        }
        else{
            newBucket = new BucketNode(curVal + offset);
            addBucketAfter(newBucket, offset == 1 ?curBucket: curBucket.pre);
            valueBucketMap.put(curVal + offset, newBucket);
        }
        removeKeyfromBucket(curBucket, key);
        newBucket.keySet.add(key);
        keyValueMap.put(key, curVal + offset);
    }
    private void addBucketAfter(BucketNode newBucket, BucketNode pre){
        newBucket.pre = pre;
        newBucket.next = pre.next;
        pre.next.pre = newBucket;
        pre.next = newBucket;
    }
    private void removeKeyfromBucket(BucketNode bucket, String key){
        bucket.keySet.remove(key);
        if(bucket.keySet.size() == 0){
            removeBucketfromBucketList(bucket);
            valueBucketMap.remove(bucket.val);
        }
    }
    private void removeBucketfromBucketList(BucketNode bucket){
        bucket.pre.next = bucket.next;
        bucket.next.pre = bucket.pre;
        bucket.pre = null;
        bucket.next = null;
    }
