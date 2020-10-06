class Twitter {
    private HashSet<String> follow;//"x,y"表示x follow y
    private ArrayList<String> tweets;//tweets[t]="x,y"表示在t时刻x发了y
    private int tweetsTot;//当前tweets总数，同时表示当前时刻

    /** Initialize your data structure here. */
    public Twitter() {
        follow=new HashSet<String>();
        tweets=new ArrayList<String>();
        tweetsTot=0;
    }
    
    /** Compose a new tweet. */
    public void postTweet(int userId, int tweetId) {
        String s=userId+","+tweetId;
        tweets.add(s);
        tweetsTot++;
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    public List<Integer> getNewsFeed(int userId) {
        List<Integer> ans=new ArrayList<Integer>();
        for(int i=tweetsTot-1;i>=0;i--){
            String[] tweet=tweets.get(i).split(",");
            if(Integer.parseInt(tweet[0])==userId){
                ans.add(Integer.parseInt(tweet[1]));
            }else{
                String s=userId+","+tweet[0];
                if(follow.contains(s)){
                    ans.add(Integer.parseInt(tweet[1]));
                }
            }
            if(ans.size()==10) break;
        }
        return ans;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    public void follow(int followerId, int followeeId) {
        String s=followerId+","+followeeId;
        if(!follow.contains(s)) follow.add(s);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    public void unfollow(int followerId, int followeeId) {
        String s=followerId+","+followeeId;
        if(follow.contains(s)) follow.remove(s);
    }
}

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * List<Integer> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */