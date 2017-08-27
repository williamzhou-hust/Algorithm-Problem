//
//  main.cpp
//  wangyiceshi
//
//  Created by William Zhou on 2017/3/25.
//  Copyright © 2017年 William Zhou. All rights reserved.
//

/*#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    //cin>>s;
    s="3+5*7";
    string::size_type N=s.length();
    string tt(N,' ');
    int s_head=0,tt_head=0;
    for(s_head=0;s_head<N;){
        if(s[s_head]!='*'){
            tt[tt_head]=s[s_head];
            ++tt_head;
            ++s_head;
        }
        else if(s[s_head]=='*'){//s_head>0&&s_head<N-1&&
            tt[tt_head-1]='0'+(tt[tt_head-1]-'0')*(s[s_head+1]-'0');
            s_head+=2;
        }
    }
    int sum=tt[0]-'0';
    for(int j=0;j<tt_head;){
        if(tt[j]=='+'||tt[j]=='-'){
            sum+=(tt[j+1]-'0');
            j+=2;
        }
        else ++j;
    }
    cout<<sum<<endl;
}*/

/*#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    //cin>>s;
    s="3+5*7";
    int N=s.length();
    int sum=s[0]-'0';
    for(int i=1;i<N;){
        if(s[i]=='+'){
            sum+=(s[i+1]-'0');
            i+=2;
        }
        else if(s[i]=='-'){
            sum-=(s[i+1]-'0');
            i+=2;
        }
        else if(s[i]=='*'){
            sum*=(s[i+1]-'0');
            i=i+2;
        }
        else ++i;
    }
    cout<<sum<<endl;
}*/
/*#include <iostream>
#include <set>
using namespace std;
int main() {
    int w,x,y,z;
    cin>>w>>x>>y>>z;
    set<double> answer;
    for(int i=w;i<=x;i++)
        for(int j=y;j<=z;j++){
            answer.insert(i/j);
        }
    cout<<answer.size()<<endl;
}*/
/*#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int sum1=0,sum2=0;
    int n;
    cin>>n;
    vector<int> length(n);
    for(int i=0;i<n;i++){
        cin>>length[i];
        //sum+=length[i];
    }
    int sum=0;
    for(int i=0;i<5;i++){
        sum+=length[i];
    }
    sum1=length[0];
    for(int i=1;i<n;i++){
        if(sum1+length[i]<sum/2){
            sum1+=length[i];
        }
        else{
            sum2+=length[i];
        }
    }
    cout<<max(sum1,sum2)<<endl;
}*/
/*
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int N=0;
    while(cin>>N){
        vector<int> mvec(N,0);
        for(int i=0;i<N;i++){
            cin>>mvec[i];
        }
        sort(mvec.begin(),mvec.end());
        //for(int i=0;i<N;i++) cout<<mvec[i]<<" ";
        //cout<<endl;
        vector<int>::iterator ite=unique(mvec.begin(),mvec.end());
        //for(int i=0;i<N;i++) cout<<mvec[i]<<" ";
        //cout<<endl;
        mvec.erase(ite,mvec.end());
        //for(int i=0;i<mvec.size();i++) cout<<mvec[i]<<" ";
        //cout<<endl;
        if(mvec.size()>=3)
            cout<<mvec[2]<<endl;
        else
            cout<<-1;
    }
    return 0;
}*/

/*#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc,char* argv[]){
    int N=0;
    while(cin>>N){
        vector<int> mvec_a(N,0);
        vector<int> mvec_b;
        for(int i=0;i<N;i++){
            cin>>mvec_a[i];
            mvec_b.push_back(mvec_a[i]);
            reverse(mvec_b.begin(),mvec_b.end());
        }
        for(int i=0;i<N-1;i++)
            cout<<mvec_b[i]<<" ";
        cout<<mvec_b[N-1]<<endl;
    }
    return 0;
}*/


