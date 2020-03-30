class Solution_Brutal {
    HashSet<String> exist=new  HashSet<String>();
    boolean find;
    int fullA,fullB,target;
    String Num2String(int x,int y){
        return x+","+y;
    }
    void search(int x,int y){
        if(exist.contains(Num2String(x,y))||find) return;
        exist.add(Num2String(x,y));
        if(x==target||y==target||x+y==target){
            find=true;return;
        }
        //fill A(x)
        search(fullA,y);
        //fill B(y)
        search(x,fullB);
        //empty A(x)
        search(0,y);
        //empty B(y)
        search(x,0);
        //A->B
        int newx=0,newy=x+y;
        if(newy>fullB){
            newx=newy-fullB;newy=fullB;
        }
        search(newx,newy);
        //B->A
        newx=x+y;newy=0;
        if(newx>fullA){
            newy=newx-fullA;newx=fullA;
        }
        search(newx,newy);
        return;
    }
    public boolean canMeasureWater(int x, int y, int z) {
        exist.clear();find=false;
        fullA=x;fullB=y;target=z;
        search(0,0);
        return find;
    }
}