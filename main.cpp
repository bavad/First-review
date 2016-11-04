#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
using std::max;

int result[101][301][301];
int main() {
    int busesNumber, volume, peopleNumber;
    cin >> busesNumber >> volume >> peopleNumber;
    int peopleSize[peopleNumber+1];
    for (int i = 1; i <= peopleNumber; ++i) {
        cin >> peopleSize[i];
    }

    result[0][0][0]=0;
    for (int iindex = 0; iindex < busesNumber; ++iindex) {
        for (int jindex = 0; jindex <= peopleNumber; ++jindex) {
            for (int kindex = 0; kindex <= volume; ++kindex) {
                if (jindex > 0 && kindex >= peopleSize[jindex] && kindex > 0) {
                    result[iindex][jindex][kindex] = max(max(result[iindex][jindex - 1][kindex],
                    1 + result[iindex][jindex - 1][kindex - peopleSize[jindex]]),
                    result[iindex][jindex][kindex - 1]);
                } else if (jindex == 0 && kindex > 0) {
                    result[iindex][jindex][kindex]=result[iindex][jindex][kindex - 1];
                } else if (jindex > 0 && kindex < peopleSize[jindex] && kindex > 0) {
                    result[iindex][jindex][kindex] = max (result[iindex][jindex - 1][kindex],
                    result[iindex][jindex][kindex - 1]);
                }
                if (kindex == 0 && iindex > 0) {
                    result[iindex][jindex][kindex]=result[iindex - 1][jindex][volume];
                }
            }
        }
    }

    cout << result[busesNumber - 1][peopleNumber][volume];
    return 0;
}