/*include <iostream>
using namespace std;
int main(int argc,char* argv[]){
    int x=0,f=0,d=0,p=0;
    while(cin>>x>>f>>d>>p){
        int ans=0;
        if(f*x>d) ans=d/x;
        else ans=f+(d-f*x)/(p+x);
        cout<<ans;
    }
    return 0;
}*/

/*#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(int argc,char* argv[]){
    int N;
    while(cin>>N){
        vector<int> mvec(N,0);
        for(int i=0;i<N;i++){
            cin>>mvec[i];
        }
        sort(mvec.begin(),mvec.end());
        int abs_sum=0;
        vector<int> b(N,0);
        if(!(N&0x1)){
            for(int i=0;i<N/2-1;i++){
                b[2*i+1]=mvec[i];
                b[2*i+2]=mvec[N-1-i];
            }
            b[0]=mvec[N/2];
            b[N-1]=mvec[N/2-1];
        }
        if(N&0x1){
            if(2*mvec[N/2]<mvec[1]+mvec[N/2+1]){
                for(int i=0;i<N/2;i++){
                    b[2*i]=mvec[i];
                    b[2*i+1]=mvec[N-1-i];
                }
                b[N-1]=mvec[N/2];
            }
            else{
                b[0]=mvec[N/2];
                for(int i=0;i<N/2;i++){
                    b[2*i+1]=mvec[i];
                    b[2*i+2]=mvec[N-1-i];
                }
            }
        }
        for(auto item:b)
            cout<<item<<" ";
        cout<<endl;
        for(int i=0;i<N-1;i++)
            abs_sum+=abs(b[i]-b[i+1]);
        cout<<abs_sum<<endl;
    }
    return 0;
}*/

/*#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct score{
    int a;
    int b;
} score;

bool isShorter(const score& ra,const score& rb){
    return ra.b<rb.b;
}

int main(int argc,char* argv[]){
    int n=0,r=0,avg=0;
    while(cin>>n>>r>>avg){
        vector<score> sc;
        score temp;
        int ans=0;
        int sum=0;
        for(int i=0;i<n;i++){
            cin>>temp.a>>temp.b;
            sc.push_back(temp);
            sum+=temp.a;
        }
        if(sum>=n*avg) cout<<0<<endl;
        else{
            int diff=n*avg-sum;
            sort(sc.begin(),sc.end(),isShorter);
            //for(auto item:sc){
            //    cout<<item.a<<" "<<item.b<<endl;
            //}
            for(int i=0;i<n;i++){
                if(sc[i].a<r){
                    if(r-sc[i].a<=diff){
                        ans+=(r-sc[i].a)*sc[i].b;
                        //cout<<ans<<endl;
                        diff-=r-sc[i].a;
                    }
                    else{
                        ans+=diff*sc[i].b;
                        //cout<<ans<<endl;
                        break;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}*/

/*#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(int argc,char* argv[]){
    int n;
    while(cin>>n){
        vector<int> mvec(n,0);
        for(int i=0;i<n;i++){
            cin>>mvec[i];
        }
        sort(mvec.begin(),mvec.end());
        vector<int>::iterator end_unique=unique(mvec.begin(),mvec.end());
        mvec.erase(end_unique,mvec.end());
        cout<<mvec.size()<<endl;
        for(int i=0;i<mvec.size();i++){
            cout<<mvec[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}*/

/*#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(int argc,char* argv[]){
    int n;
    while(cin>>n){
        vector<int> mvec(n,0);
        for(int i=0;i<n;i++){
            cin>>mvec[i];
        }
        int count=0;
        int i=0,j=n-1;
        while(i<j){
            while(mvec[i]!=3) ++i;
            while(mvec[j]==3) --j;
            if(i<j){
                swap(mvec[i],mvec[j]);
                count++;
            }
        }
        i=0,j=n-1;
        while(i<j){
            while(mvec[i]!=2) ++i;
            while(mvec[j]!=1) --j;
            if(i<j){
                swap(mvec[i],mvec[j]);
                count++;
            }
        }
        cout<<count<<endl;
    }
    return 0;
}*/

