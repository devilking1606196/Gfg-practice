// // #include<bits/stdc++.h>
// // using namespace std;

// // //  int hammingWeight(uint32_t n) {
// // //      int count=0;
// // //      while(n!=0){
// // //          if(n&1){
// // //          count++;
// // //          }
// // //          n=n>>1;
// // //      }   
// // //      return count;    
// // //     }

// // vector<string> gss(string s){
// //     if(s.length()==0)
// //     {
// //         vector<string>ans={""};
// //         return ans;
// //     }
// //     char ch=s[0];
// //     string s1=s.substr(1);
// //     vector<string>ans=gss(s1);
// //     vector <string> myAns;
// //     for(int i=0;i<ans.size();i++)
// //     {
// //         myAns.push_back(ans[i]);
// //     }
// //     for(int i=0;i<ans.size();i++)
// //     {
// //         myAns.push_back(ch+ans[i]);
// //     }
// //     return myAns;
// // }

// // vector<string> getKPC(string s) {
// //     if(s.length()==0)
// //     {
// //         vector<string> ans={""};
// //         return ans;
// //     }
// //   string code[]={".;","abc","def","ghi","jkl","mno","pqrs","tu","vwx","yz"};
// //   char ch=s[0];
// //   string s1=s.substr(1);
// //   vector<string> ans=getKPC(s1);
// //   vector<string> myAns;
// //   for(int i=0;i<ans.size();i++)
// //   {
// //       for(int j=0;j<code[ch-48].length();j++)
// //       {
// //           myAns.push_back(code[ch-48][j]+ans[i]);
// //       }
// //   }
// //   return myAns;
// // }




// // int main(){
// //  string s="578";
// //   vector<string> ans = getKPC(s);
// //   int cnt = 0;
// //   cout<<ans.size();

// //   cout << '[';
// //   for (string str : ans) {
// //     if (cnt != ans.size() - 1)
// //       cout << str << ", ";
// //     else
// //       cout << str;
// //     cnt++;
// //   }
// //   cout << ']';












// //     //  string s="bc";
// //     // vector<string> ans = gss(s);
// //     // int cnt = 0;

// //     // cout << '[';
// //     // for (string str : ans){
// //     //     if (cnt != ans.size() - 1)
// //     //         cout << str << ", ";
// //     //     else
// //     //         cout << str;
// //     //     cnt++;
// //     // }
// //     // cout << ']';
// // }



// //     // int arr[5]={1};
// //     // for(int i=0;i<5;i++){
// //     //     cout<<arr[i]<<" ";
// //     // }
// //     // cout<<endl;
// //     // cout<<(1^2^5^5)<<endl;
// //     // string s="11000";
// //     // vector<int> a={1};
// //     // // cout<<solve(s);
// //     // cout<<a.size()<<" ";
// //     // cout<<min(1,1)<<endl;
// //     // cout<<INT8_MIN;
// //     // pair <int,int> p;
// //     // p.first=1;
// //     // p.second=2;
// //     // cout<<"\n"<<p.first<<p.second;
// //     // cout<<"  "<<(5&3);
// //     // int a=1,b=2;
// //     // if(a-- >0 || ++b >2)
// //     //   cout<<" 1 skdln"<<endl;
// //     //   else
// //     //   cout<<"2";
// //     //   cout<<(25*(++b));
// //     // cout<<hammingWeight(11);
// //     // cout<<(((0^1)<<1)^1);
// //     // cout<<(-256>>4);
// //     // cout<<((int(log10(1223))+1)&1)<<endl;
// //     // cout<<(3&1);
// // // }





// // // unique strings

// // // bool solve(string s) {
// // //     if (s.size() > 'z' - 'a' + 1) return false;

// // //     int x = 0;
// // //     for (int i = 0; i < s.size(); i++) {
// // //         if (x & (1 << (s[i] - 'a'))) return false;
// // //         x |= (1 << (s[i] - 'a'));
// // //     }
// // //     return true;
// // // }
// // #include<iostream>
// // #include<vector>
// // #include<string>

// // using namespace std;

// // vector<string> get_maze_paths(int sr, int sc, int dr, int dc)
// // {
// //     vector <string> hpath,vpath,dpath,paths;
// //     if(sc==dc&&sr==dr)
// //     {
// //         paths={""};
// //         return paths;
// //     }
    
