int func(int n){
        int p = 1;
        while(n){
            int dig = n%10;
            p *= dig;
            n /= 10;
        }
        return p;
    }
    int smallestNumber(int n, int t) {
        int i = n;
        while(true){
            int prod = func(i);
            if(prod%t==0) return i;
            i++;
        }
        return -1;
    }