/*#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(int argc,char* argv[]){
    int n;
    while(cin>>n){
        vector<int> mvec(n,0);
        for(int i=0;i<n;i++){
            cin>>mvec[i];
        }
        sort(mvec.begin(),mvec.end());
        vector<int>::iterator end_unique=unique(mvec.begin(),mvec.end());
        mvec.erase(end_unique,mvec.end());
        cout<<mvec.size()<<endl;
        for(int i=0;i<mvec.size()-1;i++){
            cout<<mvec[i]<<" ";
        }
        cout<<mvec[mvec.size()-1]<<endl;
    }
    return 0;
}*/

/*#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct node{
    int x;
    int y;
    int d;
}node;

bool isShorter(const node& a,const node& b){
    return a.d<b.d;
}

bool isShorter_x(const node& a,const node& b){
    return a.x<b.x;
}

bool isMax(const node& a,const node& b){
    if(a.x>=b.x&&a.y>=b.y)
        return true;
    return false;
}

int main(int argc,char* argv[]){
    int n;
    node temp;
    while(cin>>n){
        vector<node> mvec;
        vector<node> ans;
        for(int i=0;i<n;i++){
            cin>>temp.x>>temp.y;
            temp.d=temp.x*temp.x+temp.y*temp.y;
            mvec.push_back(temp);
        }
        sort(mvec.begin(),mvec.end(),isShorter);
        //for(auto item:mvec){
        //    cout<<item.x<<" "<<item.y<<" "<<item.d<<endl;
        //}
        for(int i=n-1;i>=0;i--){
            bool brk=false;
            for(int j=n-1;j!=i&&j>=0;j--){
                if(isMax(mvec[j],mvec[i])){
                    brk=true;
                    break;
                }
            }
            if(!brk)
                ans.push_back(mvec[i]);
        }
        sort(ans.begin(),ans.end(),isShorter_x);
        for(int i=0;i<ans.size();i++)
            cout<<ans[i].x<<" "<<ans[i].y<<endl;
    }
    return 0;
}*/

/*#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void count_sort(vector<int>& A,vector<int>& B,int k)
{
    int *C = (int *)malloc((k+1) * sizeof(int));
    int i,j;
    for(i=0;i<=k;i++)//初始化数组C
        C[i]=0;
    
    for(j=0;j<=A.size()-1;j++)//计算A中元素的个数
        C[A[j]] = C[A[j]]+1;
    for(i=1;i<=k;i++)//计算小于等于C[i]的元素的个数
        C[i] = C[i] + C[i-1];
    for(j=(int)A.size()-1;j>=0;j--)
    {
        int k=C[A[j]]-1;
        B[k] = A[j];
        C[A[j]] = C[A[j]] - 1;
    }
    free(C);
}

int main(int argc,char* argv[]){
    int n;
    while(cin>>n){
        vector<int> mvec(n,0);
        vector<int> mvec_2(n,0);
        for(int i=0;i<n;i++){
            cin>>mvec[i];
        }
        count_sort(mvec,mvec_2,100);
        for(auto item:mvec_2){
            cout<<item<<endl;
        }
        long max=0;
        for(int i=1;i<=n;i++){
            long sum=0;
            for(int j=n-1;j>=n-i;j--){
                sum+=mvec_2[j];
            }
            long temp=sum*mvec_2[n-i];
            if(temp>max)
                max=temp;
        }
        cout<<max<<endl;
    }
    return 0;
}*/
/*
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <unordered_set>
#include <vector>
#include <string>
#include <iostream>
#define MAX_DICT_LEN 255
#define MAX_STR 255
using namespace std;

typedef struct simple_str {
    const char * str;
    int len;
} simple_str_t;

void wordBreakDFS(string &s, unordered_set<string> &wordDict, int start, vector<bool> &possible, string &out, vector<string> &res) {
    if (start == s.size()) {
        res.push_back(out.substr(0, out.size() - 1));
        return;
    }
    for (int i = start; i < s.size(); ++i) {
        string word = s.substr(start, i - start + 1);
        if (wordDict.find(word) != wordDict.end() && possible[i + 1]) {
            out.append(word).append(" ");
            int oldSize = res.size();
            wordBreakDFS(s, wordDict, i + 1, possible, out, res);
            if (res.size() == oldSize) possible[i + 1] = false;
            out.resize(out.size() - word.size() - 1);
        }
    }
}

vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
    vector<string> res;
    string out;
    vector<bool> possible(s.size() + 1, true);
    wordBreakDFS(s, wordDict, 0, possible, out, res);
    return res;
}

int calcuBlank(const string& s){
    int n=s.length();
    int ans=0;
    for(int i=0;i<n;i++){
        if(s[i]==' ')
            ++ans;
    }
    return n;
}

void mincut(simple_str_t* str, simple_str_t* dict, int dict_len) {
    unordered_set<string> wordDict;
    string s=str->str;
    for(int i=0;i<dict_len;i++){
        wordDict.insert(dict[i].str);
    }
    vector<string> ans=wordBreak(s,wordDict);
    //for(auto item:ans)
    //    cout<<item<<endl;
    int min=0x7FFFFFFF,index=0;
    for(int i=0;i<ans.size();i++){
        if(calcuBlank(ans[i])<min){
            min=calcuBlank(ans[i]);
            index=i;
        }
    }
    cout<<ans[index]<<endl;
}

int main(int argc, const char * argv[]) {
    char strS[MAX_STR];
    char dictStr[MAX_STR];
    int nDict;
    simple_str_t dict[MAX_DICT_LEN];
    simple_str_t srcStr;
    
    scanf("%s", strS);
    scanf("%d", &nDict);
    
    srcStr.str = strdup(strS);
    srcStr.len = strlen(strS);
    
    for (int i = 0; i < nDict; i++)
    {
        scanf("%s", strS);
        dict[i].str = strdup(strS);
        dict[i].len = strlen(strS);
    }
    
    mincut(&srcStr, dict, nDict);
    
    return 0;
}*/

