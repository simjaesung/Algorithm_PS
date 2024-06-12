#include <string>
#include <vector>

using namespace std;
pair<int,int>loc[10] = {{3,1},{0,0},{0,1},{0,2},{1,0},{1,1},{1,2},{2,0},{2,1},{2,2}};
pair<int,int>locL = {3,0}; //왼손 위치
pair<int,int>locR = {3,2}; //오른손 위치
int whand; //오른손잡이면 1
string solution(vector<int> numbers, string hand) {
    string answer = "";
    if(hand == "right") whand = 1;
    for(int x : numbers){
        if(x == 1 || x == 4 || x == 7){
            locL.first = loc[x].first;
            locL.second = loc[x].second;
            answer += 'L';
        }
        else if(x == 3 || x == 6 || x == 9){
            locR.first = loc[x].first;
            locR.second = loc[x].second;
            answer += 'R';
        }
        else{
            int lenL = abs(loc[x].first - locL.first) + abs(loc[x].second - locL.second);
            int lenR = abs(loc[x].first - locR.first) + abs(loc[x].second - locR.second);
            if(lenL < lenR) {
                answer +='L';
                locL.first = loc[x].first;
                locL.second = loc[x].second;
            }
            else if(lenR < lenL) {
                answer +='R';
                locR.first = loc[x].first;
                locR.second = loc[x].second;
            }
            else{
                if(whand) {
                    answer +='R';
                    locR.first = loc[x].first;
                    locR.second = loc[x].second;
                }
                else {
                    answer +='L';
                    locL.first = loc[x].first;
                    locL.second = loc[x].second;
                }
            }
        }
    }
    return answer;
}