// //     if(sc<dc)
// //     {
// //     for(int h=1;h<=dc-sc;h++)
// //     {
// //         hpath=get_maze_paths(sr,sc+h,dr,dc);
// //         for(string p:hpath)
// //         {
// //             paths.push_back("h"+to_string(h)+p);
// //         }
    
// //     }
// //     }
// //     if(sr<dr)
// //     {
// //     for( int v=1;v<=dr-sr;v++)
// //     {
// //         vpath=get_maze_paths(sr+1,sc,dr,dc);
// //         for(string p:vpath)
// //         {
// //             paths.push_back("v"+to_string(v)+p);
// //         }
// //     }
// //     }
// //     if(sr<dr&&sc<dc)
// //     {
// //     for(int d=1;d<=dr-sr&&d<=dc-sc;d++)
// //     {
// //         dpath=get_maze_paths(sr+1,sc+1,dr,dc);
// //         for(string p:dpath)
// //         {
// //             paths.push_back("d"+to_string(d)+p);
// //         }
// //     }
// //     }
// //     return paths;
  
// // }

// // void display(vector<string>& arr) {
// //   cout << "[";
// //   for (int i = 0; i < arr.size(); i++) {
// //     cout << arr[i];
// //     if (i < arr.size() - 1) cout << ", ";
// //   }

// //   cout << "]" << endl;
// // }


// // // int main() {
// // //   int n=3, m=3;
// // // //   vector<string> ans = get_maze_paths(0, 0, n - 1, m - 1);
// // // //   display(ans);
// // //   string s="abc",s1;
// // //   s1=s[0];
// // //   cout<<s1<<endl;
// // //   cout<<s.erase(1,1);

// // //   return 0;
// // // }


// // #include <iostream>
// // using namespace std;

// // void printPermutations(string str, string asf){
// //     // write your code here
// //     if(str.length()==0)
// //     {
// //         cout<<asf<<endl;
// //         return;
// //     }
// //     string s;
// //     for(int i=0;i<str.length();i++)
// //     {
// //         char ans=str[i];
// //         s=str.substr(0,i)+str.substr(i+1);
// //         printPermutations(s,asf+ans);
        
// //     }
    
// // }

// // int main(){
// //     string str="abc";
// //     //  for(int i=0;i<str.length();i++)
// //     // {
// //     //  string s=str.substr(0,i)+str.substr(i+1);
// //     //  cout<<s<<endl;
// //     // }
// //     string s1="134";
// //     string c=s1.substr(0,2);

// //     int i=stoi(c);
// //     cout<<i<<endl;
// //     char ans=char('a'+i-1);
// //     cout<<ans;
// //     // printPermutations(str,"");
    
// // }




// // // #include <iostream>
// // // #include<string>
// // using namespace std;
// // void printEncoding(string str, string asf){
// //     // write your code here
// //     if(str.length()==0)
// //     {
// //         cout<<asf<<endl;
// //         return;
// //     }
// //     else if(str.length()==1)
// //     {
// //         char ch=str[0];
// //         if(ch=='0')
// //         return;
// //         else
// //         {
// //             int cho=ch-'0';
// //             char ans='a'+cho-1;
// //             string ros=str.substr(1);
// //             printEncoding(ros,asf+ans);
// //         }
// //     }
// //     else
// //     {
// //         char ch=str[0];
// //         if(ch=='0')
// //         return;
// //         else
// //         {
// //             int cho=ch-'0';
// //             char ans='a'+cho-1;
// //             string ros=str.substr(1);
// //             printEncoding(ros,asf+ans);
// //         }

// //         string ch1=str.substr(0,2),ros1=str.substr(2);
// //         int cho1=stoi(ch1);
// //         if(cho1>=27)
// //         return;
// //         else
// //         {
// //             char ans='a'+cho1-1;
// //             printEncoding(ros1,asf+ans);
// //         }


// //     }

// // }

// // int main(){
// //     string str="105423";
// //     printEncoding(str,"");
    
// // }




// #include<iostream>

// #include<vector>