/*#include <set>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

void wordBreakDFS(string &s,const set<string> &wordDict, int start, vector<bool> &possible, string &out, vector<string> &res) {
    if (start == s.size()) {
        res.push_back(out.substr(0, out.size() - 1));
        return;
    }
    for (int i = start; i < s.size(); ++i) {
        string word = s.substr(start, i - start + 1);
        if (wordDict.find(word) != wordDict.end() && possible[i + 1]) {
            out.append(word).append(" ");
            int oldSize = res.size();
            wordBreakDFS(s, wordDict, i + 1, possible, out, res);
            if (res.size() == oldSize) possible[i + 1] = false;
            out.resize(out.size() - word.size() - 1);
        }
    }
}

vector<string> wordBreak(string s,const set<string>& wordDict) {
    vector<string> res;
    string out;
    vector<bool> possible(s.size() + 1, true);
    wordBreakDFS(s, wordDict, 0, possible, out, res);
    return res;
}

int calcuBlank(const string& s){
    int n=s.length();
    int ans=0;
    for(int i=0;i<n;i++){
        if(s[i]==' ')
            ++ans;
    }
    return n;
}


void mincut(const string& str, const set<string>& dict)
{
    vector<string> ans=wordBreak(str,dict);
    //for(auto item:ans)
    //    cout<<item<<endl;
    int min=0x7FFFFFFF,index=0;
    for(int i=0;i<ans.size();i++){
        if(calcuBlank(ans[i])<min){
            min=calcuBlank(ans[i]);
            index=i;
        }
    }
    cout<<ans[index]<<endl;
}


int main(int argc, const char * argv[])
{
    string strS;
    string dictStr;
    int nDict;
    set<string> dict;
    
    cin>>strS;
    cin>>nDict;
    for (int i = 0; i < nDict; i++)
    {
        cin>>dictStr;
        dict.insert(dictStr);
    }
    mincut(strS, dict);
    
    return 0;
}*/

