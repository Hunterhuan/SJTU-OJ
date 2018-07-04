#include <iostream>

using namespace std;

int box[26][26];
int num[26];
int N;
int pos[26];


bool islegal(int a,int b)
{
    if(a==b || pos[a]==pos[b])
        return false;
    return true;
}
void moveonto(int a,int b)
{
    if(!islegal(a,b))
        return;
    int pos_a = pos[a],pos_b = pos[b];
        for(;num[pos_a]>=0;--num[pos_a])
        {
            if(box[pos_a][num[pos_a]]==a)
                break;
            else
            {
                int tmp = box[pos_a][num[pos_a]];
                pos[tmp] = tmp;
                num[tmp]++;
                box[tmp][num[tmp]] = tmp;
            }
        }
        for(;num[pos_b]>=0;--num[pos_b])
        {
            if(box[pos_b][num[pos_b]]==b)
                break;
            else
            {
                int tmp = box[pos_b][num[pos_b]];
                pos[tmp] = tmp;
                num[tmp]++;
                box[tmp][num[tmp]] = tmp;
            }
        }
        pos[a] = pos[b];
        num[pos_b]++;
        box[pos_b][num[pos_b]] = a;
        --num[pos_a];
}

void moveover(int a,int b)
{
    if(!islegal(a,b))
        return;
    int pos_a = pos[a],pos_b = pos[b];
    for(;num[pos_a]>=0;--num[pos_a])
    {
        if(box[pos_a][num[pos_a]]==a)
            break;
        else
        {
            int tmp = box[pos_a][num[pos_a]];
            pos[tmp] = tmp;
            num[tmp]++;
            box[tmp][num[tmp]] = tmp;
        }
    }
    pos[a] = pos[b];
    num[pos_b]++;
    box[pos_b][num[pos_b]] = a;
    --num[pos_a];
}

void pileonto(int a,int b)
{
    if(!islegal(a,b))
        return;
    int pos_a = pos[a],pos_b = pos[b];
    for(;num[pos_b]>=0;--num[pos_b])
    {
        if(box[pos_b][num[pos_b]]==b)
               break;
        else
        {
            int tmp = box[pos_b][num[pos_b]];
            pos[tmp] = tmp;
            num[tmp]++;
            box[tmp][num[tmp]] = tmp;
        }
    }
    int posa;
    for(int i=0;i<26;++i)
    {
        if(box[pos_a][i]==a)
        {
            posa = i;
            break;
        }
    }
    for(int i=posa;i<=num[pos_a];++i)
    {
        int tmp = box[pos_a][i];
        pos[tmp] = pos_b;
        ++num[pos_b];
        box[pos_b][num[pos_b]]=tmp;
    }
    num[pos_a] = posa-1;
}

void pileover(int a,int b)
{
    if(!islegal(a,b))
        return;
    int pos_a = pos[a],pos_b = pos[b];
    int posa;
    for(int i=0;i<26;++i)
    {
        if(box[pos_a][i]==a)
        {
            posa = i;
            break;
        }
    }
    for(int i=posa;i<=num[pos_a];++i)
    {
        int tmp = box[pos_a][i];
        pos[tmp] = pos_b;
        ++num[pos_b];
        box[pos_b][num[pos_b]]=tmp;
    }
    num[pos_a] = posa-1;
}

void display()
{
    for(int i=0;i<N;++i)
    {
        cout<<i<<": ";
        for(int j=0;j<=num[i];++j)
            cout<<box[i][j]<<' ';
        cout<<endl;
    }
}
int main()
{
    for(int i=0;i<26;++i)
    {
        pos[i] = i;
        box[i][0] = i;
    }
    cin>>N;
    char s[10];
    while(true)
    {
        int a,b;
        cin>>s;
        if(s[0]=='m')
        {
            cin>>a;
            cin>>s;
            cin>>b;
            if(s[1]=='n')
                moveonto(a,b);
            else
                moveover(a,b);

        }
        else if(s[0]=='p')
        {
            cin>>a;
            cin>>s;
            cin>>b;
            if(s[1]=='n')
                pileonto(a,b);
            else
                pileover(a,b);
        }
        else
            {
                display();
                break;}
    }
    return 0;
}