// using namespace std;
// // asf -> answer so far
// void floodfill(vector<vector<int>> maze, int sr, int sc, string asf,vector<vector<bool>> visited) 
// {
//     if(sr<0||sc<0||sr==maze.size()||sc==maze[0].size()||maze[sr][sc]==1||visited[sr][sc]==1)
//     {
//         return;
//     }
//     if(sr==maze.size()-1&&sc==maze[0].size()-1)
//     {
//         cout<<asf<<endl;
//         return;
//     }
//     visited[sr][sc]=true;
//     floodfill(maze,sr-1,sc,asf+"t",visited);
//     floodfill(maze,sr,sc-1,asf+"l",visited);
//     floodfill(maze,sr+1,sc,asf+"d",visited);
//     floodfill(maze,sr,sc+1,asf+"r",visited);
//     visited[sr][sc]=false;
// }

// int main() {

//   vector < vector < int >> arr={{0,0,0},{1,0,1},{0,0,0}};
// //   for(auto i:arr)
// //   {
// //       for(auto x:i)
// //       {
// //           cout<<x<<endl;
// //       }
// //   }
//   vector<vector<bool>> visited(3,vector<bool>(3));
//   floodfill(arr, 0, 0, "",visited);
// }




// #include<iostream>

// #include<vector>

// using namespace std;
// // asf -> answer so far
// void floodfill(vector<vector<int>> maze, int sr, int sc, string asf)
//  {
//     vector<vector<bool>> visited(maze.size(),vector<bool>(maze[0].size()));


//     if(sr<0||sc<0||sr==maze.size()||sc==maze[0].size()||maze[sr][sc]==1||visited[sr][sc]==1)
//     {
//         return;
//     }
//     if(sr==maze.size()-1&&sc==maze[0].size()-1)
//     {
//         cout<<asf<<endl;
//         return;
//     }
//     visited[sr][sc]=true;
//     floodfill(maze,sr-1,sc,asf+"t");
//     floodfill(maze,sr,sc-1,asf+"l");
//     floodfill(maze,sr+1,sc,asf+"d");
//     floodfill(maze,sr,sc+1,asf+"r");
//     visited[sr][sc]=false;


      
// }

// int main() {
  

//   vector < vector < int >> arr={{0,0,0},{1,0,1},{0,0,0}};

//   floodfill(arr, 0, 0, "");
// }




#include<bits/stdc++.h>
using namespace std;

// set is the subset
// sos is sum of subset
// tar is target
void printTargetSumSubsets(vector<int> arr, int idx, string set, int sos, int tar) {
  //write your code here
  if(idx==arr.size())
  {
      if(sos==tar)
  {
      cout<<set<<"."<<endl;
  }
      return;
  }
  
      printTargetSumSubsets(arr,idx+1,set+to_string(arr[idx])+",",sos+arr[idx],tar);
      printTargetSumSubsets(arr,idx+1,set,sos,tar);
  

}


int main() {
    // int n=5,t=60;
    // vector<int> arr={10,20,30,40,50};
   
    // // printTargetSumSubsets(arr,0,"",0,t);
    // int n,nutan=0,tulsa=0;
    // cin>>n;
    // string s;
    // cin>>s;
    // for(int i=0;i<s.length();i++)
    // {
    //     if(s[i]=='N')
    //     { 
    //         cout<<nutan<<endl;
    //         nutan++;
    //     }
    //     else 
    // {
    //     cout<<tulsa<<endl;
    //     tulsa++;
    // }
    // }
    // cout<<nutan<<"\n"<<tulsa;
    // if(nutan>tulsa)
    // cout<<"Nutan";
    // else
    // cout<<"Tulsa";
    // int arr[]={5,3,20,15,8,2},max=INT_MIN;
    // // reverse(arr,arr+2);
    // // reverse(arr+2,arr+7);
    // // reverse(arr,arr+7);
    // stack<int> s;
    // int n =sizeof(arr)/sizeof(arr[0]);
    // for(int i=n-1;i>=0;i--)
    // {
    //     if(arr[i]>max)
    //     {
    //         s.push(arr[i]);
    //         max=arr[i]; 
    //     }
    // }
    // while(!s.empty())
    // {
    //     cout<<s.top()<<" ";
    //     s.pop();
    // }
    // return 0;
    char c='+';
    if('+'== 42)
    {
        cout<<"yes";
    }
}