/*
#include <set>
#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

unordered_map<string, vector<string>> m;

vector<string> combine(string word, vector<string> prev){
    for(int i=0;i<prev.size();++i){
        prev[i]+=" "+word;
    }
    return prev;
}

vector<string> wordBreak(string s, const set<string>& dict) {
    if(m.count(s)) return m[s]; //take from memory
    vector<string> result;
    if(dict.count(s)){ //a whole string is a word
        result.push_back(s);
    }
    for(int i=1;i<s.size();++i){
        string word=s.substr(i);
        if(dict.count(word)){
            string rem=s.substr(0,i);
            vector<string> prev=combine(word,wordBreak(rem,dict));
            result.insert(result.end(),prev.begin(), prev.end());
        }
    }
    m[s]=result; //memorize
    return result;
}

void mincut(const string& str, const set<string>& dict)
{
    vector<string> ans=wordBreak(str,dict);
    //for(auto item:ans)
    //    cout<<item<<endl;
    int min=0x7FFFFFFF,index=0;
    if(!ans.size()) cout<<"n/a"<<endl;
    else{
        for(int i=0;i<ans.size();i++){
            if(ans[i].length()<min){
                min=ans[i].length();
                index=i;
            }
    }
    cout<<ans[index]<<endl;
    }
}


int main(int argc, const char * argv[])
{
    string strS;
    string dictStr;
    int nDict;
    set<string> dict;
    
    cin>>strS;
    cin>>nDict;
    for (int i = 0; i < nDict; i++)
    {
        cin>>dictStr;
        dict.insert(dictStr);
    }
    mincut(strS, dict);
    
    return 0;
}
 */

/*#include <iostream>
#include <vector>
using namespace std;

int main(int argc,char* argv[]){
    int number;
    int max=0x80000000;
    int sum=0;
    vector<int> vec;
    while(cin>>number){
        vec.push_back(number);
    }
    for(int i=0;i<vec.size();i++){
        sum+=vec[i];
        if(sum<0) sum=0;
        if(sum>max){
            max=sum;
        }
    }
    cout<<max<<endl;
    return 0;
}*/

/*#include <iostream>
#include <vector>
using namespace std;

int main(int argc,char* argv[]){
    int number;
    int max=0x80000000;
    int sum=0;
    while(cin>>number){
        sum+=number;
        if(sum<0) sum=0;
        if(sum>max){
            max=sum;
        }
    }
    cout<<max<<endl;
    return 0;
}*/

#include <iostream>
#include <vector>
using namespace std;

int partion(int *p, int n)
{
    int idx=rand()%n;
    swap(p[idx], p[n-1]);
    int i=-1;
    int j=0;
    for(j=0; j<n; j++)
    {
        if(p[j]<p[n-1])
        {
            swap(p[++i], p[j]);
        }
    }
    swap(p[++i], p[n-1]);
    return i;
}

int getMaxK(int *p, int n, int k)
{
    int mid;
    if(k<=0)
        return -1;
    if(n<k)
        return -1;
    mid=partion(p, n);
    if(mid == n-k)
        return p[mid];
    else if(mid<n-k)
        return getMaxK(p+mid+1, n-mid-1, k);
    else
        return getMaxK(p, mid, k-(n-mid));
}

int main(int argc,char* argv[])
{
    vector<int> vec;
    int number;
    int k=0;
    while(cin>>number){
        vec.push_back(number);
    }
    //for(auto item:vec) cout<<item<<" ";
    //cout<<endl;
    k=vec[vec.size()-1];
    //cout<<k<<endl;
    vec.pop_back();
    //for(auto item:vec) cout<<item<<" ";
    //cout<<endl;
    int kpos=getMaxK(&vec[0], (int)vec.size(), k);
    printf("%d\n",kpos);
    return 0;
}

/*int main(void)
{
    int num,a[] = {12012, 3, 945, 965, 66, 232, 65, 7, 8, 898, 56, 878, 170, 13, 5};
    num=getMaxK(a, 15, 4);
    printf("%d\n",num);
    system("pause");
    return 0;
}*/

