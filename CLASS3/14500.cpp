#include <iostream>
using namespace std;

int tetromino[19][4][2] = {
    {{0,0}, {0,1}, {0,2}, {0,3}},
    {{0,0}, {1,0}, {2,0}, {3,0}},

    {{0,0}, {1,0}, {0,1}, {1,1}},

    {{0,0}, {1,0}, {2,0}, {2,1}},
    {{0,0}, {1,0}, {2,0}, {2,-1}},
    {{0,0}, {0,1}, {0,2}, {1,2}},
    {{0,0}, {1,0}, {0,1}, {0,2}},
    {{0,0}, {0,-1}, {1,0}, {2,0}},
    {{0,0}, {0,1}, {1,0}, {2,0}},
    {{0,0}, {0,1}, {0,2}, {-1,2}},
    {{0,0}, {-1,0}, {0,1}, {0,2}},
    
    {{0,0}, {1,0}, {1,1}, {2,1}},
    {{0,0}, {1,0}, {1,-1}, {2,-1}},
    {{0,0}, {0,1}, {1,1}, {1,2}},
    {{0,0}, {0,-1}, {-1,-1}, {-1,-2}},

    {{0,0}, {0,1}, {0,2}, {1,1}},
    {{0,0}, {0,1}, {0,2}, {-1,1}},
    {{0,0}, {1,0}, {2,0}, {1,1}},
    {{0,0}, {1,0}, {2,0}, {1,-1}}
};


int map[500][500];


int main(){
    int N, M;
    cin >> N >> M;
    int sum;
    int temp = 0;

    for(int i =0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> map[i][j];
        }
    }

    for(int y = 0; y < N; y++){
        for(int x = 0; x < M; x++){
            for(int k = 0; k < 19; k++){
                sum = 0;
                for(int t = 0; t < 4; t++){
                    if(y + tetromino[k][t][0] < 0 || y + tetromino[k][t][0] >= N) {
                        sum = 0;
                        break;
                    }
                    if(x + tetromino[k][t][1] < 0 || x + tetromino[k][t][1] >= M) {
                        sum = 0;
                        break;
                    }
                    sum += map[y+tetromino[k][t][0]][x+tetromino[k][t][1]];
                }
                temp = max(sum, temp);
            }
        }
    }

    cout << temp;
}