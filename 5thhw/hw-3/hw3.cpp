#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstdio>
using namespace std;
#include<stdio.h>

class Mul
{
    public:
        char* Str_Add(char*,char*,int);
        char* Str_Sub(char*,char*,int);
        char* Str_Multiple(char*,char*,int);
        char* Multiple(char*,char*);
    private:
        char multmp[129];
        char addtmp[129];
        char subtmp[129];
        char ans[258];
};

char* Mul::Str_Add(char*buff1,char*buff2,int N)
{
    int n=0;
    char addbuff[N+2];
    for(int i=0;i<N;i++)
    {
            addbuff[i]=((buff1[N-1-i]-'0'+buff2[N-1-i]-'0'+n)%10)+'0';
            n=(buff1[N-1-i]-'0'+buff2[N-1-i]-'0'+n)/10;
    }
    if(n==0) 
        addbuff[N]='\0';
    else     {
        addbuff[N]=n+'0';
        addbuff[N+1]='\0';
    }
    memset(addtmp,0,strlen(addtmp));   
    for(int i=strlen(addbuff)-1;i>=0;i--)
    {
        
        addtmp[strlen(addbuff)-i-1]=addbuff[i];
    }
    addtmp[strlen(addbuff)]='\0';
    return addtmp;
}
char* Mul::Str_Sub(char*buff1,char*buff2,int N)
{
    char buff3[N+1];
    int t=strlen(buff2)-strlen(buff1);

    for(int i=0;i<N;i++){
        if(t+i<0)
                buff3[i]=9;
        else
                buff3[i]='9'-buff2[i+t];    
    }    

    buff3[N-1]+=1; buff3[N]='\0';
    for(int i=N-1;i>=0;i--){
        if(buff3[i]>9) {
            buff3[i-1]+=1;
            buff3[i]=buff3[i]-10;
        }    
        buff3[i]+='0';    
    }      
    strcpy(subtmp,Str_Add(buff1,buff3,N)+1);
    return subtmp;
    
}
char* Mul::Multiple(char* buff1,char* buff2)
{
    unsigned long long int l_buf;

    cout<<atoll(buff1)<<" * "<<atoll(buff2);
    l_buf=atoll(buff1)*atoll(buff2);
    cout<<" = "<<l_buf<<endl;

    sprintf(multmp,"%llu",l_buf);
    return multmp;    
}
char* Mul::Str_Multiple(char* U,char* V,int N)
{   
    char buff[2*N+1];
    if(N<=9)
        return Multiple(U,V);
    else{
        
        char W[N/2+1],X[N/2+1];
        char Y[N/2+1],Z[N/2+1];
        char P[N+1],Q[N+1],R[N+1];
        char U_t[N/2+1],V_t[N/2+1];
        char mid[N/2+1];
        
        
        memcpy(W,&U[0],strlen(U)-N/2);
        if(strlen(U)%2==0){
                memcpy(X,&U[strlen(U)-N/2],N/2);
                X[N/2]='\0';
        }
        else{
            X[0]='0';
            memcpy(X+1,&U[strlen(U)-N/2],N/2);
            X[N/2+1]='\0';
        }    
        memcpy(Y,&V[0],strlen(V)-N/2);
        if(strlen(V)%2==0){    
            memcpy(Z,&V[strlen(V)-N/2],N/2);
            Z[N/2]='\0';
        }
        else{
            Z[0]='0';
            memcpy(Z+1,&V[strlen(V)-N/2],N/2);
            Z[N/2+1]='\0';
        }    
      
        W[strlen(U)-N/2]='\0';
        Y[strlen(V)-N/2]='\0';

        
        cout<<"U:"<<U<<" W:"<<W<<" X:"<<X<<endl;
        cout<<"V:"<<V<<" Y:"<<Y<<" Z:"<<Z<<endl;        
        
        strcpy(P,Str_Multiple(W,Y,strlen(W)));
        strcpy(Q,Str_Multiple(X,Z,strlen(X)));
        
        strcpy(U_t,Str_Add(W,X,strlen(W)));
        strcpy(V_t,Str_Add(Y,Z,strlen(X)));
        
        strcpy(R,Str_Multiple(U_t,V_t,strlen(U_t)));
        strcpy(mid,Str_Sub(Str_Sub(R,P,strlen(R)),Q,strlen(R)));

                
        memset(buff,0,2*N+1);
        
        for(int i=0;i<strlen(Q);i++)   buff[i]+=Q[strlen(Q)-1-i]-'0';       
        for(int i=0;i<strlen(mid);i++) buff[i+(N/2)]+=mid[strlen(mid)-1-i]-'0';          
        for(int i=0;i<strlen(P);i++)   buff[i+(N/2)*2]+=P[strlen(P)-1-i]-'0';        
        buff[N+strlen(P)]='\0';
        
        for(int i=0;i<N+strlen(P);i++) {
            buff[i+1]+=buff[i]/10;
            buff[i]=buff[i]%10;            
            buff[i]+='0'; 
        }    
                
        memset(ans,0,strlen(ans));
        for(int i=0;i<strlen(buff);i++)        ans[i]=buff[strlen(buff)-1-i];
        ans[strlen(buff)]='\0';

        cout<<"P "<<P<<"\nQ "<<Q<<"\nR "<<R<<endl;
        cout<<"R-P-Q "<<mid<<"\nans "<<ans<<"\n\n";

        return ans;        
    }
}
int main()
{
    char num1[129],num2[129];
    char filename[20];

    cout << "Input filename:";
    cin  >> filename;

//    ifstream fin ("hw3.txt"); 
    ifstream fin (filename);
    fin >> num1>>num2;
    fin.close();
    
    class Mul hw_3;
    
    cout<<"\nInput: "<<num1<<" "<<num2<<endl;
    cout<<hw_3.Str_Multiple(num1,num2,strlen(num1))<<endl;
    
    return 0;
    
}
