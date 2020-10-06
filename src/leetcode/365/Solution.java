class Solution {
    public int gcd(int x,int y){
        if(x*y==0) return x+y;
        return x%y==0?y:gcd(y,x%y);
    }
    public boolean canMeasureWater(int x, int y, int z) {
        if(x+y<z) return false;
        if(z==0) return true;
        int GCD=gcd(x,y);
        if(GCD==0) return false;
        return z%GCD==0;
    }
}