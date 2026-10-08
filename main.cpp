#include <bits/stdc++.h>
using namespace std;

class Cube{
public:
    // 0-U,1-D,2-F,3-B,4-L,5-R
    char cube[6][3][3];
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

        for(int j=0;j<3;j++)
            t[j]=cube[2][0][j];

        for(int j=0;j<3;j++)
            cube[2][0][j]=cube[5][0][j];

        for(int j=0;j<3;j++)
            cube[5][0][j]=cube[3][0][j];

        for(int j=0;j<3;j++)
            cube[3][0][j]=cube[4][0][j];

        for(int j=0;j<3;j++)
            cube[4][0][j]=t[j];
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

        for(int j=0;j<3;j++)
            t[j]=cube[2][2][j];

        for(int j=0;j<3;j++)
            cube[2][2][j]=cube[4][2][j];

        for(int j=0;j<3;j++)
            cube[4][2][j]=cube[3][2][j];

        for(int j=0;j<3;j++)
            cube[3][2][j]=cube[5][2][j];

        for(int j=0;j<3;j++)
            cube[5][2][j]=t[j];
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

        char t[3];

        for(int i=0;i<3;i++)
            t[i]=cube[0][2][i];

        for(int i=0;i<3;i++)
            cube[0][2][i]=cube[4][2-i][2];

        for(int i=0;i<3;i++)
            cube[4][i][2]=cube[1][0][i];

        for(int i=0;i<3;i++)
            cube[1][0][i]=cube[5][2-i][0];

        for(int i=0;i<3;i++)
            cube[5][i][0]=t[i];
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

        char t[3];

        for(int i=0;i<3;i++)
            t[i]=cube[0][0][i];

        for(int i=0;i<3;i++)
            cube[0][0][i]=cube[5][i][2];

        for(int i=0;i<3;i++)
            cube[5][i][2]=cube[1][2][2-i];

        for(int i=0;i<3;i++)
            cube[1][2][i]=cube[4][i][0];

        for(int i=0;i<3;i++)
            cube[4][i][0]=t[2-i];
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

        char t[3];

        for(int i=0;i<3;i++)
            t[i]=cube[0][i][0];

        for(int i=0;i<3;i++)
            cube[0][i][0]=cube[3][2-i][2];

        for(int i=0;i<3;i++)
            cube[3][i][2]=cube[1][2-i][0];

        for(int i=0;i<3;i++)
            cube[1][i][0]=cube[2][i][0];

        for(int i=0;i<3;i++)
            cube[2][i][0]=t[i];
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

        char t[3];

        for(int i=0;i<3;i++)
            t[i]=cube[0][i][2];

        for(int i=0;i<3;i++)
            cube[0][i][2]=cube[2][i][2];

        for(int i=0;i<3;i++)
            cube[2][i][2]=cube[1][i][2];

        for(int i=0;i<3;i++)
            cube[1][i][2]=cube[3][2-i][0];

        for(int i=0;i<3;i++)
            cube[3][i][0]=t[2-i];
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
    c.printCube();

}