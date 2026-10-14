#include <bits/stdc++.h>
using namespace std;

class Cube{
public:
    // 0-U,1-D,2-F,3-B,4-L,5-R
    char cube[6][3][3];
    vector<string> moves={"U","U'","U2","D","D'","D2","F","F'","F2","B","B'","B2","L","L'","L2","R","R'","R2"};
    vector<string> path;
    
    void input(){
        for(int f=0;f<6;f++){
            cout<<"Enter face "<<f<<" (9 colors):\n";

            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    cin>>cube[f][i][j];
                }
            }
        }
    }

    int corners[8][3][3]={
        {{0,2,2},{2,0,2},{5,0,0}},
        {{0,2,0},{2,0,0},{4,0,2}},
        {{0,0,2},{3,0,0},{5,0,2}},
        {{0,0,0},{3,0,2},{4,0,0}},
        {{1,0,2},{2,2,2},{5,2,0}},
        {{1,0,0},{2,2,0},{4,2,2}},
        {{1,2,2},{3,2,0},{5,2,2}},
        {{1,2,0},{3,2,2},{4,2,0}}
    };

    int edges[12][2][3]={
        {{0,2,1},{2,0,1}},
        {{0,1,2},{5,1,0}},
        {{0,0,1},{3,0,1}},
        {{0,1,0},{4,1,2}},
        {{1,0,1},{2,2,1}},
        {{1,1,2},{5,2,1}},
        {{1,2,1},{3,2,1}},
        {{1,1,0},{4,2,1}},
        {{2,1,2},{5,1,1}},
        {{2,1,0},{4,1,1}},
        {{3,1,0},{5,1,1}},
        {{3,1,2},{4,1,1}}
    };

    bool validColors(){
        map<char,int> mp;
        for(int f=0;f<6;f++){
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    mp[cube[f][i][j]]++;
                }
            }
        }

        if(mp.size() != 6) return false;

        string colors = "WYGBOR";
        for(char c:colors){
            if(mp[c] != 9)
                return false;
        }

        return true;
    }

    void rotateFace(int f){
        char temp[3][3];
        memcpy(temp,cube[f],sizeof(temp));

        for(int j=0;j<3;j++){
            for(int i=2;i>=0;i--){
                cube[f][j][2-i]=temp[i][j];
            }
        }
    }

    void U(){
        rotateFace(0);
        char t[3];
        for(int j=0;j<3;j++) t[j]=cube[2][0][j];
        for(int j=0;j<3;j++) cube[2][0][j]=cube[5][0][j];
        for(int j=0;j<3;j++) cube[5][0][j]=cube[3][0][j];
        for(int j=0;j<3;j++) cube[3][0][j]=cube[4][0][j];
        for(int j=0;j<3;j++) cube[4][0][j]=t[j];
    }

    void U2(){
        U();
        U();
    }

    void UPrime(){
        U();
        U();
        U();
    }

    void D(){
        rotateFace(1);
        char t[3];
        for(int j=0;j<3;j++) t[j]=cube[2][2][j];
        for(int j=0;j<3;j++) cube[2][2][j]=cube[4][2][j];
        for(int j=0;j<3;j++) cube[4][2][j]=cube[3][2][j];
        for(int j=0;j<3;j++) cube[3][2][j]=cube[5][2][j];
        for(int j=0;j<3;j++) cube[5][2][j]=t[j];
    }

    void D2(){
        D();
        D();
    }

    void DPrime(){
        D();
        D();
        D();
    }

    void F(){
        rotateFace(2);
        char u[3],l[3],d[3],r[3];
        for(int i=0;i<3;i++){
            u[i]=cube[0][2][i];
            l[i]=cube[4][i][2];
            d[i]=cube[1][0][i];
            r[i]=cube[5][i][0];
        }
        for(int i=0;i<3;i++){
            cube[0][2][i]=l[2-i];
            cube[4][i][2]=d[i];
            cube[1][0][i]=r[2-i];
            cube[5][i][0]=u[i];
        }
    }

    void F2(){
        F();
        F();
    }

    void FPrime(){
        F();
        F();
        F();
    }

    void B(){
        rotateFace(3);
        char u[3],r[3],d[3],l[3];
        for(int i=0;i<3;i++){
            u[i]=cube[0][0][i];
            r[i]=cube[5][i][2];
            d[i]=cube[1][2][i];
            l[i]=cube[4][i][0];
        }
        for(int i=0;i<3;i++){
            cube[0][0][i]=r[i];
            cube[5][i][2]=d[2-i];
            cube[1][2][i]=l[i];
            cube[4][i][0]=u[2-i];
        }
    }

    void B2(){
        B();
        B();
    }

    void BPrime(){
        B();
        B();
        B();
    }

    void L(){
        rotateFace(4);
        char u[3],b[3],d[3],f[3];
        for(int i=0;i<3;i++){
            u[i]=cube[0][i][0];
            b[i]=cube[3][i][2];
            d[i]=cube[1][i][0];
            f[i]=cube[2][i][0];
        }
        for(int i=0;i<3;i++){
            cube[0][i][0]=b[2-i];
            cube[3][i][2]=d[2-i];
            cube[1][i][0]=f[i];
            cube[2][i][0]=u[i];
        }
    }

    void L2(){
        L();
        L();
    }

    void LPrime(){
        L();
        L();
        L();
    }

    void R(){
        rotateFace(5);
        char u[3],f[3],d[3],b[3];
        for(int i=0;i<3;i++){
            u[i]=cube[0][i][2];
            f[i]=cube[2][i][2];
            d[i]=cube[1][i][2];
            b[i]=cube[3][i][0];
        }
        for(int i=0;i<3;i++){
            cube[0][i][2]=f[i];
            cube[2][i][2]=d[i];
            cube[1][i][2]=b[2-i];
            cube[3][i][0]=u[2-i];
        }
    }

    void R2(){
        R();
        R();
    }

    void RPrime(){
        R();
        R();
        R();
    }

    void move(string s){
        if(s=="U") U();
        else if(s=="U'") UPrime();
        else if(s=="U2") U2();

        else if(s=="D") D();
        else if(s=="D'") DPrime();
        else if(s=="D2") D2();

        else if(s=="F") F();
        else if(s=="F'") FPrime();
        else if(s=="F2") F2();

        else if(s=="B") B();
        else if(s=="B'") BPrime();
        else if(s=="B2") B2();

        else if(s=="L") L();
        else if(s=="L'") LPrime();
        else if(s=="L2") L2();

        else if(s=="R") R();
        else if(s=="R'") RPrime();
        else if(s=="R2") R2();
    }

    bool isSolved(){
        for(int f=0;f<6;f++){
            char color=cube[f][1][1];
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    if(cube[f][i][j]!=color)
                        return false;
                }
            }
        }
        return true;
    }

    void saveCube(char temp[6][3][3]){
        memcpy(temp,cube,sizeof(cube));
    }

    void restoreCube(char temp[6][3][3]){
        memcpy(cube,temp,sizeof(cube));
    }

    bool pruneHelper(string s){
        if(path.empty()) return false;

        char prev=path.back()[0];
        char curr=s[0];

        if(prev==curr) return true;

        if((prev=='U' && curr=='D') ||
        (prev=='D' && curr=='U') ||
        (prev=='F' && curr=='B') ||
        (prev=='B' && curr=='F') ||
        (prev=='L' && curr=='R') ||
        (prev=='R' && curr=='L')){
            if(prev>curr) return true;
        }

        return false;
    }

    int h(){
        int bc=0,be=0;

        for(int i=0;i<8;i++){
            char a[3],b[3];

            for(int j=0;j<3;j++){
                int f=corners[i][j][0];
                int r=corners[i][j][1];
                int c=corners[i][j][2];

                a[j]=cube[f][r][c];
                b[j]=cube[f][1][1];
            }

            sort(a,a+3);
            sort(b,b+3);

            if(!equal(a,a+3,b)) bc++;
        }

        for(int i=0;i<12;i++){
            char a[2],b[2];

            for(int j=0;j<2;j++){
                int f=edges[i][j][0];
                int r=edges[i][j][1];
                int c=edges[i][j][2];

                a[j]=cube[f][r][c];
                b[j]=cube[f][1][1];
            }

            sort(a,a+2);
            sort(b,b+2);

            if(!equal(a,a+2,b)) be++;
        }

        return max((bc+3)/4,(be+3)/4);
    }

    bool dfs(int depth,int limit){
        if(isSolved()) return true;
        int estimate=depth+h();
        if(estimate>limit) return false;
        for(string s:moves){
            if(pruneHelper(s)) continue;

            char temp[6][3][3];
            saveCube(temp);

            move(s);
            path.push_back(s);

            if(dfs(depth+1,limit)) return true;

            path.pop_back();
            restoreCube(temp);
        }
        return false;
    }

    bool solve(){
        path.clear();

        if(isSolved()) return true;

        int limit=h();

        while(limit<=30){
            if(dfs(0,limit)) return true;
            limit++;
        }

        return false;
    }

    void printCube(){
        for(int f=0;f<6;f++){
            cout<<"Face "<<f<<":\n";
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    cout<<cube[f][i][j]<<" ";
                }
                cout<<"\n";
            }
            cout<<"\n";
        }
    }
};

int main(){
    Cube c;

    c.input();

    if(!c.validColors()){
        cout<<"Invalid cube colors!\n";
        return 0;
    }

    if(c.isSolved()){
        cout<<"Cube is already solved!\n";
        return 0;
    }

    if(c.solve()){
        cout<<"Solution:\n";

        for(string s:c.path){
            cout<<s<<" ";
        }

        cout<<"\n";
    }
    else{
        cout<<"No solution found within depth 30.\n";
    }
}