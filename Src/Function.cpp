int add(int a,int b){
    ans=a+b;
    return ans;
}

int sub(int a,int b){
    ans=a-b;
    return ans;
}

int mul(int a,int b){
    ans=a*b;
    return ans;
}

int divide(int a,int b){
    ans=a/b;
    return ans;
}
 
void initStack(){
    TOP=-1;
}

int isEmpty(){
    if(TOP==-1)
        return 1;
    else
        return 0;
}
 
int isFull(){
    if(TOP==MAX-1)
        return 1;
    else   
        return 0;
}
 
void push(int num){
    if(isFull()){
        cout<<"STACK is FULL."<<endl;
        return; 
    }
    ++TOP;
    STACK[TOP]=num;
}
 
void display(){
    int i;
    cout<<"Your memory is:";
    if(isEmpty()){
        cout<<"Nothing in memory"<<endl;
        return;
    }
    for(i=TOP;i>=0;i--){
        cout<<STACK[i]<<" ";
    }
    cout<<endl;
}