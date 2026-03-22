class Solution {
public:
    string fractionAddition(string expression) {
        int num=0, den=1;
        int i=0, n= expression.size();
        while(i<n){
            int sign=1,cnum=0,cden=0;
            if(expression[i]=='+') i++;
            else if(expression[i]=='-'){
                i++;
                sign=-1;
            }
            int tnos=0;
            sscanf(expression.c_str()+i,"%d/%d%n",&cnum,&cden,&tnos);
            i+=tnos;
            cnum*=sign;
            num=cnum*den+num*cden;
            den=den*cden;
            int d= __gcd(abs(num),den);
            num=num/d;
            den=den/d;
        }
        return to_string(num)+"/"+to_string(den);
    }
};